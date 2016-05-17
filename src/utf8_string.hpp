#ifndef UTF8_STRING_HPP_INCLUDED
#define UTF8_STRING_HPP_INCLUDED

#include <string>
#include <vector>

#include "utf8_types.hpp"

class UTF8string
{
    std::vector<byte_t> utf8data;
    utf8_len_t utf8length;

    utf8_len_t utf8_length_();

public:

    UTF8string();
    UTF8string(const std::string &str);

    utf8_len_t utf8_size();
    utf8_len_t utf8_length();
    const char * utf8_str();

    ~UTF8string() = default;
};

#endif // UTF_STRING_HPP_INCLUDED
