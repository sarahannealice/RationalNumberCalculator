//
// Created by sarah on 25/03/2023.
//

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
    int fraction[2];

    if (true) {//check if string contains '/'
        getFraction(number);
    } else {
        numerator = stoi(number);
        denominator = 1;
    }
}

//destructor
Rational::~Rational() {
    cout << "---destructor called---" << endl;
}

//string parsing method -- https://stackoverflow.com/a/46931770
int *Rational::getFraction(const string& input) {
    static int fraction[2];
    stringstream stream(input);
    char delimiter = '/';
    string token;

    while (getline(stream, token, delimiter)) {
        for (int i = 0; i < sizeof(fraction); i++) {
            fraction[i] = stoi(token);
        }
    }

    return fraction;
}

Rational Rational::reduceFraction(Rational &fraction) {


    return Rational();
}

//----------math functions----------// >>returns a reduced rational number
Rational Rational::operator+(Rational &rn) const {
    Rational answer;

    answer.numerator = (this->numerator * rn.denominator) + (this->denominator * rn.numerator);
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced


    return answer;
}

Rational Rational::operator-(Rational &rn) const {
    Rational answer;

    answer.numerator = (this->numerator * rn.denominator) - (this->denominator * rn.numerator);
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced


    return answer;
}

Rational Rational::operator*(Rational &rn) const {
    Rational answer;

    answer.numerator = this->numerator * rn.numerator;
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced


    return answer;
}

Rational Rational::operator/(Rational &rn) const {
    Rational answer;

    answer.numerator = this->numerator * rn.denominator;
    answer.denominator = this->denominator * rn.numerator;

    //send to be reduced


    return answer;
}

//----------comparison functions----------//
bool Rational::operator>(Rational &rn) {
    return false;
}

bool Rational::operator<(Rational &rn) {
    return false;
}

bool Rational::operator==(Rational &rn) {
    return false;
}


//----------friend function----------//
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