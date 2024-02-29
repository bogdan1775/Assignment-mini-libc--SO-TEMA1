/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include<internal/types.h>
#include <time.h>

// structura a fost luata din nanosleep man https://linux.die.net/man/2/nanosleep
struct timespec {
    long tv_sec;          /* seconds */
    long   tv_nsec;       /* nanoseconds */
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
