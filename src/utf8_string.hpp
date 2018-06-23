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

#ifndef UTF8_STRING_HPP_INCLUDED
#define UTF8_STRING_HPP_INCLUDED


/**
*   @file utf8_string.hpp
*   @brief This is a UTF-8 string library header
*/

#include <string>
#include <iostream>

class UTF8iterator;

/**
*   @class UTF8string final
*   @brief UTF-8 string class
*
*   This class defines a UTF-8 string
*/
class UTF8string final
{
    using byte_t = unsigned char;
    using u8string = std::string;

    u8string _utf8string = {};
    size_t _utf8length = 0U;

    bool utf8_is_valid_() const noexcept;
    size_t utf8_length_() const noexcept;
    size_t utf8_codepoint_len_( const size_t j ) const noexcept;
    size_t utf8_bpos_at_( const size_t cpos ) const noexcept;
    u8string utf8_at_( const size_t index ) const noexcept;

    UTF8iterator utf8_iterator_() const noexcept;
    UTF8string utf8_reverse_aux_( UTF8iterator& it,
                                  const UTF8iterator& _end, UTF8string& res );

public:

    /**
    *   @typedef u8char
    *   @brief The UTF-8 character
    */
    using u8char = std::string;

    /**
    *   @var npos
    *
    *   *npos* is a static member constant value with the greatest
    *   possible value for an element of type *size_t*.
    *
    *   This value, when used as the value for a len parameter in some
    *   UTF-8 string's member functions(utf8_substr()),
    *   means "until the end of the utf-8 string".
    *
    *   As a return value in utf8_find(), it is used to indicate no matches.
    *   This constant is defined with a value of -1,
    *   which because *size_t* is an unsigned integral type,
    *   it is the largest possible representable value for this type.
    *
    */
    constexpr static size_t npos = static_cast<const size_t>( -1 );

    /**
    *   @fn UTF8string() = default
    */
    UTF8string() = default;
    /**
    *   @fn UTF8string(const char * str)
    *   @param str
    *   @pre str is not null
    *   @exception std::invalid_argument If the string is not valid
    */
    UTF8string( const char * str );
    /**
    *   @fn UTF8string(const std::string& str)
    *   @param str
    *   @exception std::invalid_argument If the string is not valid
    */
    UTF8string( const std::string& str );
    /**
    *   @fn UTF8string(const UTF8string& u8str) noexcept
    *   @param u8str
    */
    UTF8string( const UTF8string& u8str ) noexcept;
    /**
    *   @fn UTF8string(const UTF8string& u8str, size_t pos, size_t len = npos) noexcept
    *   @param u8str
    *   @param pos The beginning position of the substring
    *   @param len The length of the substring (in number of codepoints, default value = npos)
    */
    UTF8string( const UTF8string& u8str, size_t pos, size_t len = npos ) noexcept;
    /**
    *   @fn UTF8string(UTF8string&& u8str) noexcept
    *   @param u8str
    */
    UTF8string( UTF8string&& u8str ) noexcept;

    /**
    *   @fn UTF8string& operator =(const char * str)
    *   @param str C-string that will be converted
    *   @return A reference to the new utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    *   @note If an exception is thrown, the object in not modified
    */
    UTF8string& operator =( const char * str );
    /**
    *   @fn UTF8string& operator =(const std::string& str)
    *   @param str The string that will be converted and checked
    *   @return A reference to the new utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    *   @note If an exception is thrown, the object in not modified
    */
    UTF8string& operator =( const std::string& str );
    /**
    *   @fn UTF8string& operator =(const UTF8string& u8str)
    *   @param u8str The utf-8 string
    *   @return A reference to the new utf-8 string
    */
    UTF8string& operator =( const UTF8string& u8str ) noexcept;
    /**
    *   @fn UTF8string& operator =(UTF8string&& u8str)
    *   @param u8str The utf-8 string
    *   @return A reference to the new utf-8 string
    */
    UTF8string& operator =( UTF8string&& u8str ) noexcept;

    /**
    *   @fn const UTF8string& operator +=(const UTF8string& u8str)
    *
    *   Append a utf-8 string
    *
    *   @param u8str The string to convert from
    *   @return The reference to the concatenated utf-8 string
    */
    const UTF8string& operator +=( const UTF8string& u8str );
    /**
    *   @fn const UTF8string& operator +=(const std::string& str)
    *
    *   Append a string
    *
    *   @param str The string to convert from
    *   @return The reference to the concatenated utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    *   @note If an exception is thrown, the object in not modified
    */
    const UTF8string& operator +=( const std::string& str );
    /**
    *   @fn const UTF8string& operator +=(const char * str)
    *
    *   Append a C-string
    *
    *   @param str The string to convert from
    *   @return The reference to the concatenated utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    */
    const UTF8string& operator +=( const char * str );

    /**
    *   @fn void utf8_clear() noexcept
    *   Clear the content of the object
    */
    void utf8_clear() noexcept;
    /**
    *   @fn bool utf8_empty() const noexcept
    *
    *   Check if the content is empty
    *
    *   @return TRUE If it is empty, FALSE otherwise
    */
    bool utf8_empty() const noexcept;


    /**
    *   @fn UTF8string& utf8_assign(const char * str)
    *   @return The updated string
    */
    UTF8string& utf8_assign( const char * str );
    /**
    *   @fn UTF8string& utf8_assign(const u8string& str)
    *   @return The updated string
    */
    UTF8string& utf8_assign( const u8string& str );
    /**
    *   @fn UTF8string& utf8_assign(const u8string& str, size_t pos, size_t count = npos)
    *
    *   Replaces the contents with a substring [pos, pos+count) of str.
    *   If the requested substring lasts past the end of the string, or if count == npos, the resulting substring is [pos, str.size()).
    *
    *   @exception std::out_of_range If pos > str.size()
    *   @return The updated string
    */
    UTF8string& utf8_assign( const u8string& str, size_t pos, size_t count = npos );
    /**
    *   @fn UTF8string& utf8_assign(UTF8string&& u8str) noexcept
    *   @return The updated string
    */
    UTF8string& utf8_assign( UTF8string&& u8str ) noexcept;

    /**
    *   @fn UTF8string::u8char utf8_at(const size_t index) const
    *
    *   Get the codepoint at a specified position.
    *
    *   @param index The index of the requested codepoint in the string
    *   @return The codepoint
    *   @exception std::out_of_range If the index is out of the string range
    *   @note If an exception is thrown, the object in not modified
    */
    UTF8string::u8char utf8_at( const size_t index ) const;
    /**
    *   @fn UTF8string::u8char operator [](const size_t index) const noexcept
    *
    *   Get the codepoint at a specified position.
    *
    *   @param index The index of the requested codepoint in the string
    *   @return The codepoint
    *
    *   @note If the index is out of the string range, calling this functions
    *         causes undefined behaviour
    */
    UTF8string::u8char operator []( const size_t index ) const noexcept;
    /**
    *   @fn void utf8_pop()
    *
    *   Remove the last codepoint.
    *
    *   @exception std::length_error If the string is empty
    *   @note If an exception is thrown, the object in not modified
    */
    void utf8_pop();
    /**
    *   @fn UTF8string& utf8_erase(const size_t index = 0, const size_t count = npos)
    *
    *   Removes min(count, utf8_size() - index) characters starting at index
    *
    *   @return *this
    *   @exception std::out_of_range if ```index > utf8_size()```
    *   @note If an exception is thrown, the object in not modified
    */
    UTF8string& utf8_erase( const size_t index = 0, const size_t count = npos );
    /**
    *   @fn UTF8iterator utf8_erase(const UTF8iterator& position)
    *
    *   Removes the character at position
    *
    *   @return Iterator pointing to the character immediately following the character erased,
    *           or utf8_end() if no such character exists
    *   @note If the iterator does not point to *this, the behaviour is undefined
    */
    UTF8iterator utf8_erase( const UTF8iterator& position );
    /**
    *   @fn UTF8iterator utf8_erase(const UTF8iterator& first, const UTF8iterator& last)
    *
    *   Removes the character in the range [first, last[
    *
    *   @return Iterator pointing to the character ```last```before the erase,
    *           or utf8_end() if no such character exists
    *   @note If one of the iterators does not point to *this, the behaviour is undefined
    */
    UTF8iterator utf8_erase( const UTF8iterator& first, const UTF8iterator& last );

    /**
    *   @fn UTF8string utf8_substr(size_t pos = 0, size_t len = npos) const
    *
    *   Generate a substring according to the position and the length requested.
    *
    *   The substring is the portion of the object that starts at
    *   character position *pos* and spans *len* characters
    *   (or until the end of the string, whichever comes first).
    *
    *   @param pos The beginning position of the substring (default value: 0)
    *   @param len The length of the substring (in number of codepoints, default value = npos)
    *   @return The substring
    */
    UTF8string utf8_substr( size_t pos = 0, size_t len = npos ) const;
    /**
    *   @fn size_t utf8_find(const UTF8string& str, size_t pos = 0) const
    *
    *   Search for the first occurrence of utf8 string
    *   specified in argument.
    *
    *   When pos is specified, the search only includes characters
    *   at or after position pos, ignoring any possible occurrences
    *   that include characters before pos.
    *
    *   @param str The string to look for
    *   @param pos The position to start the search
    *   @return The position of the substring if it was found
    *           (in number of codepoints), UTF8string::npos otherwise.
    */
    size_t utf8_find( const UTF8string& str, size_t pos = 0 ) const;
    /**
    *   @fn UTF8string& utf8_reverse()
    *   Reverse the current utf-8 string.
    *   @return The reversed string
    */
    UTF8string& utf8_reverse();

    /**
    *   @fn size_t utf8_size() const noexcept
    *   Get the memory size (in bytes) of the utf-8 string
    *   @return The memory size of the utf-8 string
    */
    size_t utf8_size() const noexcept;
    /**
    *   @fn size_t utf8_length() const noexcept
    *   Get the length of the utf-8 string
    *   @return The length of the utf-8 string (in number of codepoints)
    */
    size_t utf8_length() const noexcept;

    /**
    *   @fn const std::string utf8_sstring() const noexcept
    *
    *   Returns the string related to the UTF-8 string
    *
    *   @return The string
    */
    const std::string utf8_sstring() const noexcept;
    /**
    *   @fn const char * utf8_str() const noexcept
    *
    *   Returns a pointer to an array that contains a null-terminated sequence
    *   of characters (C-string).
    *
    *   This array include exactly the string plus the null character ('\0')
    *   at the end.
    *
    *   @return A pointer to a C-string
    */
    const char * utf8_str() const noexcept;
    /**
    *   @fn size_t hash() const noexcept
    *   Generate a hash value of the utf8 string
    *   @return The hash value
    */
    size_t hash() const noexcept;

    /**
    *   @fn UTF8iterator utf8_begin() const noexcept
    *
    *   Returns an iterator that points to the first codepoint of the string
    *
    *   @return An iterator to the beginnigng of the string
    */
    UTF8iterator utf8_begin() const noexcept;
    /**
    *   @fn UTF8iterator utf8_end() const noexcept
    *
    *   Returns an iterator that points to the *past-the-end* codepoint of the string
    *
    *   The past-the-end codepoint is a theoretical codepoint that would follow
    *   the last codepoint in the string. It shall not be dereferenced.
    *
    *   @return An iterator to the past-the-end codepoint
    */
    UTF8iterator utf8_end() const noexcept;

    /**
    *   @fn UTF8iterator begin() const noexcept
    *
    *   Returns an iterator that points to the first codepoint of the string
    *
    *   @return An iterator to the beginnigng of the string
    *   @note Same as utf8_begin()
    */
    UTF8iterator begin() const noexcept;
    /**
    *   @fn UTF8iterator end() const noexcept
    *
    *   Returns an iterator that points to the *past-the-end* codepoint of the string
    *
    *   The past-the-end codepoint is a theoretical codepoint that would follow
    *   the last codepoint in the string. It shall not be dereferenced.
    *
    *   @return An iterator to the past-the-end codepoint
    *   @note Same as utf8_end()
    */
    UTF8iterator end() const noexcept;

    ~UTF8string() = default;
};


namespace std
{

template<>
class hash<UTF8string>
{
public:
    size_t operator()( const UTF8string& u8str ) const
    {
        return u8str.hash();
    }
};

}


/**
*   @fn bool operator ==(const UTF8string& str1, const UTF8string& str2) noexcept
*
*   Check if two utf-8 strings are equals.
*
*   Two utf-8 strings are equals if and only if they heve the same length
*   and have the same sequence of codepoints.
*
*   @param str1 utf-8 string
*   @param str2 utf-8 string
*   @return TRUE if they are equals, FALSE otherwise
*/
bool operator ==( const UTF8string& str1, const UTF8string& str2 ) noexcept;

/**
*   @fn bool operator !=(const UTF8string& str1, const UTF8string& str2) noexcept
*
*   Check if two utf-8 strings are differents.
*
*   @param str1 utf-8 string
*   @param str2 utf-8 string
*   @return TRUE if they are not equals, FALSE otherwise
*/
bool operator !=( const UTF8string& str1, const UTF8string& str2 ) noexcept;

/**
*   @fn bool operator <=(const UTF8string& str1, const UTF8string& str2) noexcept
*
*   Check if the first utf-8 string is shorter or equal
*   than/to the second utf-8 string
*
*   @param str1 utf-8 string
*   @param str2 utf-8 string
*   @return TRUE if the first string is shorter, FALSE otherwise
*/
bool operator <=( const UTF8string& str1, const UTF8string& str2 ) noexcept;

/**
*   @fn bool operator >=(const UTF8string& str1, const UTF8string& str2) noexcept
*
*   Check if the first utf-8 string is longer or equal than/to the second utf-8 string
*
*   @param str1 utf-8 string
*   @param str2 utf-8 string
*   @return TRUE if tthe first string is longer, FALSE otherwise
*/
bool operator >=( const UTF8string& str1, const UTF8string& str2 ) noexcept;

/**
*   @fn bool operator <(const UTF8string& str1, const UTF8string& str2) noexcept
*
*   Check if the first utf-8 string is strictly shorter
*   than the second utf-8 string
*
*   @param str1 utf-8 string
*   @param str2 utf-8 string
*   @return TRUE if the first string is strictly shorter, FALSE otherwise
*/
bool operator <( const UTF8string& str1, const UTF8string& str2 ) noexcept;

/**
*   @fn bool operator >(const UTF8string& str1, const UTF8string& str2) noexcept
*
*   Check if the first utf-8 string is strictly longer
*   than the second utf-8 string
*
*   @param str1 utf-8 string
*   @param str2 utf-8 string
*   @return TRUE if the string is strictly longer, FALSE otherwise
*/
bool operator >( const UTF8string& str1, const UTF8string& str2 ) noexcept;

/**
*   @fn UTF8string operator +(const UTF8string& str1, const UTF8string& str2)
*
*   Generate a string as a concatenation of the two utf-8 givenin arguments
*
*   @param str1 utf-8 string
*   @param str2 utf-8 string
*   @return A new string whose values is the concatenation of str1 and str2
*/
UTF8string operator +( const UTF8string& str1, const UTF8string& str2 );

/**
*   @fn UTF8string operator +(const UTF8string& str1, const std::string& str2)
*
*   Generate a string as a concatenation of a utf-8 string and a string
*   given in arguments
*
*   @param str1 utf-8 string
*   @param str2 string
*   @return A new string whose values is the concatenation of str1 and str2
*/
UTF8string operator +( const UTF8string& str1, const std::string& str2 );

/**
*   @fn UTF8string operator +(const std::string& str1, const UTF8string& str2)
*
*   Generate a string as a concatenation of a string and a utf-8 string
*   given in arguments
*
*   @param str1 string
*   @param str2 utf-8 string
*   @return A new string whose values is the concatenation of str1 and str2
*/
UTF8string operator +( const std::string& str1, const UTF8string& str2 );

/**
*   @fn UTF8string operator +(const UTF8string& str1, const char * str2)
*
*   Generate a string as a concatenation of a utf-8 string and a C-string
*   given in arguments
*
*   @param str1 utf-8 string
*   @param str2 C-string
*   @return A new string whose values is the concatenation of str1 and str2
*/
UTF8string operator +( const UTF8string& str1, const char * str2 );

/**
*   @fn UTF8string operator +(const char * str1, const UTF8string& str2)
*
*   Generate a string as a concatenation of a C-string and a utf-8 string
*   given in arguments
*
*   @param str1 C-string
*   @param str2 utf8 string
*   @return A new string whose values is the concatenation of str1 and str2
*/
UTF8string operator +( const char * str1, const UTF8string& str2 );

/**
*   @fn std::ostream& operator <<(std::ostream& os, const UTF8string& str)
*
*   Insert a utf-8 string into a stream.
*
*   This function overloads *operator <<* to behave as described
*   in *ostream::operator <<* for C-strings, but applied to utf-8 string objects.
*
*   @param os The output stream
*   @param str utf8 string to put
*   @return The same as parameter *os*
*/
std::ostream& operator <<( std::ostream& os, const UTF8string& str );

/**
*   @fn std::istream& operator >>(std::istream& is, UTF8string& str)
*
*   Extract a utf-8 string from a stream, storing the sequence in str,
*   which is overwritten (the previous value of str is replaced).
*
*   This function overloads *operator >>* to behave as described
*   in *istream::operator >>* for c-strings, but applied to string objects.
*
*   @param is The input stream
*   @param str utf8 string to put
*   @return The same as parameter *is*
*/
std::istream& operator >>( std::istream& is, UTF8string& str );

#include "utf8_iterator.hpp"

#endif // UTF8_STRING_HPP_INCLUDED
