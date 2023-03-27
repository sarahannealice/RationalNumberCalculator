//
// Created by sarah on 25/03/2023.
//

#include "../inc/rational.h"

using namespace std;

int main() {
    string input;
    int cont;
    bool loopProgram = true;

    while (loopProgram) {
        //taking user input
        cout << "enter a rational number: ";
        cin >> input;
        Rational rn1(input);

        cout << "enter a second rational number: ";
        cin >> input;
        Rational rn2(input);

        cout << "your inputted values were [1]" << rn1 << " [2]" << rn2 << endl;

        cout << "math operations overloaded demonstration" << endl;


        //end of loop question
        cout << "\nwould you like to continue? [1]yes [3]no" << endl;
        cin >> cont;

        if (cont == 1) {
            continue;
        } else if (cont == 3) {
            //breaks while loop
            cout << "ending program";
            loopProgram = false;
        } else {
            cout << "invalid input. assuming you'd like to continue\n" << endl;
        }
    }//end program loop

    return 0;
}//end main method
