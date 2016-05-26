#include <iostream>
#include <string>

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
    return 0;
}
