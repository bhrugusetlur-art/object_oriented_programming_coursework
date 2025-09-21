#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
using namespace std;

// Bhrugu Setlur
// rec02

struct Formula {
    vector<string> chem_names;
    int num_carbon;
    int num_hydro; 
};

void openFile(ifstream& fileStream);
int findLocation(const vector<Formula>& formulas, int num_carbon, int num_hydro);
void fillVector(vector<Formula>& formulas, const string& name, int num_carbon, int num_hydro);
void readFile(ifstream& inputFile, vector<Formula>& formulas);
void sortFormulas(vector<Formula>& formulas);
void displayFormulas(const vector<Formula>& formulas);


int main() {
    vector<Formula> formulas;
    ifstream in;
    openFile(in);
    readFile(in, formulas);
    displayFormulas(formulas);
    cout << endl;
    sortFormulas(formulas);
    displayFormulas(formulas);
}

void openFile(ifstream& fileStream) {
    string filename;
    do {
        cout << "Enter file name: ";
        cin >> filename;
        fileStream.open(filename);

    } while (!fileStream);
}

int findLocation(const vector<Formula>& formulas, int num_carbon, int num_hydro) {
    for (int index = 0; index < formulas.size(); ++index) {
        if (formulas[index].num_carbon == num_carbon && formulas[index].num_hydro == num_hydro) {
            return index;
        }
    }
    return formulas.size();
}

void fillVector(vector<Formula>& formulas, const string& name, int num_carbon, int num_hydro) {
    int exists = findLocation(formulas, num_carbon, num_hydro);
    if (exists < formulas.size()) {
        formulas[exists].chem_names.push_back(name);
    }
    else {
        Formula new_chem;
        new_chem.chem_names.push_back(name);
        new_chem.num_carbon = num_carbon;
        new_chem.num_hydro = num_hydro;
        formulas.push_back(new_chem);
    }
}

void readFile(ifstream& inputFile, vector<Formula>& formulas) {
    string name;
    while (inputFile >> name) {
        char carbon;
        inputFile >> carbon;
        int num_carbon;
        inputFile >> num_carbon;

        char hydro;
        inputFile >> hydro;
        int num_hydro;
        inputFile >> num_hydro;

        fillVector(formulas, name, num_carbon, num_hydro);
    }
    inputFile.close();
}

void sortFormulas(vector<Formula>& formulas) {
    for (int index = 1; index < formulas.size(); ++index) {
        while (formulas[index].num_hydro < formulas[index - 1].num_hydro) {
            swap(formulas[index], formulas[index - 1]);
        }
    }

    for (int index = 1; index < formulas.size(); ++index) {
        while (formulas[index].num_carbon < formulas[index - 1].num_carbon) {
            swap(formulas[index], formulas[index - 1]);
        }
    }

}

void displayFormulas(const vector<Formula>& formulas) {
    for (const Formula& f : formulas) {
        cout << 'C' << f.num_carbon << 'H' << f.num_hydro << ' ';
        for (const string& name : f.chem_names) {
            cout << name << ' ';
        }
        cout << endl;
    }
}



