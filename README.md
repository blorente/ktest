# ktest
A very simple testing framework for plain C/C++

It was designed to circle the constraints of another open-source project: [ScummVM](http://scummvm.org)

## Usage
To use, certain things have to happen:
- Place the files of the include folder inside your project's include folder.
- Create an implementation file to contain all the tests (see `src/examples.cpp`).
	- Note that this file must implement the print method, which will usually will be a call to printf. This is done because the project that this was designed for ([ScummVM](http://scummvm.org)) implements it's own version of printf.
- Write your tests in the implementation file.
- Call KWorks::Tests::runTests(); from your code to run the tests.

## Just because I love Asciinema:
[![asciicast](https://asciinema.org/a/7o2y872n5fsli6qnrf5y50cyo.png)](https://asciinema.org/a/7o2y872n5fsli6qnrf5y50cyo)

