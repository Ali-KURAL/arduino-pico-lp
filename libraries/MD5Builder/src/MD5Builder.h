/*
    MD5Builder - Simple MD5 hash calculations

    Updated for the Pico by Earle F. Philhower, III

    Modified from the ESP8266 version which is
    Copyright (c) 2015 Hristo Gochkov. All rights reserved.
    This file is part of the esp8266 core for Arduino environment.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#include <api/String.h>
#include <Stream.h>
#include <bearssl/bearssl_hash.h>

class MD5Builder {
private:
    br_md5_context _ctx;
    uint8_t _buf[16];
public:
    void begin(void);
    void add(const uint8_t * data, const uint16_t len);
    void add(const char * data) {
        add((const uint8_t*)data, strlen(data));
    }
    void add(char * data) {
        add((const char*)data);
    }
    void add(const String& data) {
        add(data.c_str());
    }
    void addHexString(const char * data);
    void addHexString(char * data) {
        addHexString((const char*)data);
    }
    void addHexString(const String& data) {
        addHexString(data.c_str());
    }
    bool addStream(Stream & stream, const size_t maxLen);
    void calculate(void);
    void getBytes(uint8_t * output) const;
    void getChars(char * output) const;
    String toString(void) const;
};
