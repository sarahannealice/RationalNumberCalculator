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
    //default constructor
    Rational() {
        cout << "---default constructor called---" << endl;

        numerator = 0;
        denominator = 0;
    }

    //one arg constructor
    explicit Rational(int num) {
        cout << "---one argument constructor called---" << endl;

        numerator = num;
        denominator = 1;
    }

    //two arg constructor
    Rational(int num, int denom) {
        cout << "---two argument constructor called---" << endl;

        numerator = num;
        denominator = denom;
    }

    /* -- figure out how to handle a string argument
    //string constructor
    Rational(string number) {
        cout << "---string constructor called---" << endl;


    }
     */
};

#endif //RATIONALNUMBERCALCULATOR_RATIONAL_H
