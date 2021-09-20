/**
 * Unit tests for FamilyTree
 * 
 * Author: Meir Nizri
 * Second assignment in cpp course
 * Date: 2020-04-13
 */
 
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace family;

static Tree T("Yosef");
static Tree T2("Meir");

TEST_CASE("Test relation 1") {

    T.addFather("Yosef", "Yaakov")  
     .addMother("Yosef", "Rachel")   
     .addFather("Yaakov", "Isaac")
     .addMother("Yaakov", "Rivka")
     .addFather("Rachel", "Lavan")
     .addMother("Rachel", "UN")     
     .addFather("Isaac", "Avraham")
     .addMother("Isaac", "Sarah")
     .addFather("Avraham", "Terah");
    T.display();
     
    CHECK(T.relation("Yosef") == string("me")); 
    CHECK(T.relation("Yaakov") == string("father"));
    CHECK(T.relation("Rachel") == string("mother"));
    CHECK(T.relation("Isaac") == string("grandfather"));
    CHECK(T.relation("Rivka") == string("grandmother"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    CHECK(T.relation("Sarah") == string("great-grandmother"));
    CHECK(T.relation("Lavan") == string("grandfather"));
    CHECK(T.relation("UN") == string("grandmother"));
    CHECK(T.relation("Terah") == string("great-great-grandfather"));
    CHECK(T.relation("Tera") == string("unrelated"));
    CHECK(T.relation("lavan") == string("unrelated"));
    CHECK(T.relation("abc") == string("unrelated"));
    CHECK(T.relation(" ") == string("unrelated"));
    CHECK(T.relation("") == string("unrelated"));
}

TEST_CASE("Test find 1") {
    CHECK(T.find("me") == string("Yosef"));
    CHECK(T.find("father") == string("Yaakov"));
    CHECK(T.find("mother") == string("Rachel"));
    CHECK(T.find("great-grandfather") == string("Avraham"));
    CHECK(T.find("great-grandmother") == string("Sarah"));
    CHECK((T.find("grandfather") == string("Isaac") || T.find("grandfather") == string("Lavan")));
    CHECK((T.find("grandmother") == string("Rivka") || T.find("grandmother") == string("UN")));
    CHECK(T.find("great-great-grandfather") == string("Terah"));
    CHECK_THROWS(T.find("uncle"));
    CHECK_THROWS(T.find("great-great-grandmother"));
    CHECK_THROWS(T.find("great-great-great-grandfather"));
    CHECK_THROWS(T.find(" "));
}

TEST_CASE("Test remove 1") {
    T.remove("Rachel")
     .remove("Terah");
    CHECK(T.relation("Yosef") == string("me")); 
    CHECK(T.relation("Yaakov") == string("father"));
    CHECK(T.relation("Isaac") == string("grandfather"));
    CHECK(T.relation("Rivka") == string("grandmother"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    CHECK(T.relation("Sarah") == string("great-grandmother"));
    CHECK(T.relation("Terah") == string("unrelated"));
    CHECK(T.relation("Rachel") == string("unrelated"));
    CHECK(T.relation("Lavan") == string("unrelated"));
    CHECK(T.relation("UN") == string("unrelated"));
    CHECK(T.find("me") == string("Yosef"));
    CHECK(T.find("father") == string("Yaakov"));
    CHECK(T.find("grandfather") == string("Isaac")); 
    CHECK(T.find("grandmother") == string("Rivka"));
    CHECK(T.find("great-grandfather") == string("Avraham"));
    CHECK(T.find("great-grandmother") == string("Sarah"));
    CHECK_THROWS(T.find("great-great-grandfather"));
    CHECK_THROWS(T.find("mother"));
    CHECK_THROWS(T.find("great-great-grandmother"));
    CHECK_THROWS(T.find("great-great-great-grandfather"));
}    

TEST_CASE("Test relation 2") {
    T2.addFather("Meir", "Michael")  
     .addMother("Meir", "Rivka")   
     .addFather("Michael", "Rephael")
     .addMother("Michael", "Hana")
     .addFather("Rivka", "Avraham")
     .addMother("Rivka", "Ester")     
     .addFather("Rephael", "Asher")
     .addMother("Rephael", "Nofar")
     .addFather("Avraham", "Shalom")
     .addMother("Avraham", "Dana");
    T2.display();
     
    CHECK(T2.relation("Meir") == string("me")); 
    CHECK(T2.relation("Michael") == string("father"));
    CHECK(T2.relation("Rivka") == string("mother"));
    CHECK(T2.relation("Rephael") == string("grandfather"));
    CHECK(T2.relation("Hana") == string("grandmother"));
    CHECK(T2.relation("Avraham") == string("grandfather"));
    CHECK(T2.relation("Ester") == string("grandmother"));
    CHECK(T2.relation("Asher") == string("great-grandfather"));
    CHECK(T2.relation("Nofar") == string("great-grandmother"));
    CHECK(T2.relation("Shalom") == string("great-grandfather"));
    CHECK(T2.relation("Dana") == string("great-grandmother"));
    CHECK(T2.relation("dana") == string("unrelated"));
    CHECK(T2.relation("abc") == string("unrelated"));
    CHECK(T2.relation("shalom") == string("unrelated"));
    CHECK(T2.relation("grandmother") == string("unrelated"));
    CHECK(T2.relation("great-grandmother") == string("unrelated"));
    CHECK(T2.relation(" ") == string("unrelated"));
    CHECK(T2.relation("") == string("unrelated"));
}

TEST_CASE("Test find 2") {
    CHECK(T2.find("me") == string("Meir"));
    CHECK(T2.find("father") == string("Michael"));
    CHECK(T2.find("mother") == string("Rivka"));
    CHECK((T2.find("grandfather") == string("Rephael") || T.find("grandfather") == string("Avraham")));
    CHECK((T2.find("grandmother") == string("Hana") || T.find("grandmother") == string("Ester")));
    CHECK((T2.find("great-grandfather") == string("Asher") || T.find("great-grandfather") == string("Shalom")));
    CHECK((T2.find("great-grandmother") == string("Nofar") || T.find("great-grandmother") == string("Dana")));
    CHECK_THROWS(T2.find("uncle"));
    CHECK_THROWS(T2.find("great-great-grandmother"));
    CHECK_THROWS(T2.find("great-great-great-grandfather"));
    CHECK_THROWS(T2.find(" "));
}

TEST_CASE("Test remove 2") {
    T2.remove("Ester")
     .remove("Avraham");
CHECK(T2.relation("Meir") == string("me")); 
    CHECK(T2.relation("Michael") == string("father"));
    CHECK(T2.relation("Rivka") == string("mother"));
    CHECK(T2.relation("Rephael") == string("grandfather"));
    CHECK(T2.relation("Hana") == string("grandmother"));
    CHECK(T2.relation("Asher") == string("great-grandfather"));
    CHECK(T2.relation("Nofar") == string("great-grandmother"));
    CHECK(T2.relation("Avraham") == string("unrelated"));
    CHECK(T2.relation("Ester") == string("unrelated"));
    CHECK(T2.relation("Shalom") == string("unrelated"));
    CHECK(T2.relation("Dana") == string("unrelated"));
    CHECK(T2.relation("dana") == string("unrelated"));
    CHECK(T2.relation("abc") == string("unrelated"));
    CHECK(T2.relation("shalom") == string("unrelated"));
    CHECK(T2.find("me") == string("Meir"));
    CHECK(T2.find("father") == string("Michael"));
    CHECK(T2.find("mother") == string("Rivka"));
    CHECK(T2.find("grandfather") == string("Rephael")); 
    CHECK(T2.find("grandmother") == string("Hana"));
    CHECK(T2.find("great-grandfather") == string("Asher"));
    CHECK(T2.find("great-grandmother") == string("Nofar"));
    CHECK_THROWS(T2.find("uncle"));
    CHECK_THROWS(T2.find("great-great-grandmother"));
    CHECK_THROWS(T2.find("great-great-great-grandfather"));
    CHECK_THROWS(T2.find(" "));
}    