

/*
*
*	Copyright (C) 2016 Luxon Jean-Pierre
*	gumichan01.olympe.in
*
*
*	Luxon Jean-Pierre (Gumichan01)
*	luxon.jean.pierre@gmail.com
*
*/

#include "utf8_string.hpp"


UTF8string::UTF8string() : utf8length(0){}

UTF8string::UTF8string(const std::string &str)
 : UTF8string()
{
    for(auto c : str)
    {
        utf8data.push_back(c);
    }

    /// @todo Check if the utf-8 string is valid
    utf8length = utf8_length_();
}


utf8_len_t UTF8string::utf8_size()
{
    return utf8data.size();
}


utf8_len_t UTF8string::utf8_length_()
{
    auto end_data = utf8data.end();
    auto it = utf8data.begin();
    utf8_len_t len = 0;

    while(it != end_data)
    {
        byte_t byte = *it;

        if (0xf0 == (0xf8 & *it))
        {
            // 4-byte utf8 character
            // (0b11110xxx 0bxxxxxxxx 0bxxxxxxxx 0bxxxxxxxx)
            it += 4;
        }
        else if (0xe0 == (0xf0 & *it))
        {
            // 3-byte utf8 code point (0b110xxxxx 0bxxxxxxxx 0bxxxxxxxx)
            it += 3;
        }
        else if (0xc0 == (0xe0 & *it))
        {
            // 2-byte utf8 code point (0b110xxxxx 0bxxxxxxxx)
            it += 2;
        }
        else
        {
            // 1-byte utf8 code point (0b0xxxxxxx)
            it += 1;
        }

        // We want the number of characters (utf-8 code point)
        len += 1;
    }

    return len;
}

utf8_len_t UTF8string::utf8_length()
{
    return utf8length;
}

const char * UTF8string::utf8_str()
{
    std::string str;

    for(auto c : utf8data)
    {
        str += c;
    }

    return str.c_str();
}
