#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

void Withdraw(double , vector<float> &);
void ImportFile(vector<int> &, vector<float> &, string );
struct Dataformat
{
    vector<int> ID;
    vector<float> money;
};

int main()
{
    Dataformat ID;
    Dataformat money;
    string id;
    float amount;
    cout << "input your id : ";
    cin >> id;

    string userfile_1 = id+".txt";

    ofstream writefile_1;
    writefile_1.open(userfile_1);

    writefile_1 << "650612100"
    << ","
    << "10000" << endl;

    writefile_1.close();


    ImportFile(ID.ID, money.money,userfile_1); 



    cout << "Enter amount : ";
    cin >> amount;
    Withdraw(amount ,money.money);
    cout << "withdraw : " << amount ;
    cout << "\nNow : ID : " <<ID.ID[0] << ", total balance is : " << money.money[0]<< endl;

    writefile_1.open(userfile_1);

    writefile_1 << ID.ID[0]
    << ","
    << money.money[0]<< endl;

    writefile_1.close();

}

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

void Withdraw(double amount, vector<float> &money ) 
{
    if (amount > money[0])
    {
        cout << "You don't have enough money\n";
    cout << "Now you have : " << money[0] << " You can't withdraw money\n";
    }
    else
    {
    money[0] = money[0] - amount;

    }
}