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
string s ;

// TransferMoney
void TransferMoney(double , vector<float> &);
void ImportFile(vector<int> &, vector<float> &, string );
struct Dataformat
{
    vector<int> ID;
    vector<float> money;
};

void TranfersMoney( int id_from_menu)
{
    Dataformat ID;
    Dataformat money;
    string id, IdTranfer;
    float amount;
    id = id_from_menu;
    cout << "What ID you want to tranfer : ";
    cin >> IdTranfer;
    string userfile_1 = id+".txt";
    string userfile_2 = IdTranfer+".txt";
    ofstream writefile_1 ,writefile_2 ;
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
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

    cout << "\033[0m"  << setw(l)<<" | \n"; // window
}

//Login failed
int Login_failed (){
    system("cls");
    cout << "+-------------------------------------+" ;
    cout << "\nLogin failed. Incorrect ID or password. \n" ;
    cout << "+-------------------------------------+\n" ;
    cout << setw(28) <<"Please try again." ;
    cout << "\n+-------------------------------------+\n" ;
}

//Login ATM
int login(){
    //int id, password;
    //char ch;
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

//ทำฟังก์ชั่น เรียกฟังก์ชั่น
int main(){
    //login
    login();
    if (id-650610000 == password ) {
        string s =String.valueOf(id);
        ifstream(id);
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
                        cout << "Your current balance is: $" << fixed << setprecision(2) << balance << "\n";
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
                            cout << "Deposit successful!" << "\nYour new balance is: $" << fixed << setprecision(2) << balance << "\n";
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
                                    Sleep(2000); // Wait for 1000 milliseconds
                                    main();
                                }
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
                        TranfersMoney(id);

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
    } else {
        Login_failed();
        Sleep(1500); // Wait for 1000 milliseconds
        main();
                 
    }
    
}
