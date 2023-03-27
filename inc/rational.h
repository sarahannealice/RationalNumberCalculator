//
// Created by sarah on 25/03/2023.
//

#ifndef RATIONALNUMBERCALCULATOR_RATIONAL_H
#define RATIONALNUMBERCALCULATOR_RATIONAL_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Rational {

private:
    int numerator;
    int denominator;

public:
    //constructors
    Rational();
    explicit Rational(int num);
    Rational(int num, int denom);
    explicit Rational(string number);

    //destructor
    ~Rational();

    //string parser -- returning array instead of vector (takes less memory/more efficient)
    //https://www.tutorialspoint.com/difference-between-std-vector-and-std-array-in-cplusplus
    static int * getFraction(const string& input);


    //overloaded math operators


    //friend function
    friend ostream& operator<< (ostream& stream, const Rational &rn);
};

#endif //RATIONALNUMBERCALCULATOR_RATIONAL_H
