
#include <iostream>
#include <string>
#include <stdexcept>

#include "../src/utf8_string.hpp"

using namespace std;

int main()
{
    /* First test suite */
    {
        UTF8string u8("がんばつて Gumichan");

        // copy construtore
        UTF8string hum;
        hum = "がんばつて Gumichan";

        // Test the test
        if(u8 != u8)
            return 1;

        if(u8 != hum)
            return 2;

        // assignment
        UTF8string uu8 = u8;

        if(u8 != uu8)
            return 3;

        // assignment
        std::string str1 = "がんばつて";
        UTF8string utf8 = str1;
        std::string str2 = utf8.utf8_str();

        if(str1 != str2)
            return 4;

        // assignment
        std::string strg1 = "Gumi";
        std::string strg2 = "chan";
        const size_t sz1 = strg1.size();
        const size_t sz2 = strg2.size();
        const size_t len1 = strg1.length();
        const size_t len2 = strg2.length();
        UTF8string utf8_cat = strg1;

        if(utf8_cat.utf8_size() != sz1)
        {
            cerr << "ERROR : expected : " << sz1
                 << "; got : " << utf8_cat.utf8_size() << endl;
            return 5;
        }

        if(utf8_cat.utf8_length() != len1)
        {
            cerr << "ERROR : expected : " << len1
                 << "; got : " << utf8_cat.utf8_length() << endl;
            return 6;
        }

        utf8_cat += strg2;

        if(utf8_cat.utf8_size() != (sz1 + sz2))
        {
            cerr << "ERROR : expected : " << (sz1 + sz2)
                 << "; got : " << utf8_cat.utf8_size() << endl;
            return 7;
        }

        if(utf8_cat.utf8_length() != (len1 + len2))
        {
            cerr << "ERROR : expected : " << (len1 + len2)
                 << "; got : " << utf8_cat.utf8_length() << endl;
            return 8;
        }
    }

    /* Second test suite */
    {
        // Exract the utf8 string
        UTF8string utf("がんばつて Gumichan");
        UTF8string sub1 = utf.utf8_substr(6,4);
        UTF8string sub2 = utf.utf8_substr(0,5);
        UTF8string aexpected("Gumi");
        UTF8string u8expected("がんばつて");

        if(sub1 != aexpected)
        {
            cerr << "ERROR : expected : " << aexpected.utf8_str()
                 << "; got :" << sub1.utf8_str() << endl;
            return 9;
        }

        if(sub2 != u8expected)
        {
            cerr << "ERROR : expected : " << u8expected.utf8_str()
                 << "; got :" << sub2.utf8_str() << endl;
            return 10;
        }

        utf.utf8_clear();

        if(!utf.utf8_empty())
            return 11;

        UTF8string aaaa("aaaa");
        UTF8string bbbb("bbbb");
        UTF8string aaa("aaaa");

        if(aaaa > bbbb)
            return 12;

        if(aaa > aaaa)
            return 13;

        if(aaaa > aaaa)
            return 14;

        if(aaaa < aaaa)
            return 15;

        auto it_begin = aaaa.utf8_begin();
        auto it_end = aaaa.utf8_end();

        if(it_begin == it_end)
            return 16;

        UTF8string str("がんばつて! Gumichan");
        UTF8string ganbatsute("がんばつて");
        UTF8string gumichan("Gumichan");
        size_t lenstr1 = str.utf8_find(ganbatsute);
        size_t lenstr2 = str.utf8_find(gumichan);

        if(lenstr1 != 0)
        {
            cout << lenstr1 << " expected : 0" << endl;
            return 17;
        }

        if(lenstr2 != 7)
        {
            cout << lenstr2 << " expected : 7" << endl;
            return 18;
        }
    }

    // Invalid UTF-8 string test
    {
        /// 1-byte codepoint
        try
        {
            // An invalid codepoint
            char inv1[] = {'\x80'};
            string chstr = inv1;
            UTF8string u8 = chstr;

            return 19;
        }
        catch(const std::invalid_argument &) {}

        /// 2-byte codepoint
        // 0xC2 is not followed by a continuation byte
        try
        {
            char inv1[] = {'\xFF', '\x00'};
            string chstr = inv1;
            UTF8string u8 = chstr;

            return 20;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // 0xC2 is followed by a continuation byte > BF
            char inv2[] = {'\xC2', '\xFE', '\x00'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 21;
        }
        catch(const std::invalid_argument &) {}


        try
        {
            // 0xC2 is followed by a continuation byte < 0x80
            char inv2[] = {'\xC2', '\x7F', '\x00'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 22;
        }
        catch(const std::invalid_argument &) {}


        /// 3-byte codepoint
        try
        {
            // 0xE0 has no continuation byte
            char inv2[] = {'\xE0'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 23;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0xC0) after 0xE0
            char inv2[] = {'\xE0','\xA7','\xC0','\x00'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 24;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x9F) after 0xE0
            char inv3[] = {'\xE0','\x9F','\xA7','\x00'};
            string chstr = inv3;
            UTF8string u8 = chstr;

            return 25;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x71) after 0xED
            char inv3[] = {'\xED','\x71','\xA7','\x00'};
            string chstr = inv3;
            UTF8string u8 = chstr;

            return 26;
        }
        catch(const std::invalid_argument &){}

        try
        {
            // Invalid continuation byte (0xA0) after 0xED
            char inv3[] = {'\xED','\xA0','\xA7','\x00'};
            string chstr = inv3;
            UTF8string u8 = chstr;

            return 27;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // valid string
            char inv2[] = {'\xE0','\xA7','\xA7','\x00'};
            string chstr = inv2;
            UTF8string u8 = chstr;

        }
        catch(const std::invalid_argument &)
        {
            return 28;
        }

        try
        {
            // 0xE0 has no continuation byte
            char inv2[] = {'\xED'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 29;
        }
        catch(const std::invalid_argument &) {}

        /// 4-byte codepoint
        try
        {
            // 0xF0 has no continuation byte
            char inv2[] = {'\xF0'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 30;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // 0xF4 has no continuation byte
            char inv2[] = {'\xF4'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 31;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // 0xF5 is not the first byte of a codepoint
            char inv2[] = {'\xF4','\x90','\x90','\x90'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 31;
        }
        catch(const std::invalid_argument &) {}

        // With 0xF0 as the first byte of the codepoint
        try
        {
            // Invalid continuation byte (0x8F) after 0xF0
            char inv2[] = {'\xF0','\x8F','\x91','\xB5','\x00'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 32;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x8F) after 0xF0
            char inv2[] = {'\xF0','\xC7','\x91','\xB5','\x00'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 33;
        }
        catch(const std::invalid_argument &) {}


        // With 0xF4 as the first byte of the codepoint
        try
        {
            // Invalid continuation byte (0x7F) after 0xF4
            char inv2[] = {'\xF4','\x7F','\x91','\xB5','\x00'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 34;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x92) after 0xF4
            char inv2[] = {'\xF4','\x92','\x91','\xB5','\x00'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 35;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Not enough bytes after the first codepoint byte
            char inv2[] = {'\xF4','\x92'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 36;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Not enough bytes after the first codepoint byte
            char inv2[] = {'\xF4','\x92','\x91'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 37;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Not enough bytes after the first codepoint byte
            char inv2[] = {'\xF0','\x92','\x91'};
            string chstr = inv2;
            UTF8string u8 = chstr;

            return 38;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Valid string
            string jap1 = "ドロテ: すみません、ゆうびんきょくはどこですか。";
            string jap2 = "けいかん: ゆうびんきょくですか。このみちをまっすぐいってください。ひとつめのしんごうをみぎにまがってください。";
            string jap3 = "ドロテ: ひとつめのしんごうをみぎですね。";
            string jap4 = "けいかん: はい、それから、まっすぐいってください。ふたつめのかどにゆうびんきょくがあります。";
            string jap5 = "ドロテ: ふたつめのかどですね。わかりました。どうもありがとうございます。";
            string jap6 = "けいかん: いいえ、どういたしまして。";
            UTF8string u8 = (jap1 + jap2 + jap3 + jap4 + jap5 + jap6);

            UTF8string u8sub = string("わかりました");

            if(u8.utf8_find(u8sub) == std::string::npos)
            {
                return 39;
            }

        }
        catch(const std::invalid_argument &)
        {
            return 40;
        }
    }

    return 0;
}
