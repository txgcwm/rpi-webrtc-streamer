/*
Copyright (c) 2017, rpi-webrtc-streamer Lyu,KeunChang

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef RPI_STREAMER_CONFIG_
#define RPI_STREAMER_CONFIG_

#include "webrtc/base/checks.h"

#include "webrtc/base/fileutils.h"
#include "webrtc/base/optionsfile.h"
#include "webrtc/base/pathutils.h"


class StreamerConfig  {
public:
    explicit StreamerConfig(const std::string &config_file);
    ~StreamerConfig();

    // WebSocket Config
    bool GetWebSocketEnable();
    bool GetWebSocketPort(int& port);

    // Direct Socket Config
    bool GetDirectSocketEnable();
    bool GetDirectSocketPort(int& port);

    bool GetStunServer(std::string& server);
    bool GetTurnServer(std::string& server);

    // App Channel Config
    bool GetAppChannelConfig(std::string& conf);

    // Media Config
    bool GetMediaConfig(std::string& conf);

private:
    bool config_loaded_;
    rtc::OptionsFile config_;
};



#endif  // RPI_STREAMER_CONFIG_
