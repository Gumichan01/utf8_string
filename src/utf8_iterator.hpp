/*
*
*   Copyright (C) 2016 Luxon Jean-Pierre
*   gumichan01.olympe.in
*
*   This library is under the MIT license
*
*   Luxon Jean-Pierre (Gumichan01)
*   luxon.jean.pierre@gmail.com
*
*/

#ifndef UTF8_ITERATOR_HPP_INCLUDED
#define UTF8_ITERATOR_HPP_INCLUDED

/**
*   @file utf8_iterator.hpp
*   @brief This is a UTF-8 string library header
*/

class UTF8string;


/**
*   @class UTF8iterator
*   @brief Iterator on UTF8 string
*
*   This class defines the iterator of UTF-8 string
*/
class UTF8iterator
{
    size_t index;
    UTF8string data;

    char& operator ->();

public:

    /**
    *   @fn explicit UTF8iterator(const UTF8string& u)
    *   Build an iterator object using a UTF8string object
    *   @param u utf-8 string
    */
    explicit UTF8iterator(const UTF8string& u);

    /**
    *   @fn UTF8iterator(const UTF8iterator& it)
    *   @param it The iterator to copy
    */
    UTF8iterator(const UTF8iterator& it);

    /**
    *   @fn UTF8iterator& operator ++()
    *   Prefix incrementation
    *   @return The same iterator, but it has moved forward
    */
    UTF8iterator& operator ++();

    /**
    *   @fn UTF8iterator& operator ++(int)
    *
    *   Postfix incrementation
    *
    *   @param int dummy parameter
    *   @return The same iterator before it has moved forward
    */
    UTF8iterator operator ++(int);

    /**
    *   @fn UTF8iterator& operator --()
    *   Prefix derementation
    *   @return The same iterator, but it has moved backward
    */
    UTF8iterator& operator --();

    /**
    *   @fn UTF8iterator operator --(int)
    *
    *   Postfix decrementation
    *
    *   @param int dummy parameter
    *   @return The same iterator before it has moved backward
    */
    UTF8iterator operator --(int);

    /**
    *   @fn UTF8iterator& operator =(const UTF8iterator& it)
    *   Asignement
    *   @param it The iterator that wille be assigned
    *   @return The same iterator as the argument
    */
    UTF8iterator& operator =(const UTF8iterator& it);

    /**
    *   @fn bool operator ==(const UTF8iterator& it) const
    *
    *   Check if the current iterators it pointing to the same position as
    *   the iterator given in argument equals.
    *
    *   @param it The iterator to compare with
    *   @return TRUE if they are pointing to the same position, FALSE otherwise
    */
    bool operator ==(const UTF8iterator& it) const;

    /**
    *   @fn bool operator !=(const UTF8iterator& it) const
    *
    *   Check if the current iterators it pointing to a different position
    *   from the iterator given in argument equals.
    *
    *   @param it The iterator to compare with
    *   @return TRUE if they are not pointing to the same position,
    *           FALSE otherwise
    */
    bool operator !=(const UTF8iterator& it) const;

    /**
    *   @fn UTF8iterator operator +(const size_t n) const
    *
    *   Returns an iterator witch has been moved 10 positions forward
    *
    *   @param n the number of step to move forward
    *   @return The same iterator that moved forward
    */
    UTF8iterator operator +(const size_t n) const;

    /**
    *   @fn UTF8iterator operator -(const size_t n) const
    *
    *   Returns an iterator witch has been moved 10 positions backward
    *
    *   @param n the number of steps to move backward
    *   @return The same iterator that moved backward
    */
    UTF8iterator operator -(const size_t n) const;

    /**
    *   @fn const std::string operator *() const
    *
    *   Dereferences the pointer returning the codepoint
    *   pointed by the iterator at its current potision
    *
    *   @return The same iterator that moved backward
    *   @note This function will throw an *std::out_of_range* exception
    *         if the iterator does not point to a codepoint
    */
    const std::string operator *() const;

    ~UTF8iterator();
};

#endif // UTF8_ITERATOR_HPP_INCLUDED
