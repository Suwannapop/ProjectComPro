#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;


struct Dataformat
{
	vector<int> Pass;
    vector<int> ID;
    vector<float> money;
};
void deposit(Dataformat &ID1 );
void ImportFile(Dataformat &ID, string fileindex);

int main()
{
	Dataformat ID1;
    
    string id;
    float amount;
    cout << "input your id : ";
    cin >> id;

    string userfile_1 = id+".txt";
    ofstream writefile_1;
    writefile_1.open(userfile_1);
    writefile_1 << "2100"<<","<<"650612100" << "," << "10000" << endl;
    writefile_1.close();

    ImportFile(ID1, userfile_1); 
	deposit(ID1);

	writefile_1.open(userfile_1);
    writefile_1 <<ID1.Pass[0]<<","<< ID1.ID[0] << "," << ID1.money[0]<< endl;
    writefile_1.close();
}

void ImportFile(Dataformat &ID, string fileindex)
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    float balnace;
    if (data.is_open())
    {
        while (getline(data, line)) // importfile
        {
            sscanf(line.c_str(), "%d,%d,%f", &pass, &idnumber, &balnace);
            ID.Pass.push_back(pass);
            ID.ID.push_back(idnumber);
            ID.money.push_back(balnace);
        }
    }else {
        cout << "Don't have ID : " << fileindex << "in datauser" ;
    }
}

void deposit(Dataformat &ID1 ){

	int option = 0;	
	float amount;
	bool notfinished = true;

	do {
		cout << "How much money do you want to deposit? :" << endl;
		cout << "1 - $20" << endl;
		cout << "2 - $50" << endl;	
		cout << "3 - $100" << endl;
		cout << "4 - $200" << endl;
		cout << "5 - $500" << endl;
		cout << "6 - choose your own deposition amount" << endl;
		cout << "7 - cancal deposition \n";
		cout << "choose a deposit option (1-7)" << endl;
		cin >> option;

		switch (option) {
			case 1:
				ID1.money[0] = ID1.money[0] + 20;
				cout << "Successfully deposited $20 to your account. Current balance is $" << ID1.money[0] << "." << endl;
				notfinished = false;
				break;
			case 2:
				ID1.money[0] = ID1.money[0] + 50;
				cout << "Successfully deposited $50 to your account. Current balance is $" << ID1.money[0] << "." << endl;
				notfinished = false;
				break;
			case 3:
				ID1.money[0] = ID1.money[0] + 100;
				cout << "Successfully deposited $100 to your account. Current balance is $" << ID1.money[0] << "." << endl;
				notfinished = false;
				break;
			case 4:
				ID1.money[0] = ID1.money[0] + 200;
				cout << "Successfully deposited $200 to your account. Current balance is $" << ID1.money[0] << "." << endl;
				notfinished = false;
				break;
			case 5:
				ID1.money[0] = ID1.money[0] + 500;
				cout << "Successfully deposited $500 to your account. Current balance is $" << ID1.money[0] << "." << endl;
				notfinished = false;	
				break;
			case 6:
				cout << "How manny do you want to Deposit." ;
				cin >> amount;
				ID1.money[0] = ID1.money[0] + amount;
				cout << "Successfully deposited $500 to your account. Current balance is $" << ID1.money[0] << "." << endl;
				notfinished = false;
				break;
			case 7:
				cout << "Deposition canceled." << endl;
				notfinished = false;
				break;
			default:
				cout << "Invalid! Please try again." << endl;
				break;
		} 
	} while (notfinished);

}