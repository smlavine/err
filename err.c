/*
 * err - Small error-printing library for C
 * Copyright (C) 2021-2022 Sebastian LaVine <mail@smlavine.com>
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/**
 * @file err.c
 * @version 2.1.0-pre
 * @brief Main source code file
 * @details This file contains definitions and declarations of globally
 * available functions and variables.
 */

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* With glibc and perhaps some other environments, this variable is
 * declared in errno.h. But as it doesn't seem to cause any issues
 * compiling, We declare it again here without a preprocessor guard for
 * maximum portability. */
char *program_invocation_name;

/**
 * This definition is copied from err.h. We don't include err.h in err.c
 * because we don't want err.c to be dependent on err.h being in a
 * particular location.
 */
struct err_configuration {
	const char *(*strerror)(void);
	int (*error_exists)(void);
};

static const char *
err_stdlib_strerror(void)
{
	return strerror(errno);
}

static int
err_stdlib_error_exists(void)
{
	return (errno != 0);
}

static const struct err_configuration stdlib_configuration = {
	&err_stdlib_strerror,
	&err_stdlib_error_exists,
};

/**
 * @details Prints program_invocation_name, ": ", and the
 * printf(3)-like-formatted error message.
 */
void
vwarn(const char *fmt, va_list ap)
{
	fprintf(stderr, "%s: ", program_invocation_name);
	vfprintf(stderr, fmt, ap);
}

/**
 * @details First calls vwarn(), and then if e->error_exists() is true, prints
 * ": ", the message given by e, and a newline.
 */
void
vewarnl(const struct err_configuration *e, const char *fmt, va_list ap)
{
	vwarn(fmt, ap);
	if (e->error_exists()) {
		/* To avoid two colons being printed, like
		 * "program_invocation_name: : No such file or directory" */
		if (fmt != NULL && fmt[0] != '\0') {
			fputs(": ", stderr);
		}
		fprintf(stderr, "%s", e->strerror());
	}
	fputc('\n', stderr);
}

/**
 * @details Calls vwarn(), then prints ": ", strerror(errno), and a newline.
 */
void
vewarn(const char *fmt, va_list ap)
{
	vewarnl(&stdlib_configuration, fmt, ap);
}

/**
 * @details Calls vewarnl() and exits the program with the provided code.
 */
void
verrcl(const struct err_configuration *e, const int code, const char *fmt, va_list ap)
{
	vewarnl(e, fmt, ap);

	exit(code);
}

/**
 * @details Calls vewarn() and exits the program with the provided code.
 */
void
verrc(const int code, const char *fmt, va_list ap)
{
	vewarn(fmt, ap);

	exit(code);
}

/**
 * @details Calls verrcl() with EXIT_FAILURE.
 */
void
verrl(const struct err_configuration *e, const char *fmt, va_list ap)
{
	verrcl(e, EXIT_FAILURE, fmt, ap);
}

/**
 * @details Calls verrc() with EXIT_FAILURE.
 */
void
verr(const char *fmt, va_list ap)
{
	verrc(EXIT_FAILURE, fmt, ap);
}

/**
 * @details Variadic wrapper for vwarn().
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
 * @details Variadic wrapper for vewarnl().
 */
void
ewarnl(const struct err_configuration *e, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vewarnl(e, fmt, ap);
	va_end(ap);
}

/**
 * @details Variadic wrapper for vewarn().
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
 * @details Variadic wrapper for verrcl().
 */
void
errcl(const struct err_configuration *e, const int code, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	verrcl(e, code, fmt, ap);
	va_end(ap);
}

/**
 * @details Variadic wrapper for verrc().
 */
void
errc(const int code, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	verrc(code, fmt, ap);
	va_end(ap);
}

/**
 * @details Variadic wrapper for verrl().
 */
void
errl(const struct err_configuration *e, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	verrl(e, fmt, ap);
	va_end(ap);
}

/**
 * @details Variadic wrapper for verr().
 */
void
err(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	verr(fmt, ap);
	va_end(ap);
}
