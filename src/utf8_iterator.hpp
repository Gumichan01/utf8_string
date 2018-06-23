/*
*
*   Copyright © 2018 Luxon Jean-Pierre
*   https://gumichan01.github.io/
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
*   @class UTF8iterator final
*   @brief Iterator on UTF8 string
*
*   This class defines the iterator of UTF-8 string
*/
class UTF8iterator final
{
    size_t _index = 0;
    UTF8string _data;

    char& operator ->() = delete;

public:

    UTF8iterator() = delete;

    /**
    *   @fn explicit UTF8iterator(const UTF8string& u) noexcept
    *   Build an iterator object using a UTF8string object
    *   @param u utf-8 string
    */
    explicit UTF8iterator( const UTF8string& u ) noexcept;

    /**
    *   @fn UTF8iterator(const UTF8iterator& it) noexcept
    *   @param it The iterator to copy
    */
    UTF8iterator( const UTF8iterator& it ) noexcept;

    /**
    *   @fn UTF8iterator& operator ++() noexcept
    *   Prefix incrementation
    *   @return The same iterator, but it has moved forward
    */
    UTF8iterator& operator ++() noexcept;

    /**
    *   @fn UTF8iterator& operator ++(int) noexcept
    *
    *   Postfix incrementation
    *
    *   @return The same iterator before it has moved forward
    */
    UTF8iterator operator ++( int ) noexcept;

    /**
    *   @fn UTF8iterator& operator --() noexcept
    *   Prefix derementation
    *   @return The same iterator, but it has moved backward
    */
    UTF8iterator& operator --() noexcept;

    /**
    *   @fn UTF8iterator operator --(int) noexcept
    *
    *   Postfix decrementation
    *
    *   @return The same iterator before it has moved backward
    */
    UTF8iterator operator --( int ) noexcept;

    /**
    *   @fn UTF8iterator& operator =(const UTF8iterator& it) noexcept
    *   Asignement
    *   @param it The iterator that wille be assigned
    *   @return The same iterator as the argument
    */
    UTF8iterator& operator =( const UTF8iterator& it ) noexcept;

    /**
    *   @fn bool operator ==(const UTF8iterator& it) const noexcept
    *
    *   Check if the current iterator is pointing to the same position as
    *   the iterator given in argument equals.
    *
    *   @param it The iterator to compare with
    *   @return TRUE if they are pointing to the same position, FALSE otherwise
    */
    bool operator ==( const UTF8iterator& it ) const noexcept;
    /**
    *   @fn bool operator !=(const UTF8iterator& it) const noexcept
    *
    *   Check if the current iterator is pointing to a different position
    *   from the iterator given in argument equals.
    *
    *   @param it The iterator to compare with
    *   @return TRUE if they are not pointing to the same position,
    *           FALSE otherwise
    */
    bool operator !=( const UTF8iterator& it ) const noexcept;
    /**
    *   @fn bool operator <(const UTF8iterator& it) const noexcept
    *   @param it The iterator to compare with
    *   @return TRUE if the position of it is greater than *this, FALSE otherwise
    */
    bool operator <( const UTF8iterator& it ) const noexcept;
    /**
    *   @fn bool operator >(const UTF8iterator& it) const noexcept
    *   @param it The iterator to compare with
    *   @return TRUE if the position of it is less than *this, FALSE otherwise
    */
    bool operator >( const UTF8iterator& it ) const noexcept;
    /**
    *   @fn bool operator <=(const UTF8iterator& it) const noexcept
    *   @param it The iterator to compare with
    *   @return TRUE if the position of it is greater than or equal *this, FALSE otherwise
    */
    bool operator <=( const UTF8iterator& it ) const noexcept;
    /**
    *   @fn bool operator >=(const UTF8iterator& it) const noexcept
    *   @param it The iterator to compare with
    *   @return TRUE if the position of it is less than or equal to *this, FALSE otherwise
    */
    bool operator >=( const UTF8iterator& it ) const noexcept;

    /**
    *   @fn UTF8iterator operator +(const size_t n) const noexcept
    *
    *   Returns an iterator which has been moved n positions forward
    *
    *   @param n the number of step to move forward
    *   @return The same iterator that moved forward
    */
    UTF8iterator operator +( const size_t n ) const noexcept;
    /**
    *   @fn UTF8iterator operator -(const size_t n) const noexcept
    *
    *   Returns an iterator which has been moved n positions backward
    *
    *   @param n the number of steps to move backward
    *   @return The same iterator that moved backward
    */
    UTF8iterator operator -( const size_t n ) const noexcept;
    /**
    *   @fn long operator -(const UTF8iterator& it) const
    *
    *   Return the difference value between *this and it
    *
    *   @param it
    *   @return A long value *n* such that it + n = *this
    *   @pre *this and it points to the same data
    *   @post *this == it + (*this - it)
    *   @exception std::invalid_argument if the pre-condition is not satisfied
    */
    long operator -( const UTF8iterator& it ) const;

    /**
    *   @fn const UTF8string::u8char operator *() const
    *
    *   Dereferences the pointer returning the codepoint
    *   pointed by the iterator at its current potision
    *
    *   @return The codepoint
    *   @note This function will throw an *std::out_of_range* exception
    *         if the iterator does not point to a codepoint
    */
    const UTF8string::u8char operator *() const;

    ~UTF8iterator() = default;
};

#endif // UTF8_ITERATOR_HPP_INCLUDED
