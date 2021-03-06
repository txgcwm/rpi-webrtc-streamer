/*
 *  Copyright 2011 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#ifndef RPI_STREAMER_UTILS_H_
#define RPI_STREAMER_UTILS_H_

#pragma once

#include <assert.h>
#include <string>

#include "webrtc/base/filerotatingstream.h"
#include "webrtc/base/logsinks.h"

#ifndef ARRAYSIZE
#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))
#endif

namespace utils {

// save the logging messsage to file
class FileLogger {
public:
    explicit FileLogger(const std::string path, 
            const rtc::LoggingSeverity severity);
    bool Init();
    ~FileLogger();

private:
    bool inited_;
    std::string dir_path_;
    rtc::LoggingSeverity severity_;
    size_t log_max_file_size_;
    std::unique_ptr<rtc::FileRotatingLogSink> logSink_;
};

// utility functions
std::string IntToString(int i);
std::string Size_tToString(size_t i);
bool String2Int(const std::string &str,int *value );
bool ParseVideoResolution(const std::string resolution,int *width, int *height );
rtc::LoggingSeverity String2LogSeverity(const std::string severity);


};

#endif  // RPI_STREAMER_UTILS_H_

