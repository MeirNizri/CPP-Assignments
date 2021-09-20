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

#pragma once
#include <complex>

using namespace std;
namespace solver {
    
    class RealVariable {
		double a;
		double b;
		double c;
	public:
		RealVariable();
        RealVariable(double a, double b, double c);

        friend RealVariable operator+(const RealVariable& r, const double& d);        
        friend RealVariable operator+(const double& d, const RealVariable& r);
        friend RealVariable operator+(const RealVariable& r1, const RealVariable& r2);

        friend RealVariable operator-(const RealVariable& r);
        friend RealVariable operator-(const RealVariable& r, const double& d);
        friend RealVariable operator-(const double& d, const RealVariable& r);
        friend RealVariable operator-(const RealVariable& r1, const RealVariable& r2);

        friend RealVariable operator*(const RealVariable& r, const double& d);        
        friend RealVariable operator*(const double& d, const RealVariable& r);
        friend RealVariable operator*(const RealVariable& r1, const RealVariable& r2);
        
        friend RealVariable operator/(const RealVariable& r, const double& d);

        friend RealVariable operator^(const RealVariable& r, const double& n);

        friend double operator==(const RealVariable& r, const double& d);    
        friend double operator==(const double& d, const RealVariable& r);
        friend double operator==(const RealVariable& r1, const RealVariable& r2);
    };
    
    
    struct ComplexVariable {
		complex<double> a;
		complex<double> b;
		complex<double> c;
	public:
		ComplexVariable();
        ComplexVariable(complex<double> a, complex<double> b, complex<double> c);
        
        friend ComplexVariable operator+(const ComplexVariable& c, const double& d);        
        friend ComplexVariable operator+(const double& d, const ComplexVariable& c);
        friend ComplexVariable operator+(const ComplexVariable& c, const complex<double>& d);        
        friend ComplexVariable operator+(const complex<double>& d, const ComplexVariable& c);
        friend ComplexVariable operator+(const ComplexVariable& c1, const ComplexVariable& c2);

        friend ComplexVariable operator-(const ComplexVariable& c);
        friend ComplexVariable operator-(const ComplexVariable& c, const double& d);
        friend ComplexVariable operator-(const double& d, const ComplexVariable& c);
        friend ComplexVariable operator-(const ComplexVariable& c, const complex<double>& d);        
        friend ComplexVariable operator-(const complex<double>& d, const ComplexVariable& c);
        friend ComplexVariable operator-(const ComplexVariable& c1, const ComplexVariable& c2);

        friend ComplexVariable operator*(const ComplexVariable& c, const double& d);        
        friend ComplexVariable operator*(const double& d, const ComplexVariable& c);
        friend ComplexVariable operator*(const ComplexVariable& c, const complex<double>& d);        
        friend ComplexVariable operator*(const complex<double>& d, const ComplexVariable& c);
        friend ComplexVariable operator*(const ComplexVariable& c1, const ComplexVariable& c2);
        
        friend ComplexVariable operator/(const ComplexVariable& c, const double& d);
        friend ComplexVariable operator/(const ComplexVariable& c, const complex<double>& d);

        friend ComplexVariable operator^(const ComplexVariable& c, const double& n);

        friend complex<double> operator==(const ComplexVariable& c, const double& d);    
        friend complex<double> operator==(const double& d, const ComplexVariable& c);
        friend complex<double> operator==(const ComplexVariable& c, const complex<double>& d);    
        friend complex<double> operator==(const complex<double>& d, const ComplexVariable& c);
        friend complex<double> operator==(const ComplexVariable& c1, const ComplexVariable& c2);
    };
    
    double solve(const double& d);
    complex<double> solve(const complex<double>& c);
}