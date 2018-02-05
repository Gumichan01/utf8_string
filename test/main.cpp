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

#include <string>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <fstream>

#include "../src/utf8_string.hpp"

using namespace std;

int main()
{
    string jap1 = "ドロテ: すみません、ゆうびんきょくはどこですか。\n";
    string jap2 = "けいかん: ゆうびんきょくですか。このみちをまっすぐいってください。ひとつめのしんごうをみぎにまがってください。\n";
    string jap3 = "ドロテ: ひとつめのしんごうをみぎですね。\n";
    string jap4 = "けいかん: はい、それから、まっすぐいってください。ふたつめのかどにゆうびんきょくがあります。\n";
    string jap5 = "ドロテ: ふたつめのかどですね。わかりました。どうもありがとうございます。\n";
    string jap6 = "けいかん: いいえ、どういたしまして。";

    /// First test suite
    {
        UTF8string u8("がんばつて Gumichan");
        string utf8s("がんばつて Gumichan");

        // copy construtor
        UTF8string hum;
        hum = "がんばつて Gumichan";

        {
            try
            {
                UTF8string tmp(utf8s);
            }
            catch(...)
            {
                return 100;
            }
        }

        // Test the test
        if(u8 != u8)
            return 1;

        // assignment
        UTF8string uu8 = u8;

        if(u8 != uu8)
            return 2;

        // assignment
        std::string str1 = "がんばつて";
        UTF8string utf8 = str1;
        std::string str2 = utf8.utf8_str();

        if(str1 != str2)
            return 3;

        if(str1 != utf8.utf8_sstring())
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
                 << "; got : " << utf8_cat.utf8_size() << "\n";
            return 4;
        }

        if(utf8_cat.utf8_length() != len1)
        {
            cerr << "ERROR : expected : " << len1
                 << "; got : " << utf8_cat.utf8_length() << "\n";
            return 5;
        }

        utf8_cat += strg2;

        if(utf8_cat.utf8_size() != (sz1 + sz2))
        {
            cerr << "ERROR : expected : " << (sz1 + sz2)
                 << "; got : " << utf8_cat.utf8_size() << "\n";
            return 6;
        }

        if(utf8_cat.utf8_length() != (len1 + len2))
        {
            cerr << "ERROR : expected : " << (len1 + len2)
                 << "; got : " << utf8_cat.utf8_length() << "\n";
            return 7;
        }
    }

    /// Second test suite
    {
        // Exract the utf8 string
        UTF8string utf("がんばつて Gumichan");
        UTF8string sub1 = utf.utf8_substr(6,4);
        UTF8string sub2 = utf.utf8_substr(0,5);
        UTF8string sub3 = utf.utf8_substr(64,1024);
        UTF8string aexpected("Gumi");
        UTF8string u8expected("がんばつて");

        if(sub1 != aexpected)
        {
            cerr << "ERROR : expected : " << aexpected.utf8_str()
                 << "; got :" << sub1.utf8_str() << "\n";
            return 8;
        }

        if(sub2 != u8expected)
        {
            cerr << "ERROR : expected : " << u8expected.utf8_str()
                 << "; got :" << sub2.utf8_str() << "\n";
            return 9;
        }

        if(!sub3.utf8_empty())
        {
            return 99;
        }

        UTF8string sub = utf.utf8_substr();
        if(sub != utf)
        {
            cerr << "ERROR : expected : " << u8expected.utf8_str()
                 << "; got :" << sub.utf8_str() << "\n";
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

        // Find the string
        UTF8string str("がんばつて! Gumichan");
        UTF8string ganbatsute("がんばつて");
        UTF8string gumichan("Gumichan");
        size_t lenstr0 = str.utf8_find(UTF8string("a"));
        size_t lenstr1 = str.utf8_find(ganbatsute);
        size_t lenstr2 = str.utf8_find(gumichan,2);
        size_t lenpos = str.utf8_find(ganbatsute,1024);

        UTF8string u8 = (jap1 + jap2 + jap3 + jap4 + jap5 + jap6);
        UTF8string subjp(std::string("いいえ、どういたしまして。"));
        size_t res = u8.utf8_find(subjp);

        if(lenstr0 != 13)
        {
            cout << lenstr0 << " expected : 13 \n";
            return 17;
        }

        if(lenstr1 != 0)
        {
            cout << lenstr1 << " expected : 0 \n";
            return 171;
        }

        if(UTF8string::npos != str.utf8_find(UTF8string("")))
        {
            return 172;
        }

        if(lenstr2 != 7)
        {
            cout << lenstr2 << " expected : 7" << "\n";
            return 18;
        }

        if(lenpos != UTF8string::npos)
        {
            return 181;
        }

        if(res != (u8.utf8_length() - subjp.utf8_length()))
        {
            return 182;
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
        // Bad start codepoint
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
            char inv21[] = {'\xC2', '\xFE', '\x00'};
            string chstr = inv21;
            UTF8string u8 = chstr;

            return 21;
        }
        catch(const std::invalid_argument &) {}


        try
        {
            // 0xC2 is followed by a continuation byte < 0x80
            char inv22[] = {'\xC2', '\x7F', '\x00'};
            string chstr = inv22;
            UTF8string u8 = chstr;

            return 22;
        }
        catch(const std::invalid_argument &) {}


        /// 3-byte codepoint
        try
        {
            // 0xE0 has no continuation byte
            char inv23[] = {'\xE0'};
            string chstr = inv23;
            UTF8string u8 = chstr;

            return 23;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0xC0) after 0xE0
            char inv24[] = {'\xE0','\xA7','\xC0','\x00'};
            string chstr = inv24;
            UTF8string u8 = chstr;

            return 24;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x9F) after 0xE0
            char inv25[] = {'\xE0','\x9F','\xA7','\x00'};
            string chstr = inv25;
            UTF8string u8 = chstr;

            return 25;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x71) after 0xED
            char inv26[] = {'\xED','\x71','\xA7','\x00'};
            string chstr = inv26;
            UTF8string u8 = chstr;

            return 26;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0xA0) after 0xED
            char inv27[] = {'\xED','\xA0','\xA7','\x00'};
            string chstr = inv27;
            UTF8string u8 = chstr;

            return 27;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // valid string
            char inv28[] = {'\xE0','\xA7','\xA7','\x00'};
            string chstr = inv28;
            UTF8string u8 = chstr;

        }
        catch(const std::invalid_argument &)
        {
            return 28;
        }

        try
        {
            // 0xE0 has no continuation byte
            char inv29[] = {'\xED'};
            string chstr = inv29;
            UTF8string u8 = chstr;

            return 29;
        }
        catch(const std::invalid_argument &) {}

        /// 4-byte codepoint
        try
        {
            // 0xF0 has no continuation byte
            char inv30[] = {'\xF0'};
            string chstr = inv30;
            UTF8string u8 = chstr;

            return 30;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // 0xF4 has no continuation byte
            char inv31[] = {'\xF4'};
            string chstr = inv31;
            UTF8string u8 = chstr;

            return 31;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x90) after 0xF4
            char inv32[] = {'\xF4','\x90','\x90','\x90','\x00'};
            string chstr = inv32;
            UTF8string u8 = chstr;

            return 32;
        }
        catch(const std::invalid_argument &) {}

        // With 0xF0 as the first byte of the codepoint
        try
        {
            // Invalid continuation byte (0x8F) after 0xF0
            char inv33[] = {'\xF0','\x8F','\x91','\xB5','\x00'};
            string chstr = inv33;
            UTF8string u8 = chstr;

            return 33;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x8F) after 0xF0
            char inv34[] = {'\xF0','\xC7','\x91','\xB5','\x00'};
            string chstr = inv34;
            UTF8string u8 = chstr;

            return 34;
        }
        catch(const std::invalid_argument &) {}

        // With 0xF4 as the first byte of the codepoint
        try
        {
            // Invalid continuation byte (0x7F) after 0xF4
            char inv35[] = {'\xF4','\x7F','\x91','\xB5','\x00'};
            string chstr = inv35;
            UTF8string u8 = chstr;

            return 35;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Invalid continuation byte (0x92) after 0xF4
            char inv36[] = {'\xF4','\x92','\x91','\xB5','\x00'};
            string chstr = inv36;
            UTF8string u8 = chstr;

            return 36;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Not enough bytes after the first codepoint byte
            char inv37[] = {'\xF4','\x92'};
            string chstr = inv37;
            UTF8string u8 = chstr;

            return 37;
        }
        catch(const std::invalid_argument &) {}

        try
        {
            // Not enough bytes after the first codepoint byte
            char inv38[] = {'\xF4','\x92','\x91'};
            string chstr = inv38;
            UTF8string u8 = chstr;

            return 38;
        }
        catch(const std::invalid_argument &) {}


        try
        {
            // Valid string
            UTF8string u8 = (jap1 + jap2 + jap3 + jap4 + jap5 + jap6);
            UTF8string u8sub = string("わかりました");

            if(u8.utf8_find(u8sub) == std::string::npos)
            {
                return 40;
            }

        }
        catch(const std::invalid_argument &)
        {
            return 41;
        }
    }

    // Concatenate strings
    {
        UTF8string strex1("がんばつて Gumichan");
        UTF8string strex2("Gumichanがんばつて ");
        UTF8string ganba("がんばつて ");
        std::string gumi("Gumichan");

        const char * gumistr = "Gumichan";

        // concatenate std::string and UTF8string
        if(strex1 != (ganba + gumi))
            return 42;

        if(strex2 != (gumi + ganba))
            return 43;

        if((gumi.size() + ganba.utf8_size()) !=
                (gumi + ganba).utf8_size())
            return 44;

        if((ganba.utf8_size() + gumi.size()) !=
                (ganba + gumi).utf8_size())
            return 45;

        // concatenate UTF8string and const char *
        if(strex2 != (gumistr + ganba))
            return 46;

        if(strex1 != (ganba + gumistr))
            return 46;

        if((std::strlen(gumistr) + ganba.utf8_size()) !=
                (gumistr + ganba).utf8_size())
            return 48;


        // concatenate 2 UTF8string objects
        UTF8string gumiex(gumi);
        if(strex1 != (ganba + gumiex))
            return 49;

        if((ganba.utf8_size() + gumiex.utf8_size()) !=
                (ganba + gumiex).utf8_size())
            return 50;

        if((ganba.utf8_length() + gumiex.utf8_length()) !=
                (ganba + gumiex).utf8_length())
            return 51;

        if(strex2 != (gumiex + ganba))
            return 52;

        if((gumiex.utf8_size() + ganba.utf8_size()) !=
                (gumiex + ganba).utf8_size())
            return 53;

        if((gumiex.utf8_length() + ganba.utf8_length()) !=
                (gumiex + ganba).utf8_length())
            return 54;
    }

    // Append strings
    {
        UTF8string strex1("Gumichan がんばつて");
        UTF8string strex2("Gumichan がんばつて!");
        UTF8string gumi("Gumichan");

        gumi += " がんばつて";

        if(gumi != strex1)
            return 55;

        strex1 += "!";

        if(strex1 != strex2)
            return 56;
    }

    // Get the codepoint at a specified position
    {
        UTF8string astr("Gumichan");
        UTF8string str("がんばつて Gumichan");
        std::string gcpoint = "G";
        std::string ucpoint = "u";
        std::string ncpoint = "n";
        std::string tcpoint = "て";

        try
        {
            str.utf8_at(42);
            return 57;
        }
        catch(std::out_of_range &) {}

        std::string c0 = astr[1];
        std::string cc = astr[0];
        std::string ccc = astr.utf8_at(astr.utf8_size() - 1);
        std::string c1 = str[4];
        std::string c2 = str[7];

        if(ucpoint != c0)
        {
            std::cout << "expected: " << ucpoint << "; got: " << c0 << "\n";
            return 58;
        }

        if(gcpoint != cc)
        {
            std::cout << "expected: " << gcpoint << "; got: " << cc << "\n";
            return 59;
        }

        if(ncpoint != ccc)
        {
            std::cout << "expected: " << ncpoint << ";got: " << ccc << "\n";
            return 60;
        }

        if(tcpoint != c1)
        {
            std::cout << "expected: " << tcpoint << ";got: " << c1 << "\n";
            return 61;
        }

        if(ucpoint != c2)
        {
            std::cout << "expected: " << ucpoint << ";got: " << c2 << "\n";
            return 62;
        }

        std::string point = "。";
        UTF8string u8str("łþø けいかん: いいえ、どういたしまして。");
        std::string c = u8str.utf8_at(22);

        if(point != c)
        {
            std::cout << "expected: " << point << ";got : " << c << "\n";
            return 63;
        }
    }

    // Reverse string using iterator
    {
        UTF8string utf8orig("がんばつて Gumichan");
        UTF8string utf8str("がんばつて Gumichan");

        // Bijection
        if(utf8orig != (utf8str.utf8_reverse()).utf8_reverse())
        {
            std::cout << "expected: " << utf8orig << "; got: "
                      << (utf8str.utf8_reverse()).utf8_reverse() << "\n";
            return 64;
        }

        if(utf8orig.utf8_size() != (utf8str.utf8_reverse()).utf8_size())
        {
            std::cout << "expected: " << utf8orig.utf8_size() << "; got: "
                      << (utf8str.utf8_reverse()).utf8_size() << "\n";
            return 65;
        }

        if(utf8orig.utf8_length() != (utf8str.utf8_reverse()).utf8_length())
        {
            std::cout << "expected: " << utf8orig.utf8_length() << "; got: "
                      << (utf8str.utf8_reverse()).utf8_length() << "\n";
            return 66;
        }
    }

    // Remove the last code point
    {
        UTF8string str("がんばつて Gumichan");
        UTF8string str2("がんばつて Gumichan がんばつて");
        UTF8string strpop("がんばつて Gumicha");
        UTF8string strempty;

        str.utf8_pop();

        if(str.utf8_length() != strpop.utf8_length())
        {
            std::cout << "Excpected : " << strpop.utf8_length() << ";got  : "
                      << str.utf8_length() << "\n";
            return 67;
        }

        if(str != strpop)
        {
            std::cout << "Excpected : " << strpop << ";got  : "
                      << str << "\n";
            return 68;
        }

        str.utf8_clear();
        str = "がんばつて Gumichan がんばつて";

        str2.utf8_pop();
        str2 += "て";

        if(str2.utf8_length() != str.utf8_length())
        {
            std::cout << "Excpected : " << str.utf8_length() << ";got  : "
                      << str2.utf8_length() << "\n";
            return 69;
        }

        if(str != str2)
        {
            std::cout << "Excpected : " << str2 << ";got  : "
                      << str << "\n";
            return 70;
        }

        try
        {
            strempty.utf8_pop();
            return 71;

        }
        catch(...) {}

    }

    // Last test : search for a substring in a file
    {
        UTF8string text;
        UTF8string strreq;
        UTF8string strgumi("がんばつて gumichan01。");
        std::ifstream u8file("test/lipsum.txt");

        strreq += "速スご薄具そなラひ置更けゃっ文犬2社ぎル由人へいきつ回見ト供崩モ催屋エ国続セワルリ";
        strreq += "謙髪テシ県住ざ新球ごくき名昨ツセ戸読役ホ細16態量番などトぱ。";

        if(u8file.is_open())
        {
            std::string tmp((std::istreambuf_iterator<char>(u8file)),
                            (std::istreambuf_iterator<char>()));
            u8file.close();

            try
            {
                text = tmp;
            }
            catch(std::invalid_argument& e)
            {
                cerr << e.what() << "\n";
                return 72;
            }

            cout << "File \n" << "name: lipsum.txt"
                 << "\n" << "size: " << text.utf8_size()
                 << "\n" << "Number of characters: "
                 << text.utf8_length() << "\n";

            size_t pgumi = text.utf8_find(strgumi);

            if(pgumi == UTF8string::npos)
            {
                cerr << "The position of \"" << strgumi
                     << "\" in the text must not be UTF8string::npos\n";
                return 73;
            }
            cout << "string from position " << pgumi << ": \n"
                 << text.utf8_substr(pgumi) << "\n";
        }
        else
        {
            cerr << "File not found!\n";
            return 74;
        }

        size_t pos = text.utf8_find(strreq);

        if(pos == UTF8string::npos)
        {
            cerr << "utf8_find: " << strreq << " not found!\n";
            return 75;
        }

        cout << "string from position " << pos << ": \n"
             << text.utf8_substr(pos) << "\n";
    }

    return 0;
}
