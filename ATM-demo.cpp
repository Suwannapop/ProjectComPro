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
