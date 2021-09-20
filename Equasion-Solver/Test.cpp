/**
 * Unit tests for solver
 * 
 * Author: Meir Nizri
 * Third assignment in cpp course
 * Date: 2020-04
 */
 
#include "doctest.h"
#include "solver.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace solver;

RealVariable x;
ComplexVariable y;

TEST_CASE("Test + RealVariable") {
    CHECK(solve(x+0==0) == 0);
    CHECK(solve(2+x+3==10) == 5);
    CHECK(solve(x+1.5+x+x+x+0+1==12.5) == 2.5);
    CHECK(solve(x+2==7) == 5);
    CHECK(solve(2.5+x==6.7) == 4.2);
    CHECK(solve(x+1.5+x+x==9) == 2.5);
    CHECK((solve((x^2)+x+2==22.91) == 4.1 || solve((x^2)+x+2==22.91) == -5.1));
    CHECK((solve(-x+2+(x^2)==8) == 3 || solve(-x+2+(x^2)==8) == -2));
}

TEST_CASE("Test - RealVariable") {
    CHECK(solve(x-x-x==1) == -1);
    CHECK(solve(2-x-1==-4) == 5);
    CHECK(solve(0-x-0-0==-2) == 2);
    CHECK(solve(x-2==7) == 9);
    CHECK(solve(2.5-x==6.7) == -4.2);
    CHECK(solve(x-1.5-x-x==-3.4) == 1.9);
    CHECK((solve(-(x^2)-x+2==0) == 1 || solve(-(x^2)-x+2==0) == -2));
    CHECK((solve(-x-2+(x^2)==88) == 10 || solve(-x-2+(x^2)==88) == -9));  
}

TEST_CASE("Test * RealVariable") {
    CHECK(solve(x*1==7) == 7);
    CHECK((solve(3*x*x*2==150) == 5 || solve(3*x*x*2==150) == -5));
    CHECK(solve(3*x+x+2*x==90) == 15);
    CHECK(solve(x*2==7) == 3.5);
    CHECK(solve(3*x-x*2==15) == 15);
    CHECK(solve(3*x+x+2*x-x==90) == 18);
    CHECK(solve(x*3*x-2==10) == 2);
    CHECK(solve(32*x==6) == 0.1875);
}

TEST_CASE("Test / RealVariable") {
    CHECK(solve(x/1==7.5) == 7.5);
    CHECK(solve(x/6==10) == 60);
    CHECK(solve(x/6==0) == 0);
    CHECK(solve(x/2==7.5) == 15);
    CHECK(solve(x/6==1) == 6);
    CHECK(solve(x/10/2/5/4==0.25) == 100);
    CHECK(solve(20*x/5+x/3==26) == 6);
    CHECK(solve(x/10/5+3*x/3==102) == 100);
}

TEST_CASE("Test ^ RealVariable") {
    CHECK(solve((x^2)==0) == 0);
    CHECK((solve((x^2)+(x^2)+(x^2) == 12) == 2 || solve((x^2)+(x^2)+(x^2)==123) == -2));
    CHECK((solve((x^2)==2*x) == 2 || solve((x^2)==2*x) == 0));
    CHECK(solve(((x^2)-4-x*x)==2*x) == -2);
    CHECK((solve((4*(x^2)+4*x)==0) == -1 || solve((4*(x^2)+4*x)==0) == 0));    
    CHECK(solve(2*(x^2)-4*x+2==0) == 1);
    CHECK(solve((3*(x+5))==21) == 2);
    CHECK((solve((8*(x^2)-5*x-2)==(x^2)-2*x+2) == 1 || solve((8*(x^2)-5*x-2)==(x^2)-2*x+2) == -1));
    CHECK((solve((x^2)==4) == 2 || solve((x^2)==4) == -2));    
    CHECK((solve(-(x^2)-x+2==0) == 1 || solve(-(x^2)-x+2==0) == -2));
    CHECK((solve((x^2)+x+2==22.91) == 4.1 || solve((x^2)+x+2==22.91) == -5.1));
    CHECK(solve(1+x+(x^2)-x*x*3+10*(x^2)/5+9==0) == -10);
}

TEST_CASE("Test equasion correctness - RealVariable") {
    CHECK_THROWS(solve(x*x*x==0));
    CHECK_THROWS(solve((x^2^2)==0));
    CHECK_THROWS(solve((x^(-1))==0));
    CHECK_THROWS(solve((x^1.5)==0));
    CHECK_THROWS(solve((x^2.5)==0));
    CHECK_THROWS(solve((x^-5)==0));
    CHECK_THROWS(solve((x^4)==0));
    CHECK_THROWS(solve((x^20)==0));
    CHECK_THROWS(solve((x^1.25)==0));
    CHECK_THROWS(solve((x^3)==0));
    CHECK_THROWS(solve((x^2)/0==-2));
    CHECK_THROWS(solve((x^2)==-2));
    CHECK_THROWS(solve((x^2)==-5));
    CHECK_THROWS(solve(2+(x^2)/0==-2));
    CHECK_THROWS(solve((x^2)+5==-2));
    CHECK_THROWS(solve((x^2)*x==-5));
    CHECK_THROWS(solve((x^2)+5*x*x+7==-2));
    CHECK_THROWS(solve((x^2)+5*x+7==-2));
    CHECK_THROWS(solve((x^2)+4*x+7==-2));
    CHECK_THROWS(solve((x^2)+x+1.67==0));
}

/*---------------------------------------------------------------------*/

TEST_CASE("Test + ComplexVariable") {
    CHECK(solve(y+2==7) == complex<double>(5,0));
    CHECK(solve(2.5+y==6.7) == complex<double>(4.2,0));
    CHECK(solve(2.0+1.5i+y+y==9) == complex<double>(3.5,-0.75));
    CHECK(solve(y+5+2i==8) == complex<double>(3,-2));
}

TEST_CASE("Test - - ComplexVariable") {
    CHECK(solve(y-2==7) == complex<double>(9,0));
    CHECK(solve(2.5-y==6.7) == complex<double>(-4.2,0));
    CHECK(solve(2.0-1.5i-y-y==9) == complex<double>(-3.5,-0.75));
    CHECK(solve(-y-2-5i==8) == complex<double>(-10,-5));
}

TEST_CASE("Test * - ComplexVariable") {
    CHECK(solve(y*2==7) == complex<double>(3.5,0));
    CHECK(solve(3*y*y*2==150) == complex<double>(5,0));
    CHECK(solve(3*y+y+2*y==90) == complex<double>(15,0));
    CHECK(solve(y*3*y-2==10) == complex<double>(2,0));
    CHECK(solve(y*2+5.2i==7) == complex<double>(3.5,-2.6));
    CHECK(solve(2.5*y+0.5i==6.7) == complex<double>(2.68,-0.2));
    CHECK(solve(-y*2-2.5i==8) == complex<double>(-4,-1.25));
}

TEST_CASE("Test / - ComplexVariable") {
    CHECK(solve(y/2==7.5) == complex<double>(15,0));
    CHECK(solve(20*y/5+y/3==26) == complex<double>(6,0));
    CHECK(solve(y/10/5+3*y/3==102) == complex<double>(100,0));
    CHECK(solve(10*y/10+3*y/3+5i==50+125) == complex<double>(87.5,-2.5));
}

TEST_CASE("Test ^ - ComplexVariable") {
    CHECK(solve((y^2)==0) == complex<double>(0,0));
    CHECK((solve((y^2)==4) == complex<double>(-2,0) || solve((y^2)==4) == complex<double>(2,0)));    
    CHECK((solve((y^2)+y+2==22.91) == complex<double>(4.1,0) || solve((y^2)+y+2==22.91) == complex<double>(-5.1,0)));
    CHECK(solve(1+y+(y^2)-y*y*3+10*(y^2)/5+9==0) == complex<double>(-10,0));
}

TEST_CASE("Test equasion correctness - ComplexVariable") {
    CHECK_THROWS(solve(y*y*y==0));
    CHECK_THROWS(solve((y^2^2)==0));
    CHECK_THROWS(solve((y^(-1))==0));
    CHECK_THROWS(solve((y^1.5)==0));
    CHECK_THROWS(solve((y^2.5)==0));
    CHECK_THROWS(solve((y^-5)==0));
    CHECK_THROWS(solve((y^4)==0));
    CHECK_THROWS(solve((y^20)==0));
    CHECK_THROWS(solve((y^1.25)==0));
    CHECK_THROWS(solve((y^3)==0));
    CHECK_THROWS(solve((y^2)/0==-2));
    CHECK_THROWS(solve(2+(y^2)/0==-2));
    CHECK_THROWS(solve((y^2)*y==-5));
}