
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


UTF8iterator::UTF8iterator(UTF8string& u) : data(u) {}


UTF8iterator::UTF8iterator(const UTF8iterator& it)
{
    data = it.data;
}


UTF8iterator::~UTF8iterator(){}


UTF8iterator& UTF8iterator::operator =(const UTF8iterator& it)
{
    data = it.data;
    return *this;
}


UTF8iterator& UTF8iterator::operator ++()
{
    return *this;
}


UTF8iterator& UTF8iterator::operator ++(int)
{
    return *this;
}


bool UTF8iterator::operator ==(const UTF8iterator& it) const
{
    return true;
}


bool UTF8iterator::operator !=(const UTF8iterator& it) const
{
    return true;
}


const char& UTF8iterator::operator *() const
{
    return '\0';
}
