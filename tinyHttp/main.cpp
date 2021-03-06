// minimal winSock http get parser, based on tinyHttp
//{{{
/*-
 * Copyright 2012 Matthew Endsley
 * All rights reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted providing that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
//}}}
#include "cWinHttp.h"

int main() {

  cLog::init (LOGINFO, false, "",  "tinyHttp");

  cWinHttp http;
  //if (http.get ("stream.wqxr.org", "js-stream.aac")) {
  std::string host = "as-hls-uk-live.bbcfmt.hs.llnwd.net";
  std::string path = "pool_904/live/uk/bbc_radio_fourfm/bbc_radio_fourfm.isml/bbc_radio_fourfm-audio%3d128000.norewind.m3u8";

  //auto host = http.getRedirectable ("nothings.org", "");
  auto rhost = http.getRedirectable (host, path);
  if (rhost != host)
    cLog::log(LOGINFO, "Redirect %d %s %s", http.getResponseCode(), rhost.c_str(), host.c_str());

  if (!rhost.empty()) {
    cLog::log (LOGINFO, "Response: %d", http.getResponseCode());
    if (http.getBodySize())
      cLog::log (LOGINFO, "%s", http.getBody());
    }

  auto ok = http.get (rhost, path);
  if (ok) {
    cLog::log (LOGINFO, "Response: %d", http.getResponseCode());
    if (http.getBodySize())
      cLog::log (LOGINFO, "%s", http.getBody());
    }

  return 0;
  }
