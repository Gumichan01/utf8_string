
/*
*
*	Copyright (C) 2016 Luxon Jean-Pierre
*	gumichan01.olympe.in
*
*   This library is under the MIT license
*
*	Luxon Jean-Pierre (Gumichan01)
*	luxon.jean.pierre@gmail.com
*
*/

#ifndef UTF8_STRING_HPP_INCLUDED
#define UTF8_STRING_HPP_INCLUDED

#include <string>
#include <iostream>

class UTF8iterator;

class UTF8string
{
    std::string utf8data;
    size_t utf8length;

    bool utf8_is_valid_() const;
    size_t utf8_length_() const;
    size_t utf8_codepoint_len_(size_t j) const;
    size_t utf8_bpos_at_(const size_t cpos) const;
    UTF8iterator utf8_iterator_() const noexcept;
    UTF8string utf8_reverse_aux_(UTF8iterator& it,
                                 const UTF8iterator& end, UTF8string& res);

public:

    const static size_t npos = std::string::npos;

    UTF8string();
    UTF8string(const std::string &str);
    UTF8string(const UTF8string &u8str);

    const UTF8string& operator =(const char * str);
    const UTF8string& operator =(const std::string &str);
    const UTF8string& operator =(const UTF8string &u8str);
    const UTF8string& operator +=(const UTF8string &u8str);
    const UTF8string& operator +=(const std::string &str);
    const UTF8string& operator +=(const char * str);

    void utf8_clear();
    bool utf8_empty() const;
    std::string utf8_at(const size_t index) const;
    void utf8_pop();

    UTF8string utf8_substr(size_t pos = 0, size_t len = npos);
    size_t utf8_find(const UTF8string& str, size_t pos = 0);
    UTF8string& utf8_reverse();

    size_t utf8_size() const;
    size_t utf8_length() const;
    const char * utf8_str() const;

    UTF8iterator utf8_begin() const noexcept;
    UTF8iterator utf8_end() const noexcept;

    ~UTF8string() = default;
};

bool operator ==(const UTF8string &str1, const UTF8string &str2);
bool operator !=(const UTF8string &str1, const UTF8string &str2);
bool operator <=(const UTF8string &str1, const UTF8string &str2);
bool operator >=(const UTF8string &str1, const UTF8string &str2);
bool operator <(const UTF8string &str1, const UTF8string &str2);
bool operator >(const UTF8string &str1, const UTF8string &str2);

UTF8string operator +(const UTF8string &str1, const UTF8string &str2);
UTF8string operator +(const UTF8string &str1, const std::string &str2);
UTF8string operator +(const std::string &str1, const UTF8string &str2);
UTF8string operator +(const UTF8string &str1, const char * str2);
UTF8string operator +(const char * str1, const UTF8string &str2);

std::ostream & operator <<(std::ostream &os, const UTF8string &str);
std::istream & operator >>(std::istream &is, UTF8string &str);

#include "utf8_iterator.hpp"

#endif // UTF8_STRING_HPP_INCLUDED
