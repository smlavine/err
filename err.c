/*
 * err - Small error-printing library
 * Copyright (C) 2021 Sebastian LaVine <mail@smlavine.com>
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"

char *argv0;

/***********************************************************************
 * This file contains six error and warning functions:
 * vwarn(), vewarn(), and verr(), plus variadic wrappers for each.
 *
 ***********************************************************************
 * vwarn() prints argv0, ": ", and a message formatted from the given
 * format string and va_list.
 *
 * warn() is a variadic wrapper for vwarn().
 *
 ***********************************************************************
 * vewarn() calls vwarn(), then prints ": " if the format string is
 * neither NULL nor empty, then prints the value of strerror(errno) and
 * a newline.
 *
 * ewarn() is a variadic wrapper for vewarn().
 *
 ***********************************************************************
 * verr() calls vewarn() and exits the program with the provided code.
 *
 * err() is a variadic wrapper for verr().
 *
 ***********************************************************************
 * If argv0 is not set by the caller, behavior is undefined.
 *
 * These functions print exclusively to stderr.
 *
 * Some functions in this file are named the same as functions
 * provided by libbsd's err.h. This file does NOT implement those
 * functions, and might behave completely differently.
 *
 ***********************************************************************
 */

void
vwarn(const char *fmt, va_list ap)
{
	fprintf(stderr, "%s: ", argv0);
	vfprintf(stderr, fmt, ap);
}

void
vewarn(const char *fmt, va_list ap)
{
	vwarn(fmt, ap);
	if (errno != 0) {
		/* To avoid two colons being printed, like
		 * "argv0: : No such file or directory" */
		if (fmt != NULL && fmt[0] != '\0') {
			fputs(": ", stderr);
		}
		fprintf(stderr, "%s", strerror(errno));
	}
	fputc('\n', stderr);
}

void
verr(const int code, const char *fmt, va_list ap)
{
	vewarn(fmt, ap);

	exit(code);
}

void
warn(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vwarn(fmt, ap);
	va_end(ap);
}

void
ewarn(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vewarn(fmt, ap);
	va_end(ap);
}

void
err(const int code, const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	verr(code, fmt, ap);
	va_end(ap);
}
