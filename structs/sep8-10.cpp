#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Motorcycle {
    string model;
    int cc;
};

void printBike(const Motorcycle& aBike) {
    cout << aBike.model << ' ' << aBike.cc << endl;
}

int main() {
    Motorcycle myBike;

    printBike(myBike);

    myBike.model = "Vstrom";
    myBike.cc = 650;

    printBike(myBike);

    ifstream bike_file("bike.txt");
    if (!bike_file) {
        cout << "File not found" << endl;
        exit(1);
    }

    vector<Motorcycle> bike_vector;

    Motorcycle someBike;
    while (bike_file >> someBike.model >> someBike.cc) {
        bike_vector.push_back(someBike);
    }

    string model;
    int cc;
    while (bike_file >> model >> cc) {
        Motorcycle someBike {model, cc};
        bike_vector.push_back(someBike);
    }

    for (const Motorcycle& bike: bike_vector) {
        printBike(bike);
    }
}