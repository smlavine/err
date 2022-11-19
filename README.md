[![err :)](logo.jpg)](https://sr.ht/~smlavine/err)

err is a small error-printing library. It can be used by projects
written in any major version of C or C++.

See [the website](https://err.smlavine.com) for API documentation and
examples.

# Using err

- Copy err.c and err.h into your project.
- `#include "err.h"` in files where you want to use err functions.
- Assign a value to `program_invocation_name` before calling any err functions.
- Call functions from err as you see fit!

## Generating documentation

err uses Doxygen to generate documentation. To compile the documentation
into HTML, run `doxygen`. The generated files will be put
into the `site/` directory.

# Copyright

Copyright (C) 2021-2022 Sebastian LaVine <mail@smlavine.com>

Licensed under the MPLv2. See [LICENSE][license].

[license]: https://git.sr.ht/~smlavine/err/tree/master/item/LICENSE
