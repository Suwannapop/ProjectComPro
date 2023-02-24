#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

void TransferMoney(int indexFrom , int indexTo , double amount);
void ImportFile(vector<int> &name, vector<float> &money);
void CheckIndex(int &, int &,vector<int>  , vector<float> );
struct Dataformat
{
    vector<int> ID;
    vector<float> money;
};

int main()
{
    ofstream write;
    write.open("Datafile.txt");
    string line;
    write << "650612100"
          << ","
          << "10000" << endl;
    write << "650612001"
          << ","
          << "500" << endl;
    write.close();
    Dataformat ID;
    Dataformat money;
    int id, IdTranfer;
    float amount;
    cout << "input your id : ";
    cin >> id;
    cout << "What ID you want to tranfer : ";
    cin >> IdTranfer;

    ImportFile(ID.ID, money.money); // importfile
    CheckIndex(id , IdTranfer ,ID.ID ,money.money);

    cout << "How much money : ";
    cin >> amount;
    TransferMoney(id , IdTranfer ,amount ,money.money);
    cout << "You Tranfer Money From ID To ID \n" << ID.ID[id] << " -----> " << ID.ID[IdTranfer] << endl;
    cout << "Now : ID : " <<  ID.ID[id] << " Is " << money.money[id]<< endl;
    cout << "Now : ID : " <<  ID.ID[IdTranfer] << " Is " << money.money[IdTranfer]<< endl;
    write.open("Datafile.txt");
    write << ID.ID[id]
          << ","
          << money.money[id]<< endl;
    write << ID.ID[IdTranfer]
          << ","
          << money.money[IdTranfer] << endl;
    write.close();
}
void CheckIndex(int &indexFrom , int &indexTo ,vector<int> ID )
{
    for ( unsigned int i = 0; i < ID.size(); i++)
    {
        if (indexFrom == ID[i])
        {
            indexFrom = i ;
        }if (indexTo == ID[i])
        {
            indexTo = i ;
        }
    }
    
}
void ImportFile(vector<int> &name, vector<float> &money)
{
    ifstream data;
    data.open("Datafile.txt");
    string line;
    int idnumber;
    float balnace;
    while (getline(data, line)) // importfile
    {
        sscanf(line.c_str(), "%d,%f", &idnumber, &balnace);
        name.push_back(idnumber);
        money.push_back(balnace);
    }
}

void TransferMoney(int indexFrom , int indexTo , double amount, vector<float> &money ) // เเปปปกติ
{
    if (amount > money[indexFrom])
    {
        cout << "You don't have enough money\n";
        cout << "Now you have : " << money[indexFrom] << " You can't tranfer money\n";
    }
    else
    {
        money[indexFrom] = money[indexFrom] - amount;
        money[indexTo] = money[indexTo] + amount;
    }
}
