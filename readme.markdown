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

- `TEST=y` will compile with flags that allow test coverage reports.
- `DEBUG=y` will compile with flags that allow for debugging with tools like
`gdb`.

All these flags are optional. You may not want to use them if you are profiling
for, say, performance.

Note that if you modify some source files after a build and then make with a
different flag, it is not guaranteed that your whole binary follows the flag of
your most recent compilation. To prevent this, invoke make with the always build
flag.

    make -B [...flags...] [target]

# Quick Criterion reference

This uses [Criterion](https://github.com/Snaipe/Criterion) for unit testing. The
[docs](http://criterion.readthedocs.io/en/master/#) discuss the full range of
Criterion's features but some common commands are found below.

## Running a single test

Assuming you have the following test:

    Test(suite_name, test_name){}

built into a binary named `test`. To execute only this test, do `test --filter
suite_name/test_name`. Shell wildcard patterns can also be used.

## Debugging

Assuming the binary is made with the `DEBUG` flag, run the binary with the
`--debug` option. This will start a debugging server. Then, in another terminal,
connect to the server via `gdb -q ./testbinary`.

In the resulting gdb session, target the server via `target remote
localhost:1234`. You have to do this for _every_ test the binary is set to run.
After doing this, you may issue debugging commands (`c` to start actual
execution).
