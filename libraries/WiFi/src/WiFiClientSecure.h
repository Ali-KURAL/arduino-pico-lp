/*
    WiFiClientSecure.h - Variant of WiFiClient with TLS support
    Copyright (c) 2015 Ivan Grokhotkov. All rights reserved.
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
#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiClientSecureBearSSL.h"

using namespace BearSSL;
