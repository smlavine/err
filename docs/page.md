This is the online documentation for err, a small error-printing
library.

For more on how to use err, see the project page [here][sr.ht].

## Using err in your project

The easiest way to use err is to copy err.c and err.h into your project.
You can download the latest version of err from

- <https://git.sr.ht/~smlavine/err/blob/2.0.0/err.c>
- <https://git.sr.ht/~smlavine/err/blob/2.0.0/err.h>

Alternatively, you may wish to import err as a git subtree:

```
git subtree --squash -P err/ add https://git.sr.ht/~smlavine/err 2.0.0
```

`#include "err.h"` in files where you want to use err functions.

Be sure to assign a value to `program_invocation_name` before calling
any err functions.

[sr.ht]: https://sr.ht/~smlavine/err
