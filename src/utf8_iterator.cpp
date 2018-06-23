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

#include "utf8_string.hpp"

#include <stdexcept>


UTF8iterator::UTF8iterator( const UTF8string& u ) noexcept
    : _index( 0 ), _data( u ) {}

UTF8iterator::UTF8iterator( const UTF8iterator& it ) noexcept
    : _index( it._index ), _data( it._data ) {}


UTF8iterator& UTF8iterator::operator =( const UTF8iterator& it ) noexcept
{
    _data = it._data;
    _index = it._index;
    return *this;
}


UTF8iterator& UTF8iterator::operator ++() noexcept
{
    if ( _index < _data.utf8_length() )
        _index += 1;

    return *this;
}


UTF8iterator UTF8iterator::operator ++( int ) noexcept
{
    UTF8iterator oldit( *this );

    if ( _index < _data.utf8_length() )
        _index += 1;

    return oldit;
}


UTF8iterator& UTF8iterator::operator --() noexcept
{
    if ( _index > 0 )
        _index -= 1;

    return *this;
}


UTF8iterator UTF8iterator::operator --( int ) noexcept
{
    UTF8iterator oldit( *this );

    if ( _index > 0 )
        _index -= 1;

    return oldit;
}


bool UTF8iterator::operator ==( const UTF8iterator& it ) const noexcept
{
    return ( _data == it._data ) && ( _index == it._index );
}


bool UTF8iterator::operator !=( const UTF8iterator& it ) const noexcept
{
    return !( *this == it );
}


bool UTF8iterator::operator <( const UTF8iterator& it ) const noexcept
{
    return ( _data == it._data ) && ( _index < it._index );
}

bool UTF8iterator::operator >( const UTF8iterator& it ) const noexcept
{
    return ( _data == it._data ) && ( _index > it._index );
}

bool UTF8iterator::operator <=( const UTF8iterator& it ) const noexcept
{
    return ( _data == it._data ) && ( _index <= it._index );
}

bool UTF8iterator::operator >=( const UTF8iterator& it ) const noexcept
{
    return ( _data == it._data ) && ( _index >= it._index );
}

const UTF8string::u8char UTF8iterator::operator *() const
{
    return _data.utf8_at( _index );
}


UTF8iterator UTF8iterator::operator +( const size_t n ) const noexcept
{
    UTF8iterator newit( *this );
    const size_t U8LEN = newit._data.utf8_length();

    if ( newit._index + n < U8LEN )
        newit._index += n;
    else
        newit._index = U8LEN;

    return newit;
}


UTF8iterator UTF8iterator::operator -( const size_t n ) const noexcept
{
    UTF8iterator newit( *this );

    if ( newit._index >= n )
        newit._index -= n;
    else
        newit._index = 0;

    return newit;
}

long UTF8iterator::operator -( const UTF8iterator& it ) const
{
    if ( _data != it._data )
        throw std::invalid_argument( "iterators don't point to the same data" );

    return static_cast<long>( _index ) - static_cast<long>( it._index );
}
