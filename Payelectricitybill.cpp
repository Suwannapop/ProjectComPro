#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
struct Dataformat
{
    vector<int> Pass;
    vector<int> ID;
    vector<double> money;
    string name;
};

void payebill(double amount, Dataformat &ID1, Dataformat &ID2);
void ImportFile(Dataformat &ID, string fileindex);

int main()
{
    Dataformat ID1;
    Dataformat ID2;
    string id, Idbill;
    double amount;
    cout << "input your id : ";
    cin >> id;
    string userfile_1 = id + ".txt";
    ImportFile(ID1, userfile_1);
    cout << "What ID you want to pay bill : ";
    cin >> Idbill;
    string userfile_2 = Idbill + ".txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID2, userfile_2);
    cout << "How much money ";
    cin >> amount;
    payebill(amount, ID1, ID2);
    cout << "You Pay Bill from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(10000) << ID1.money[0] << ","<< ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(10000) << ID2.money[0] << ","<< ID2.name << endl;
    writefile_1.close();
    writefile_2.close();
}

void ImportFile(Dataformat &ID, string fileindex)
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    double balance;
    char name[99];
     if (data.is_open()){
            while (getline(data, line)) 
            {
                sscanf(line.c_str(), "%d,%d,%lf,%s", &pass, &idnumber, &balance, name);
                ID.Pass.push_back(pass);
                ID.ID.push_back(idnumber);
                ID.money.push_back(balance);
                ID.name = name;
            }
        }
}

void payebill(double amount, Dataformat &ID1, Dataformat &ID2) 
{
    if (amount > ID1.money[0])
    {
        cout << "You don't have enough money\n";
        cout << "Now you have money : " << ID1.money[0] << " You can't pay this bill\n";
    }
    else
    {
        ID1.money[0] = ID1.money[0] - amount;
        ID2.money[0] = ID2.money[0] + amount;
    }
}

