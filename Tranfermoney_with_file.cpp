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
};

void TransferMoney(double amount, Dataformat &ID1, Dataformat &ID2);
void ImportFile(Dataformat &ID, string fileindex);

int main()
{
    Dataformat ID1;
    Dataformat ID2;
    string id, IdTranfer;
    double amount;
    cout << "input your id : ";
    cin >> id;
    string userfile_1 = id + ".txt";
    ImportFile(ID1, userfile_1);
    cout << "What ID you want to tranfer : ";
    cin >> IdTranfer;
    string userfile_2 = IdTranfer + ".txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID2, userfile_2);
    cout << "How much money : ";
    cin >> amount;
    TransferMoney(amount, ID1, ID2);
    cout << "You Tranfer Money From ID To ID \n"
         << ID1.ID[0] << " -----> " << ID2.ID[0] << endl;
    cout << "Now : ID : " << ID1.ID[0] << " Is " << ID1.money[0] << endl;
    cout << "Now : ID : " << ID2.ID[0] << " Is " << ID2.money[0] << endl;
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(10000)<< ID1.money[0] << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(10000)<< ID2.money[0] << endl;
    writefile_1.close();
    writefile_2.close();
}
void ImportFile(Dataformat &ID, string fileindex)
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    double balnace;
    string name = fileindex ;
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
        cout << "Don't have ID : " << name << " in datauser \n" ;
        main();
    }
}

void TransferMoney(double amount, Dataformat &ID1, Dataformat &ID2) // เเปปปกติ
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
