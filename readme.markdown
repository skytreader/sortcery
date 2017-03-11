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

There are two compilation "modes": test and, uh, nontest. Test mode compiles
with profiling flags that allow for coverage reporting. However, this adds code
to the binaries which you may not want if you are, say, profiling performance.

To build in test mode just pass a `TEST=y` flag. That is,

    make TEST=y [target]

Ommitting the flag will create a binary that is only the code in this
repository.

Note that if you modify some source files after a build and then make with a
different flag, it is not guaranteed that your whole binary follows the flag of
your most recent compilation. To prevent this, invoke make with the always build
flag.

    make -B [TEST=y] [target]
