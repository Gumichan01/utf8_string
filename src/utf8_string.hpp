#ifndef UTF8_STRING_HPP_INCLUDED
#define UTF8_STRING_HPP_INCLUDED

#include <string>
#include <vector>

#include "utf8_types.hpp"

class utf_string
{
    std::vector<byte_t> utf8_data;
    utf8_len_t utf8_length;

public:

    utf8_string();
    utf8_string(const char *str);
    utf8_string(const string &str);

    utf8_len_t utf8_size();
    utf8_len_t utf8_length();
    const char * utf8_str();

    ~utf_string() = default;
};

#endif // UTF_STRING_HPP_INCLUDED
