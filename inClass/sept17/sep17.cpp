#include <iostream>
#include <string>
using namespace std;


class Person {
    friend ostream& operator<<(ostream& os, const Person& rhs);
    

    class Date {
        //friend ostream& operator<<(ostream& os, const Date& rhs);
        friend ostream& operator<<(ostream& os, const Person::Date& rhs) {
            os << rhs.month << '/' << rhs.day << '/' << rhs.year;
            return os;
}

    public:
        Date(int m, int d, int y) : month(m), day(d), year(y) {}

    private:
        int month, day, year;
    };

public:
    Person(const string& name, int m, int d, int y)
        : name(name), bday(m, d, y) {}

private:
    string name;
    Date bday;
};

int main() {
    Person john("John", 3, 15, 2006);
    cout << john << endl;

    // Person::Date independenceDay(7, 4, 1776); // Date class in Person class
    // cout << independenceDay << endl;
}

ostream& operator<<(ostream& os, const Person& rhs) {
    os << "Person: " << rhs.name << ", dob: " << rhs.bday;
    return os;
}

// wont compile because Date class is private in Person class
// ostream& operator<<(ostream& os, const Person::Date& rhs) {
//     os << rhs.month << '/' << rhs.day << '/' << rhs.year;
//     return os;
// }