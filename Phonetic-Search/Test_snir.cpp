/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    /* Add more checks here */
    string text1 = "xxx b yyy";
    CHECK(find(text1, "p") == string("b"));
    CHECK(find(text1, "b") == string("b"));

    string text2 = "xxx p yyy";
    CHECK(find(text2, "p") == string("p"));
    CHECK(find(text2, "b") == string("p"));

    string text3 = "xxx bbb ppppppppp pppp yyy";
    CHECK(find(text3, "bbbbbbbbb") == string("ppppppppp"));
    CHECK(find(text3, "bbbb") == string("pppp"));
    CHECK(find(text3, "ppp") == string("bbb"));
    CHECK(find(text3, "bpb") == string("bbb"));
    CHECK(find(text3, "bpp") == string("bbb"));
    CHECK(find(text3, "ppb") == string("bbb"));
    CHECK(find(text3, "pbb") == string("bbb"));
    CHECK(find(text3, "bbbb") == string("pppp"));
    CHECK(find(text3, "pbbb") == string("pppp"));
    CHECK(find(text3, "bpbb") == string("pppp"));
    CHECK(find(text3, "bbpb") == string("pppp"));
    CHECK(find(text3, "bbbp") == string("pppp"));
    CHECK(find(text3, "pbpbpbpbp") == string("ppppppppp"));
    CHECK(find(text3, "pbpbpbpbb") == string("ppppppppp"));
    CHECK(find(text3, "pbpbpbbbp") == string("ppppppppp"));
    CHECK(find(text3, "pbpbbbbbp") == string("ppppppppp"));
    CHECK(find(text3, "bpbpbpbpb") == string("ppppppppp"));

    string text4 = "happy xxx yyy";
    CHECK(find(text4, "happy") == string("happy"));
    CHECK(find(text4, "habby") == string("happy"));
    CHECK(find(text4, "hapby") == string("happy"));
    CHECK(find(text4, "habpy") == string("happy"));

    string text5 = "xxx yyy happy";
    CHECK(find(text5, "happy") == string("happy"));
    CHECK(find(text5, "habby") == string("happy"));
    CHECK(find(text5, "hapby") == string("happy"));
    CHECK(find(text5, "habpy") == string("happy"));

    string text6 = " x  xx       yyy               happy                     ";
    CHECK(find(text6, "happy") == string("happy"));
    CHECK(find(text6, "habby") == string("happy"));
    CHECK(find(text6, "hapby") == string("happy"));
    CHECK(find(text6, "habpy") == string("happy"));

    string text7 = "happa happb happc happc happd happe happf happg happh happy happa";
    CHECK(find(text7, "happy") == string("happy"));
    CHECK(find(text7, "habby") == string("happy"));
    CHECK(find(text7, "hapby") == string("happy"));
    CHECK(find(text7, "habpy") == string("happy"));

    string text8 = "happj happk happl happm happn happo happp happq happy happa";
    CHECK(find(text8, "happy") == string("happy"));
    CHECK(find(text8, "habby") == string("happy"));
    CHECK(find(text8, "hapby") == string("happy"));
    CHECK(find(text8, "habpy") == string("happy"));

    string text9 = "happr happs happt happu happv happw happx happz happy happa";
    CHECK(find(text9, "happy") == string("happy"));
    CHECK(find(text9, "habby") == string("happy"));
    CHECK(find(text9, "hapby") == string("happy"));
    CHECK(find(text9, "habpy") == string("happy"));

    string text10 = "xxx happ y happy yyy";
    CHECK(find(text10, "happy") == string("happy"));
    CHECK(find(text10, "habby") == string("happy"));
    CHECK(find(text10, "hapby") == string("happy"));
    CHECK(find(text10, "habpy") == string("happy"));
}


TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
    CHECK(find(text, "HAPPi") == string("Happi"));
    CHECK(find(text, "HAPpi") == string("Happi"));
    CHECK(find(text, "HAppi") == string("Happi"));
    CHECK(find(text, "HAppI") == string("Happi"));
    CHECK(find(text, "HappI") == string("Happi"));
    CHECK(find(text, "happI") == string("Happi"));

    string text1 = "xxx Happi yyy";
    CHECK(find(text1, "happi") == string("Happi"));
    CHECK(find(text1, "Happi") == string("Happi"));
    CHECK(find(text1, "HAPPI") == string("Happi"));
    CHECK(find(text1, "HaPpI") == string("Happi"));
    
    CHECK(find(text1, "HAPPi") == string("Happi"));
    CHECK(find(text1, "HAPpi") == string("Happi"));
    CHECK(find(text1, "HAppi") == string("Happi"));
    CHECK(find(text1, "HAppI") == string("Happi"));
    CHECK(find(text1, "HappI") == string("Happi"));
    CHECK(find(text1, "happI") == string("Happi"));

    string text2 = "xxx yyy Happi";
    CHECK(find(text2, "happi") == string("Happi"));
    CHECK(find(text2, "Happi") == string("Happi"));
    CHECK(find(text2, "HAPPI") == string("Happi"));
    CHECK(find(text2, "HaPpI") == string("Happi"));
    
    CHECK(find(text2, "HAPPi") == string("Happi"));
    CHECK(find(text2, "HAPpi") == string("Happi"));
    CHECK(find(text2, "HAppi") == string("Happi"));
    CHECK(find(text2, "HAppI") == string("Happi"));
    CHECK(find(text2, "HappI") == string("Happi"));
    CHECK(find(text2, "happI") == string("Happi"));

    string text3 = "xxx yyy abcdefghijklmnopqrstuvwxyz";
    CHECK(find(text3, "abcdefghijklmnopqrstuvwxyz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRSTUVWXYz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRSTUVWXyZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRSTUVWxYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRSTUVwXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRSTUvWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRSTuVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRStUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQRsTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPQrSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOPqRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNOpQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMNoPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLMnOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKLmNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJKlMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIJkLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHIjKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGHiJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFGhIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEFgHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDEfGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCDeFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABCdEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "ABcDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "AbCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "aBCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "aBcDeFgHiJkLmNoPqRsTuVwXyZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text3, "AbCdEfGhIjKlMnOpQrStUvWxYz") == string("abcdefghijklmnopqrstuvwxyz"));

    string text4 = "xxx abcdefghijklmnopqrstuvwxyz yyy";
    CHECK(find(text4, "abcdefghijklmnopqrstuvwxyz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRSTUVWXYz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRSTUVWXyZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRSTUVWxYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRSTUVwXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRSTUvWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRSTuVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRStUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQRsTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPQrSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOPqRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNOpQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMNoPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLMnOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKLmNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJKlMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIJkLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHIjKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGHiJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFGhIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEFgHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDEfGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCDeFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABCdEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "ABcDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "AbCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "aBCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "aBcDeFgHiJkLmNoPqRsTuVwXyZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text4, "AbCdEfGhIjKlMnOpQrStUvWxYz") == string("abcdefghijklmnopqrstuvwxyz"));
    string text5 = "abcdefghijklmnopqrstuvwxyz xxx yyy";
    CHECK(find(text5, "abcdefghijklmnopqrstuvwxyz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRSTUVWXYz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRSTUVWXyZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRSTUVWxYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRSTUVwXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRSTUvWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRSTuVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRStUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQRsTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPQrSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOPqRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNOpQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMNoPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLMnOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKLmNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJKlMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIJkLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHIjKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGHiJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFGhIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEFgHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDEfGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCDeFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABCdEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "ABcDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "AbCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "aBCDEFGHIJKLMNOPQRSTUVWXYZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "aBcDeFgHiJkLmNoPqRsTuVwXyZ") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text5, "AbCdEfGhIjKlMnOpQrStUvWxYz") == string("abcdefghijklmnopqrstuvwxyz"));


}



TEST_CASE("Test replacement of f and b") {
    string text = "xxx haffy yyy";
    CHECK(find(text, "habby") == string("haffy"));
    CHECK(find(text, "habfy") == string("haffy"));
    CHECK(find(text, "hafby") == string("haffy"));
    CHECK(find(text, "haffy") == string("haffy"));
    string text1 = "haffy xxx yyy";
    CHECK(find(text1, "habby") == string("haffy"));
    CHECK(find(text1, "habfy") == string("haffy"));
    CHECK(find(text1, "hafby") == string("haffy"));
    CHECK(find(text1, "haffy") == string("haffy"));
    string text2 = "xxx yyy haffy";
    CHECK(find(text2, "habby") == string("haffy"));
    CHECK(find(text2, "habfy") == string("haffy"));
    CHECK(find(text2, "hafby") == string("haffy"));
    CHECK(find(text2, "haffy") == string("haffy"));

}
TEST_CASE("Test replacement of f and p") {
    string text = "xxx haffy yyy";
    CHECK(find(text, "happy") == string("haffy"));
    CHECK(find(text, "hapfy") == string("haffy"));
    CHECK(find(text, "hafpy") == string("haffy"));
    CHECK(find(text, "haffy") == string("haffy"));
    string text1 = "haffy xxx yyy";
    CHECK(find(text1, "happy") == string("haffy"));
    CHECK(find(text1, "hapfy") == string("haffy"));
    CHECK(find(text1, "hafpy") == string("haffy"));
    CHECK(find(text1, "haffy") == string("haffy"));
    string text2 = "xxx yyy haffy";
    CHECK(find(text2, "happy") == string("haffy"));
    CHECK(find(text2, "hapfy") == string("haffy"));
    CHECK(find(text2, "hafpy") == string("haffy"));
    CHECK(find(text2, "haffy") == string("haffy"));
    
}
TEST_CASE("Test replacement of b and p and f") {
    string text = "xxx pfb yyy";
    CHECK(find(text, "fbp") == string("pfb"));
    CHECK(find(text, "pbf") == string("pfb"));
    CHECK(find(text, "bfp") == string("pfb"));
    CHECK(find(text, "fff") == string("pfb"));
    CHECK(find(text, "bbb") == string("pfb"));
    CHECK(find(text, "ppp") == string("pfb"));
    CHECK(find(text, "pfp") == string("pfb"));
    CHECK(find(text, "pbp") == string("pfb"));
    CHECK(find(text, "bfb") == string("pfb"));
    string text1 = "pfb xxx yyy";
    CHECK(find(text1, "fbp") == string("pfb"));
    CHECK(find(text1, "pbf") == string("pfb"));
    CHECK(find(text1, "bfp") == string("pfb"));
    CHECK(find(text1, "fff") == string("pfb"));
    CHECK(find(text1, "bbb") == string("pfb"));
    CHECK(find(text1, "ppp") == string("pfb"));
    CHECK(find(text1, "pfp") == string("pfb"));
    CHECK(find(text1, "pbp") == string("pfb"));
    CHECK(find(text1, "bfb") == string("pfb"));
    string text2 = "xxx yyy pfb";
    CHECK(find(text2, "fbp") == string("pfb"));
    CHECK(find(text2, "pbf") == string("pfb"));
    CHECK(find(text2, "bfp") == string("pfb"));
    CHECK(find(text2, "fff") == string("pfb"));
    CHECK(find(text2, "bbb") == string("pfb"));
    CHECK(find(text2, "ppp") == string("pfb"));
    CHECK(find(text2, "pfp") == string("pfb"));
    CHECK(find(text2, "pbp") == string("pfb"));
    CHECK(find(text2, "bfb") == string("pfb"));
}
TEST_CASE("Test replacement of w and v")
{
    string text1 = "xxx wowry yyy";
    CHECK(find(text1, "wowry") == string("wowry"));
    CHECK(find(text1, "vowry") == string("wowry"));
    CHECK(find(text1, "vovry") == string("wowry"));
    CHECK(find(text1, "wovry") == string("wowry"));
    string text2 = "wowry xxx yyy";
    CHECK(find(text2, "wowry") == string("wowry"));
    CHECK(find(text2, "vowry") == string("wowry"));
    CHECK(find(text2, "vovry") == string("wowry"));
    CHECK(find(text2, "wovry") == string("wowry"));
    string text3 = "xxx yyy wowry";
    CHECK(find(text3, "wowry") == string("wowry"));
    CHECK(find(text3, "vowry") == string("wowry"));
    CHECK(find(text3, "vovry") == string("wowry"));
    CHECK(find(text3, "wovry") == string("wowry"));
}
TEST_CASE("Test replacement of g and j")
{
    string text1 = "xxx dogjobAndjudge yyy";
    CHECK(find(text1, "dogjobAndjudge") == string("dogjobAndjudge"));
    CHECK(find(text1, "dogjobAndjudje") == string("dogjobAndjudge"));
    CHECK(find(text1, "doggobAndjudge") == string("dogjobAndjudge"));
    CHECK(find(text1, "doggobAndgudge") == string("dogjobAndjudge"));
    CHECK(find(text1, "dojjobAndgudge") == string("dogjobAndjudge"));
    CHECK(find(text1, "dojjobAndjudje") == string("dogjobAndjudge"));
    CHECK(find(text1, "dojjobAndgudje") == string("dogjobAndjudge"));
    string text2 = "dogjobAndjudge xxx yyy";
    CHECK(find(text2, "dogjobAndjudge") == string("dogjobAndjudge"));
    CHECK(find(text2, "dogjobAndjudje") == string("dogjobAndjudge"));
    CHECK(find(text2, "doggobAndjudge") == string("dogjobAndjudge"));
    CHECK(find(text2, "doggobAndgudge") == string("dogjobAndjudge"));
    CHECK(find(text2, "dojjobAndgudge") == string("dogjobAndjudge"));
    CHECK(find(text2, "dojjobAndjudje") == string("dogjobAndjudge"));
    CHECK(find(text2, "dojjobAndgudje") == string("dogjobAndjudge"));
    string text3 = "xxx yyy dogjobAndjudge";
    CHECK(find(text3, "dogjobAndjudge") == string("dogjobAndjudge"));
    CHECK(find(text3, "dogjobAndjudje") == string("dogjobAndjudge"));
    CHECK(find(text3, "doggobAndjudge") == string("dogjobAndjudge"));
    CHECK(find(text3, "doggobAndgudge") == string("dogjobAndjudge"));
    CHECK(find(text3, "dojjobAndgudge") == string("dogjobAndjudge"));
    CHECK(find(text3, "dojjobAndjudje") == string("dogjobAndjudge"));
    CHECK(find(text3, "dojjobAndgudje") == string("dogjobAndjudge"));
}

TEST_CASE("Test replacement of c and k and q")
{
    string text1 = "xxx cocokukuququoqckkcq yyy";
    CHECK(find(text1, "cocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "kokokukuququoqkkkkq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "kocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "kokokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "kokokukuququoqkkkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "qocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "qoqokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "qoqokukuququoqqkkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "qoqokukuququoqqkkqq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "qokocuqucukuoccqcqq") == string("cocokukuququoqckkcq"));
    CHECK(find(text1, "koqocuqukucuocqcqkc") == string("cocokukuququoqckkcq"));

    string text2 = "cocokukuququoqckkcq xxx yyy";
    CHECK(find(text2, "cocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "kokokukuququoqkkkkq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "kocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "kokokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "kokokukuququoqkkkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "qocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "qoqokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "qoqokukuququoqqkkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "qoqokukuququoqqkkqq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "qokocuqucukuoccqcqq") == string("cocokukuququoqckkcq"));
    CHECK(find(text2, "koqocuqukucuocqcqkc") == string("cocokukuququoqckkcq"));

    string text3 = "xxx yyy cocokukuququoqckkcq";
    CHECK(find(text3, "cocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "kokokukuququoqkkkkq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "kocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "kokokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "kokokukuququoqkkkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "qocokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "qoqokukuququoqckkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "qoqokukuququoqqkkcq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "qoqokukuququoqqkkqq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "qokocuqucukuoccqcqq") == string("cocokukuququoqckkcq"));
    CHECK(find(text3, "koqocuqukucuocqcqkc") == string("cocokukuququoqckkcq"));
}
TEST_CASE("Test replacement of s and z")
{
    string text1 = "xxx abcdefghijklmnopqrstuvwxyz yyy";
    CHECK(find(text1, "abcdefghijklmnopqrstuvwxyz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text1, "abcdefghijklmnopqrztuvwxyz") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text1, "abcdefghijklmnopqrstuvwxys") == string("abcdefghijklmnopqrstuvwxyz"));
    CHECK(find(text1, "abcdefghijklmnopqrztuvwxys") == string("abcdefghijklmnopqrstuvwxyz"));
    string text2 = "xxx sqzsgwgazsfz yyy";
    CHECK(find(text2, "sqzsgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text2, "zqzsgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text2, "zqzzgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text2, "zqzzgwgazzfz") == string("sqzsgwgazsfz"));
    CHECK(find(text2, "sqssgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text2, "sqssgwgassfz") == string("sqzsgwgazsfz"));
    CHECK(find(text2, "zqszgwgaszfs") == string("sqzsgwgazsfz"));

    string text3 = "sqzsgwgazsfz xxx yyy";
    CHECK(find(text3, "sqzsgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text3, "zqzsgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text3, "zqzzgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text3, "zqzzgwgazzfz") == string("sqzsgwgazsfz"));
    CHECK(find(text3, "sqssgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text3, "sqssgwgassfz") == string("sqzsgwgazsfz"));
    CHECK(find(text3, "zqszgwgaszfs") == string("sqzsgwgazsfz"));

    string text4 = "xxx yyy sqzsgwgazsfz";
    CHECK(find(text4, "sqzsgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text4, "zqzsgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text4, "zqzzgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text4, "zqzzgwgazzfz") == string("sqzsgwgazsfz"));
    CHECK(find(text4, "sqssgwgazsfz") == string("sqzsgwgazsfz"));
    CHECK(find(text4, "sqssgwgassfz") == string("sqzsgwgazsfz"));
    CHECK(find(text4, "zqszgwgaszfs") == string("sqzsgwgazsfz"));
}

TEST_CASE("Test replacement of d and t")
{
    string text1 = "xxx dotnetdotnet yyy";
    CHECK(find(text1, "dotnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text1, "totnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text1, "totnettotnet") == string("dotnetdotnet"));
    CHECK(find(text1, "dodnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text1, "dodneddotnet") == string("dotnetdotnet"));
    CHECK(find(text1, "dodneddodnet") == string("dotnetdotnet"));
    CHECK(find(text1, "dodneddodned") == string("dotnetdotnet"));
    CHECK(find(text1, "dotneddodned") == string("dotnetdotnet"));
    CHECK(find(text1, "todnedtodned") == string("dotnetdotnet"));
    string text2 = "dotnetdotnet xxx yyy";
    CHECK(find(text2, "dotnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text2, "totnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text2, "totnettotnet") == string("dotnetdotnet"));
    CHECK(find(text2, "dodnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text2, "dodneddotnet") == string("dotnetdotnet"));
    CHECK(find(text2, "dodneddodnet") == string("dotnetdotnet"));
    CHECK(find(text2, "dodneddodned") == string("dotnetdotnet"));
    CHECK(find(text2, "dotneddodned") == string("dotnetdotnet"));
    CHECK(find(text2, "todnedtodned") == string("dotnetdotnet"));
    string text3 = "xxx yyy dotnetdotnet";
    CHECK(find(text3, "dotnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text3, "totnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text3, "totnettotnet") == string("dotnetdotnet"));
    CHECK(find(text3, "dodnetdotnet") == string("dotnetdotnet"));
    CHECK(find(text3, "dodneddotnet") == string("dotnetdotnet"));
    CHECK(find(text3, "dodneddodnet") == string("dotnetdotnet"));
    CHECK(find(text3, "dodneddodned") == string("dotnetdotnet"));
    CHECK(find(text3, "dotneddodned") == string("dotnetdotnet"));
    CHECK(find(text3, "todnedtodned") == string("dotnetdotnet"));
}
TEST_CASE("Test replacement of o and u")
{
    string text1 = "xxx ourorour yyy";
    CHECK(find(text1, "ourorour") == string("ourorour"));
    CHECK(find(text1, "oororour") == string("ourorour"));
    CHECK(find(text1, "uurorour") == string("ourorour"));
    CHECK(find(text1, "uororour") == string("ourorour"));
    CHECK(find(text1, "oororoor") == string("ourorour"));
    CHECK(find(text1, "uuroruur") == string("ourorour"));
    CHECK(find(text1, "uururuur") == string("ourorour"));
    CHECK(find(text1, "uoruruor") == string("ourorour"));
    string text2 = "ourorour xxx yyy";
    CHECK(find(text2, "ourorour") == string("ourorour"));
    CHECK(find(text2, "oororour") == string("ourorour"));
    CHECK(find(text2, "uurorour") == string("ourorour"));
    CHECK(find(text2, "uororour") == string("ourorour"));
    CHECK(find(text2, "oororoor") == string("ourorour"));
    CHECK(find(text2, "uuroruur") == string("ourorour"));
    CHECK(find(text2, "uururuur") == string("ourorour"));
    CHECK(find(text2, "uoruruor") == string("ourorour"));
    string text3 = "xxx yyy ourorour";
    CHECK(find(text3, "ourorour") == string("ourorour"));
    CHECK(find(text3, "oororour") == string("ourorour"));
    CHECK(find(text3, "uurorour") == string("ourorour"));
    CHECK(find(text3, "uororour") == string("ourorour"));
    CHECK(find(text3, "oororoor") == string("ourorour"));
    CHECK(find(text3, "uuroruur") == string("ourorour"));
    CHECK(find(text3, "uururuur") == string("ourorour"));
    CHECK(find(text3, "uoruruor") == string("ourorour"));
}

TEST_CASE("Test replacement of i and y")
{
    string text1 = "xxx yiyiheysayios yyy";
    CHECK(find(text1, "yiyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text1, "iiyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text1, "yiiiheysayios") == string("yiyiheysayios"));
    CHECK(find(text1, "iiiiheysayios") == string("yiyiheysayios"));
    CHECK(find(text1, "yyyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text1, "yyyyheysayios") == string("yiyiheysayios"));
    CHECK(find(text1, "yiyiheisaiios") == string("yiyiheysayios"));
    CHECK(find(text1, "iiiiheisaiios") == string("yiyiheysayios"));
    CHECK(find(text1, "yyyyheysayyos") == string("yiyiheysayios"));
    CHECK(find(text1, "iyiyheisaiyos") == string("yiyiheysayios"));
    string text2 = "yiyiheysayios xxx yyy";
    CHECK(find(text2, "yiyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text2, "iiyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text2, "yiiiheysayios") == string("yiyiheysayios"));
    CHECK(find(text2, "iiiiheysayios") == string("yiyiheysayios"));
    CHECK(find(text2, "yyyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text2, "yyyyheysayios") == string("yiyiheysayios"));
    CHECK(find(text2, "yiyiheisaiios") == string("yiyiheysayios"));
    CHECK(find(text2, "iiiiheisaiios") == string("yiyiheysayios"));
    CHECK(find(text2, "yyyyheysayyos") == string("yiyiheysayios"));
    CHECK(find(text2, "iyiyheisaiyos") == string("yiyiheysayios"));
    string text3 = "xxx yyy yiyiheysayios";
    CHECK(find(text3, "yiyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text3, "iiyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text3, "yiiiheysayios") == string("yiyiheysayios"));
    CHECK(find(text3, "iiiiheysayios") == string("yiyiheysayios"));
    CHECK(find(text3, "yyyiheysayios") == string("yiyiheysayios"));
    CHECK(find(text3, "yyyyheysayios") == string("yiyiheysayios"));
    CHECK(find(text3, "yiyiheisaiios") == string("yiyiheysayios"));
    CHECK(find(text3, "iiiiheisaiios") == string("yiyiheysayios"));
    CHECK(find(text3, "yyyyheysayyos") == string("yiyiheysayios"));
    CHECK(find(text3, "iyiyheisaiyos") == string("yiyiheysayios"));
}

TEST_CASE("word not found on the text throw")
{
    string text1 = "xxx abcdefghijklmnopqrstuvwxyz yyy";
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxya"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyb"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyc"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyd"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxye"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyf"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyg"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyh"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyi"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyj"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyk"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyl"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxym"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyn"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyo"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyp"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyq"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyr"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyt"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyu"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyv"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyw"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyx"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxyy"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxaz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxbz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxcz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxdz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxez"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxfz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxgz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxhz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxjz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxkz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxlz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxmz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxnz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxoz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxpz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxqz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxrz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxsz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxtz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxuz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxvz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxwz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxxz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvwxzz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvaxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvbxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvcxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvdxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvexyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvfxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvgxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvhxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvixyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvjxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvkxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvlxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvmxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvnxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvoxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvpxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvqxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvrxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvsxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvtxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvuxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvxxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvyxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuvzxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuawxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstubwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstucwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstudwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuewxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstufwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstugwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuhwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuiwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstujwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstukwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstulwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstumwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstunwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuowxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstupwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuqwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsturwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuswxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstutwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuuwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuxwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuywxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstuzwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstavwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstbvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstcvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstdvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstevwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstfvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstgvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsthvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstivwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstjvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstkvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstlvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstmvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstnvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstpvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstqvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstrvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstsvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsttvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstvvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstwvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstxvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstyvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrstzvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsauvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsbuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrscuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrseuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsfuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsguvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrshuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsiuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsjuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrskuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsluvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsmuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsnuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsouvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrspuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsquvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsruvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrssuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsuuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsvuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrswuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsxuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrsyuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrszuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqratuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrbtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrctuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrdtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqretuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrftuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrgtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrhtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrituvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrjtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrktuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrltuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrmtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrntuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrotuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrptuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrqtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrrtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrutuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrvtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrwtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrxtuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopqrytuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoparstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopbrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopdrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoperstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopfrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopgrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnophrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopirstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopjrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoplrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopmrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopnrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoporstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopprstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoprrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopsrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoptrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopurstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopvrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopwrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopxrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopyrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnopzrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoaqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnocqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnodqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoeqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnogqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnohqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoiqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnojqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnokqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnolqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnomqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnonqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnooqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoqqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnorqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnosqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnotqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnouqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnovqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnowqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoxqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnoyqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnozqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnapqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnbpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmncpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmndpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnepqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnfpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmngpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnhpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnipqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnjpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnkpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnlpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnmpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnnpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnppqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnqpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnrpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnspqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmntpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnvpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnwpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnxpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnypqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijklmnzpqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijalmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijblmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijdlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijelmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijflmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijglmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijhlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijilmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijjlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijllmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijmlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijnlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijolmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijplmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijrlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijslmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijtlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijulmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijvlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijwlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijxlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijylmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghijzlmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghiaklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghibklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghicklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghidklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghieklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghifklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghihklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghiiklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghikklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghilklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghimklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghinklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghioklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghipklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghiqklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghirklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghisklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghitklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghiuklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghivklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghiwklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghixklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghiyklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghizklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghajklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghbjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghcjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghdjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghejklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghfjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghgjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghhjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghjjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghkjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghljklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghmjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghnjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghojklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghpjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghqjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghrjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghsjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghtjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghujklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghvjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghwjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghxjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefghzjklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefahijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefbhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefchijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefdhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefehijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdeffhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefhhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefihijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefkhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdeflhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefmhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefnhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefohijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefphijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefqhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefrhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefshijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefthijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefuhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefvhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefwhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefxhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefyhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdefzhijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdeaghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdecghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdedghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdeeghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdehghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdeighijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdejghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdekghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdelghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdemghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdenghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdeoghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdesghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdetghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdeughijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdevghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdewghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdexghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdeyghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcdezghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcaefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abceefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcfefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcgefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abchefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abciefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcjefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abckefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abclefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcmefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcnefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcoefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcpefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcqefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcrefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcsefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcuefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcvefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcwefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcxefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abcyefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abczefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abadefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abbdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abddefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abedefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abfdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abgdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abhdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abidefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abjdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abldefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abmdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abpdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abrdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "absdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abtdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abudefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abwdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abxdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abydefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "abzdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "aacdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "accdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "adcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "aecdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "agcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "ahcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "aicdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "ajcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "akcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "alcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "amcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "ancdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "aocdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "aqcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "arcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "ascdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "atcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "aucdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "awcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "axcdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "aycdefghijklmnopqrstuvwxyz"));
    CHECK_THROWS(find(text1, "azcdefghijklmnopqrstuvwxyz"));



}

TEST_CASE("empty word")
{
    string text1 = "";
    CHECK_THROWS(find(text1, ""));
    string text2 = "          ";
    CHECK_THROWS(find(text2, " "));
    string text3 = " ";
    CHECK_THROWS(find(text3, " "));
    string text4 = " ";
    CHECK_THROWS(find(text4, "  "));
    string text5 = " ";
    CHECK_THROWS(find(text5, "          "));
    string text6 = "";
    CHECK_THROWS(find(text5, "          "));
    
}

TEST_CASE("space in the text")
{
    string text1 = " hello";
    CHECK(find(text1, "hello") == string("hello"));
    string text2 = "          hello";
    CHECK(find(text2, "hello") == string("hello"));
    string text3 = "hello ";
    CHECK(find(text3, "hello") == string("hello"));
    string text4 = "hello          ";
    CHECK(find(text4, "hello") == string("hello"));
    string text5 = " hello ";
    CHECK(find(text5, "hello") == string("hello"));
    string text6 = "          hello          ";
    CHECK(find(text6, "hello") == string("hello"));
    
}
/* Add more test cases here */
