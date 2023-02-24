#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

void TransferMoney(double , vector<float> &);
void ImportFile(vector<int> &, vector<float> &, string );
void CheckIndex(int &, int &,vector<int>);
struct Dataformat
{
    vector<int> ID;
    vector<float> money;
};

int main()
{
    Dataformat ID;
    Dataformat money;
    string id, IdTranfer;
    float amount;
    cout << "input your id : ";
    cin >> id;
    cout << "What ID you want to tranfer : ";
    cin >> IdTranfer;
    string userfile_1 = id+".txt";
    string userfile_2 = IdTranfer+".txt";
    ofstream writefile_1 ,writefile_2 ;
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << "650612100"
          << ","
          << "10000" << endl;
    writefile_2 << "650612001"
          << ","
          << "500" << endl;
    writefile_1.close();
    writefile_2.close();

    ImportFile(ID.ID, money.money,userfile_1); // importfile
    ImportFile(ID.ID, money.money,userfile_2);
    //CheckIndex(id , IdTranfer ,ID.ID);

    cout << "How much money : ";
    cin >> amount;
    TransferMoney(amount ,money.money);
    cout << "You Tranfer Money From ID To ID \n" << ID.ID[0] << " -----> " << ID.ID[1] << endl;
    cout << "Now : ID : " <<  ID.ID[0] << " Is " << money.money[0]<< endl;
    cout << "Now : ID : " <<  ID.ID[1] << " Is " << money.money[1]<< endl;
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID.ID[0]
          << ","
          << money.money[0]<< endl;
    writefile_2 << ID.ID[1]
          << ","
          << money.money[1] << endl;
    writefile_1.close();
    writefile_2.close();
}
/*void CheckIndex(int &indexFrom , int &indexTo ,vector<int> ID )
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
    
}*/
void ImportFile(vector<int> &ID, vector<float> &money , string fileindex)
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber;
    float balnace;
    while (getline(data, line)) // importfile
    {
        sscanf(line.c_str(), "%d,%f", &idnumber, &balnace);
        ID.push_back(idnumber);
        money.push_back(balnace);
    }
}

void TransferMoney(double amount, vector<float> &money ) // เเปปปกติ
{
    if (amount > money[0])
    {
        cout << "You don't have enough money\n";
        cout << "Now you have : " << money[0] << " You can't tranfer money\n";
    }
    else
    {
        money[0] = money[0] - amount;
        money[1] = money[1] + amount;
    }
}
