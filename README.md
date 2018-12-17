# aoc14
Advent of Code day 14, generate the data once at compile time, is it faster? Who knows...

There is a very cool, very clever optimised solution for this problem at https://gist.github.com/Voltara/5069980afbf6cf0762fcbb09948e5649 I don't understand AVX and my Ubuntu machine doesn't support it. So I looked around the edge.

This stretches the compiler and that machine to its limit, and a table length of more than 24 000 000 runs it out of virtual memory. About 15 minutes to compile. So completely absurd for something that only needs to run once and takes less than a second at run time. It would neat to compress the data, even into nibbles, during generation and work with that. Could probably go further and faster.
