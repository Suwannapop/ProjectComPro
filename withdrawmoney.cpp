#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Dataformat
{
    vector<int> Pass;
    vector<int> ID;
    vector<double> money;
};


void Withdraw(double, Dataformat &);
void ImportFile(vector<int> &, vector<float> &, string);
struct Dataformat
{
    vector<int> Pass;
    vector<int> ID;
    vector<double> money;
};

int mainWithdraw(Dataformat ID , string userfile_1)
{
    float amount;
    ofstream writefile_1;
    ImportFile(ID,userfile_1);
    cout << "Enter amount : ";
    cin >> amount;
    Withdraw(amount, ID);
    cout << "withdraw : " << amount;
    cout << "\nNow : ID : " << ID.ID[0] << ", total balance is : " <<setprecision(1000000)<< ID.money[0] << endl;

    writefile_1.open(userfile_1);
    writefile_1 <<ID.Pass[0]<<","<< ID.ID[0]<< ","<< ID.money[0] << endl;
    writefile_1.close();
}

void ImportFile(Dataformat &ID, string fileindex)
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    double balnace;
    if (data.is_open())
    {
        while (getline(data, line)) // importfile
        {
            sscanf(line.c_str(), "%d,%d,%lf", &pass, &idnumber, &balnace);
            ID.Pass.push_back(pass);
            ID.ID.push_back(idnumber);
            ID.money.push_back(balnace);
        }
    }else {
        cout << "Don't have ID : " << fileindex << "in datauser" ;
    }
}

void Withdraw(double amount, Dataformat &ID)
{
    if (amount > 0)
    {
        if (amount > ID.money[0])
        {
            cout << "You don't have enough money\n";
            cout << "Now you have : " << setprecision(1000000) << ID.money[0] << " You can't withdraw money\n";
        }
        else
        {
            ID.money[0] = ID.money[0] - amount;
        }
    }
}