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
    vector<int> fraction;

    //to see if rational or not -- https://stackoverflow.com/a/43629706
    if (number.find('/') != string::npos) {//check if string contains '/' (no substring found = npos)
        //copying 2 arrays -- https://stackoverflow.com/a/16137997
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

    while (getline(stream, token, delimiter)) {
        fraction.push_back(stoi(token));
    }

    return fraction;
}

Rational Rational::reduceFraction(Rational &fraction) {
    int lesserNum;
    int gcd = 1;

    //checks which number is smaller
    if (fraction.numerator > fraction.denominator) {
        lesserNum = fraction.numerator;
    } else {
        lesserNum = fraction.denominator;
    }

    //checks all ints between 2 and the lesser of the numerator/denominator for greatest common divisor
    for (int i = 2; i < lesserNum; i++) {
        if (fraction.numerator%i == 0 && fraction.denominator%i == 0) {
            gcd = i;
        }
    }

    fraction.numerator /= gcd;
    fraction.denominator /= gcd;

    return fraction;
}


//----------math functions----------// >>returns a reduced rational number
Rational Rational::operator+(Rational &rn) const {
    Rational answer;

    answer.numerator = (this->numerator * rn.denominator) + (this->denominator * rn.numerator);
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced
    reduceFraction(answer);

    if (answer.numerator > answer.denominator) {
        cout << answer.numerator/answer.denominator << " " << answer.numerator%answer.denominator << "/"
        << answer.denominator << " or ";
    }

    return answer;
}

Rational Rational::operator-(Rational &rn) const {
    Rational answer;

    answer.numerator = (this->numerator * rn.denominator) - (this->denominator * rn.numerator);
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced
    reduceFraction(answer);

    return answer;
}

Rational Rational::operator*(Rational &rn) const {
    Rational answer;

    answer.numerator = this->numerator * rn.numerator;
    answer.denominator = this->denominator * rn.denominator;

    //send to be reduced
    reduceFraction(answer);

    return answer;
}

Rational Rational::operator/(Rational &rn) const {
    Rational answer;

    answer.numerator = this->numerator * rn.denominator;
    answer.denominator = this->denominator * rn.numerator;

    //send to be reduced
    reduceFraction(answer);

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