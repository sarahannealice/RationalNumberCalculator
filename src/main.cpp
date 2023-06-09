//
// Created by sarah on 25/03/2023.
//

#include "../inc/rational.h"

using namespace std;

int main() {
    string input;
    string cont;
    int tempNum = 2;
    int tempDen = 5;
    bool loopProgram = true;
    bool  invalid = true;
    //number-fraction regex
    //https://learn.microsoft.com/en-us/cpp/standard-library/regular-expressions-cpp?view=msvc-170
    //https://stackoverflow.com/a/19329838
    regex validNum (R"(-?\d+(([/]-?[1-9])([0-9]?+))*)");//does not accept a zero denominator

    cout << "*• welcome to the rational number calculator •*" << endl;

    while (loopProgram) {
        //taking user input
        cout << "\nenter a rational number: ";
        cin >> input;

        while (invalid) {
            if (!regex_match(input, validNum)) {
                cout << "enter a number (whole or fraction [without a 0 denominator])" << endl;
                cin >> input;
            } else {
                invalid = false;
            }
        }
        Rational rn1(input);

        cout << "enter a second rational number: ";
        cin >> input;
        invalid = true;//resetting for second number input

        while (invalid) {
            if (!regex_match(input, validNum)) {
                cout << "enter a number (whole or fraction [without a 0 denominator])" << endl;
                cin >> input;
            } else {
                invalid = false;
            }
        }
        Rational rn2(input);

        cout << "your inputted values were " << rn1 << " & " << rn2 << endl;
        cout << "\n---------------------------------------------" << endl;
        cout << "demonstrating math operation overloaded" << endl;

        cout << endl << rn1 << " + " << rn2 << " = " << endl << rn1 + rn2 << endl;
        cout << endl << rn1 << " - " << rn2 << " = " << endl << rn1 - rn2 << endl;
        cout << endl << rn1 << " * " << rn2 << " = " << endl << rn1 * rn2 << endl;
        cout << endl << rn1 << " / " << rn2 << " = " << endl << rn1 / rn2 << endl;

        cout << "\n---------------------------------------------" << endl;
        cout << "demonstrating comparison operator overloads" << endl;
        cout << rn1 << " > " << rn2 << " -> ";

        if ((rn1 > rn2) == 1) {
            cout << "true" << endl;
        } else if ((rn1 > rn2) == 0){
            cout << "false" << endl;
        }

        cout << rn1 << " < " << rn2 << " -> ";
        if ((rn1 < rn2) == 1) {
            cout << "true" << endl;
        } else if ((rn1 < rn2) == 0) {
            cout << "false" << endl;
        }

        cout << rn1 << " == " << rn2 << " -> ";
        if ((rn1 == rn2) == 1) {
            cout << "true" << endl;
        } else if ((rn1 == rn2) == 0) {
            cout << "false" << endl;
        }

        cout << "\n---------------------------------------------" << endl;
        cout << "demonstrating additional constructors" << endl;
        cout << "(the example arguments will be " << tempNum << " and " << tempDen << ")" << endl << endl;

        Rational demo1(tempNum);
        cout << "numerator: " << demo1.numerator << endl;
        cout << "denominator: " << demo1.denominator << endl << endl;

        Rational demo2(tempNum, tempDen);
        cout << "numerator: " << demo2.numerator << endl;
        cout << "denominator: " << demo2.denominator << endl << endl;


        //end of loop question
        cout << "\nwould you like to continue? [1]yes [3]no" << endl;
        cin >> cont;

        if (cont == "1") {
            continue;
        } else if (cont == "3") {
            //breaks while loop
            cout << "ending program\n";
            loopProgram = false;
        } else {
            cout << "invalid input. assuming you'd like to stop\n" << endl;
            loopProgram = false;
        }
    }//end program loop

    return 0;
}//end main method
