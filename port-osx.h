/*
 * port-osx.h - required definitions and functions for OS X
 *
 * Copyright (c) 2013-2014, Hannu Valtonen <hannu.valtonen@ohmu.fi>
 * All rights reserved.
 *
 * This file is under the Apache License, Version 2.0.
 * See the file `LICENSE` for details.
 *
 */

#include <libkern/OSByteOrder.h>
#include <machine/endian.h>
#include <string.h>
#include <sys/time.h>

#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL SO_NOSIGPIPE
#endif

#define CLOCK_MONOTONIC 2

static int clock_gettime(int clk_id __attribute__((unused)), struct timespec* t) {
    struct timeval tv;
    int rv = gettimeofday(&tv, NULL);
    if (rv)
        return rv;
    t->tv_sec  = tv.tv_sec;
    t->tv_nsec = tv.tv_usec * 1000;
    return 0;
}

#define htobe16(x) OSSwapHostToBigInt16(x)
#define be16toh(x) OSSwapBigToHostInt16(x)

#define htobe32(x) OSSwapHostToBigInt32(x)
#define be32toh(x) OSSwapBigToHostInt32(x)

#define htobe64(x) OSSwapHostToBigInt64(x)
#define be64toh(x) OSSwapBigToHostInt64(x)
