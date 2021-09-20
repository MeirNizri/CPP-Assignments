/**
 * Unit tests for Itertools
 * 
 * Author: Meir Nizri
 * Fifth assignment in cpp course
 * Date: 2020-06
 */
 
#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <vector>
#include <string>
#include <set>

using namespace itertools;
using namespace std;


TEST_CASE("Test range") {
    int value = 0;
    for(int i : range(0,15)) {
        CHECK(i == value);
        value++;
    }
    
    value = -10;
    for(int i : range(-10,5)) {
        CHECK(i == value);
        value++;
    }
    
    for(int i : range(0,0)) {
        CHECK_THROWS(true);
    }
}



TEST_CASE("Test accumulate") {
    vector<int> results = {0,1,3,6,10,15,21,28,36,45};
    int i = 0;
    for (int j : accumulate(range(0,10))) {
        CHECK(j == results.at(i));
        i++;
    }

    vector<string> strings = {"im","doing","cpp","task"};
    vector<string> results1 = {"im", "imdoing", "imdoingcpp", "imdoingcpptask"};
    i = 0;
    for(string s : accumulate(strings)) {
        CHECK(s == results1.at(i));
        i++;
    }
}



TEST_CASE("Test accumulate with functors") {
    vector<int> results = {0,1,3,6,10,15,21,28,36};
    int i = 0;
    for (int j : accumulate(range(0,9), [](int x, int y){return x+y;})) {
        CHECK(j == results.at(i));
        i++;
    }
    
    vector<int> results1 = {1,2,6,24,120,720};
    i = 0;
    for (int j : accumulate(range(1,7), [](int x, int y){return x*y;})) {
        CHECK(j == results1.at(i));
        i++;
    }
    
    vector<int> results2 = {1,-1,-4,-8,-13,-19,-26,-34};
    i = 0;
    for (int j : accumulate(range(1,9), [](int x, int y){return x-y;})) {
        CHECK(j == results2.at(i));
        i++;
    }
}



TEST_CASE("Test filterfalse") {
    vector<int> results = {0,2,4,6,8,10};
    int i = 0;
    for (int j : filterfalse([](int x){return x%2 == 1;}, range(0,11))) {
        CHECK(j == results.at(i));
        CHECK_FALSE(j == results.at(i)+1);
        i++;
    }
    
    int value = 0;
    for (int i : filterfalse([](int x){return x>=10;}, range(0,15))) {
        CHECK(i == value);
        value++;
    }
}



TEST_CASE("Test compress") {
   vector<int> results = {0,2,4,6};
    int i = 0;
    for (int j : compress(range(0,8), vector({true,false,true,false,true,false,true,false}))) {
        CHECK(j == results.at(i));
        CHECK_FALSE(j == results.at(i)+1);
        i++;
    }
    
    vector<char> results1 = {'a','b','e','g'};
    i = 0;
    for (char j : compress(string("abcdefg"), vector({true,true,false,false,true,false,true}))) {
        CHECK(j == results1.at(i));
        i++;
    }
}

