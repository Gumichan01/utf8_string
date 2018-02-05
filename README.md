# UTF-8 string #

[![Build Status](https://travis-ci.org/Gumichan01/utf8_string.svg?branch=master)](https://travis-ci.org/Gumichan01/utf8_string)

This is a simple implementation of UTF-8 strings in C++.

## Implementation ##

UTF8string is based on *std::string* provided by the standard C++ library
but has been implemented to support UTF-8 encoded strings.

Some functions have been adapted for utf8 strings :
 - utf8_length : get number of characters in a string (number of codepoints).
 - utf8_size   : get get the memory size of the string (in byte).
 - utf8_find   : find a utf8 substring in the current string.
 - utf8_substr : get a utf8 substring of the current string.
 - utf8_at     : get the codepoint at a specified position.
 - utf8_pop    : remove the last codepoint of the string.

## Usage ##

You just need to include all of the ***.hpp*** and ***.cpp*** files from *src/*
in your project. For each file that uses UTF8string, include this piece of code :

    #include "utf8_string.hpp"

## Code example ##

```cpp
UTF8string u8("がんばつて Gumichan");
UTF8string sub = u8.utf8_substr(0,5);
size_t pos = u8.utf8_find(UTF8string("chan"));
size_t sz  = u8.utf8_size();
size_t l   = u8.utf8_length();

std::cout << "u8 string: " << u8 << "\n";
std::cout << "utf8 substring from 0 to 5: " << sub << "\n";
std::cout << "utf8 codepoint at 2: " << u8.utf8_at(2) << "\n";
std::cout << "utf8 string \"chan\" at " << pos << "\n";
std::cout << "u8 string - memory size: " << sz << "; length: " << l << "\n\n";

for (auto s: sub)    // or for (const std::string& s: u8)
{
    std::cout << "-> " << s << "\n";
}

```

Output :

```
utf8 string: がんばつて Gumichan
utf8 substring from 0 to 5: がんばつて
utf8 codepoint at 2: ば
utf8 string "chan" at 10
u8 string - memory size: 24; length: 14

-> が
-> ん
-> ば
-> つ
-> て

```

## License ##

This library is under the MIT License.
