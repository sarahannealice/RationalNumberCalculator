//
// Created by sarah on 25/03/2023.
//

#ifndef RATIONALNUMBERCALCULATOR_RATIONAL_H
#define RATIONALNUMBERCALCULATOR_RATIONAL_H

#include <string>
#include <sstream>
#include <iostream>
#include <regex>

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
    Rational reduceFraction(Rational& fraction);

    //overloaded math operators
    Rational operator+(Rational& rn) const;
    Rational operator-(Rational& rn) const;
    Rational operator*(Rational& rn) const;
    Rational operator/(Rational& rn) const;

    //overloaded comparison operators
    bool operator>(Rational& rn);
    bool operator<(Rational& rn);
    bool operator==(Rational& rn);

    //friend function
    friend ostream& operator<<(ostream& stream, const Rational &rn);
};

#endif //RATIONALNUMBERCALCULATOR_RATIONAL_H
