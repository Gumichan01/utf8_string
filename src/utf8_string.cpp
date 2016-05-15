

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


utf8_string::utf8_string() : utf8_str_length(0){}

utf8_string::utf8_string(const std::string &str)
 : utf8_string()
{
    for(auto c : str)
    {
        utf8_data.push_back(c);
    }
}

