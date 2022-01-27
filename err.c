/*
 * err - Small error-printing library for C
 * Copyright (C) 2021 Sebastian LaVine <mail@smlavine.com>
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/**
 * @file err.c
 * @brief Small error-printing library for C
 */

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"

char *argv0;

/**
 * @brief Prints a formatted warning message to stderr.
 * @details Prints argv0, ": ", and the printf(3)-like-formatted error message.
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void
vwarn(const char *fmt, va_list ap)
{
	fprintf(stderr, "%s: ", argv0);
	vfprintf(stderr, fmt, ap);
}

/**
 * @brief Prints a formatted error message to stderr.
 * @details Calls vwarn(), then prints ": ", strerror(errno), and a newline.
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
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

/**
 * @brief Prints a formatted error message to stderr and exits.
 * @details Calls vewarn() and exits the program with the provided code.
 * @param code exit code
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void
verr(const int code, const char *fmt, va_list ap)
{
	vewarn(fmt, ap);

	exit(code);
}

/**
 * @brief Prints a formatted warning message to stderr.
 * @details Variadic wrapper for vwarn().
 * @param fmt format string
 * @param ... arguments for the format string
 */
void
warn(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vwarn(fmt, ap);
	va_end(ap);
}

/**
 * @brief Prints a formatted error message to stderr.
 * @details Variadic wrapper for vewarn().
 * @param fmt format string
 * @param ... arguments for the format string
 */
void
ewarn(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vewarn(fmt, ap);
	va_end(ap);
}

/**
 * @brief Prints a formatted error message to stderr and exits.
 * @details Variadic wrapper for verr().
 * @param code exit code
 * @param fmt format string
 * @param ... arguments for the format string
 */
void
err(const int code, const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	verr(code, fmt, ap);
	va_end(ap);
}
