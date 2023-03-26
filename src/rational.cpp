//
// Created by sarah on 25/03/2023.
//
#include <iostream>
#include <string>

#include "../inc/rational.h"

using namespace std;

//----------constructors & destructor----------//
//default constructor
Rational::Rational() {
    cout << "---default constructor called---" << endl;

    numerator = 0;
    denominator = 0;
}

//one arg constructor
Rational::Rational(int num) {
    cout << "---one argument constructor called---" << endl;

    numerator = num;
    denominator = 1;
}

//two arg constructor
Rational::Rational(int num, int denom) {
    cout << "---two argument constructor called---" << endl;

    numerator = num;
    denominator = denom;
}

//string constructor
Rational::Rational(string number) {
cout << "---string constructor called---" << endl;

numerator = stoi(number);
//to-do: split string into numerator and denominator
denominator = 1;
}

//destructor
Rational::~Rational() {
    cout << "---destructor called---" << endl;
}



//friend function
ostream &operator<<(ostream &stream, const Rational &rn) {
    if (rn.numerator == rn.denominator) {
        cout << 1;
    } else if (rn.numerator == 0) {
        cout << 0;
    } else if (rn.denominator == 1) {
        cout << rn.numerator;
    } else {
        cout << rn.numerator << "/" << rn.denominator;
    }
}