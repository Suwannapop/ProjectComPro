#include <iostream>
#include <conio.h> // for getch() function
#include <iomanip> 
#include <windows.h> //sleep
#include <fstream>
#include <vector>

using namespace std;
int id, password; //login
char ch; //login && ATM
int choice = 1; //ATM
float balance ; //ลบออก

int main();
struct Dataformat
{
    vector<int> Pass;
    vector<int> ID;
    vector<float> money;
};

//deposit
void deposit(Dataformat &ID1 );
void ImportFile(Dataformat &ID, string fileindex);

int deposit()
{
	Dataformat ID1;
    
    string id;
    float amount;
    cout << "input your id : "; //รับจาก login
    cin >> id;

    string userfile_1 = id+".txt";
    ofstream writefile_1;

    ImportFile(ID1, userfile_1); 
	deposit(ID1);

	writefile_1.open(userfile_1);
    writefile_1 <<ID1.Pass[0]<<","<< ID1.ID[0] << "," << ID1.money[0]<< endl;
    writefile_1.close();
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
				if (amount > 0)
				{

					ID1.money[0] = ID1.money[0] + amount;
					cout << "Successfully deposited $500 to your account. Current balance is $" << ID1.money[0] << "." << endl;
					notfinished = false;
					break;
				}else {
					cout << "Invalid! Please try again." << endl;
					Sleep(1000);
					break;
				}
				
			case 7:
				cout << "Deposition canceled." << endl;
				notfinished = false;
				break;
			default:
				cout << "Invalid! Please try again." << endl;
				Sleep(1000);
				break;
		} 
	} while (notfinished);

}
//higlight_yes_or_No
void higlight_Yes_or_No(int index, bool selected) { 
    int l = 0 ;
    if (selected) {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index) {
        case 1:
            l = 31 ;
            cout << "Yes";
            break;
        case 2:
            l = 32 ;
            cout << "No";
            break;
        default:
            break;
    }

    cout << "\033[0m"  << setw(l)<<" |";  // window
}

//Login failed
int Login_failed (){
        system("cls");
        cout << "+-------------------------------------+\n";
        cout << "|             Login failed.           |\n";
        cout << "|       Incorrect ID or password.     |\n";
        cout << "+-------------------------------------+\n";
        cout << setw(28) <<"Please try again.\n" ;
}

void ImportFile(Dataformat &ID, string fileindex) //ใช้ฝากถอนโอน
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
        do{
                Login_failed();
                cout << "+-------------------------------------+\n" ;
                cout << "|     If you don't have an accoun     |\n" ;
                cout << "|    Want to create a new account?    | ";
            for (int i = 1; i < 3; i++) {
                cout << "\n| ";
                higlight_Yes_or_No(i, i == choice);
                }
                cout << "\n+-------------------------------------+\n";

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1) { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 3) { // down arrow key
                    choice++;
                }
            } while (ch != 13);
                switch (choice)
                {
                case 1:
                    cout << "Yes";
                    break;
                case 2:
                    cout << "No";
                    main();
                    break;
                default:
                    break;
                }
                 
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


void mainTransferMoney( string id )
{
    Dataformat ID1;
    Dataformat ID2;
    string IdTranfer;
    float amount;
    cout << "What ID you want to tranfer : ";
    cin >> IdTranfer;
    string userfile_1 = id + ".txt";
    string userfile_2 = IdTranfer + ".txt";
    ofstream writefile_1, writefile_2;
    ImportFile(ID1, userfile_1); // importfile
    ImportFile(ID2, userfile_2);
    cout << "How much money : ";
    cin >> amount;
    TransferMoney(amount,ID1,ID2);
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

//higlight atm menu
void highlight_ATM_MENU(int index, bool selected) { 
    int l = 0 ;
    if (selected) {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index) {
        case 1:
            l = 21 ;
            cout << "Balance Inquiry"; //เช็ค
            break;
        case 2:
            l = 29 ;
            cout << "Deposit"; //ฝาก
            break;
        case 3:
            l = 28 ;
            cout << "Withdraw"; //ถอน
            break;
        case 4:
            l = 21 ;
            cout << "Transfers money"; //โอน
            break;
        case 5:
            l = 32 ;
            cout << "Exit"; //ออก
            break;
        default:
            break;
    }

    cout << "\033[0m"  << setw(l)<<" | \n"; // window
}

//higlighat Withdraw menu
void highlight_Withdraw_MENU(int index, bool selected) { 
    int l = 0 ;
    if (selected) {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index) {
        case 1:
            l = 33 ;
            cout << "100";
            break;
        case 2:
            l = 33 ;
            cout << "500";
            break;
        case 3:
            l = 32 ;
            cout << "1000";
            break;
        case 4:
            l = 13 ;
            cout << "choose amount of money"; 
            break;
        case 5:
            l = 32 ;
            cout << "Exit";
            break;
        default:
            break;
    }

    cout << "\033[0m"  << setw(l)<<" | \n";  // window
}

//Login ATM
int login(string &id , int &password ){
    char ch;
    // Display login window frame
    system("cls");
    cout << "+-------------------------------------+\n" ;
    cout << "|              Login ATM              |\n" ;
    cout << "+-------------------------------------+\n" ;
    // Display prompts for ID and password
    cout << "\nEnter your ID: ";
    cin >> id;
    cout << "Enter your password: ";

    // Read in password character by character without displaying on screen
    password = 0;
    while ((ch = _getch()) != '\r') {  // Stop reading when user presses Enter key
        if (ch == '\b') {  // Handle backspace character
            if (password > 0) {
                password /= 10;
                cout << "\b \b";  // Move cursor back and overwrite character with space
            }
        } else if (isdigit(ch)) {  // Handle numeric characters
            password = password * 10 + (ch - '0');
            cout << "*";
        }
    } 
}

int main(){
    int password;
    int pass_id;
    string id ;
    Dataformat ID1;
    //login
    login(id , password);
    string fileindex = id + ".txt" ;
    ImportFile(ID1, fileindex);
    ifstream myfile;
    myfile.open(id + ".txt");
    
    if (ID1.Pass[0] == password ) {
        system("cls");
        cout << "+-------------------------------------+\n";
        cout << "|          Login successful!          |\n";
        cout << "+-------------------------------------+\n";
        Sleep(1000); // Wait for 1000 milliseconds
        //ATM
        do {
            system("cls"); // clear the console
            cout << "+-------------------------------------+\n";
            cout << "|              ATM Menu               |\n"; 
            cout << "+-------------------------------------+\n";
            // display the menu options
            for (int i = 1; i < 6; i++) {
            cout << "| ";
            highlight_ATM_MENU(i, i == choice);
            }
            cout << "|                                     |\n";
            cout << "+-------------------------------------+\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1) { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 5) { // down arrow key
                choice++;
            }
            } while (ch != 13); // enter key

                // display the selected option
                switch (choice) {
                    case 1:
                        // Balance Inquiry
                        system("cls");
                        cout << "+-------------------------------------+\n";
                        cout << "|           Balance Inquiry           |\n"; 
                        cout << "+-------------------------------------+\n";
                        cout << "Your current balance is: $" << fixed << setprecision(2) <<ID1.money[0] << "\n";
                        Sleep(2000); // Wait for 1000 milliseconds
                        system("cls"); // clear the console
                        cout << "+-------------------------------------+\n";
                        cout << "|           Balance Inquiry           |\n"; 
                        cout << "+-------------------------------------+\n";
                        cout << "Thank you for using this ATM. Goodbye!\n";
                        Sleep(2000); // Wait for 1000 milliseconds
                        main();
                        break;

                    case 2:
                        // Deposit
                        deposit();
                        
                        /*
                        system("cls"); // clear the console
                        cout << "+-------------------------------------+\n";
                        cout << "|               Deposit               |\n"; 
                        cout << "+-------------------------------------+\n";
                        double depositAmount;
                        cout << "Enter the amount to deposit: ";
                        cin >> depositAmount;
    
                        if (depositAmount > 0) {
                            balance += depositAmount;
                            system("cls"); // clear the console
                            cout << "+-------------------------------------+\n";
                            cout << "|               Deposit               |\n"; 
                            cout << "+-------------------------------------+\n";
                            cout << "Deposit successful!" << "\nYour new balance is: $" << fixed << setprecision(2) << ID1.money[0] << "\n";
                            Sleep(2000); // Wait for 1000 milliseconds
                            system("cls"); // clear the console
                            cout << "+-------------------------------------+\n";
                            cout << "|               Deposit               |\n"; 
                            cout << "+-------------------------------------+\n";
                            cout << "Thank you for using this ATM. Goodbye!\n";
                            Sleep(2000); // Wait for 1000 milliseconds
                            main();

                         } else {
                                    cout << "Invalid deposit amount.\n";
                                    Sleep(4000); // Wait for 1000 milliseconds
                                    main();
                                }*/
                                break;
                    
                    case 3:
                        // Withdraw
                        double withdrawAmount;
                        do{
                            system("cls");
                            cout << "+-------------------------------------+\n";
                            cout << "|               Withdraw              |\n"; 
                            cout << "+-------------------------------------+\n";
                        for (int i = 1; i < 6; i++) {
                            cout << "| ";
                            highlight_Withdraw_MENU(i, i == choice);
                            }
                            cout << "|                                     |\n";
                            cout << "+-------------------------------------+\n";

                            ch = getch(); // wait for a key press

                            // update the choice variable based on the arrow key input
                            if (ch == 72 && choice > 1) { // up arrow key
                                choice--;
                            }
                            else if (ch == 80 && choice < 6) { // down arrow key
                                choice++;
                            }
                        } while (ch != 13);
                            switch (choice)
                            {
                            case 1:
                                cout << "100";
                                withdrawAmount = 100;
                                break;
                            case 2:
                                cout << "500";
                                withdrawAmount = 500;
                                break;
                            case 3:
                                cout << "1000";
                                withdrawAmount = 1000;
                                break;
                            case 4:
                                cout << "choose amount of monney";
                                cout << "Enter the amount to withdraw: ";
                                cin >> withdrawAmount; 
                            case 5:
                                cout << "Exit";
                                main();
                                break;
                            default:
                                break;
                            }


                        if (withdrawAmount <= balance && withdrawAmount > 0) {
                                balance -= withdrawAmount;
                                system("cls"); // clear the console
                                cout << "+-------------------------------------+\n";
                                cout << "|               Withdraw              |\n"; 
                                cout << "+-------------------------------------+\n";
                                cout << "Withdrawal successful!" << "\nYour new balance is: $" << fixed << setprecision(2) << balance << "\n";
                                Sleep(2000); // Wait for 1000 milliseconds
                                system("cls"); // clear the console
                                cout << "+-------------------------------------+\n";
                                cout << "|               Withdraw              |\n"; 
                                cout << "+-------------------------------------+\n";
                                cout << "Thank you for using this ATM. Goodbye!\n";
                                Sleep(2000); // Wait for 1000 milliseconds
                                main();
                        } else {
                                    cout << "Invalid withdrawal amount.\n";
                                    Sleep(2000); // Wait for 1000 milliseconds
                                    main();
                                }
                                break;

                    case 4:
                        //Transfers money
                        system("cls"); // clear the console
                        cout << "+-------------------------------------+\n";
                        cout << "|           Transfers money           |\n"; 
                        cout << "+-------------------------------------+\n";
                        mainTransferMoney(id);
                        Sleep(2000);
                        main();
                        break;

                    case 5:
                        // Exit
                        system("cls"); // clear the console
                        cout << "+-------------------------------------+\n";
                        cout << "|                 Exit                |\n"; 
                        cout << "+-------------------------------------+\n";
                        cout << "Thank you for using this ATM. Goodbye!\n";
                        Sleep(2000); // Wait for 1000 milliseconds
                        main();// Return to login page 
                        break;
                        }

                        return 0; 
   }else {
        do{
                Login_failed();
                cout << "+-------------------------------------+\n" ;
                cout << "|     If you don't have an accoun     |\n" ;
                cout << "|    Want to create a new account?    | ";
            for (int i = 1; i < 3; i++) {
                cout << "\n| ";
                higlight_Yes_or_No(i, i == choice);
                }
                cout << "\n+-------------------------------------+\n";

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1) { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 3) { // down arrow key
                    choice++;
                }
            } while (ch != 13);
                switch (choice)
                {
                case 1:
                    cout << "Yes";
                    break;
                case 2:
                    cout << "No";
                    main();
                    break;
                default:
                    break;
                }
                 
    }
   
    
}
