#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*
Bhrugu Setlur, hw01
Decryption text
Opens encrypted text file, reads lines
passes lines into function that decrypts it,
then prints out decrypted text
*/

char decodeChar(char& c, int shift);
void inputString(string& s, int shift);


int main() {
    ifstream inputFile("encrypted.txt");
    if (!inputFile) {
        cout << "File not found" << endl;
    }
    vector <string> all_lines;
    string line;
    int shift;

    inputFile >> shift;

    // put lines in vector
    while (getline(inputFile, line)) { 
        all_lines.push_back(line);
    }

    inputFile.close();
    
    // pass each line into 2nd function
    for (string& s : all_lines) {
        inputString(s,shift);
    }

    // print new lines in reverse order
    for (int index = all_lines.size() - 1; index >= 0; --index) {
        cout << all_lines[index] << endl;
    }
}

// takes in character and shift int and performs
// shift
char decodeChar(char& c, int shift) {
    if (c < 'a' && c != ' ' && c != '.') {
        // shift character in circular method
        for (int step = 1; step <= shift; ++step) {
            c -= 1;
            if (c == '@') {
                c = 'Z';
            }
        }
    }
    return c;
}

// takes in line and shift int
// passes each character into above function
void inputString(string& s, int shift) {
    // pass each character in line to decryption function
    for (char& c : s) {
        c = decodeChar(c, shift);
    }
}

