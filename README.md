## Meeus

This is a C-library of astronomical algorithms, as described in Jean Meeus'
[Astronomical Algorithms][aa] (ISBN: 0943396611). In particular, the code and
examples in this repository are adapted from the 1st edition of the book,
published in 1998 by Willmann-Bell, Inc., Virginia, USA.

#### Tests

[CMocka][cmocka] is used to unit test this code. It can be installed on Mac OS X
via [Homebrew][brew]:
```bash
brew install cmocka
```

The test suite can be compiled and run via `make`:
```bash
make tests
```

#### License

This repository is licensed under the terms and conditions of the
[MIT License][mit_license]. Please see the `LICENSE.txt` file for more details.

[aa]: http://www.willbell.com/math/mc1.htm
[brew]: http://brew.sh/
[cmocka]: https://cmocka.org/
[mit_license]: http://opensource.org/licenses/mit-license.php
