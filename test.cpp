#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void transferMoney(string fromAccount, string toAccount, double amount) {
    // Open the accounts file for reading and writing
    fstream accounts("accounts.txt", ios::in | ios::out);
    
    if (!accounts) {
        cerr << "Error opening accounts file" << endl;
        return;
    }
    
    string line;
    bool fromAccountFound = false;
    bool toAccountFound = false;
    
    // Loop through the file to find the accounts
    while (getline(accounts, line)) {
        if (line.find(fromAccount) != string::npos) {
            fromAccountFound = true;
            double balance = stod(line.substr(line.find_last_of(" ") + 1));
            if (balance < amount) {
                cerr << "Insufficient funds in account " << fromAccount << endl;
                return;
            }
            balance -= amount;
            line = fromAccount + " " + to_string(balance);
        }
        else if (line.find(toAccount) != string::npos) {
            toAccountFound = true;
            double balance = stod(line.substr(line.find_last_of(" ") + 1));
            balance += amount;
            line = toAccount + " " + to_string(balance);
        }
    }
    
    if (!fromAccountFound) {
        cerr << "Account " << fromAccount << " not found" << endl;
        return;
    }
    
    if (!toAccountFound) {
        cerr << "Account " << toAccount << " not found" << endl;
        return;
    }
    
    // Write the updated account information back to the file
    accounts.seekg(0, ios::beg);
    fstream tmp("tmp.txt", ios::out);
    
    while (getline(accounts, line)) {
        if (line.find(fromAccount) != string::npos || line.find(toAccount) != string::npos) {
            tmp << line << endl;
        }
    }
    
    tmp.seekg(0, ios::beg);
    accounts.seekg(0, ios::beg);
    
    while (getline(tmp, line)) {
        accounts << line << endl;
    }
    
    // Close the file
    accounts.close();
    tmp.close();
    
    // Print success message
    cout << "Successfully transferred $" << amount << " from account " << fromAccount << " to account " << toAccount << endl;
}

int main() {
    transferMoney("1234", "5678", 1000.0);
    return 0;
}



#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;
void TranferMoney(int Fromuer, int Touser, double money, double Data[]);

struct user
{
    string ID;
    string pass;
    double money;
};
int main()
{
    user u1 = {"650612100", "2100", 1000};
    user u2 = {"650612082", "2082", 1000};
    double MoneyData[] = {};
    MoneyData[0] = u1.money;
    MoneyData[1] = u2.money;
    int user, Touser;
    double amount;
    cout << MoneyData[0] << " " << MoneyData[1];
    do
    {
        cout << "\nwhich user do you what to enter [1-10] : ";
        cin >> user;
        if (user <= 0)
        {
            cout << "plz in put [1-10]";
        }

    } while (user <= 0);

    do
    {
        cout << "\nwhich user do you want to move to : ";
        cin >> Touser;
        if (Touser <= 0)
        {
            cout << "\nplz in put [1-10]";
        }

    } while (Touser <= 0);

    do
    {
        cout << "How much to move ";
        cin >> amount;
        if (amount < 0)
        {
            cout << "\nplz in put [1-10]";
        }

    } while (amount < 0);

    TranferMoney(user, Touser, amount, MoneyData);
}

void TranferMoney(int Fromuer, int Touser, double money, double Data[])
{
    if (money > Data[Fromuer])
    {
        cout << "You don't have enough money";
    }
    else
    {
        Data[Fromuer - 1] = Data[Fromuer - 1] - money;
        Data[Touser - 1] = Data[Touser - 1] + money;
        cout << "Now money is " << Data[Fromuer - 1] << endl;
        cout << "Now money is " << Data[Touser - 1] << endl;
    }
}
