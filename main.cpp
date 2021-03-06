//Math 151A
//Richard Chung
//Code for Composite Midpoint Rule
//Written in C++

#include <iostream>
#include <cmath>
#include <iomanip>

long double function(double x);
long double composed_midpoint(double p0, double tol, double n);

long double function(double x){

    long double ln = log(x);
    long double gx = x*ln;
    
      return gx;
}

long double composed_midpoint(double a, double b, double n){
    long double h = (b-a)/n;
    long double output = 0.0;
    
    for (int i = 1; i <= n/2 ; i++){
        long double x_mid = a+(2.0*i-1)*h;
        output = output+2*h*function(x_mid);
    }
    return output;
}

long double actual_error(long double approx){
    //long double exact = 0.5*pow(2,2)*log(2)-pow(2,2)/4 - (0.5*pow(1,2)*log(1)-pow(1,2)/4);
    long double exact =(8.0*log(2.0)-3.0)/4.0;
    long double error = exact - approx;
    return abs(error);
}

int main() {
    long double a = 1.0;
    long double b = 2.0;
    long double n = 40826.0;
    
    long double approx = composed_midpoint(a, b, n);
    
    std::cout << std::setprecision(12) << approx <<  std::endl;
    
    std::cout << actual_error(approx) << std::endl;
}
