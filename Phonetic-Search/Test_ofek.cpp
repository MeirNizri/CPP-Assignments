#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

/*
This test written by python script that makes all the test by checking 
all scenarios. I wrote the script. 
This test file test this scenarios:
* replacement of lower letters and another lower letters
    (All scenarios, checks all options)
* replacement of high letters and another high letters
    (All scenarios, checks all options)

* Mix test- replacement of high/lower letter by another high/lower letter.
    (All scenarios, checks all options)

* words that cannot be changed. (Like 'be')

* same words. check this scenarios: find(text,originalWord) == originalWord

* Empty words

* Words that appear twice

*/

TEST_CASE("Test replacement of lower letters and another lower letters") {

    string text = "hello world";
    CHECK(find(text, "hellu") == string("hello"));
    CHECK(find(text, "hello") == string("hello"));
    CHECK(find(text, "vurlt") == string("world"));
    CHECK(find(text, "vurld") == string("world"));
    CHECK(find(text, "vorlt") == string("world"));
    CHECK(find(text, "vorld") == string("world"));
    CHECK(find(text, "wurlt") == string("world"));
    CHECK(find(text, "wurld") == string("world"));
    CHECK(find(text, "worlt") == string("world"));
    CHECK(find(text, "world") == string("world"));
    text = "vw bfp gj ckq sz dt ou iy";
    CHECK(find(text, "wv") == string("vw"));
    CHECK(find(text, "ww") == string("vw"));
    CHECK(find(text, "vv") == string("vw"));
    CHECK(find(text, "vw") == string("vw"));
    CHECK(find(text, "fbb") == string("bfp"));
    CHECK(find(text, "fbp") == string("bfp"));
    CHECK(find(text, "fbf") == string("bfp"));
    CHECK(find(text, "ffb") == string("bfp"));
    CHECK(find(text, "ffp") == string("bfp"));
    CHECK(find(text, "fff") == string("bfp"));
    CHECK(find(text, "fpb") == string("bfp"));
    CHECK(find(text, "fpp") == string("bfp"));
    CHECK(find(text, "fpf") == string("bfp"));
    CHECK(find(text, "bbb") == string("bfp"));
    CHECK(find(text, "bbp") == string("bfp"));
    CHECK(find(text, "bbf") == string("bfp"));
    CHECK(find(text, "bfb") == string("bfp"));
    CHECK(find(text, "bfp") == string("bfp"));
    CHECK(find(text, "bff") == string("bfp"));
    CHECK(find(text, "bpb") == string("bfp"));
    CHECK(find(text, "bpp") == string("bfp"));
    CHECK(find(text, "bpf") == string("bfp"));
    CHECK(find(text, "pbb") == string("bfp"));
    CHECK(find(text, "pbp") == string("bfp"));
    CHECK(find(text, "pbf") == string("bfp"));
    CHECK(find(text, "pfb") == string("bfp"));
    CHECK(find(text, "pfp") == string("bfp"));
    CHECK(find(text, "pff") == string("bfp"));
    CHECK(find(text, "ppb") == string("bfp"));
    CHECK(find(text, "ppp") == string("bfp"));
    CHECK(find(text, "ppf") == string("bfp"));
    CHECK(find(text, "jg") == string("gj"));
    CHECK(find(text, "jj") == string("gj"));
    CHECK(find(text, "gg") == string("gj"));
    CHECK(find(text, "gj") == string("gj"));
    CHECK(find(text, "kcc") == string("ckq"));
    CHECK(find(text, "kcq") == string("ckq"));
    CHECK(find(text, "kck") == string("ckq"));
    CHECK(find(text, "kkc") == string("ckq"));
    CHECK(find(text, "kkq") == string("ckq"));
    CHECK(find(text, "kkk") == string("ckq"));
    CHECK(find(text, "kqc") == string("ckq"));
    CHECK(find(text, "kqq") == string("ckq"));
    CHECK(find(text, "kqk") == string("ckq"));
    CHECK(find(text, "ccc") == string("ckq"));
    CHECK(find(text, "ccq") == string("ckq"));
    CHECK(find(text, "cck") == string("ckq"));
    CHECK(find(text, "ckc") == string("ckq"));
    CHECK(find(text, "ckq") == string("ckq"));
    CHECK(find(text, "ckk") == string("ckq"));
    CHECK(find(text, "cqc") == string("ckq"));
    CHECK(find(text, "cqq") == string("ckq"));
    CHECK(find(text, "cqk") == string("ckq"));
    CHECK(find(text, "qcc") == string("ckq"));
    CHECK(find(text, "qcq") == string("ckq"));
    CHECK(find(text, "qck") == string("ckq"));
    CHECK(find(text, "qkc") == string("ckq"));
    CHECK(find(text, "qkq") == string("ckq"));
    CHECK(find(text, "qkk") == string("ckq"));
    CHECK(find(text, "qqc") == string("ckq"));
    CHECK(find(text, "qqq") == string("ckq"));
    CHECK(find(text, "qqk") == string("ckq"));
    CHECK(find(text, "zs") == string("sz"));
    CHECK(find(text, "zz") == string("sz"));
    CHECK(find(text, "ss") == string("sz"));
    CHECK(find(text, "sz") == string("sz"));
    CHECK(find(text, "td") == string("dt"));
    CHECK(find(text, "tt") == string("dt"));
    CHECK(find(text, "dd") == string("dt"));
    CHECK(find(text, "dt") == string("dt"));
    CHECK(find(text, "uo") == string("ou"));
    CHECK(find(text, "uu") == string("ou"));
    CHECK(find(text, "oo") == string("ou"));
    CHECK(find(text, "ou") == string("ou"));
    CHECK(find(text, "yi") == string("iy"));
    CHECK(find(text, "yy") == string("iy"));
    CHECK(find(text, "ii") == string("iy"));
    CHECK(find(text, "iy") == string("iy"));
}

TEST_CASE("Test replacement of a lower/high letters") {
    string text = "AriEL";
    CHECK(find(text, "ARIEL") == string("AriEL"));
    CHECK(find(text, "ARiEL") == string("AriEL"));
    CHECK(find(text, "ArIEL") == string("AriEL"));
    CHECK(find(text, "AriEL") == string("AriEL"));
    text = "Vw BFP gJ CkQ SZ dt oU IY";
    CHECK(find(text, "VW") == string("Vw"));
    CHECK(find(text, "Vw") == string("Vw"));
    CHECK(find(text, "BFP") == string("BFP"));
    CHECK(find(text, "GJ") == string("gJ"));
    CHECK(find(text, "gJ") == string("gJ"));
    CHECK(find(text, "CKQ") == string("CkQ"));
    CHECK(find(text, "CkQ") == string("CkQ"));
    CHECK(find(text, "SZ") == string("SZ"));
    CHECK(find(text, "DT") == string("dt"));
    CHECK(find(text, "Dt") == string("dt"));
    CHECK(find(text, "dT") == string("dt"));
    CHECK(find(text, "dt") == string("dt"));
    CHECK(find(text, "OU") == string("oU"));
    CHECK(find(text, "oU") == string("oU"));
    CHECK(find(text, "IY") == string("IY"));
}

TEST_CASE("Test mix") {
    string text = "Vw BfP";
    CHECK(find(text, "wv") == string("Vw"));
    CHECK(find(text, "WV") == string("Vw"));
    CHECK(find(text, "Wv") == string("Vw"));
    CHECK(find(text, "wV") == string("Vw"));
    CHECK(find(text, "ww") == string("Vw"));
    CHECK(find(text, "WW") == string("Vw"));
    CHECK(find(text, "Ww") == string("Vw"));
    CHECK(find(text, "wW") == string("Vw"));
    CHECK(find(text, "vv") == string("Vw"));
    CHECK(find(text, "VV") == string("Vw"));
    CHECK(find(text, "Vv") == string("Vw"));
    CHECK(find(text, "vV") == string("Vw"));
    CHECK(find(text, "vw") == string("Vw"));
    CHECK(find(text, "VW") == string("Vw"));
    CHECK(find(text, "Vw") == string("Vw"));
    CHECK(find(text, "vW") == string("Vw"));
    CHECK(find(text, "fbb") == string("BfP"));
    CHECK(find(text, "FBB") == string("BfP"));
    CHECK(find(text, "FBb") == string("BfP"));
    CHECK(find(text, "FbB") == string("BfP"));
    CHECK(find(text, "Fbb") == string("BfP"));
    CHECK(find(text, "fBB") == string("BfP"));
    CHECK(find(text, "fBb") == string("BfP"));
    CHECK(find(text, "fbB") == string("BfP"));
    CHECK(find(text, "fbp") == string("BfP"));
    CHECK(find(text, "FBP") == string("BfP"));
    CHECK(find(text, "FBp") == string("BfP"));
    CHECK(find(text, "FbP") == string("BfP"));
    CHECK(find(text, "Fbp") == string("BfP"));
    CHECK(find(text, "fBP") == string("BfP"));
    CHECK(find(text, "fBp") == string("BfP"));
    CHECK(find(text, "fbP") == string("BfP"));
    CHECK(find(text, "fbf") == string("BfP"));
    CHECK(find(text, "FBF") == string("BfP"));
    CHECK(find(text, "FBf") == string("BfP"));
    CHECK(find(text, "FbF") == string("BfP"));
    CHECK(find(text, "Fbf") == string("BfP"));
    CHECK(find(text, "fBF") == string("BfP"));
    CHECK(find(text, "fBf") == string("BfP"));
    CHECK(find(text, "fbF") == string("BfP"));
    CHECK(find(text, "ffb") == string("BfP"));
    CHECK(find(text, "FFB") == string("BfP"));
    CHECK(find(text, "FFb") == string("BfP"));
    CHECK(find(text, "FfB") == string("BfP"));
    CHECK(find(text, "Ffb") == string("BfP"));
    CHECK(find(text, "fFB") == string("BfP"));
    CHECK(find(text, "fFb") == string("BfP"));
    CHECK(find(text, "ffB") == string("BfP"));
    CHECK(find(text, "ffp") == string("BfP"));
    CHECK(find(text, "FFP") == string("BfP"));
    CHECK(find(text, "FFp") == string("BfP"));
    CHECK(find(text, "FfP") == string("BfP"));
    CHECK(find(text, "Ffp") == string("BfP"));
    CHECK(find(text, "fFP") == string("BfP"));
    CHECK(find(text, "fFp") == string("BfP"));
    CHECK(find(text, "ffP") == string("BfP"));
    CHECK(find(text, "fff") == string("BfP"));
    CHECK(find(text, "FFF") == string("BfP"));
    CHECK(find(text, "FFf") == string("BfP"));
    CHECK(find(text, "FfF") == string("BfP"));
    CHECK(find(text, "Fff") == string("BfP"));
    CHECK(find(text, "fFF") == string("BfP"));
    CHECK(find(text, "fFf") == string("BfP"));
    CHECK(find(text, "ffF") == string("BfP"));
    CHECK(find(text, "fpb") == string("BfP"));
    CHECK(find(text, "FPB") == string("BfP"));
    CHECK(find(text, "FPb") == string("BfP"));
    CHECK(find(text, "FpB") == string("BfP"));
    CHECK(find(text, "Fpb") == string("BfP"));
    CHECK(find(text, "fPB") == string("BfP"));
    CHECK(find(text, "fPb") == string("BfP"));
    CHECK(find(text, "fpB") == string("BfP"));
    CHECK(find(text, "fpp") == string("BfP"));
    CHECK(find(text, "FPP") == string("BfP"));
    CHECK(find(text, "FPp") == string("BfP"));
    CHECK(find(text, "FpP") == string("BfP"));
    CHECK(find(text, "Fpp") == string("BfP"));
    CHECK(find(text, "fPP") == string("BfP"));
    CHECK(find(text, "fPp") == string("BfP"));
    CHECK(find(text, "fpP") == string("BfP"));
    CHECK(find(text, "fpf") == string("BfP"));
    CHECK(find(text, "FPF") == string("BfP"));
    CHECK(find(text, "FPf") == string("BfP"));
    CHECK(find(text, "FpF") == string("BfP"));
    CHECK(find(text, "Fpf") == string("BfP"));
    CHECK(find(text, "fPF") == string("BfP"));
    CHECK(find(text, "fPf") == string("BfP"));
    CHECK(find(text, "fpF") == string("BfP"));
    CHECK(find(text, "bbb") == string("BfP"));
    CHECK(find(text, "BBB") == string("BfP"));
    CHECK(find(text, "BBb") == string("BfP"));
    CHECK(find(text, "BbB") == string("BfP"));
    CHECK(find(text, "Bbb") == string("BfP"));
    CHECK(find(text, "bBB") == string("BfP"));
    CHECK(find(text, "bBb") == string("BfP"));
    CHECK(find(text, "bbB") == string("BfP"));
    CHECK(find(text, "bbp") == string("BfP"));
    CHECK(find(text, "BBP") == string("BfP"));
    CHECK(find(text, "BBp") == string("BfP"));
    CHECK(find(text, "BbP") == string("BfP"));
    CHECK(find(text, "Bbp") == string("BfP"));
    CHECK(find(text, "bBP") == string("BfP"));
    CHECK(find(text, "bBp") == string("BfP"));
    CHECK(find(text, "bbP") == string("BfP"));
    CHECK(find(text, "bbf") == string("BfP"));
    CHECK(find(text, "BBF") == string("BfP"));
    CHECK(find(text, "BBf") == string("BfP"));
    CHECK(find(text, "BbF") == string("BfP"));
    CHECK(find(text, "Bbf") == string("BfP"));
    CHECK(find(text, "bBF") == string("BfP"));
    CHECK(find(text, "bBf") == string("BfP"));
    CHECK(find(text, "bbF") == string("BfP"));
    CHECK(find(text, "bfb") == string("BfP"));
    CHECK(find(text, "BFB") == string("BfP"));
    CHECK(find(text, "BFb") == string("BfP"));
    CHECK(find(text, "BfB") == string("BfP"));
    CHECK(find(text, "Bfb") == string("BfP"));
    CHECK(find(text, "bFB") == string("BfP"));
    CHECK(find(text, "bFb") == string("BfP"));
    CHECK(find(text, "bfB") == string("BfP"));
    CHECK(find(text, "bfp") == string("BfP"));
    CHECK(find(text, "BFP") == string("BfP"));
    CHECK(find(text, "BFp") == string("BfP"));
    CHECK(find(text, "BfP") == string("BfP"));
    CHECK(find(text, "Bfp") == string("BfP"));
    CHECK(find(text, "bFP") == string("BfP"));
    CHECK(find(text, "bFp") == string("BfP"));
    CHECK(find(text, "bfP") == string("BfP"));
    CHECK(find(text, "bff") == string("BfP"));
    CHECK(find(text, "BFF") == string("BfP"));
    CHECK(find(text, "BFf") == string("BfP"));
    CHECK(find(text, "BfF") == string("BfP"));
    CHECK(find(text, "Bff") == string("BfP"));
    CHECK(find(text, "bFF") == string("BfP"));
    CHECK(find(text, "bFf") == string("BfP"));
    CHECK(find(text, "bfF") == string("BfP"));
    CHECK(find(text, "bpb") == string("BfP"));
    CHECK(find(text, "BPB") == string("BfP"));
    CHECK(find(text, "BPb") == string("BfP"));
    CHECK(find(text, "BpB") == string("BfP"));
    CHECK(find(text, "Bpb") == string("BfP"));
    CHECK(find(text, "bPB") == string("BfP"));
    CHECK(find(text, "bPb") == string("BfP"));
    CHECK(find(text, "bpB") == string("BfP"));
    CHECK(find(text, "bpp") == string("BfP"));
    CHECK(find(text, "BPP") == string("BfP"));
    CHECK(find(text, "BPp") == string("BfP"));
    CHECK(find(text, "BpP") == string("BfP"));
    CHECK(find(text, "Bpp") == string("BfP"));
    CHECK(find(text, "bPP") == string("BfP"));
    CHECK(find(text, "bPp") == string("BfP"));
    CHECK(find(text, "bpP") == string("BfP"));
    CHECK(find(text, "bpf") == string("BfP"));
    CHECK(find(text, "BPF") == string("BfP"));
    CHECK(find(text, "BPf") == string("BfP"));
    CHECK(find(text, "BpF") == string("BfP"));
    CHECK(find(text, "Bpf") == string("BfP"));
    CHECK(find(text, "bPF") == string("BfP"));
    CHECK(find(text, "bPf") == string("BfP"));
    CHECK(find(text, "bpF") == string("BfP"));
    CHECK(find(text, "pbb") == string("BfP"));
    CHECK(find(text, "PBB") == string("BfP"));
    CHECK(find(text, "PBb") == string("BfP"));
    CHECK(find(text, "PbB") == string("BfP"));
    CHECK(find(text, "Pbb") == string("BfP"));
    CHECK(find(text, "pBB") == string("BfP"));
    CHECK(find(text, "pBb") == string("BfP"));
    CHECK(find(text, "pbB") == string("BfP"));
    CHECK(find(text, "pbp") == string("BfP"));
    CHECK(find(text, "PBP") == string("BfP"));
    CHECK(find(text, "PBp") == string("BfP"));
    CHECK(find(text, "PbP") == string("BfP"));
    CHECK(find(text, "Pbp") == string("BfP"));
    CHECK(find(text, "pBP") == string("BfP"));
    CHECK(find(text, "pBp") == string("BfP"));
    CHECK(find(text, "pbP") == string("BfP"));
    CHECK(find(text, "pbf") == string("BfP"));
    CHECK(find(text, "PBF") == string("BfP"));
    CHECK(find(text, "PBf") == string("BfP"));
    CHECK(find(text, "PbF") == string("BfP"));
    CHECK(find(text, "Pbf") == string("BfP"));
    CHECK(find(text, "pBF") == string("BfP"));
    CHECK(find(text, "pBf") == string("BfP"));
    CHECK(find(text, "pbF") == string("BfP"));
    CHECK(find(text, "pfb") == string("BfP"));
    CHECK(find(text, "PFB") == string("BfP"));
    CHECK(find(text, "PFb") == string("BfP"));
    CHECK(find(text, "PfB") == string("BfP"));
    CHECK(find(text, "Pfb") == string("BfP"));
    CHECK(find(text, "pFB") == string("BfP"));
    CHECK(find(text, "pFb") == string("BfP"));
    CHECK(find(text, "pfB") == string("BfP"));
    CHECK(find(text, "pfp") == string("BfP"));
    CHECK(find(text, "PFP") == string("BfP"));
    CHECK(find(text, "PFp") == string("BfP"));
    CHECK(find(text, "PfP") == string("BfP"));
    CHECK(find(text, "Pfp") == string("BfP"));
    CHECK(find(text, "pFP") == string("BfP"));
    CHECK(find(text, "pFp") == string("BfP"));
    CHECK(find(text, "pfP") == string("BfP"));
    CHECK(find(text, "pff") == string("BfP"));
    CHECK(find(text, "PFF") == string("BfP"));
    CHECK(find(text, "PFf") == string("BfP"));
    CHECK(find(text, "PfF") == string("BfP"));
    CHECK(find(text, "Pff") == string("BfP"));
    CHECK(find(text, "pFF") == string("BfP"));
    CHECK(find(text, "pFf") == string("BfP"));
    CHECK(find(text, "pfF") == string("BfP"));
    CHECK(find(text, "ppb") == string("BfP"));
    CHECK(find(text, "PPB") == string("BfP"));
    CHECK(find(text, "PPb") == string("BfP"));
    CHECK(find(text, "PpB") == string("BfP"));
    CHECK(find(text, "Ppb") == string("BfP"));
    CHECK(find(text, "pPB") == string("BfP"));
    CHECK(find(text, "pPb") == string("BfP"));
    CHECK(find(text, "ppB") == string("BfP"));
    CHECK(find(text, "ppp") == string("BfP"));
    CHECK(find(text, "PPP") == string("BfP"));
    CHECK(find(text, "PPp") == string("BfP"));
    CHECK(find(text, "PpP") == string("BfP"));
    CHECK(find(text, "Ppp") == string("BfP"));
    CHECK(find(text, "pPP") == string("BfP"));
    CHECK(find(text, "pPp") == string("BfP"));
    CHECK(find(text, "ppP") == string("BfP"));
    CHECK(find(text, "ppf") == string("BfP"));
    CHECK(find(text, "PPF") == string("BfP"));
    CHECK(find(text, "PPf") == string("BfP"));
    CHECK(find(text, "PpF") == string("BfP"));
    CHECK(find(text, "Ppf") == string("BfP"));
    CHECK(find(text, "pPF") == string("BfP"));
    CHECK(find(text, "pPf") == string("BfP"));
    CHECK(find(text, "ppF") == string("BfP"));
}

TEST_CASE("Test same words") {
    string text = "Vw BfP";
    CHECK(find(text, "Vw") == string("Vw"));
    CHECK(find(text, "BfP") == string("BfP"));
}

TEST_CASE("Test word that do not exist in the text") {
    string text = "Vw BfP";
    CHECK_THROWS_AS(find(text, "Ababa"), std::exception);
    CHECK_THROWS_AS(find(text, "a"), std::exception);
    CHECK_THROWS_AS(find(text, "aback"), std::exception);
    CHECK_THROWS_AS(find(text, "AAA"), std::exception);
    CHECK_THROWS_AS(find(text, "ABA"), std::exception);
    CHECK_THROWS_AS(find(text, "Abbott"), std::exception);
    CHECK_THROWS_AS(find(text, "abbreviate"), std::exception);
    CHECK_THROWS_AS(find(text, "a"), std::exception);
    CHECK_THROWS_AS(find(text, "abbot"), std::exception);
    CHECK_THROWS_AS(find(text, "AAA"), std::exception);
    CHECK_THROWS_AS(find(text, "aback"), std::exception);
    CHECK_THROWS_AS(find(text, "abalone"), std::exception);
    CHECK_THROWS_AS(find(text, "AAA"), std::exception);
    CHECK_THROWS_AS(find(text, "abbreviate"), std::exception);
    CHECK_THROWS_AS(find(text, "abbot"), std::exception);
    CHECK_THROWS_AS(find(text, "Ababa"), std::exception);
    CHECK_THROWS_AS(find(text, "abbe"), std::exception);
    CHECK_THROWS_AS(find(text, "a"), std::exception);
    CHECK_THROWS_AS(find(text, "Ababa"), std::exception);
    CHECK_THROWS_AS(find(text, "abbreviate"), std::exception);
}

TEST_CASE("Test empty word")
{
    string text = " ";
    string text2 = "        ";
    string text3 = "";
    string anyWord = "anyWord";

    CHECK_THROWS_AS(find(text, anyWord), std::exception);
    CHECK_THROWS_AS(find(text2, anyWord), std::exception);
    CHECK_THROWS_AS(find(text3, anyWord), std::exception);
}


