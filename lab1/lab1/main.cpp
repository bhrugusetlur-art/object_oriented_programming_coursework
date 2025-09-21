/*
  rec01_start.cpp
  fall 2024
*/


//
// main
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
    //std::cout << "Hello" << endl;


    // Task 2  Printing hello ...  Using "using namespace"
    
    //cout << "Hello World" << endl;
    


    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
    
    //int x;
    //cout << "x = " << x << endl;
    

    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.
    
    //cout << "size of int " << sizeof(int) << endl;
    //cout << "size of float " << sizeof(double) << endl;
    //cout << "size of string " << sizeof(string) << endl;


    
    // Task 5  Attempt to assign the wrong type of thing to a variable
    //int x = "Hello";

    //
    // Conditions
    
    //

    // Task 6  Testing for a range
    
//    int y = 15;
//
//    if (y >= 10 && y <= 20) {
//        cout << "True" << endl;
//    }
//    else {
//        cout << "False" << endl;
//    }
    

    

    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
    
//    for (int i = 10; i <= 20; ++i) {
//        cout << i << endl;
//    }

    // Then with a while loop
    
//    int i = 10;
//    while (i <= 20) {
//        cout << i << endl;
//        ++i;
//    }

    // Finally with a do-while loop
//    int i = 10;
//    do {
//        cout << i << endl;
//        ++i;
//    } while (i < 20);
//    
//    cout << i << endl;
//    ++i;
    

    // Task 8  Looping to successfully open a file, asking user for the name
    
    string filename;
    cin >> filename;
    
    ifstream jab(filename);
    while (!jab) {
        cout << "File not found" << endl;
        cin >> filename;
        ifstream jab(filename);
    }
    

    // Task 9  Looping, reading file word by "word".


    // Task 10 Open a file of integers, read it in, and display the sum.


    // Task 11 Open and read a file of integers and words. Display the sum.


    //
    // Vectors
    //

    // Task 12 Filling a vector of ints

    
    // Task 13 Displaying the vector THREE times
    //         a) using the indices,

    //         b) using a "ranged for"

    //         c) using indices again but backwards


    // Task 14. Initialize a vector with the primes less than 20.

    
} // main

