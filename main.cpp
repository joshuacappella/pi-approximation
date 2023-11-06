/*
 * Pi Fractional Approximation
 * Joshua Cappella
 * 11/05/2023
 */
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cfloat>
using namespace std;

int main(){
    int digits = 0;
    long double max = 0L;
    long double pi = 3.14159265358979324L;
    long double bestNum = 1L;
    long double bestDen = 1L;
    long double bestDiff = LDBL_MAX;
    long double currDiff = 0L;
    long double approxAns = 0L;
    //input the number of digits permitted in numerator/denominator
    cout << "Input the maximum number of digits desired in the numerator and denominator to obtain your fractional representation of pi:\n";
    cin >> digits;
    if(digits>numeric_limits<long double>::digits10){
        cout << "Number of digits greater than "
        << numeric_limits<long double>::digits10
        << ", results will be inaccurate.\n";
        return 0;
    }
    if(digits<0){
        cout << "A negative number of digits doesn't make sense. Get some sleep.\n";
        return 0;
    }
    if(digits==0){
        cout << "With no digits I can offer no solution.\n";
        return 0;
    }
    cout << "Input digit is: " << digits << endl;
    
    max = (pow(10,digits) - 1);
    cout << "Max numerator/denominator value is: "<< setprecision(numeric_limits<long double>::digits10) << max << endl;
    for(long double denMin = 1L; denMin <= max; denMin++){
        //iterate through all possible denominator values
        for(long double numMin = 1L; numMin <= max; numMin++){
            //iterate through all possible numerator values
            currDiff = abs(pi - (numMin/denMin));
            if(currDiff < bestDiff){
                bestNum = numMin;
                bestDen = denMin;
                bestDiff = abs(pi - (bestNum/bestDen));
            }
        }
    }
    approxAns = bestNum/bestDen;
    cout << "Pi rounded to eighteen digits is: "
    << setprecision(numeric_limits<long double>::digits10) << pi << endl;
    cout << "The most accurate fraction to represent pi using a maximum of " << max
    << " digits in the numerator or the denomintor is: " << bestNum << "/"
    << bestDen << " = " << approxAns << endl;
    return 0;
}