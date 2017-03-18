# sortcery

[![Build Status](https://travis-ci.org/skytreader/sortcery.svg?branch=master)](https://travis-ci.org/skytreader/sortcery)
[![Coverage Status](https://coveralls.io/repos/github/skytreader/sortcery/badge.svg?branch=master)](https://coveralls.io/github/skytreader/sortcery?branch=master)

For the purposes of this exercise, sorting is always in ascending order.

# Set-up

Install [Criterion](https://github.com/Snaipe/Criterion).

    sudo add-apt-repository ppa:snaipewastaken/ppa
    sudo apt-get update
    sudo apt-get install criterion-dev

# Compilation

There are a couple of flags you can pass to `make` when compiling/building.

- `TEST` will compile with flags that allow test coverage reports.
- `DEBUG` will compile with flags that allow for debugging with tools like
`gdb`.

All these flags are optional. You may not want to use them if you are profiling
for, say, performance.

Note that if you modify some source files after a build and then make with a
different flag, it is not guaranteed that your whole binary follows the flag of
your most recent compilation. To prevent this, invoke make with the always build
flag.

    make -B [...flags...] [target]
