#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;


void deposit(double , vector<float> &);

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
    writefile_1 << "650612100" << "," << "10000" << endl;
    writefile_1.close();

    ImportFile(ID.ID, money.money,userfile_1); 

	deposit(amount ,money.money);

	writefile_1.open(userfile_1);
    writefile_1 << ID.ID[0] << "," << money.money[0]<< endl;
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

void deposit(double amount, vector<float> &money){

	int option = 0;	
	bool notfinished = true;

	do {
		cout << "How much money do you want to deposit? :" << endl;
		cout << "1 - $20" << endl;
		cout << "2 - $50" << endl;	
		cout << "3 - $100" << endl;
		cout << "4 - $200" << endl;
		cout << "5 - $500" << endl;
		cout << "6 - cancel deposition" << endl;
		cout << "choose a deposit option (1-6)" << endl;
		cin >> option;

		switch (option) {
			case 1:
				money = money + 20;
				cout << "Successfully deposited $20 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;
				break;
			case 2:
				money = money + 50;
				cout << "Successfully deposited $50 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;
				break;
			case 3:
				money = money + 100;
				cout << "Successfully deposited $100 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;
				break;
			case 4:
				money = money + 200;
				cout << "Successfully deposited $200 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;
				break;
			case 5:
				money = money + 500;
				cout << "Successfully deposited $500 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;	
				break;
			case 6:
				cout << "Deposition canceled." << endl;
				notfinished = false;
				break;
			default:
				cout << "Invalid! Please try again." << endl;
				break;
		} 
	} while (notfinished);

}