/**
 * Unit tests for PhoneticFinder
 * First assignment in cpp course
 * 
 * Author: Meir Nizri
 * Second assignment in cpp course
 * Date: 2020-03-30
 */
 
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
#include <iostream>
using namespace std;

TEST_CASE("Test replacement of v and w") {
    string text = "wow im victorious";
    CHECK(find(text, "Wow") == string("wow"));
    CHECK(find(text, "vow") == string("wow"));
    CHECK(find(text, "Vow") == string("wow"));
    CHECK(find(text, "woV") == string("wow"));
    CHECK(find(text, "Victorious") == string("victorious"));
    CHECK(find(text, "wictorious") == string("victorious"));
    CHECK(find(text, "Wictorious") == string("victorious"));
}

TEST_CASE("Test replacement of b, f and p") {
    string text = "peter is my best friend";
    CHECK(find(text, "Peter") == string("peter"));
    CHECK(find(text, "beter") == string("peter"));
    CHECK(find(text, "feter") == string("peter"));
    CHECK(find(text, "Feter") == string("peter"));
    CHECK(find(text, "Best") == string("best"));
    CHECK(find(text, "pest") == string("best"));
    CHECK(find(text, "Pest") == string("best"));
    CHECK(find(text, "fest") == string("best"));
    CHECK(find(text, "Friend") == string("friend"));
    CHECK(find(text, "priend") == string("friend"));
    CHECK(find(text, "briend") == string("friend"));
    CHECK(find(text, "Briend") == string("friend"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "im going to the jungle";
    CHECK(find(text, "GoinG") == string("going"));
    CHECK(find(text, "joinj") == string("going"));
    CHECK(find(text, "Joing") == string("going"));
    CHECK(find(text, "Junjle") == string("jungle"));
    CHECK(find(text, "gungle") == string("jungle"));
    CHECK(find(text, "Gunjle") == string("jungle"));
}

TEST_CASE("Test replacement of c, k and q") {
    string text = "kurt quit from soccer";
    CHECK(find(text, "Kurt") == string("kurt"));
    CHECK(find(text, "Curt") == string("kurt"));
    CHECK(find(text, "curt") == string("kurt"));
    CHECK(find(text, "qurt") == string("kurt"));
    CHECK(find(text, "Quit") == string("quit"));
    CHECK(find(text, "cuit") == string("quit"));
    CHECK(find(text, "Kuit") == string("quit"));
    CHECK(find(text, "kuit") == string("quit"));
    CHECK(find(text, "socker") == string("soccer"));
    CHECK(find(text, "soqker") == string("soccer"));
    CHECK(find(text, "sokker") == string("soccer"));
    CHECK(find(text, "socqer") == string("soccer"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "susan is present";
    CHECK(find(text, "Susan") == string("susan"));
    CHECK(find(text, "suzan") == string("susan"));
    CHECK(find(text, "zusan") == string("susan"));
    CHECK(find(text, "Zuzan") == string("susan"));
    CHECK(find(text, "prezent") == string("present"));
    CHECK(find(text, "preZent") == string("present"));
    CHECK(find(text, "preSent") == string("present"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "i didnt mean that";
    CHECK(find(text, "didnd") == string("didnt"));
    CHECK(find(text, "Didnt") == string("didnt"));
    CHECK(find(text, "tidnt") == string("didnt"));
    CHECK(find(text, "Tidnt") == string("didnt"));
    CHECK(find(text, "that") == string("that"));
    CHECK(find(text, "dhat") == string("that"));
    CHECK(find(text, "Dhad") == string("that"));
    CHECK(find(text, "thad") == string("that"));
    CHECK(find(text, "That") == string("that"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "our university is now closed";
    CHECK(find(text, "our") == string("our"));
    CHECK(find(text, "Our") == string("our"));
    CHECK(find(text, "oor") == string("our"));
    CHECK(find(text, "uur") == string("our"));
    CHECK(find(text, "nuw") == string("now"));
    CHECK(find(text, "nOw") == string("now"));
    CHECK(find(text, "clused") == string("closed"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "get fit working out at the gym";
    CHECK(find(text, "gYm") == string("gym"));
    CHECK(find(text, "gim") == string("gym"));
    CHECK(find(text, "gIm") == string("gym"));
    CHECK(find(text, "fIt") == string("fit"));
    CHECK(find(text, "fyt") == string("fit"));
    CHECK(find(text, "workyng") == string("working"));
}

TEST_CASE("Test capital letters") {
    string text = "Test Capital Letters";
    CHECK(find(text, "test") == string("Test"));
    CHECK(find(text, "TEST") == string("Test"));
    CHECK(find(text, "tesT") == string("Test"));
    CHECK(find(text, "capital") == string("Capital"));
    CHECK(find(text, "CAPITAL") == string("Capital"));
    CHECK(find(text, "CapitaL") == string("Capital"));
    CHECK(find(text, "letters") == string("Letters"));
    CHECK(find(text, "LETTERS") == string("Letters"));
    CHECK(find(text, "letTers") == string("Letters"));
}

TEST_CASE("Test combination of letters 1") {
    string text = "im computer science student in ariel university";
    CHECK(find(text, "Combuder") == string("computer"));
    CHECK(find(text, "komputer") == string("computer"));
    CHECK(find(text, "comfuder") == string("computer"));
    CHECK(find(text, "Scyence") == string("science"));
    CHECK(find(text, "Scienke") == string("science"));
    CHECK(find(text, "skyence") == string("science"));
    CHECK(find(text, "sdudent") == string("student"));
    CHECK(find(text, "stutend") == string("student"));
    CHECK(find(text, "Sdutent") == string("student"));
    CHECK(find(text, "aryel") == string("ariel"));
    CHECK(find(text, "Ariel") == string("ariel"));
    CHECK(find(text, "Aryel") == string("ariel"));
    CHECK(find(text, "Oniwersity") == string("university"));
    CHECK(find(text, "univerzidy") == string("university"));
    CHECK(find(text, "Uniwersiti") == string("university"));
}

TEST_CASE("Test combination of letters 2") {
    string text = "my operating system is windows from Microsoft";
    CHECK(find(text, "Operading") == string("operating"));
    CHECK(find(text, "oferatyng") == string("operating"));
    CHECK(find(text, "oberadyng") == string("operating"));
    CHECK(find(text, "Sysdem") == string("system"));
    CHECK(find(text, "sistem") == string("system"));
    CHECK(find(text, "syzdem") == string("system"));
    CHECK(find(text, "Windowz") == string("windows"));
    CHECK(find(text, "vindows") == string("windows"));
    CHECK(find(text, "wintovz") == string("windows"));
    CHECK(find(text, "Microsopd") == string("Microsoft"));
    CHECK(find(text, "Mikrozoft") == string("Microsoft"));
    CHECK(find(text, "Miqrosopt") == string("Microsoft"));
}

TEST_CASE("Test return errors") {
    string text = "my operating system is windows from Microsoft";
    CHECK_THROWS(find(text, "Operaing"));
    CHECK_THROWS(find(text, "ofratyng"));
    CHECK_THROWS(find(text, "oberadyngu"));
    CHECK_THROWS(find(text, "Sysdjem"));
    CHECK_THROWS(find(text, "    "));
    CHECK_THROWS(find(text, ""));
}