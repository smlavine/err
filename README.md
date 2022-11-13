# [err](https://sr.ht/~smlavine/err)

err is a small error-printing library. It can be used by projects
written in any major version of C or C++.

The BSDs provide similar functionality in their standard library with a
[file of the same name][freebsd-err.h]. This library does *not*
implement that interface, and might behave completely differently.

[freebsd-err.h]: https://www.freebsd.org/cgi/man.cgi?query=err

# Using err

**Online documentation can be found here**: <https://err.smlavine.com>

- Copy err.c and err.h into your project.
- `#include "err.h"` in files where you want to use err functions.
- Assign a value to `program_invocation_name` before calling any err functions.
- Call functions from err as you see fit!

See the [examples/][examples] directory for example programs.

[examples]: https://git.sr.ht/~smlavine/err/tree/master/item/examples/

## Generating documentation

err uses Doxygen to generate documentation. To compile the documentation
into a readable form, run `doxygen`. The generated files will be put
into the `docs/` directory.

Documentation is compiled to HTML and manpage formats.

# Copyright

Copyright (C) 2021-2022 Sebastian LaVine <mail@smlavine.com>

Licensed under the MPLv2. See [LICENSE][license].

[license]: https://git.sr.ht/~smlavine/err/tree/master/item/LICENSE
