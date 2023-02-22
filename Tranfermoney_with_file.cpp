#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

void TransferMoney(int idnumber[], float balance[], int indexFrom, int indexTo, double amountmoney);

int main()
{
    ofstream write;
    write.open("C:\\Users\\User\\Desktop\\compro\\Project\\ProjectComPro\\Datafile.txt");
    ifstream data;
    data.open("C:\\Users\\User\\Desktop\\compro\\Project\\ProjectComPro\\Datafile.txt");
    string line;
    write << "650612100"
          << ","
          << "10000" << endl;
    write << "650612001"
          << ","
          << "500" << endl;
    write.close();
    int id, idnumber[3], IdTranfer, i = 0, indexFrom = 0, indexTo = 0;
    double amount;
    float balance[3];
    cout << "input your id : ";
    cin >> id;
    cout << "What ID you want to tranfer : ";
    cin >> IdTranfer;

    while (getline(data, line)) // ระบบดูเงิน
    {
        sscanf(line.c_str(), "%d,%f", &idnumber[i], &balance[i]);
        if (id == idnumber[i])
        {
            indexFrom = i;
        }
        if (IdTranfer == idnumber[i])
        {
            indexTo = i;
        }
        i++;
    }
    cout << "How much money : ";
    cin >> amount;
    TransferMoney(idnumber, balance, indexFrom, indexTo, amount);
    cout << idnumber[indexFrom] << " To " << idnumber[indexTo] << endl;
    cout << idnumber[indexFrom] << " now " << balance[indexFrom] << endl;
    cout << idnumber[indexTo] << " now " << balance[indexTo] << endl;
    write.open("C:\\Users\\User\\Desktop\\compro\\Project\\ProjectComPro\\Datafile.txt");
    write << "650612100"
          << ","
          << balance[indexFrom] << endl;
    write << "650612001"
          << ","
          << balance[indexTo] << endl;
    write.close();

}

void TransferMoney(int idnumber[], float balance[], int indexFrom, int indexTo, double amountmoney) // เเปปปกติ
{
    if (amountmoney > balance[indexFrom])
    {
        cout << "You don't have enough money\n" ;
    }
    else
    {
        balance[indexFrom ] = balance[indexFrom ] - amountmoney;
        balance[indexTo] = balance[indexTo] + amountmoney;
    }
}
