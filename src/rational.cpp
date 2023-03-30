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
    denominator = 1;
}

//one arg constructor
Rational::Rational(int num) {
    cout << "---one argument constructor called---" << endl;

    numerator = num;
    denominator = 1;
}

//two arg constructor
Rational::Rational(int num, int den) {
    cout << "---two argument constructor called---" << endl;

    numerator = num;
    denominator = den;
}

//string constructor
Rational::Rational(const string& number) {
    cout << "---string constructor called---" << endl;
    vector<int> fraction;

    //to see if rational or not -- https://stackoverflow.com/a/43629706
    if (number.find('/') != string::npos) {//check if string contains '/' (no substring found = npos)
        fraction = getFraction(number);

        numerator = fraction[0];
        denominator = fraction[1];
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
vector<int> Rational::getFraction(const string& input) {
    vector<int> fraction;
    stringstream stream(input);
    char delimiter = '/';
    string token;

    //splits a string using a delimiter and adds to vector accordingly
    while (getline(stream, token, delimiter)) {
        fraction.push_back(stoi(token));
    }

    return fraction;
}//end of string parsing method

//normalizing method
Rational Rational::reduceFraction(Rational &fraction) {
    int lesserNum;
    int gcd = 1;

    //checks which number is smaller
    if (fraction.numerator > fraction.denominator) {
        lesserNum = fraction.numerator;
    } else {
        lesserNum = fraction.denominator;
    }

    //checks all ints between 2 and the smallest of the numerator/denominator (inclusively) for greatest common divisor
    for (int i = 2; i <= lesserNum; i++) {
        if (fraction.numerator%i == 0 && fraction.denominator%i == 0) {
            gcd = i;
        }
    }

    //calculations using gcd
    fraction.numerator /= gcd;
    fraction.denominator /= gcd;

    //if statement to account for negative whole numbers in fraction form
    if ((fraction.numerator < 0 || fraction.denominator < 0) && !(fraction.numerator < 0 && fraction.denominator < 0)) {
        if (fraction.numerator < 0) {
            if ((fraction.numerator * -1) == fraction.denominator) {
                fraction.numerator *= -1;
                fraction.denominator = 1;
            }
        } else if (fraction.denominator < 0) {
            if (fraction.numerator == (fraction.denominator * -1)) {
                fraction.numerator = -1;
                fraction.denominator = 1;
            }
        }
    }

    return fraction;
}//end of reduce method


//----------math functions----------// >>returns a reduced rational number
Rational Rational::operator+(Rational &rn) const {
    Rational answer;

    answer.numerator = (this->numerator * rn.denominator) + (this->denominator * rn.numerator);
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced
    reduceFraction(answer);

    //accounting for negative denominator
    if (answer.denominator < 0) {
        answer.numerator *= -1;
        answer.denominator *= -1;
    }

    //if statement to normalize fraction if numerator is greater than denominator
    if (answer.numerator > answer.denominator && answer.numerator%answer.denominator != 0) {
        if (answer.numerator < 0) {
            cout << answer.numerator / answer.denominator << " " << (answer.numerator % answer.denominator) * -1 << "/"
                 << answer.denominator << " or ";
        } else {
            cout << answer.numerator / answer.denominator << " " << answer.numerator % answer.denominator << "/"
                 << answer.denominator << " or ";
        }
    }

    return answer;
}

Rational Rational::operator-(Rational &rn) const {
    Rational answer;

    answer.numerator = (this->numerator * rn.denominator) - (this->denominator * rn.numerator);
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced
    reduceFraction(answer);

    //accounting for negative denominator
    if (answer.denominator < 0) {
        answer.numerator *= -1;
        answer.denominator *= -1;
    }

    //if statement to normalize fraction if numerator is greater than denominator
    if (answer.numerator > answer.denominator && answer.numerator%answer.denominator != 0) {
        if (answer.numerator < 0) {
            cout << answer.numerator / answer.denominator << " " << (answer.numerator % answer.denominator) * -1 << "/"
                 << answer.denominator << " or ";
        } else {
            cout << answer.numerator / answer.denominator << " " << answer.numerator % answer.denominator << "/"
                 << answer.denominator << " or ";
        }
    }

    return answer;
}

Rational Rational::operator*(Rational &rn) const {
    Rational answer;

    answer.numerator = this->numerator * rn.numerator;
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced
    reduceFraction(answer);

    //accounting for negative denominator
    if (answer.denominator < 0) {
        answer.numerator *= -1;
        answer.denominator *= -1;
    }

    //if statement to normalize fraction if numerator is greater than denominator
    if (answer.numerator > answer.denominator && answer.numerator%answer.denominator != 0) {
        if (answer.numerator < 0) {
            cout << answer.numerator / answer.denominator << " " << (answer.numerator % answer.denominator) * -1 << "/"
                 << answer.denominator << " or ";
        } else {
            cout << answer.numerator / answer.denominator << " " << answer.numerator % answer.denominator << "/"
                 << answer.denominator << " or ";
        }
    }

    return answer;
}

Rational Rational::operator/(Rational &rn) const {
    Rational answer;

    answer.numerator = this->numerator * rn.denominator;
    answer.denominator = this->denominator * rn.numerator;

    //send to be reduced
    reduceFraction(answer);

    //accounting for negative denominator
    if (answer.denominator < 0) {
        answer.numerator *= -1;
        answer.denominator *= -1;
    }

    //if statement to normalize fraction if numerator is greater than denominator
    if (answer.numerator > answer.denominator && answer.numerator%answer.denominator != 0) {
        if (answer.numerator < 0) {
            cout << (answer.numerator / answer.denominator)*-1 << " " << (answer.numerator % answer.denominator) * -1 << "/"
                 << answer.denominator << " or ";
        } else {
            cout << answer.numerator / answer.denominator << " " << answer.numerator % answer.denominator << "/"
                 << answer.denominator << " or ";
        }
    }

    return answer;
}

//----------comparison functions----------//
bool Rational::operator>(Rational &rn) const {
    //convert to double to account for decimals
    double first = (double)this->numerator/(double)this->denominator;
    double second = (double)rn.numerator/(double)rn.denominator;

    if (first > second) {
        return true;
    } else {
        return false;
    }
}

bool Rational::operator<(Rational &rn) const {
    //convert to double to account for decimals
    double first = (double)this->numerator/(double)this->denominator;
    double second = (double)rn.numerator/(double)rn.denominator;

    if (first < second) {
        return true;
    } else {
        return false;
    }
}

bool Rational::operator==(Rational &rn) const {
    //convert to double to account for decimals
    double first = (double)this->numerator/(double)this->denominator;
    double second = (double)rn.numerator/(double)rn.denominator;

    if (first == second) {
        return true;
    } else {
        return false;
    }
}


//----------friend function----------//
ostream &operator<<(ostream &stream, const Rational &rn) {
    //if statement to check what to send to stream when using '<<' and Rational objects
    if (rn.numerator == rn.denominator) {
        stream << 1;
    } else if (rn.numerator == 0) {
        stream << 0;
    } else if (rn.denominator == 1) {
        stream << rn.numerator;
    } else {
        stream << rn.numerator << "/" << rn.denominator;
    }

    return stream;
}