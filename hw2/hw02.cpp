#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/*
Bhrugu Setlur hw02
Warrior game; reads commands from file
executes commands using 5 functions
displays results
*/

struct Warrior {
    string name;
    int strength;
};

Warrior& findWarrior(vector<Warrior>& warriors, string warr_name);
void status(const vector<Warrior>& warriors);
bool checkExistence(const vector<Warrior>& warriors, string name);
void new_warrior(vector<Warrior>& warriors, string name, int strength);
void battle(Warrior& warr1, Warrior& warr2);


int main() {
    ifstream inputStream("warriors.txt");
    if (!inputStream) {
        cout << "File not found!" << endl;
        exit(1);
    }

    vector<Warrior> warriors;
    string word;

    // reads words from file and determines which function to call
    // depending on first word of each line
    while (inputStream >> word) {
        if (word == "Warrior") {
            inputStream >> word;
            string name = word;
            int strength;
            inputStream >> strength;
            new_warrior(warriors, name, strength);
        }
        else if (word == "Status") {
            status(warriors);
        }
        else {
            string name1;
            inputStream >> name1;
            string name2;
            inputStream >> name2;

            Warrior& warr1 = findWarrior(warriors, name1);
            Warrior& warr2 = findWarrior(warriors, name2);
            battle(warr1, warr2);
        }

    }
    inputStream.close();
}

// takes in vector of existing warriors and name of a warrior
// if warrior exists, returns warrior with that name, else raises error
Warrior& findWarrior(vector<Warrior>& warriors, string warr_name) { 
    
    // finds warrior based on name passed in function
    for (Warrior& warr : warriors) {
        if (warr.name == warr_name) {
            return warr;
            // return reference value instead of const ref b/c returned val
            // gets modified
        }
    }
    cerr << "Warrior not found" << endl;
}

// takes in vector of all warriors and displays all warriors in vector
void status(const vector<Warrior>& warriors) {
    int num_of_warr = warriors.size();
    cout << "There are: " << num_of_warr << " warriors" << endl;
    
    // displays all warriors
    for (const Warrior& warr : warriors) {
        cout << "Warrior: " << warr.name << ", strength: " << warr.strength << endl;
    }
}

// takes in vector of warriors and a name
// checks if a warrior with that name exists in vector
bool checkExistence(const vector<Warrior>& warriors, string name) {
    
    // checks if warrior exists
    for (const Warrior& warr : warriors) {
        if (warr.name == name) {
            return true;
        }
    }
    return false;
}

// takes in vector of warriors, warrior name and strength
// creates new Warrior object and add it to vector
void new_warrior(vector<Warrior>& warriors, string name, int strength) {

    // check if warrior already exists
    if (checkExistence(warriors, name)) {
        cout << "Warrior already exists" << endl;
    }
    else {
        Warrior new_warr;
        new_warr.name = name;
        new_warr.strength = strength;
        warriors.push_back(new_warr);
    }
}

// takes in 2 Warrior objects
// modifies strength of each based on outcome of battle
void battle(Warrior& warr1, Warrior& warr2) {
    cout << warr1.name << " battles " << warr2.name << endl;

    if (warr1.strength > warr2.strength) {
        if (warr2.strength == 0) {
            cout << "They're dead, " << warr1.name << endl;
        }

        cout << warr1.name << " defeats " << warr2.name << endl;
        warr1.strength -= warr2.strength;

        warr2.strength = 0;
    }
    else if (warr2.strength > warr1.strength) {
        if (warr1.strength == 0) {
            cout << "They're dead, " << warr2.name << endl;
        }

        cout << warr2.name << " defeats " << warr1.name << endl;
        warr2.strength -= warr1.strength;
        warr1.strength = 0;
    }
    else {
        cout << "Oh No. They're both dead!" << endl;
        warr1.strength = 0;
        warr2.strength = 0;
    }
}


