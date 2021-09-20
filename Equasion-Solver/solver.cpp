/**
 * This class represents a equation solver. The equation can 
 * be with a one real variable or one complex variable at most. 
 * The equations are up to rank 2 at most.
 * The equasion can include the next opertators: +,-,*,\,^,==, and also 'i' in the complex variable.
 * 
 * Author: Meir Nizri
 * Third assignment in cpp course
 * Date: 2020-04
 */

#include "solver.hpp"
#include <stdexcept>
#include <complex>
#include <cmath>

using namespace std;
using namespace solver;

// Constructors
RealVariable::RealVariable(){
    a = c = 0;
    b = 1;
}
RealVariable::RealVariable(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

// Operator '+'
RealVariable solver::operator+(const RealVariable& r, const double& d) {
    return RealVariable(r.a, r.b, r.c+d);
}
RealVariable solver::operator+(const double& d, const RealVariable& r) {
    return (r + d);
}
RealVariable solver::operator+(const RealVariable& r1, const RealVariable& r2) {
    return RealVariable(r1.a+r2.a, r1.b+r2.b, r1.c+r2.c);;
}

// Operator '-'
RealVariable solver::operator-(const RealVariable& r) {
    return RealVariable(-r.a, -r.b, -r.c);
}
RealVariable solver::operator-(const RealVariable& r, const double& d) {
    return RealVariable(r.a, r.b, r.c-d);
}
RealVariable solver::operator-(const double& d, const RealVariable& r) {
    return RealVariable(-r.a, -r.b, -r.c+d);
}
RealVariable solver::operator-(const RealVariable& r1, const RealVariable& r2) {
    return RealVariable(r1.a-r2.a, r1.b-r2.b, r1.c-r2.c);
}

// Operator '*'
RealVariable solver::operator*(const RealVariable& r, const double& d) {
    return RealVariable(r.a*d, r.b*d, r.c*d);
}
RealVariable solver::operator*(const double& d, const RealVariable& r) {
    return (r * d);
}
RealVariable solver::operator*(const RealVariable& r1, const RealVariable& r2) {
    if (r1.a*r2.a!=0 || r1.a*r2.b!=0 || r1.b*r2.a!=0)
        throw std::runtime_error("Multiply will outputs polynom with degree > 2");
    return RealVariable(r1.b*r2.b, r1.b*r2.c + r1.c*r2.b, r1.c*r2.c);
}

// Operator '/'
RealVariable solver::operator/(const RealVariable& r, const double& d) {
    if (d == 0) throw std::runtime_error("Can't divide by zero");
    return RealVariable(r.a/d, r.b/d, r.c/d);
}

// Operator '^'
RealVariable solver::operator^(const RealVariable& r, const double& n) {
    if (n == 0) return RealVariable(0, 0, 1);
    else if (n == 1) return RealVariable(r.a, r.b, r.c);
    else if(n == 2) {
        if (r.a != 0) throw std::runtime_error("Exponentiation will outputs polynom with degree > 2");
        return RealVariable(r.b*r.b, r.b*2*r.c, r.c*r.c);
    }
    else throw std::runtime_error("Exponentiation will outputs polynom with degree > 2");
    return RealVariable();
}

// Operator '=='
double solver::operator==(const RealVariable& r, const double& d) {
    RealVariable res = r-d;
    double ans;
    if (res.a != 0) { // rank 2 equasion. use quadratic equasion to find x
        const double& discriminant = res.b*res.b - 4*res.a*res.c;
        if (discriminant < 0) throw std::runtime_error("There is no real solution");
        ans = (-res.b + sqrt(discriminant)) / (2*res.a);
    }
    else if (res.b != 0)  ans = (-res.c)/res.b;
    else if (res.c == 0)  ans = 0;
    else throw std::runtime_error("Invalid equation");
    return ans;
}
double solver::operator==(const double& d, const RealVariable& r) {
    return (r == d);
}
double solver::operator==(const RealVariable& r1, const RealVariable& r2) {
    RealVariable res = r1-r2;
    return (res == 0);
}

/*---------------------------------------------------------------------------------------------------*/

// Constructors
ComplexVariable::ComplexVariable() {
    a = c = 0;
    b = 1;
}
ComplexVariable::ComplexVariable(complex<double> a, complex<double> b, complex<double> c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
const complex<double> zero {0,0}; // t

// Operator '+'
ComplexVariable solver::operator+(const ComplexVariable& c, const double& d) {
    return ComplexVariable(c.a, c.b, c.c+d);
}
ComplexVariable solver::operator+(const double& d, const ComplexVariable& c) {
    return (c + d);
}
ComplexVariable solver::operator+(const ComplexVariable& c, const complex<double>& d) {
    return ComplexVariable(c.a, c.b, c.c+d);
}
ComplexVariable solver::operator+(const complex<double>& d, const ComplexVariable& c) {
    return (c + d);
}
ComplexVariable solver::operator+(const ComplexVariable& c1, const ComplexVariable& c2) {
    return ComplexVariable(c1.a+c2.a, c1.b+c2.b, c1.c+c2.c);;
}

// Operator '-'
ComplexVariable solver::operator-(const ComplexVariable& c) {
    return ComplexVariable(-c.a, -c.b, -c.c);
}
ComplexVariable solver::operator-(const ComplexVariable& c, const double& d) {
    return ComplexVariable(c.a, c.b, c.c-d);
}
ComplexVariable solver::operator-(const double& d, const ComplexVariable& c) {
    return ComplexVariable(-c.a, -c.b, -c.c+d);
}
ComplexVariable solver::operator-(const ComplexVariable& c, const complex<double>& d) {
    return ComplexVariable(c.a, c.b, c.c-d);
}
ComplexVariable solver::operator-(const complex<double>& d, const ComplexVariable& c) {
    return ComplexVariable(-c.a, -c.b, -c.c+d);
}
ComplexVariable solver::operator-(const ComplexVariable& c1, const ComplexVariable& c2) {
    return ComplexVariable(c1.a-c2.a, c1.b-c2.b, c1.c-c2.c);
}

// Operator '*'
ComplexVariable solver::operator*(const ComplexVariable& c, const double& d) {
    return ComplexVariable(c.a*d, c.b*d, c.c*d);
}
ComplexVariable solver::operator*(const double& d, const ComplexVariable& c) {
    return (c * d);
}
ComplexVariable solver::operator*(const ComplexVariable& c, const complex<double>& d) {
    return ComplexVariable(c.a*d, c.b*d, c.c*d);
}
ComplexVariable solver::operator*(const complex<double>& d, const ComplexVariable& c) {
    return (c * d);
}
ComplexVariable solver::operator*(const ComplexVariable& c1, const ComplexVariable& c2) {
    if (c1.a*c2.a!=zero || c1.a*c2.b!=zero || c1.b*c2.a!=zero)
        throw std::runtime_error("Multiply will outputs polynom with degree > 2");
    return ComplexVariable(c1.b*c2.b, c1.b*c2.c + c1.c*c2.b, c1.c*c2.c);
}

// Operator '/'
ComplexVariable solver::operator/(const ComplexVariable& c, const double& d) {
    if (d == 0) throw std::runtime_error("Can't divide by zero");
    return ComplexVariable(c.a/d, c.b/d, c.c/d);
}
ComplexVariable solver::operator/(const ComplexVariable& c, const complex<double>& d) {
    if (d == zero) throw std::runtime_error("Can't divide by zero");
    return ComplexVariable(c.a/d, c.b/d, c.c/d);
}

// Operator '^'
ComplexVariable solver::operator^(const ComplexVariable& c, const double& n) {
    if (n == 0) return ComplexVariable(zero, zero, complex<double>(1,0));
    else if (n == 1) return ComplexVariable(c.a, c.b, c.c);
    else if (n == 2) {
        if (c.a != zero) throw std::runtime_error("Exponentiation will outputs polynom with degree > 2");
        return ComplexVariable(c.b*c.b, c.b*2.0*c.c, c.c*c.c);
    }
    throw std::runtime_error("Exponentiation will outputs polynom with degree > 2");
    return ComplexVariable();
}

// Operator '=='
complex<double> solver::operator==(const ComplexVariable& c, const double& d) {
    ComplexVariable res = c-d;
    complex<double> ans;
    if (res.a != zero) ans = ((-res.b + sqrt(res.b*res.b - 4.0*res.a*res.c)) / (2.0*res.a));
    else if (res.b != zero)  ans = (-res.c)/c.b;
    else if (res.c == zero)  ans = zero;
    else throw std::runtime_error("Invalid equation");
    return ans;
}
complex<double> solver::operator==(const double& d, const ComplexVariable& c) {
    return (c == d);
}
complex<double> solver::operator==(const ComplexVariable& c, const complex<double>& d) {
    ComplexVariable res = c-d;
    return (res == 0);
}
complex<double> solver::operator==(const complex<double>& d, const ComplexVariable& c) {
    return (c == d);
}
complex<double> solver::operator==(const ComplexVariable& c1, const ComplexVariable& c2) {
    ComplexVariable res = c1-c2;
    return (res == 0);
}

// Contains the equation. Get the solution from the operator '=='' and return it
double solver::solve(const double& d) {
    return d;
}
complex<double> solver::solve(const complex<double>& d) {
    return d;
}