/*
  rec03_start.cpp
*/

// Bhrugu Setlur - N15706715

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
struct Account {
    string name;
    int account_number;
};

// Task 2
// Define an Account class (use a different name than in Task 1)
class Account2 {
    friend ostream& operator<<(ostream& os, const Account2& account);
public:
    Account2(const string& name, int account_number)
        : name(name), account_number(account_number) {}

    const string& getName() const { return name; }
    const int& getAcctNum() const { return account_number; } // ok to keep as ref per your style

private:
    string name;
    int account_number;
};

ostream& operator<<(ostream& os, const Account2& account) {
    os << "Account: " << account.name << ' ' << account.account_number;
    return os;
}

// Task 3
// Define another Account class (use a different name than in Task
// 1&2) and a Transaction class. The Transaction class is to be
// defined outside of the Account class, i.e. it is not "nested".

class Transaction {
    friend ostream& operator<<(ostream& os, const Transaction& transaction);
public:
    Transaction(const string& type, int amount) : type(type), amount(amount) {}

    const string& getType() const { return type; }
    int getAmount() const { return amount; } // return by value

private:
    string type;
    int amount;
};

ostream& operator<<(ostream& os, const Transaction& transaction) {
    os << "Transaction: " << transaction.type << ' ' << transaction.amount;
    return os;
}

class Account3 {
    friend ostream& operator<<(ostream& os, const Account3& account);
public:
    Account3(const string& name, int account_number)
        : name(name), account_number(account_number) {}

    void deposit(const Transaction& transaction)  { 
        balance += transaction.getAmount();
        transactions.push_back(transaction);
    }
    
    void withdraw(const Transaction& transaction) { 
        if (balance >= transaction.getAmount()) {
            balance -= transaction.getAmount(); 
            transactions.emplace_back(transaction);
        }
        
    }

    const string& getName() const { return name; }
    int getAcctNumber() const { return account_number; }

private:
    string name;
    int account_number;
    vector<Transaction> transactions;
    int balance = 0;
};

ostream& operator<<(ostream& os, const Account3& account) {
    os << "Account: " << account.getName() << ' ' << account.getAcctNumber() << '\n';
    for (const Transaction& transaction : account.transactions) {
        os << transaction << '\n';
    }
    return os;
}


// Task 4
// Define yet another Account class, this time with a nested public
// Transaction class. Again use a different name for the Account class
// than in the previous Tasks. Note that it is NOT necessary to rename
// the Transaction class, since it is nested.

class Account4 {
    friend ostream& operator<<(ostream& os, const Account4& account);
public:
    class Transaction {
        friend ostream& operator<<(ostream&, const Transaction&);
    public:
        Transaction(string type, int amount) : type(std::move(type)), amount(amount) {}
        const string& getType() const { return type; }
        int getAmount() const { return amount; }
    private:
        string type;
        int amount;
    };

    Account4(string name, int account_number) : name(name), account_number(account_number) {}
    
    void deposit(int amt)  { 
        balance += amt; transactions.emplace_back("Deposit",  amt); 
    }
    
    void withdraw(int amt) { 
        if (balance >= amt) {
            balance -= amt; 
            transactions.emplace_back("Withdraw", amt);
        }
         
    }

    const string& getName() const { return name; }
    int getAcct() const { return account_number; }

private:
    string name;
    int account_number;
    int balance = 0;
    vector<Transaction> transactions;
};

ostream& operator<<(ostream& os, const Account4::Transaction& t) {
    return os << "Transaction: " << t.type << ' ' << t.amount;
}

ostream& operator<<(ostream& os, const Account4& account) {
    os << "Account: " << account.name << ' ' << account.account_number << '\n';
    for (const Account4::Transaction& transaction : account.transactions)
        os << transaction << '\n';
    return os;
}


// Task 5
// Same as Task 4, but make the Transaction nested class private.
// Yes, the Account class needs a new name but, again, the Transaction
// class does not.



int main() {
    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n"
         << "Filling vector of struct objects, define a local struct instance\n"
         << "and set fields explicitly:\n";

    vector<Account> accounts;
    string name;
    int account_num;

    ifstream inputStream("accounts.txt");
    if (!inputStream) {
        cout << "Could not open accounts.txt\n";
        return 1;
    }

    while (inputStream >> name >> account_num) {
        Account newAccount;
        newAccount.name = name;
        newAccount.account_number = account_num;
        accounts.push_back(newAccount);
    }
    inputStream.close();

    for (const Account& a : accounts)
        cout << a.name << ' ' << a.account_number << '\n';

    cout << '\n';

    //      1b
    cout << "Task1b:\nFilling vector of struct objects, using {} initialization:\n";

    accounts.clear();
    inputStream.open("accounts.txt");
    if (!inputStream) {
        cout << "Reopen failed\n";
        return 1;
    }

    while (inputStream >> name >> account_num) {
        accounts.push_back(Account{name, account_num});
    }
    inputStream.close();

    for (const Account& a : accounts)
        cout << a.name << ' ' << a.account_number << '\n';

    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:\nFilling vector of class objects, using local class object:\n";
    vector<Account2> accounts2;

    inputStream.open("accounts.txt");
    if (!inputStream) { cout << "Reopen failed\n"; return 1; }

    while (inputStream >> name >> account_num) {
        Account2 newAccount(name, account_num);
        cout << newAccount.getName() << ' ' << newAccount.getAcctNum() << '\n';
        accounts2.push_back(newAccount);
    }
    inputStream.close();

    cout << "\nTask2b:\noutput using output operator with getters\n";
    for (const Account2& account : accounts2)
        cout << account << '\n';

    cout << "\nTask2c:\noutput using output operator as friend without getters\n";
    for (const Account2& account : accounts2)
        cout << account << '\n';

    cout << "\nTask2d:\nFilling vector of class objects, using temporary class object:\n";
    accounts2.clear();
    inputStream.open("accounts.txt");
    if (!inputStream) { cout << "Reopen failed\n"; return 1; }

    while (inputStream >> name >> account_num) {
        accounts2.push_back(Account2(name, account_num));
    }
    inputStream.close();

    for (const Account2& account : accounts2)
        cout << account << '\n';

    cout << "\nTask2e:\nFilling vector of class objects, using emplace_back:\n";
    inputStream.open("accounts.txt");
    if (!inputStream) { cout << "Reopen failed\n"; return 1; }

    while (inputStream >> name >> account_num) {
        accounts2.emplace_back(name, account_num);
    }
    inputStream.close();

    for (const Account2& account : accounts2)
        cout << account << '\n';

    cout << "==============\n"
         << "\nTask 3:\nAccounts and Transaction:\n";

    ifstream transactionStream("transactions.txt");
    if (!transactionStream) {
        cout << "Could not open transactions.txt\n";
        return 1;
    }

    vector<Account3> accounts3;

    string first_word, second_word;
    int acct_num, amount;

    while (transactionStream >> first_word) {
        if (first_word == "Account") {
            transactionStream >> second_word >> acct_num;
            accounts3.emplace_back(second_word, acct_num);
        }
        else if (first_word == "Deposit") {
            transactionStream >> acct_num >> amount;
            Transaction new_transaction(first_word, amount);
            for (Account3& account : accounts3) {             
                if (account.getAcctNumber() == acct_num) {  
                    account.deposit(new_transaction);
                    break;                      
                }
            }
        }
        else { 
            transactionStream >> acct_num >> amount;
            Transaction new_transaction(first_word, amount);
            for (Account3& account : accounts3) {
                if (account.getAcctNumber() == acct_num) {
                    account.withdraw(new_transaction);
                    break;
                }
            }
        }
    }
    transactionStream.close();

    for (const Account3& account : accounts3)
        cout << account << '\n';

    cout << "==============\n"
         << "\nTask 4:\nTransaction nested in public section of Account:\n";

    // ===== Task 4: Transaction nested in public section of Account =====
vector<Account4> accounts4;

transactionStream.open("transactions.txt");
string t4word, t4name;
int t4acct, t4amt;

while (transactionStream >> t4word) {
    if (t4word == "Account") {
        transactionStream >> t4name >> t4acct;
        accounts4.emplace_back(t4name, t4acct);
    }
    else if (t4word == "Deposit") {
        transactionStream >> t4acct >> t4amt;
        for (Account4& a : accounts4) {
            if (a.getAcct() == t4acct) { a.deposit(t4amt); break; }
        }
    }
    else { 
        transactionStream >> t4acct >> t4amt;
        for (Account4& account : accounts4) {
            if (account.getAcct() == t4acct) { 
                account.withdraw(t4amt); 
                break; 
            }
        }
    }
}
transactionStream.close();

for (const Account4& a : accounts4) {
    cout << a << '\n';
}



    
    cout << "==============\n"
         << "\nTask 5:\nTransaction nested in private section of Account:\n";

}
