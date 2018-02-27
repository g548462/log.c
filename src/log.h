/**
 * Copyright (c) 2017 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `log.c` for details.
 */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>

typedef void (*log_LockFn)(void *udata, int lock);

// LOG_INFO is define in syslog log_level, so rename it as LOGINFO
enum {
    LOGTRACE = 0,
    LOGDEBUG,
    LOGINFO,
    LOGWARN,
    LOGERROR,
    LOGFATAL
};

#define log_trace(...) log_log(LOGTRACE, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) log_log(LOGDEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...)  log_log(LOGINFO,  __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...)  log_log(LOGWARN,  __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOGERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_log(LOGFATAL, __FILE__, __LINE__, __VA_ARGS__)

void log_set_udata(void *udata);
void log_set_lock(log_LockFn fn);
void log_set_fp(FILE *fp);
void log_set_level(int level);
void log_set_quiet(int enable);

void log_log(int level, const char *file, int line, const char *fmt, ...);

#endif
