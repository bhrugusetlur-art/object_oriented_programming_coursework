#include <iostream>
#include <string>
using namespace std;

//struct Person { used for public data
class Person { // used for data hiding and encapsulation
    friend ostream& operator << (ostream& os, const Person& aPerson);
public:
    Person(const string& name) : name(name) {}

    void eating() const { // const method
        cout << name << " eating\n";
    }

    // setter / mutator
    void setName(const string& aName) { name = aName; }

    // getter / accessor
    const string& getName() const { return name; } // add const

private:
    string name;
};

void personEating(const Person& aPerson) {
    aPerson.eating();
}

ostream& operator << (ostream& os, const Person& aPerson) {
        // os << "Person: " << aPerson.name << endl; only compiles if function is a friend
        os << "Person: " << aPerson.getName() << endl;
        return os;
}

int main() {
    Person john("John");

    cout << john.getName() << endl;
    personEating(john);

    // Person sarah; won't compile 

    //cout << john << endl;

    

    
}
