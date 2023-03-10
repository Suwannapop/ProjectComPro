#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
struct Dataformat
{
    vector<int> ID;
    vector<double> money;
};

void topup(double amount, Dataformat &ID1, Dataformat &ID2);
void ImportFile(Dataformat &ID, string fileindex);

int main()
{
    Dataformat ID1;
    Dataformat ID2;
    string id, IdTopup;
    double amount;
    cout << "input your id : ";
    cin >> id;
    string userfile_1 = id + ".txt";
    ImportFile(ID1, userfile_1);
    cout << "What ID you want to tranfer : ";
    cin >> IdTopup;
    string userfile_2 = IdTopup + ".txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID2, userfile_2);
    cout << "How much money do you want to top up: ";
    cin >> amount;
    topup(amount, ID1, ID2);
    cout << "You top up money from ID To ID \n"
         << ID1.ID[0] << " -----> " << ID2.ID[0] << endl;
    cout << "Now : ID : " << ID1.ID[0] << " Is " << ID1.money[0] << endl;
    cout << "Now : ID : " << ID2.ID[0] << " Is " << ID2.money[0] << endl;
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.ID[0] << "," << setprecision(10000)<< ID1.money[0] << endl;
    writefile_2 << ID2.ID[0] << "," << setprecision(10000)<< ID2.money[0] << endl;
    writefile_1.close();
    writefile_2.close();
}

void ImportFile(Dataformat &ID, string fileindex)
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber;
    double balnace;
    string name = fileindex ;
    if (data.is_open())
    {
        while (getline(data, line)) // importfile
        {
            sscanf(line.c_str(), "%d,%lf", &idnumber, &balnace);

            ID.ID.push_back(idnumber);
            ID.money.push_back(balnace);
        }
    }else {
        cout << "Don't have ID : " << name << " in database \n" ;
        main();
    }
}

void topup(double amount, Dataformat &ID1, Dataformat &ID2) 
{
    if (amount > ID1.money[0])
    {
        cout << "You don't have enough money\n";
        cout << "Now you have : " << ID1.money[0] << " You can't tranfer money\n";
    }
    else
    {
        ID1.money[0] = ID1.money[0] - amount;
        ID2.money[0] = ID2.money[0] + amount;
    }
}
