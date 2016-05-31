
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

#ifndef UTF8_ITERATOR_HPP_INCLUDED
#define UTF8_ITERATOR_HPP_INCLUDED

// Iterator on UTF8string
class UTF8iterator
{
    size_t index;
    UTF8string data;

    char& operator ->();

public:

    UTF8iterator(const UTF8string& u);
    UTF8iterator(const UTF8iterator& it);

    UTF8iterator& operator ++();
    UTF8iterator operator ++(int);
    UTF8iterator& operator --();
    UTF8iterator operator --(int);
    UTF8iterator& operator =(const UTF8iterator& it);

    bool operator ==(const UTF8iterator& it) const;
    bool operator !=(const UTF8iterator& it) const;
    UTF8iterator operator +(const size_t n) const;
    UTF8iterator operator -(const size_t n) const;

    const std::string operator *() const;

    ~UTF8iterator();
};

#endif // UTF8_ITERATOR_HPP_INCLUDED
