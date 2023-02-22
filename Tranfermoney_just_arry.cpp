#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;
void TranferMoney(int , int , double , vector<double> &);

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
    vector<double> MoneyData ;
    MoneyData.push_back(u1.money) ;
    MoneyData.push_back(u2.money) ;
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

void TranferMoney(int Fromuer, int Touser, double money, vector<double> &Data)  //เเปปปกติ
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