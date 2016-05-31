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
 - utf8_at     : get the codepoint at a specified position.
 - utf8_pop    : remove the last codepoint of the string.

## Usage ##

You just need to include all of the ***.hpp*** and ***.cpp*** files from *src/*
in your project. For each file that uses UTF8string, include this piece of code :

    #include "utf8_string.hpp"


## Example ##

    UTF8string u8("がんばつて Gumichan");
    UTF8string sub = utf.utf8_substr(0,5);

    std::cout << "utf8 string: " << u8 << endl;
    std::cout << "utf8 substring: " << sub << endl;
    std::cout << "utf8 substring at 2: " << sub.utf8_at(2) << endl;
    std::cout << "utf8 string at 13: " << sub.utf8_at(13) << endl;

Output :

    utf8 string: がんばつて Gumichan
    utf8 substring: がんばつて
    utf8 substring at 2: ば
    utf8 string at 13: a

## License ##

This library is under the MIT License.
