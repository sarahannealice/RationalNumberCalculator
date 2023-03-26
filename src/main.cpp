//
// Created by sarah on 25/03/2023.
//
#include <iostream>

using namespace std;

int main() {
    string firstNum;
    string secNum;
    int cont;
    bool loopProgram = true;

    while (loopProgram) {
        //taking user input
        cout << "enter a rational number: ";
        cin >> firstNum;

        cout << "enter a second rational number: ";
        cin >> secNum;

        cout << "first: " << firstNum << endl;
        cout << "second: " << secNum << endl;

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
