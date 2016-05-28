# UTF-8 string #

[![Build Status](https://travis-ci.org/Gumichan01/utf8_string.svg?branch=master)](https://travis-ci.org/Gumichan01/utf8_string)

This is a simple implementation of UTF-8 strings in C++.

## Implementation ##

UTF8string is based on *std::string* provided by the standard C++ library
but has been implemented to support UTF-8 encoded strings.

Some functions have been adapted for utf8 strings :
 - utf8_length : get number of characters in a string (number of codepoints).
 - utf8_find   : find a utf8 substring in the current string.
 - utf8_substr : get a utf8 substring of the current string.


## Usage ##

You just need to include *utf8_string.hpp* and *utf8_string.cpp* in your project.


## License ##

This library is under the MIT License.
