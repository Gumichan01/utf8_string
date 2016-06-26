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


/**
*   @file utf8_string.hpp
*   This is a UTF-8 string library header
*/

#include <string>
#include <iostream>

class UTF8iterator;

/**
*   @class UTF8string
*   @brief UTF-8 string class
*
*   This class defines a UTF-8 string
*/
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

    /**
    *   @fn UTF8string()
    */
    UTF8string();

    /**
    *   @fn UTF8string(const std::string &str)
    *   @param str The string to convert from
    *   @exception std::invalid_argument If the string is not valid
    */
    UTF8string(const std::string &str);

    /**
    *   @fn UTF8string(const UTF8string &u8str)
    *   @param u8str The string to convert from
    *   @exception std::invalid_argument If the string is not valid
    */
    UTF8string(const UTF8string &u8str);

    /**
    *   @fn const UTF8string& operator =(const char * str)
    *   @param str C-string that will be converted
    *   @return A reference to the new utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    */
    const UTF8string& operator =(const char * str);

    /**
    *   @fn const UTF8string& operator =(const std::string &str)
    *   @param str The string that will be converted and checked
    *   @return A reference to the new utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    */
    const UTF8string& operator =(const std::string &str);

    /**
    *   @fn const UTF8string& operator =(const UTF8string &u8str)
    *   @param u8str The utf-8 string
    *   @return A reference to the new utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    */
    const UTF8string& operator =(const UTF8string &u8str);

    /**
    *   @fn const UTF8string& operator +=(const UTF8string &u8str)
    *
    *   Append a utf-8 string
    *
    *   @param u8str The string to convert from
    *   @return The reference to the concatenated utf-8 string
    */
    const UTF8string& operator +=(const UTF8string &u8str);

    /**
    *   @fn const UTF8string& operator +=(const std::string &str)
    *
    *   Append a string
    *
    *   @param str The string to convert from
    *   @return The reference to the concatenated utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    */
    const UTF8string& operator +=(const std::string &str);

    /**
    *   @fn const UTF8string& operator +=(const char * str)
    *
    *   Append a C-string
    *
    *   @param str The string to convert from
    *   @return The reference to the concatenated utf-8 string
    *   @exception std::invalid_argument If the string is not valid
    */
    const UTF8string& operator +=(const char * str);

    /**
    *   @fn void utf8_clear()
    *   Clear the content of the object
    */
    void utf8_clear();

    /**
    *   @fn bool utf8_empty() const
    *
    *   Check if the content is empty
    *
    *   @return TRUE If it is empty, FALSE otherwise
    */
    bool utf8_empty() const;

    /**
    *   @fn std::string utf8_at(const size_t index) const
    *
    *   Get the codepoint at a specified position.
    *
    *   @param index The index of the requested codepoint in the string
    *   @return The codepoint
    *   @exception std::out_of_range If the index if out of the string range
    */
    std::string utf8_at(const size_t index) const;

    /**
    *   @fn void utf8_pop()
    *
    *   Remove the last codepoint.
    *
    *   @exception std::length_error If the string is empty
    */
    void utf8_pop();

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
    UTF8string utf8_substr(size_t pos = 0, size_t len = npos) const;

    /**
    *   @fn size_t utf8_find(const UTF8string& str, size_t pos = 0) const
    *
    *   Search the utf8 string for the first occurrence of
    *   the sequence specified by its argument.
    *
    *   When pos is specified, the search only includes characters
    *   at or after position pos, ignoring any possible occurrences
    *   that include characters before pos.
    *
    *   @param str The string to look for
    *   @param pos The osition to start the search
    *   @return The position of the subtring if it was found
    *           (in number of codepoints), UTF8string::npos otherwise.
    */
    size_t utf8_find(const UTF8string& str, size_t pos = 0) const;

    /**
    *   @fn UTF8string& utf8_reverse()
    *   Reverse the current utf-8 string.
    *   @return The reversed string
    */
    UTF8string& utf8_reverse();

    /**
    *   @fn size_t utf8_size() const
    *   Get the memory size (in bytes) of the utf-8 string
    *   @return The memory size of the utf-8 string
    */
    size_t utf8_size() const;

    /**
    *   @fn size_t utf8_length() const
    *   Get the length of the utf-8 string
    *   @return The length of the utf-8 string (in number of codepoints)
    */
    size_t utf8_length() const;

    /**
    *   @fn const char * utf8_str() const
    *
    *   Retunrs a pointer to an array that contains a null-terminated sequence
    *   of characters (C-string).
    *
    *   This array include exactly the string plus the null character ('\0')
    *   at the end.
    *
    *   @return A pointer to a C-string
    */
    const char * utf8_str() const;

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
