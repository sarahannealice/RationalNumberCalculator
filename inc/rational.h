//
// Created by sarah on 25/03/2023.
//

#ifndef RATIONALNUMBERCALCULATOR_RATIONAL_H
#define RATIONALNUMBERCALCULATOR_RATIONAL_H

#include <string>
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

    //overloaded math operators


    //friend function
    friend ostream& operator<< (ostream& stream, const Rational &rn);
};

#endif //RATIONALNUMBERCALCULATOR_RATIONAL_H
