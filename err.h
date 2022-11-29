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
 * @file err.h
 * @version 2.1.0-pre
 * @brief Header file
 * @details #include this to use err in your project.
 */

#ifndef ERR_ERR_H
#define ERR_ERR_H

#include <stdarg.h>

/**
 * @brief Global value for the program's name.
 * @details This must be set before any err functions are called.
 */
extern char *program_invocation_name;

/**
 * @brief Interface for using custom error messages with err.
 * @details See vewarnl().
 */
struct err_configuration {
	const char *(*strerror)(void);
	int (*error_exists)(void);
};

/**
 * @brief Prints a formatted warning message to stderr.
 * @pre program_invocation_name is set
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void vwarn(const char *, va_list);

/**
 * @brief Prints a formatted error message to stderr. Uses a custom
 * err_configuration.
 * @pre program_invocation_name is set
 * @param e configuration specifying source of error message
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void vewarnl(const struct err_configuration *, const char *, va_list);

/**
 * @brief Prints a formatted error message to stderr.
 * @pre program_invocation_name is set
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void vewarn(const char *, va_list);

/**
 * @brief Prints a formatted error message to stderr and exits with the given
 * exit code. Uses a custom err_configuration.
 * @pre program_invocation_name is set
 * @param e configuration specifying source of error message
 * @param code exit code
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void verrcl(const struct err_configuration *, const int, const char *, va_list);

/**
 * @brief Prints a formatted error message to stderr and exits with the given
 * exit code.
 * @pre program_invocation_name is set
 * @param code exit code
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void verrc(const int, const char *, va_list);

/**
 * @brief Prints a formatted error message to stderr and exits. Uses a custom
 * err_configuration.
 * @pre program_invocation_name is set
 * @param e configuration specifying source of error message
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void verrl(const struct err_configuration *, const char *, va_list);

/**
 * @brief Prints a formatted error message to stderr and exits.
 * @pre program_invocation_name is set
 * @param fmt format string
 * @param ap va_list of arguments for the format string
 */
void verr(const char *, va_list);

/**
 * @brief Prints a formatted warning message to stderr.
 * @pre program_invocation_name is set
 * @param fmt format string
 * @param ... arguments for the format string
 */
void warn(const char *, ...);

/**
 * @brief Prints a formatted error message to stderr. Uses a custom
 * err_configuration.
 * @pre program_invocation_name is set
 * @param e configuration specifying source of error message
 * @param fmt format string
 * @param ... arguments for the format string
 */
void ewarnl(const struct err_configuration *, const char *, ...);

/**
 * @brief Prints a formatted error message to stderr.
 * @pre program_invocation_name is set
 * @param fmt format string
 * @param ... arguments for the format string
 */
void ewarn(const char *, ...);

/**
 * @brief Prints a formatted error message to stderr and exits with the given
 * exit code. Uses a custom err_configuration.
 * @pre program_invocation_name is set
 * @param code exit code
 * @param e configuration specifying source of error message
 * @param fmt format string
 * @param ... arguments for the format string
 */
void errcl(const struct err_configuration *, const int, const char *, ...);

/**
 * @brief Prints a formatted error message to stderr and exits with the given
 * exit code.
 * @pre program_invocation_name is set
 * @param code exit code
 * @param fmt format string
 * @param ... arguments for the format string
 */
void errc(const int, const char *, ...);

/**
 * @brief Prints a formatted error message to stderr and exits. Uses a custom
 * err_configuration.
 * @pre program_invocation_name is set
 * @param e configuration specifying source of error message
 * @param fmt format string
 * @param ... arguments for the format string
 */
void errl(const struct err_configuration *, const char *, ...);

/**
 * @brief Prints a formatted error message to stderr and exits.
 * @pre program_invocation_name is set
 * @param fmt format string
 * @param ... arguments for the format string
 */
void err(const char *, ...);

#endif
