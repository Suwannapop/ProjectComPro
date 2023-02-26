#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;



void deposit(int account, double balance){

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
				balance = balance + 20;
				cout << "Successfully deposited $20 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;
				break;
			case 2:
				balance = balance + 50;
				cout << "Successfully deposited $50 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;
				break;
			case 3:
				balance = balance + 100;
				cout << "Successfully deposited $100 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;
				break;
			case 4:
				balance = balance + 200;
				cout << "Successfully deposited $200 to your account. Current balance is $" << balance << "." << endl;
				notfinished = false;
				break;
			case 5:
				balance = balance + 500;
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

int main()
{
   fstream data ;
   data.open("Datafile.txt");
}
