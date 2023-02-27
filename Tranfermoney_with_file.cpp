#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

void TransferMoney(double amount, vector<float> &money1, vector<float> &money2);
void ImportFile(vector<int> &Password, vector<int> &ID, vector<float> &money, string fileindex);
struct Dataformat
{
    vector<int> Pass;
    vector<int> ID;
    vector<float> money;
};

int main()
{
    Dataformat ID1;
    Dataformat ID2;
    string id, IdTranfer;
    float amount;
    cout << "input your id : ";
    cin >> id;
    cout << "What ID you want to tranfer : ";
    cin >> IdTranfer;
    string userfile_1 = id + ".txt";
    string userfile_2 = IdTranfer + ".txt";
    ofstream writefile_1, writefile_2;
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1<< "2100"<< ","<< "650612100"<< ","<< "10000";
    writefile_2<< "2001"<< ","<< "650612001"<< ","<< "500";
    writefile_1.close();
    writefile_2.close();
    ImportFile(ID1.Pass, ID1.ID, ID1.money, userfile_1); // importfile
    ImportFile(ID2.Pass, ID2.ID, ID2.money, userfile_2);
    cout << "How much money : ";
    cin >> amount;
    TransferMoney(amount, ID1.money, ID2.money);
    cout << "You Tranfer Money From ID To ID \n"
         << ID1.ID[0] << " -----> " << ID2.ID[0] << endl;
    cout << "Now : ID : " << ID1.ID[0] << " Is " << ID1.money[0] << endl;
    cout << "Now : ID : " << ID2.ID[0] << " Is " << ID2.money[0] << endl;
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << ID2.money[0] << endl;
    writefile_1.close();
    writefile_2.close();
}
void ImportFile(vector<int> &Password, vector<int> &ID, vector<float> &money, string fileindex)
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    float balnace;
    while (getline(data, line)) // importfile
    {
        sscanf(line.c_str(), "%d,%d,%f", &pass, &idnumber, &balnace);
        Password.push_back(pass);
        ID.push_back(idnumber);
        money.push_back(balnace);
    }
}

void TransferMoney(double amount, vector<float> &money1, vector<float> &money2) // เเปปปกติ
{
    if (amount > money1[0])
    {
        cout << "You don't have enough money\n";
        cout << "Now you have : " << money1[0] << " You can't tranfer money\n";
    }
    else
    {
        money1[0] = money1[0] - amount;
        money2[0] = money2[0] + amount;
    }
}
