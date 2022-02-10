# webCHIP
A work-in-progress, cross-platform port of my original C++ CHIP-8 emulator/interpreter [Chipulator](https://github.com/TomRCummings/Chipulator). Targeted at WASM via Emscripten, using a bit of SDL2. Compiles, but does not run.

## CHIP-8
[CHIP-8](https://en.wikipedia.org/wiki/CHIP-8) is an interpreted programming language developed in the 70s. Originally meant for the
home-built microcomputers of the time, CHIP-8 also found a life on graphing calculators in the 90s and was expanded with Chip-48 (also called Super-Chip or SCHIP).
Today, CHIP-8 is generally a person's first foray into emulation. A quick search on GitHub will turn up 20 or more different flavors of CHIP-8 emulators/interpreters,
from the fabulous [Octo](https://github.com/JohnEarnest/Octo) to my own Chipulator.  
  
CHIP-8 makes use of 36 instructions to do everything it needs to do and can access up to 4KB of RAM, 16 8-bit registers and 1 16-bit register. The keyboard was hexadecimal,
the display was 64x32 pixels and monochromatic, and the speaker only produces one note. All you need to a good game of Pong! 

You can learn a lot more about CHIP-8 at [Cowgod's Technical Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#memmap).

## ROMs
A huge amount of games, demos, and fun programs exist for the CHIP-8 after all the decades it has been around. You'll find a handful of very simple, widely shared
examples in the "roms" folder in the repository and in the release. You can find loads more online, so be sure to explore! Keep in mind that many of the games you'll find are buggy,
but it you do encounter a problem, don't hesitate to report an issue here.

## Reporting bugs
Please report any bugs you may encounter in the [Issues](https://github.com/TomRCummings/webCHIP/issues) page of the project. If you don't have a Github account, feel free to email
your issue to me at cummings dot t287 at gmail dot com. When you report the bug, please include details about your system, what ROM was running at the time, and copy in the text of log.log from
the directory the executable is in. Thank you in advance for helping to make the project better!

## Author
Thomas Cummings  
Contact me: cummings dot t287 at gmail dot com

## MIT License
MIT License

Copyright (c) 2021 Thomas Cummings

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
