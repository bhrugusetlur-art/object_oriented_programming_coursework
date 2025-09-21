#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


// part 1
// struct Account {
//     string name;
//     int account_number;
// };

// int main() {
//     vector<Account> accounts;
//     string name;
//     int account_num;

//     ifstream inputStream("accounts.txt");
//     if (!inputStream) { 
//         cout << "Could not open accounts.txt" << endl; 
//     }

//     while (inputStream >> name >> account_num) {
//         Account newAccount;
//         newAccount.name = name;
//         newAccount.account_number = account_num;
//         accounts.push_back(newAccount);
//     }
//     inputStream.close();

//     for (const Account& a : accounts)
//         cout << a.name << ' ' << a.account_number << '\n';

//     cout << '\n';

//     accounts.clear();
//     inputStream.open("accounts.txt");
    
//     if (!inputStream) { 
//         cout << "Reopen failed" << endl; 
//     }

//     while (inputStream >> name >> account_num) {
//         Account newAccount{name, account_num};
//         accounts.push_back(newAccount);  
//     }

//     inputStream.close();

//     for (const Account& a : accounts)
//         cout << a.name << ' ' << a.account_number << '\n';

// }


// part 2

class Account {
    friend ostream& operator << (ostream& os, const Account& account);
public:
    Account(const string& name, int account_number) : name(name), account_number(account_number) {}

    const string& getName() const { return name; }
    const int& getAcctNum() const { return account_number; }

private:
    string name;
    int account_number;
};

ostream& operator << (ostream& os, const Account& account) {
    os << "Account: " << account.name << ' ' << account.account_number;
    return os;
}

int main() {
    vector<Account> accounts;
    string name;
    int account_num;

    ifstream inputStream("accounts.txt");
    if (!inputStream) { 
        cout << "Could not open accounts.txt" << endl; 
    }

    while (inputStream >> name >> account_num) {
        accounts.emplace_back(name, account_num);  
    }

    inputStream.close();

    for (const Account& a : accounts) {
        cout << a << endl;
    }

    

}

