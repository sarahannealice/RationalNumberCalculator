//
// Created by sarah on 25/03/2023.
//

#ifndef RATIONALNUMBERCALCULATOR_RATIONAL_H
#define RATIONALNUMBERCALCULATOR_RATIONAL_H

#include <string>
#include <sstream>//used for string stream parsing
#include <iostream>
#include <regex>

using namespace std;

class Rational {

//would normally be private
public:
    int numerator;
    int denominator;

public:
    //constructors
    Rational();
    explicit Rational(int num);
    Rational(int num, int den);
    explicit Rational(const string& number);

    //destructor
    ~Rational();

    //string parser -- returning array instead of vector (takes less memory/more efficient)
    //https://www.tutorialspoint.com/difference-between-std-vector-and-std-array-in-cplusplus
    //although it takes less memory, for simplicity's sake I'm using a vector (having memory issues)
    static vector<int> getFraction(const string& input);
    static Rational reduceFraction(Rational& fraction);

    //overloaded math operators
    Rational operator+(Rational& rn) const;
    Rational operator-(Rational& rn) const;
    Rational operator*(Rational& rn) const;
    Rational operator/(Rational& rn) const;

    //overloaded comparison operators
    bool operator>(Rational& rn) const;
    bool operator<(Rational& rn) const;
    bool operator==(Rational& rn) const;

    //friend function
    friend ostream& operator<<(ostream& stream, const Rational &rn);
};

#endif //RATIONALNUMBERCALCULATOR_RATIONAL_H
