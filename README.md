# err - Small error-printing library for C

err is a small error-printing library for C programs. It was initially
written as part of [navipage](https://sr.ht/~smlavine/navipage). For
examples of its use, see that project.

err can be used in projects written in any major version of C or C++.

These functions print exclusively to stderr.

The BSDes provide similar functionality in their standard library with a
[file of the same name][freebsd-err.h]. This library does *not*
implement that interface, and might behave completely differently.

[freebsd-err.h]: https://www.freebsd.org/cgi/man.cgi?query=err

# Using err

- Copy err.c and err.h into your project.
- ```#include "err.h"``` in files where you want to use err functions.
- Assign a value to ```argv0``` before calling any err functions, or
  suffer the wrath of undefined behavior.
- Call functions from err as you see fit!

# Functions provided by err

- __vwarn(char *, va_list)__ prints argv0, ": ", and a message
  formatted from the given format string and va_list.
  - __warn(char *, ...)__ is a variadic wrapper for vwarn().
- __vewarn(char *, va_list)__ calls vwarn(), then prints ": " if
  the format string is neither NULL nor empty, then prints the value of
  strerror(errno) and a newline.
  - __ewarn(char *, ...)__ is a variadic wrapper for vewarn().
- __verr(int, char *, va_list)__ calls vewarn() and exits the program
  with the provided code.
  - __err(int, char *, ...)__ is a variadic wrapper for verr().

See the comments in err.c for much the same information.

# Copyright

Copyright (C) 2021 Sebastian LaVine <mail@smlavine.com>

err is published and made available under the terms of version 2.0 of
the Mozilla Public License. A copy of the MPL-2.0 is distributed with
err; alternatively you can obtain one at <http://mozilla.org/MPL/2.0/>.

---

This project is hosted at <https://sr.ht/~smlavine/err>.

To browse the source code repository, see
<https://git.sr.ht/~smlavine/err>.

For patches and discussion related to the project, see the mailing list
at <https://lists.sr.ht/~smlavine/public-inbox>. If you've used err in
your own project, I'd love to hear about it!

For announcements related to the project, see the mailing list at
<https://lists.sr.ht/~smlavine/err-announce>.
