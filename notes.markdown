# Make use of C types to prevent bugs and trivial checks

Specifically, declare array indices and limits as `unsigned int` instead of
`int` since indices, by definition, are always nonnegative. This also removes
the need to write trivial checks that a variable is not negative.

## Related reading:

[1]Extra, Extra - Read All About It: Nearly All Binary Searches and Mergesorts are Broken: 2006. https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html?m=1. Accessed: 2017- 08- 02.
[2]Nearly All Binary Searches and Mergesorts Are Broken (2006) | Hacker News: 2017. https://news.ycombinator.com/item?id=14906429. Accessed: 2017- 08- 02.
    - Hacker News discussion of [1]
