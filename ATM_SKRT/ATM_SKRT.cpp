#include <iostream>
#include <conio.h> // for getch() function
#include <ctype.h>
#include <iomanip>
#include <windows.h> //sleep higlight
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int id, password; // login
char ch;          // login && ATM
int choice = 1;   // ATM

int main();
struct Dataformat
{
    vector<int> Pass;
    vector<int> ID;
    vector<double> money;
    string name;
};

int windows(){
    for (int i = 0; i < 39 ; i++)
    {
        cout << char(205);
    }
}

int straight_line(){
    for (int i = 0; i < 39 ; i++)
    {
        cout << char(196);
    }
}

// higlight_back_to_menu_for_bill use in receipt
void higlight_back_to_menu_for_bill(int index, bool selected)
{
    int l = 0;
    cout << "              ";
    if (selected)
    {
        // cout  << "\n|           ";
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    // cout << index << ". ";

    // print the option label  cout << "|           Back To Login Menu          |\n";
    switch (index)
    {
    case 1:
        l = 14;
        cout << "Back To Login";
        break;
    default:
        break;
    }
    cout << "\033[0m" << setw(l) << " |\n"; //<< setw(l)
}

// higlight_back_to_menu use in receipt
void higlight_back_to_menu(int index, bool selected)
{
    int l = 0;
    cout << char(186) << "             ";
    if (selected)
    {
        // cout  << "\n|           ";
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    // cout << index << ". ";

    // print the option label  cout << "|           Back To Login Menu          |\n";
    switch (index)
    {
    case 1:
        l = 14;
        cout << "Back To Login";
        break;
    default:
        break;
    }
    cout << "\033[0m" << setw(l) << char(186); //<< setw(l)
}

void receipt_depos(Dataformat ID1, float amount)
{
    if (amount > 0)
    {
        do
        {
            system("cls");
            cout << " _______________________________________\n";
            cout << "|                                       |\n";
            cout << "|               + "<< "\033[1;1m"<<"RECEIPT"<< "\033[0m"<<" +             |\n";
            cout << "|                 DEPOSIT               |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "| Name :" << setw(31) << ID1.name << " |\n";
            cout << "| Account :" << setw(28) << ID1.ID[0] << " |\n";
            cout << "| Deposit Amount :  " << fixed << setw(19) << setprecision(2) << amount << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "| Total : " << fixed << setw(29) << setprecision(2) << ID1.money[0] << setw(3) << "|\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "|               "<< "\033[1;3m"<<"Skrt Bank <3"<< "\033[0m"<<"            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |\n";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                cout << "|";
                higlight_back_to_menu_for_bill(i, i == choice);
            }
            cout << "|_______________________________________|\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "\n|           ";
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }
    else
    {
        do
        {
            system("cls"); // clear the console
            cout << "+_______________________________________+\n";
            cout << "|                 Deposit               |\n";
            cout << "|             Invalid! amount.          |\n";
            cout << "|=======================================|\n";
            cout << "|                                       |\n";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                cout << "|";
                higlight_back_to_menu_for_bill(i, i == choice);
            }
            cout << "|_______________________________________|\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }
}

void receipt_wdraw(Dataformat ID1, float amount)
{
    if (amount > 0)
    {
        do
        {
            system("cls"); // clear the console
            cout << " _______________________________________\n";
            cout << "|                                       |\n";
            cout << "|               + "<< "\033[1;1m"<<"RECEIPT"<< "\033[0m"<<" +             |\n";
            cout << "|                 WITHDRAW              |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "| Name :" << setw(31) << ID1.name << " |\n";
            cout << "| Account :" << setw(28) << ID1.ID[0] << " |\n";
            cout << "| Withdraw Amount : " << fixed << setw(19) << setprecision(2) << amount << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "| Total : " << fixed << setw(29) << setprecision(2) << ID1.money[0] << setw(3) << "|\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "|               "<< "\033[1;3m"<<"Skrt Bank <3"<< "\033[0m"<<"            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |\n";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                cout << "|";
                higlight_back_to_menu_for_bill(i, i == choice);
            }
            cout << "|_______________________________________|\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }
    else
    {
        do
        {
            system("cls"); // clear the console
            cout << "+_______________________________________+\n";
            cout << "|                 Deposit               |\n";
            cout << "|             Invalid! amount.          |\n";
            cout << "|=======================================|\n";
            cout << "|                                       |\n";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                cout << "|";
                higlight_back_to_menu_for_bill(i, i == choice);
            }
            cout << "|_______________________________________|\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login ";
            main();
            break;
        default:
            main();
            break;
        }
    }
}

void receipt_transf(Dataformat ID1, Dataformat ID2, float amount)
{
    if (amount > 0)
    {
        do
        {
            system("cls"); // clear the console
            cout << " _______________________________________\n";
            cout << "|                                       |\n";
            cout << "|               + "<< "\033[1;1m"<<"RECEIPT"<< "\033[0m"<<" +             |\n";
            cout << "|             TRANSFER MONEY            |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "| Name :" << setw(31) << ID1.name << " |\n";
            cout << "| Account :" << setw(28) << ID1.ID[0] << " |\n";
            cout << "| Transfer Amount : " << fixed << setw(19) << setprecision(2) << amount << " |\n";
            cout << "| Total : " << fixed << setw(29) << setprecision(2) << ID1.money[0] << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "| ------------- transfer to ----------- |\n";
            cout << "|                                       |\n";
            cout << "| Name :" << setw(31) << ID2.name << " |\n";
            cout << "| Account :" << setw(28) << ID2.ID[0] << " |\n";
            cout << "|                                       |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "|               "<< "\033[1;3m"<<"Skrt Bank <3"<< "\033[0m"<<"            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |\n";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                cout << "|";
                higlight_back_to_menu_for_bill(i, i == choice);
            }
            cout << "|_______________________________________|\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }
    else
    {
        do
        {
            system("cls"); // clear the console
            cout << "+_______________________________________+\n";
            cout << "|                 Deposit               |\n";
            cout << "|             Invalid! amount.          |\n";
            cout << "|=======================================|\n";
            cout << "|                                       |\n";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                cout << "|";
                higlight_back_to_menu_for_bill(i, i == choice);
            }
            cout << "|_______________________________________|\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }
}

void receipt_paybill(Dataformat ID1, Dataformat ID2, float amount)
{
    if (amount > 0)
    {
        do
        {
            system("cls"); // clear the console
            cout << " _______________________________________\n";
            cout << "|                                       |\n";
            cout << "|               + "<< "\033[1;1m"<<"RECEIPT"<< "\033[0m"<<" +             |\n";
            cout << "|                 PAYBILL               |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "| Name :" << setw(31) << ID1.name << " |\n";
            cout << "| Pay Amount :  " << fixed << setw(23) << setprecision(2) << amount << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "| Total : " << fixed << setw(29) << setprecision(2) << ID1.money[0] << setw(3) << "|\n";
            cout << "| ------------- transfer to ----------- |\n";
            cout << "|                                       |\n";
            cout << "| Name :" << setw(31) << ID2.name << " |\n";
            cout << "|                                       |\n";
            //        cout << "| Total : " << fixed << setw(29) << setprecision(2) << ID2.money[0] << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "|               "<< "\033[1;3m"<<"Skrt Bank <3"<< "\033[0m"<<"            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |\n";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                cout << "|";
                higlight_back_to_menu_for_bill(i, i == choice);
            }
            cout << "|_______________________________________|\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }else{
        do
        {
            system("cls"); // clear the console
            cout << "+_______________________________________+\n";
            cout << "|                 Deposit               |\n";
            cout << "|             Invalid! amount.          |\n";
            cout << "|=======================================|\n";
            cout << "|                                       |\n";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                cout << "|";
                higlight_back_to_menu_for_bill(i, i == choice);
            }
            cout << "|_______________________________________|\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }
}

// higlight_new_account_Yes_or_No
void higlight_new_account_Yes_or_No(int index, bool selected)
{
    int l = 0;
    if (selected)
    {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index)
    {
    case 1:
        l = 27;
        cout << "Try again";
        break;
    case 2:
        l = 32;
        cout << "Exit";
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << char(186); // window
}

// new_account
int new_account()
{
    system("cls");
    int UserPass1, UserPass2, UserID, money;
    string name;
    cout << char(201) ; windows(); cout << char(187) << endl;
    cout << char(186) << "           Create your account         " << char(186) << endl;
    cout << char(186) << "  Do you want to create a new account? " << char(186) << endl;
    cout << char(200) ; windows(); cout << char(188) << endl;
    cout << " What is your name: ";
    getline(cin, name);
    cin >> name;
    cout << " Enter your ID: ";
    cin >> UserID;
    cout << " Enter your password: ";
    UserPass1 = 0;
    while ((ch = _getch()) != '\r')
    { // Stop reading when user presses Enter key
        if (ch == '\b')
        { // Handle backspace character
            if (UserPass1 > 0)
            {
                UserPass1 /= 10;
                cout << "\b \b"; // Move cursor back and overwrite character with space
            }
        }
        else if (isdigit(ch))
        { // Handle numeric characters
            UserPass1 = UserPass1 * 10 + (ch - '0');
            cout << "*";
        }
    }

    cout << "\n Confirm password: ";
    UserPass2 = 0;
    while ((ch = _getch()) != '\r')
    { // Stop reading when user presses Enter key
        if (ch == '\b')
        { // Handle backspace character
            if (UserPass2 > 0)
            {
                UserPass2 /= 10;
                cout << "\b \b"; // Move cursor back and overwrite character with space
            }
        }
        else if (isdigit(ch))
        { // Handle numeric characters
            UserPass2 = UserPass2 * 10 + (ch - '0');
            cout << "*";
        }
    }
    if (UserPass1 == UserPass2)
    {
        cout << "\n Enter your money: ";
        cin >> money;
        if (money >= 0)
        {
            string identification = to_string(UserID);
            string filename = to_string(UserID) + ".txt";
            ofstream outfile(filename);
            if (outfile.is_open())
            {
                outfile << UserPass1 << "," << identification << "," << money << "," << name;
                outfile.close();
                do
                {
                    system("cls"); // clear the console
                    cout << char(201) ; windows(); cout << char(187) << endl;
                    cout << char(186) << "          Created successfully         " << char(186) << endl;
                    cout << char(204) ; windows(); cout << char(185) << endl;
                    cout << char(186) << "                                       " << char(186) << endl;
                    cout << char(186) << " Created successfully " << setw(16) << name << " " << char(186) << endl;
                    cout << char(186) << " Now you have money : " << setw(12) << money << " THB " << char(186) << endl;
                    cout << char(199) << "---------------------------------------" << char(182) << endl;
                    cout << char(186) << "                                       " << char(186) << endl;
                    // display the menu options
                    for (int i = 1; i < 2; i++)
                    {
                        higlight_back_to_menu(i, i == choice);
                    }
                    cout << endl
                         << char(200) ; windows(); cout << char(188) << endl;

                    ch = getch(); // wait for a key press

                    // update the choice variable based on the arrow key input
                    if (ch == 72 && choice > 1)
                    { // up arrow key
                        choice--;
                    }
                    else if (ch == 80 && choice < 2)
                    { // down arrow key
                        choice++;
                    }
                } while (ch != 13); // enter key
                // display the selected option
                switch (choice)
                {
                case 1:
                    cout << "Back To Login Menu";
                    main();
                    break;
                default:
                    main();
                    break;
                }
            }
        }
        else
        {
            do
            {
                system("cls");
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "              Invalid amount           " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << setw(30) << "Please try again." << setw(10) << char(186) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;

                // display the menu options
                for (int i = 1; i < 3; i++)
                {
                    cout << "\n"
                         << char(186) << " ";
                    higlight_new_account_Yes_or_No(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 5)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Try again";
                new_account();
                break;
            case 2:
                cout << "Exit";
                main();
                break;
            default:
                main();
                break;
            }
        }
    }
    else
    {
        do
        {
            system("cls");
            cout << char(201) ; windows(); cout << char(187) << endl;
            cout << char(186) << "          Passwords do not match       " << char(186) << endl;
            cout << char(204) ; windows(); cout << char(185) << endl;
            cout << char(186) << setw(30) << "Please try again." << setw(10) << char(186) << endl;
            cout << char(199) << "---------------------------------------" << char(182);
            // display the menu options
            for (int i = 1; i < 3; i++)
            {
                cout << "\n"
                     << char(186) << " ";
                higlight_new_account_Yes_or_No(i, i == choice);
            }
            cout << endl
                 << char(200) ; windows(); cout << char(188) << endl;

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 5)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Try again";
            new_account();
            break;
        case 2:
            cout << "Exit";
            main();
            break;
        default:
            main();
            break;
        }
    }
}

// deposit
void deposit(Dataformat &ID1, string userfile_1);
void ImportFile(Dataformat &ID, string fileindex, bool check = false);

int main_deposit(Dataformat ID1, string userfile_1)
{
    ImportFile(ID1, userfile_1);
    deposit(ID1, userfile_1);
}

// higlight_deposit
void higlight_deposit(int index, bool selected)
{
    int l = 0;
    if (selected)
    {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index)
    {
    case 1:
        l = 30;
        cout << "20 THB";
        break;
    case 2:
        l = 30;
        cout << "50 THB";
        break;
    case 3:
        l = 29;
        cout << "100 THB";
        break;
    case 4:
        l = 29;
        cout << "200 THB";
        break;
    case 5:
        l = 29;
        cout << "500 THB";
        break;
    case 6:
        l = 28;
        cout << "1000 THB";
        break;
    case 7:
        l = 10;
        cout << "Choose your own Deposition";
        break;
    case 8:
        l = 19;
        cout << "cancel Deposition";
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << char(186) << endl; // window
}

void deposit(Dataformat &ID1, string userfile_1)
{
    ofstream writefile_1;
    int option = 0;
    float amount;
    bool notfinished = true;

    do
    {
        system("cls"); // clear the console
        cout << char(201) ; windows(); cout << char(187) << endl;
        cout << char(186) << "                Deposit                " << char(186) << endl;
        cout << char(204) ; windows(); cout << char(185) << endl;
        // display the menu options
        for (int i = 1; i < 9; i++)
        {
            cout << char(186) << " ";
            higlight_deposit(i, i == choice);
        }
        // cout << "|                                     |\n";
        cout << char(200) ; windows(); cout << char(188) << endl;

        ch = getch(); // wait for a key press

        // update the choice variable based on the arrow key input
        if (ch == 72 && choice > 1)
        { // up arrow key
            choice--;
        }
        else if (ch == 80 && choice < 8)
        { // down arrow key
            choice++;
        }
        // cout << "How much money do you want to deposit? :" << endl;
        // cout << "choose a deposit option (1-7)" << endl;

    } while (ch != 13);
    switch (choice)
    {
    case 1:
        // cout << "1 - $20" ;
        ID1.money[0] = ID1.money[0] + 20;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1, 20);
        break;
    case 2:
        // cout << "2 - $50" ;
        ID1.money[0] = ID1.money[0] + 50;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1, 50);
        break;
    case 3:
        // cout << "3 - $100" ;
        ID1.money[0] = ID1.money[0] + 100;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1, 100);
        break;
    case 4:
        // cout << "4 - $200" ;
        ID1.money[0] = ID1.money[0] + 200;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1, 200);
        break;
    case 5:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] + 500;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1, 500);
        break;
    case 6:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] + 1000;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1, 1000);
        break;
    case 7:
        // cout << "6 - choose your own deposition amount" ;
        system("cls"); // clear the console
        cout << char(201) ; windows(); cout << char(187) << endl;
        cout << char(186) << "                Deposit                " << char(186) << endl;
        cout << char(186) << "           Enter your amount.          " << char(186) << endl;
        cout << char(200) ; windows(); cout << char(188) << endl;
        cout << "          THB : ";
        cin >> amount;
        if (amount > 0)
        {
            ID1.money[0] = ID1.money[0] + amount;
            notfinished = false;
            writefile_1.open(userfile_1);
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
            writefile_1.close();
            receipt_depos(ID1, amount);
            break;
        }
        else
        {
            do
            {
                system("cls"); // clear the console
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "                Deposit                " << char(186) << endl;
                cout << char(186) << "       Invalid! Please try again.      " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Back To Login Menu";
                main();
                break;
            default:
                main();
                break;
            }
            break;
        }

    case 8:
        // cout << "7 - cancel deposition \n";
        notfinished = false;
        do
        {
            system("cls"); // clear the console
            cout << char(201) ; windows(); cout << char(187) << endl;
            cout << char(186) << "                Deposit                " << char(186) << endl;
            cout << char(186) << "          Deposition canceled.         " << char(186) << endl;
            cout << char(204) ; windows(); cout << char(185) << endl;
            cout << char(186) << "                                       " << char(186) << endl;
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                higlight_back_to_menu(i, i == choice);
            }
            cout << endl
                 << char(200) ; windows(); cout << char(188) << endl;

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
        break;
    default:
        main();
        break;
    }
}
// higlight_yes_or_No
void higlight_Yes_or_No(int index, bool selected)
{
    // int l = 0;
    if (selected)
    {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    // cout << index << ". ";

    // print the option label
    switch (index)
    {
    case 1:
        // l = 5;
        cout << "Yes";
        break;
    case 2:
        // l = 5;
        cout << "No";
        break;
    default:
        break;
    }

    cout << "\033[0m"
         << "  "; //<< setw(l)  // window
}

// Login failed
int Login_failed()
{
    do
    {
        system("cls");
        cout << char(201) ; windows(); cout << char(187) << endl;
        cout << char(186) << "              Login failed.            " << char(186) << endl;
        cout << char(186) << "        Incorrect ID or password.      " << char(186) << endl;
        cout << char(204) ; windows(); cout << char(185) << endl;
        cout << char(186) << setw(29) << "Please try again." << setw(11) << char(186) << endl;
        cout << char(199) << "---------------------------------------" << char(182) << endl;
        cout << char(186) << "                                       " << char(186) << endl;
        // display the menu options
        for (int i = 1; i < 2; i++)
        {
            higlight_back_to_menu(i, i == choice);
        }
        cout << endl
             << char(200) ; windows(); cout << char(188) << endl;

        ch = getch(); // wait for a key press

        // update the choice variable based on the arrow key input
        if (ch == 72 && choice > 1)
        { // up arrow key
            choice--;
        }
        else if (ch == 80 && choice < 1)
        { // down arrow key
            choice++;
        }
    } while (ch != 13); // enter key
    // display the selected option
    switch (choice)
    {
    case 1:
        cout << "Back To Login Menu";
        main();
        break;
    default:
        break;
    }
}

void ImportFile(Dataformat &ID, string fileindex, bool check) // ใช้ฝากถอนโอน
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    double balnace;
    char name[99];

    if (check = false)
    {
        if (data.is_open())
        {
            while (getline(data, line)) // importfile
            {
                sscanf(line.c_str(), "%d,%d,%lf,%s", &pass, &idnumber, &balnace, name);
                ID.Pass.push_back(pass);
                ID.ID.push_back(idnumber);
                ID.money.push_back(balnace);
                ID.name = name;
            }
        }
    }
    else if (check = true)
    {
        if (data.is_open())
        {
            while (getline(data, line)) // importfile
            {
                sscanf(line.c_str(), "%d,%d,%lf,%s", &pass, &idnumber, &balnace, name);
                ID.Pass.push_back(pass);
                ID.ID.push_back(idnumber);
                ID.money.push_back(balnace);
                ID.name = name;
            }
        }
        else
        {
            do
            {
                system("cls");
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                cout << char(186) << "       Don't have ID in Database       " << char(186) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "     If you don't have an account      " << char(186) << endl;
                cout << char(186) << "  Do you want to create a new account? " << char(186) << endl;
                cout << char(186) << "               ";
                // display the menu options
                // higlight_Yes_or_No
                for (int i = 1; i < 3; i++)
                {
                    higlight_Yes_or_No(i, i == choice);
                }
                cout << "               " << char(186);
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 3)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13);
            switch (choice)
            {
            case 1:
                new_account();
                main();
                break;
            case 2:
                cout << "No";
                main();
                break;
            default:
                main();
                break;
            }
        }
    }
}

// ใช้สำหรับแก้บัคตอนโอนเงิน
void ImportFile_T(Dataformat &ID, string fileindex, bool check) // ใช้ฝากถอนโอน
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    double balnace;
    char name[99];

    if (check = false)
    {
        if (data.is_open())
        {
            while (getline(data, line)) // importfile
            {
                sscanf(line.c_str(), "%d,%d,%lf,%s", &pass, &idnumber, &balnace, name);
                ID.Pass.push_back(pass);
                ID.ID.push_back(idnumber);
                ID.money.push_back(balnace);
                ID.name = name;
            }
        }
    }
    else if (check = true)
    {
        if (data.is_open())
        {
            while (getline(data, line)) // importfile
            {
                sscanf(line.c_str(), "%d,%d,%lf,%s", &pass, &idnumber, &balnace, name);
                ID.Pass.push_back(pass);
                ID.ID.push_back(idnumber);
                ID.money.push_back(balnace);
                ID.name = name;
            }
        }
        else
        {
            do
            {
                system("cls");
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                cout << char(186) << "       Don't have ID in Database       " << char(186) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Back To Login Menu";
                main();
                break;
            default:
                main();
                break;
            }
        }
    }
}

/*void TransferMoney(double amount, Dataformat &ID1, Dataformat &ID2) // เเปปปกติ // Kong(ล่าสุดเอาไปยัดไว้ในฟังก์ชั่นหลักการโอนล่ะ)
{
    if (amount > 0)
    {
        if (amount > ID1.money[0])
        {
            cout << "You don't have enough money\n";
            cout << "Now you have money : " << ID1.money[0] << " You can't tranfer money\n";
            Sleep(2000);
        }
        else
        {

            ID1.money[0] = ID1.money[0] - amount;
            ID2.money[0] = ID2.money[0] + amount;

            receipt_transf(ID1,ID2,amount);
        }
    }
    else if (amount <= 0)
    {
        cout << "You can't tranfer money less than 0 or = 0\n";
        Sleep(2000);
    }
}*/

void mainTransferMoney(string id)
{
    Dataformat ID1;
    Dataformat ID2;
    string IdTranfer;
    float amount;
    system("cls"); // clear the console
    cout << char(201) ; windows(); cout << char(187) << endl;
    cout << char(186) << "             TransferMoney             " << char(186) << endl;
    cout << char(200) ; windows(); cout << char(188) << endl;
    cout << "           Destination Account         \n";   
//    cout << "      Do What ID you want to tranfer   \n";
    cout << "             ID : ";
    cin >> IdTranfer;
    string userfile_1 = id + ".txt";
    string userfile_2 = IdTranfer + ".txt";
    ofstream writefile_1, writefile_2;
    ImportFile(ID1, userfile_1);         // importfile
    ImportFile_T(ID2, userfile_2, true); // Bug , true

    if (userfile_1 == userfile_2)
    {
        do
        {
            system("cls"); // clear the console
            cout << char(201) ; windows(); cout << char(187) << endl;
            cout << char(186) << "             TransferMoney             " << char(186) << endl;
            cout << char(204) ; windows(); cout << char(185) << endl;
            cout << char(186) << "            This is your ID            " << char(186) << endl;
            cout << char(186) << "         can't transfer money          " << char(186) << endl;
            cout << char(186) << "                                       " << char(186) << endl;
            cout << char(204) ; windows(); cout << char(185) << endl;
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                higlight_back_to_menu(i, i == choice);
            }
            cout << endl
                 << char(200) ; windows(); cout << char(188) << endl;

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 1)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }
    else
    {
        straight_line(); cout << char(196) << char(196)  << endl;
        //cout << "=========================================" << endl;
        cout << "             How much money  \n";
        cout << "             THB : ";
        cin >> amount;
        if (amount > 0)
        {
            if (amount > ID1.money[0])
            {
                do
                {
                    system("cls"); // clear the console
                    cout << char(201) ; windows(); cout << char(187) << endl;
                    cout << char(186) << "             TransferMoney             " << char(186) << endl;
                    cout << char(204) ; windows(); cout << char(185) << endl;
                    cout << char(199) << "---------------------------------------" << char(182) << endl;
                    cout << char(186) << "       You don't have enough money     " << char(186) << endl;
                    cout << char(186) << " Now you have money : " << fixed << setw(12) << ID1.money[0] << " THB " << char(186) << endl;
                    cout << char(199) << "---------------------------------------" << char(182) << endl;
                    cout << char(204) ; windows(); cout << char(185) << endl;
                    cout << char(186) << "                                       " << char(186) << endl;
                    // display the menu options
                    for (int i = 1; i < 2; i++)
                    {
                        higlight_back_to_menu(i, i == choice);
                    }
                    cout << endl
                         << char(200) ; windows(); cout << char(188) << endl;

                    ch = getch(); // wait for a key press

                    // update the choice variable based on the arrow key input
                    if (ch == 72 && choice > 1)
                    { // up arrow key
                        choice--;
                    }
                    else if (ch == 80 && choice < 1)
                    { // down arrow key
                        choice++;
                    }
                } while (ch != 13); // enter key
                // display the selected option
                switch (choice)
                {
                case 1:
                    cout << "Back To Login Menu";
                    main();
                    break;
                default:
                    main();
                    break;
                }
            }
            else
            {

                ID1.money[0] = ID1.money[0] - amount;
                ID2.money[0] = ID2.money[0] + amount;

                writefile_1.open(userfile_1);
                writefile_2.open(userfile_2);
                writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name << endl;
                writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << ID2.money[0] << "," << ID2.name << endl;
                writefile_1.close();
                writefile_2.close();

                receipt_transf(ID1, ID2, amount);
            }
        }
        else if (amount <= 0)
        {
            do
            {
                system("cls"); // clear the console
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "             TransferMoney             " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "            invalid amount             " << char(186) << endl; // ม่ายมีตังค่าาา แก้ให้ถูกด้วย
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Back To Login Menu";
                main();
                break;
            default:
                main();
                break;
            }
        }

        /*
         TransferMoney(amount, ID1, ID2);
         writefile_1.open(userfile_1);
         writefile_2.open(userfile_2);
         writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name<< endl;
         writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << ID2.money[0] << "," << ID2.name<< endl;
         writefile_1.close();
         writefile_2.close();
         */
    }
}

// higlight atm menu
void highlight_ATM_MENU(int index, bool selected)
{
    int l = 0;
    if (selected)
    {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index)
    {
    case 1:
        l = 21;
        cout << "Balance Inquiry"; // เช็ค
        break;
    case 2:
        l = 29;
        cout << "Deposit"; // ฝาก
        break;
    case 3:
        l = 28;
        cout << "Withdraw"; // ถอน
        break;
    case 4:
        l = 21;
        cout << "Transfers money"; // โอน
        break;
    case 5:
        l = 29;
        cout << "Payment"; // จ่ายบิลลลลลลลลล
        break;
    case 6:
        l = 32;
        cout << "Exit"; // ออก
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << char(186) << endl; // window
}

// Login ATM
int login(string &id, int &password)
{
    char ch;
    // Display login window frame
    system("cls");
    cout << char(201) ; windows(); cout << char(187) << endl;
    cout << char(186) << "               " << "\033[1;1m""Login ATM" << "\033[0m""               " << char(186) << endl;
    cout << char(200) ; windows(); cout << char(188) << endl;
    // Display prompts for ID and password
    cout << "\n Enter your ID: ";
    cin >> id;
    cout << " Enter your Password: ";

    // Read in password character by character without displaying on screen
    password = 0;
    while ((ch = _getch()) != '\r')
    { // Stop reading when user presses Enter key
        if (ch == '\b')
        { // Handle backspace character
            if (password >= 0)
            {
                password /= 10;
                cout << "\b \b"; // Move cursor back and overwrite character with space
            }
        }
        else if (isdigit(ch))
        { // Handle numeric characters 
            //password = password * 10 ;
            //cout << password <<  endl ; 
            // 1  10  + 2-0
            password = password * 10 + (ch - '0');
            //cout << password <<  endl ;
            cout << "*";
        }
    }
}

// higlighat Withdraw menu
void higlight_Withdraw(int index, bool selected)
{
    int l = 0;
    if (selected)
    {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index)
    {
    case 1:
        l = 30;
        cout << "20 THB";
        break;
    case 2:
        l = 30;
        cout << "50 THB";
        break;
    case 3:
        l = 29;
        cout << "100 THB";
        break;
    case 4:
        l = 29;
        cout << "200 THB";
        break;
    case 5:
        l = 29;
        cout << "500 THB";
        break;
    case 6:
        l = 28;
        cout << "1000 THB";
        break;
    case 7:
        l = 12;
        cout << "Choose your own Withdraw";
        break;
    case 8:
        l = 21;
        cout << "cancel Withdraw";
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << char(186) << endl; // window
}

void Withdraw(double, Dataformat &);
void mainWithdraw(Dataformat ID1, string userfile_1)
{
    float amount;
    ofstream writefile_1;
    ImportFile(ID1, userfile_1);
    Withdraw(amount, ID1);

    do
    {
        system("cls"); // clear the console
        cout << char(201) ; windows(); cout << char(187) << endl;
        cout << char(186) << "                Withdraw               " << char(186) << endl;
        // cout << char(186) <<"       You don't have enough money.    " << char(186) << endl;
        cout << char(204) ; windows(); cout << char(185) << endl;
        // display the menu options
        for (int i = 1; i < 9; i++)
        {
            cout << char(186) << " ";
            higlight_Withdraw(i, i == choice);
        }
        // cout << "|                                     |\n";
        cout << char(200) ; windows(); cout << char(188) << endl;

        ch = getch(); // wait for a key press

        // update the choice variable based on the arrow key input
        if (ch == 72 && choice > 1)
        { // up arrow key
            choice--;
        }
        else if (ch == 80 && choice < 8)
        { // down arrow key
            choice++;
        }
        // cout << "How much money do you want to deposit? :" << endl;
        // cout << "choose a deposit option (1-7)" << endl;

    } while (ch != 13);
    switch (choice)
    {
    case 1:
        // cout << "1 - $20" ;
        ID1.money[0] = ID1.money[0] - 20;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1, 20);
        break;
    case 2:
        // cout << "2 - $50" ;
        ID1.money[0] = ID1.money[0] - 50;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1, 50);
        break;
    case 3:
        // cout << "3 - $100" ;
        ID1.money[0] = ID1.money[0] - 100;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1, 100);
        break;
    case 4:
        // cout << "4 - $200" ;
        ID1.money[0] = ID1.money[0] - 200;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1, 200);
        break;
    case 5:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] - 500;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1, 500);
        break;
    case 6:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] - 1000;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1, 100);
        break;
    case 7:
        // cout << "6 - choose your own Withdraw amount" ;
        system("cls"); // clear the console
        cout << char(201) ; windows(); cout << char(187) << endl;
        cout << char(186) << "               Withdraw                " << char(186) << endl;
        cout << char(186) << "           Enter your amount.          " << char(186) << endl;
        cout << char(200) ; windows(); cout << char(188) << endl;
        cout << "          THB : ";
        cin >> amount;
        if (ID1.money[0] - amount >= 0 && amount >= 0)
        {
            ID1.money[0] = ID1.money[0] - amount;
            writefile_1.open(userfile_1);
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name;
            writefile_1.close();
            receipt_wdraw(ID1, amount);
            break;
        }
        else if (ID1.money[0] - amount < 0 && amount >= 0)
        {
            do
            {
                system("cls"); // clear the console
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "                Withdraw               " << char(186) << endl;
                cout << char(186) << "       You don't have enough money.    " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(186) << " Now you have money : " << fixed << setw(12) << ID1.money[0] << " THB " << char(186) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Back To Login Menu";
                main();
                break;
            default:
                main();
                break;
            }
            break;
        }
        else
        {
            do
            {
                system("cls"); // clear the console
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "                Withdraw               " << char(186) << endl;
                cout << char(186) << "       Invalid! Please try again.      " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Back To Login Menu";
                main();
                break;
            default:
                main();
                break;
            }
            break;
        }

    case 8:
        // cout << "7 - cancel deposition \n";
        do
        {
            system("cls"); // clear the console
            cout << char(201) ; windows(); cout << char(187) << endl;
            cout << char(186) << "                Withdraw               " << char(186) << endl;
            cout << char(186) << "          Deposition canceled.         " << char(186) << endl;
            cout << char(204) ; windows(); cout << char(185) << endl;
            cout << char(186) << "                                       " << char(186) << endl;
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                higlight_back_to_menu(i, i == choice);
            }
            cout << endl
                 << char(200) ; windows(); cout << char(188) << endl;

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 2)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
        break;
    default:
        main();
        break;
    }
}

void Withdraw(double amount, Dataformat &ID1)
{
    if (amount > 0)
    {
        if (amount > ID1.money[0])
        {
            cout << "You don't have enough money\n";
            cout << "Now you have money : " << setprecision(2) << ID1.money[0] << " You can't withdraw money\n";
        }
        else
        {
            ID1.money[0] = ID1.money[0] - amount;
        }
    }
}

void payebill(double amount, Dataformat &ID1, Dataformat &ID2);

void main_payebill(string id) // ไฟฟ้า ไม่เขียนดีๆ ก๋อง ขก แก้ละตามนี้เลย555
{
    Dataformat ID1;
    Dataformat ID2;
    // string id, Idbill;
    float amount;
    // cout << "input your id : ";
    // cin >> id;
    // cout << "What ID you want to pay bill : ";
    // cin >> Idbill;
    system("cls"); // clear the console
    cout << char(201) ; windows(); cout << char(187) << endl;
    cout << char(186) << "           Electricity Bill            " << char(186) << endl;
    cout << char(200) ; windows(); cout << char(188) << endl;
    cout << "       How much do you want to pay?  \n";
    cout << "              THB : ";
    cin >> amount;

    string userfile_1 = id + ".txt";
    string userfile_2 = "777777777.txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID1, userfile_1);
    ImportFile_T(ID2, userfile_2, true);
    payebill(amount, ID1, ID2);

    /*ถ้าใส่ฟังก์ชั่นสลีปละลบอันนี้ด้วย
    cout << "You Pay Bill from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    Sleep(2000);
    */

    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(10000) << ID1.money[0] << "," << ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(10000) << ID2.money[0] << "," << ID2.name << endl;
    writefile_1.close();
    writefile_2.close();

    // เรียกฟังก์ชั่นสลีปใบเสร็จตรงนี้นะ
    receipt_paybill(ID1, ID2, amount);
}

void payebill(double amount, Dataformat &ID1, Dataformat &ID2)
{
    if (amount > 0)
    {
        if (amount > ID1.money[0])
        {
            do
            {
                system("cls"); // clear the console
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "             + RECEIPT +               " << char(186) << endl;
                cout << char(186) << "       You don't have enough money.    " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(186) << " Now you have money : " << fixed << setw(12) << setprecision(2) << ID1.money[0] << " THB " << char(186) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Back To Login Menu";
                main();
                break;
            default:
                main();
                break;
            }
        }
        else
        {
            ID1.money[0] = ID1.money[0] - amount;
            ID2.money[0] = ID2.money[0] + amount;
        }
    }
}

void paywaterbill(double amount, Dataformat &ID1, Dataformat &ID2);

void main_paywaterbill(string id)
{
    Dataformat ID1;
    Dataformat ID2;
    float amount;
    // cout << "input your id : ";
    // cin >> id;
    string userfile_1 = id + ".txt";
    // cout << "What Game ID you want to top up: ";
    // cin >> IdTopup;
    system("cls"); // clear the console
    cout << char(201) ; windows(); cout << char(187) << endl;
    cout << char(186) << "               Water Bill              " << char(186) << endl;
    cout << char(200) ; windows(); cout << char(188) << endl;
    cout << "       How much do you want to pay?  \n";
    cout << "              THB : ";
    cin >> amount;

    string userfile_2 = "666666666.txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID1, userfile_1);
    ImportFile_T(ID2, userfile_2, true);
    paywaterbill(amount, ID1, ID2);

    /*ถ้าใส่ฟังก์ชั่นสลีปละลบอันนี้ด้วย
    cout << "You top up money from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    Sleep(2000);
    */

    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(10000) << ID1.money[0] << "," << ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(10000) << ID2.money[0] << "," << ID2.name << endl;
    writefile_1.close();
    writefile_2.close();

    // เรียกฟังก์ชั่นสลีปใบเสร็จตรงนี้นะ
    receipt_paybill(ID1, ID2, amount);
}

void paywaterbill(double amount, Dataformat &ID1, Dataformat &ID2)
{
    if (amount > 0)
    {
        if (amount > ID1.money[0])
        {
            do
            {
                system("cls"); // clear the console
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "             + RECEIPT +               " << char(186) << endl;
                cout << char(186) << "       You don't have enough money.    " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(186) << " Now you have money : " << fixed << setw(12) << setprecision(2) << ID1.money[0] << " THB " << char(186) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
        // display the selected option
        switch (choice)
        {
        case 1:
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
            break;
        }
    }
    else
    {
        ID1.money[0] = ID1.money[0] - amount;
        ID2.money[0] = ID2.money[0] + amount;
         }
    }
}

void topup(double amount, Dataformat &ID1, Dataformat &ID2);
void main_topup(string id)
{
    Dataformat ID1;
    Dataformat ID2;
    float amount;
    // cout << "input your id : ";
    // cin >> id;
    string userfile_1 = id + ".txt";
    // cout << "What Game ID you want to top up: ";
    // cin >> IdTopup;
    system("cls"); // clear the console
    cout << char(201) ; windows(); cout << char(187) << endl;
    cout << char(186) << "               Game Topup              " << char(186) << endl;
    cout << char(200) ; windows(); cout << char(188) << endl;
    cout << "       How much do you want to pay?  \n";
    cout << "              THB : ";
    cin >> amount;

    string userfile_2 = "999999999.txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID1, userfile_1);
    ImportFile_T(ID2, userfile_2, true);
    topup(amount, ID1, ID2);

    /*ถ้าใส่ฟังก์ชั่นสลีปละลบอันนี้ด้วย
    cout << "You top up money from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    Sleep(2000);
    */

    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(10000) << ID1.money[0] << "," << ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(10000) << ID2.money[0] << "," << ID2.name << endl;
    writefile_1.close();
    writefile_2.close();

    // เรียกฟังก์ชั่นสลีปใบเสร็จตรงนี้นะ
    receipt_paybill(ID1, ID2, amount);
}

void topup(double amount, Dataformat &ID1, Dataformat &ID2)
{
    if (amount > 0)
    {
        if (amount > ID1.money[0])
        {
            do
            {
                system("cls"); // clear the console
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "             + RECEIPT +               " << char(186) << endl;
                cout << char(186) << "       You don't have enough money.    " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(186) << " Now you have money : " << fixed << setw(12) << setprecision(2) << ID1.money[0] << " THB " << char(186) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Back To Login Menu";
                main();
                break;
            default:
                main();
                break;
            }
        }
        else
        {
            ID1.money[0] = ID1.money[0] - amount;
            ID2.money[0] = ID2.money[0] + amount;
        }
    }
}

void PhoneBill(double amount, Dataformat &ID1, Dataformat &ID2);
void main_PhoneBill(string id)
{
    Dataformat ID1;
    Dataformat ID2;
    // string id, IdTopup;
    float amount;
    // cout << "input your id : ";
    // cin >> id;
    system("cls"); // clear the console
    cout << char(201) ; windows(); cout << char(187) << endl;
    cout << char(186) << "               Phone Bill              " << char(186) << endl;
    cout << char(200) ; windows(); cout << char(188) << endl;
    cout << "       How much do you want to pay?  \n";
    cout << "              THB : ";
    cin >> amount;

    string userfile_1 = id + ".txt";
    string userfile_2 = "888888888.txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID1, userfile_1);
    ImportFile_T(ID2, userfile_2, true);
    PhoneBill(amount, ID1, ID2);

    /*ถ้าใส่ฟังก์ชั่นสลีปละลบอันนี้ด้วย
    cout << "You top up money from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    Sleep(2000);
    */

    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(2) << ID1.money[0] << "," << ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(2) << ID2.money[0] << "," << ID2.name << endl;
    writefile_1.close();
    writefile_2.close();

    // เรียกฟังก์ชั่นสลีปใบเสร็จตรงนี้นะ
    receipt_paybill(ID1, ID2, amount);
}

void PhoneBill(double amount, Dataformat &ID1, Dataformat &ID2)
{
    if (amount > 0)
    {
        if (amount > ID1.money[0])
        {
            do
            {
                system("cls"); // clear the console
                cout << char(201) ; windows(); cout << char(187) << endl;
                cout << char(186) << "             + RECEIPT +               " << char(186) << endl;
                cout << char(186) << "       You don't have enough money.    " << char(186) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(186) << " Now you have money : " << fixed << setw(12) << setprecision(2) << ID1.money[0] << " THB " << char(186) << endl;
                cout << char(199) << "---------------------------------------" << char(182) << endl;
                cout << char(204) ; windows(); cout << char(185) << endl;
                cout << char(186) << "                                       " << char(186) << endl;
                // display the menu options
                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << endl
                     << char(200) ; windows(); cout << char(188) << endl;

                ch = getch(); // wait for a key press

                // update the choice variable based on the arrow key input
                if (ch == 72 && choice > 1)
                { // up arrow key
                    choice--;
                }
                else if (ch == 80 && choice < 1)
                { // down arrow key
                    choice++;
                }
            } while (ch != 13); // enter key
            // display the selected option
            switch (choice)
            {
            case 1:
                cout << "Back To Login Menu";
                main();
                break;
            default:
                main();
                break;
            }
        }
        else
        {
            ID1.money[0] = ID1.money[0] - amount;
            ID2.money[0] = ID2.money[0] + amount;
        }
    }
}

// higlight Payment menu
void highlight_Payment_MENU(int index, bool selected)
{
    int l = 0;
    if (selected)
    {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index)
    {
    case 1:
        l = 20;
        cout << "Electricity Bill";
        break;
    case 2:
        l = 26;
        cout << "Water Bill";
        break;
    case 3:
        l = 26;
        cout << "Phone Bill";
        break;
    case 4:
        l = 25;
        cout << "Game Top Up";
        break;
    case 5:
        l = 32;
        cout << "Exit"; // ออก
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << char(186) << endl; // window
}

//hghlight_Login_Sing_in
void highlight_Login_Sing_in(int index, bool selected)
{
    int l = 0;
        cout << "               ";
    if (selected)
    {
        cout << "\033[1;4m"; // set background and foreground color to white and black
    }
    //cout << "--> ";

    // print the option label
    switch (index)
    {
    case 1:
        l = 17;
        cout <<"Sign in" ;
        break;
    case 2:
        l = 17;
        cout << " Login ";
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << char(186) << endl; // window
}


int main()
{
    do
        {
            system("cls"); // clear the console
            cout << char(201) ; windows(); cout << char(187) << endl;
            cout << char(186) << "               "<< "\033[1;1m" << "ATM SKRT" << "\033[0m" << "                " << char(186) << endl;
            cout << char(204) ; windows(); cout << char(185) << endl;
            cout << char(186) << "                                       " << char(186) << endl;
            // display the menu options
            for (int i = 1; i < 3; i++)
            {
                cout << char(186) << " ";
                highlight_Login_Sing_in(i, i == choice);
            }
            cout << char(186) << "                                       " << char(186) << endl;
            cout << char(186) << "                "<< "\033[1;3m" << "CPE102" << "\033[0m" << "                 " << char(186) << endl;
            cout << char(200) ; windows(); cout << char(188) << endl;
            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1)
            { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 2)
            { // down arrow key
                choice++;
            }
        } while (ch != 13); // enter key

        // display the selected option
        switch (choice)
        {
        case 1:
            new_account();
            break;

        case 2:
                    int password , pass_id;
                        string id;
                        Dataformat ID1;
                        // login
                        login(id, password);
                        string fileindex = id + ".txt"; // id.txt
                        ImportFile(ID1, fileindex);
                        ifstream myfile;
                        myfile.open(id + ".txt");

                        if (ID1.Pass[0] == password)
                        {
                            system("cls");
                            cout << char(201) ; windows(); cout << char(187) << endl;
                            cout << char(186) << "           "<< "\033[1;1m" <<"Login successful!"<< "\033[0m" <<"           " << char(186) << endl;
                            cout << char(200) ; windows(); cout << char(188) << endl;
                            Sleep(1000); // Wait for 1000 milliseconds
                            // ATM
                            do
                            {
                                system("cls"); // clear the console
                                cout << char(201) ; windows(); cout << char(187) << endl;
                                cout << char(186) << "               "<< "\033[1;1m" << "ATM Menu" << "\033[0m" << "                " << char(186) << endl;
                                cout << char(204) ; windows(); cout << char(185) << endl;
                                // display the menu options
                                for (int i = 1; i < 7; i++)
                                {
                                    cout << char(186) << " ";
                                    highlight_ATM_MENU(i, i == choice);
                                }
                                cout << char(186) << "                "<< "\033[1;3m" << "CPE102" << "\033[0m" << "                 " << char(186) << endl;
                                cout << char(200) ; windows(); cout << char(188) << endl;
                                ch = getch(); // wait for a key press

                                // update the choice variable based on the arrow key input
                                if (ch == 72 && choice > 1)
                                { // up arrow key
                                    choice--;
                                }
                                else if (ch == 80 && choice < 6)
                                { // down arrow key
                                    choice++;
                                }
                            } while (ch != 13); // enter key

                            // display the selected option
                            switch (choice)
                            {
                            case 1:
                                // Balance Inquiry
                                do
                                {
                                    system("cls");
                                    cout << char(201) ; windows(); cout << char(187) << endl;
                                    cout << char(186) << "            "<< "\033[1;1m"<<"Balance Inquiry"<< "\033[0m"<<"            " << char(186) << endl;
                                    cout << char(204) ; windows(); cout << char(185) << endl;
                                    cout << char(199) ; straight_line() ; cout << char(182) << endl;
                                    cout << char(186) << "   Current balance : " << fixed << setw(13) << setprecision(2) << ID1.money[0] << " THB " << char(186) << "\n"; // setprecision(1000)
                                    cout << char(199) ; straight_line() ; cout << char(182) << endl;
                                    cout << char(204) ; windows(); cout << char(185) << endl;
                                    for (int i = 1; i < 2; i++)
                                    {
                                        higlight_back_to_menu(i, i == choice);
                                    }
                                    // cout << "\n|_______________________________________|";
                                    cout << endl
                                        << char(200) ; windows(); cout << char(188) << endl;

                                    ch = getch(); // wait for a key press

                                    // update the choice variable based on the arrow key input
                                    if (ch == 72 && choice > 1)
                                    { // up arrow key
                                        choice--;
                                    }
                                    else if (ch == 80 && choice < 1)
                                    { // down arrow key
                                        choice++;
                                    }
                                } while (ch != 13); // enter key
                                // display the selected option
                                switch (choice)
                                {
                                case 1:
                                    //cout << "Back To Login Menu";
                                    system("cls"); // clear the console
                                    cout << char(201) ; windows(); cout << char(187) << endl;
                                    cout << char(186) << "            Balance Inquiry            " << char(186) << endl;
                                    cout << char(200) ; windows(); cout << char(188) << endl;
                                    cout << " Thank you for using this ATM. Goodbye!\n";
                                    Sleep(2000); // Wait for 1000 milliseconds
                                    main();
                                    break;
                                default:
                                    break;
                                }
                                break;

                            case 2:
                                // Deposit
                                main_deposit(ID1, fileindex);
                                break;

                            case 3:
                                // Withdraw
                                mainWithdraw(ID1, fileindex);
                                break;

                            case 4:
                                // Transfers money
                                mainTransferMoney(id);
                                break;
                            case 5:
                                // payment
                                do
                                {
                                    system("cls");
                                    cout << char(201) ; windows(); cout << char(187) << endl;
                                    cout << char(186) << "              Payment MENU             " << char(186) << endl;
                                    // cout << "+---------------------------------------+\n";
                                    // cout << "  =====================================  \n";
                                    // cout << "   Your current balance is: $" << fixed << setprecision(2) << ID1.money[0] << "\n" ; //setprecision(1000)
                                    // cout << "  =====================================  \n";
                                    cout << char(204) ; windows(); cout << char(185) << endl;
                                    for (int i = 1; i < 6; i++)
                                    {
                                        cout << char(186) << " ";
                                        highlight_Payment_MENU(i, i == choice);
                                    }
                                    // cout << "|_______________________________________|";
                                    // cout << "\n+---------------------------------------+";
                                    cout << char(186) << "                "<< "\033[1;3m" << "CPE102" << "\033[0m" << "                 " << char(186) << endl;
                                    cout << char(200) ; windows(); cout << char(188) << endl;
                                    ch = getch(); // wait for a key press

                                    // update the choice variable based on the arrow key input
                                    if (ch == 72 && choice > 1)
                                    { // up arrow key
                                        choice--;
                                    }
                                    else if (ch == 80 && choice < 5)
                                    { // down arrow key
                                        choice++;
                                    }
                                } while (ch != 13); // enter key
                                // display the selected option
                                switch (choice)
                                {
                                case 1:
                                    cout << "Electricity bill";
                                    main_payebill(id);
                                    break;
                                case 2:
                                    cout << "Water bill";
                                    main_paywaterbill(id);
                                    break;
                                case 3:
                                    cout << "PhoneBill";
                                    main_PhoneBill(id);
                                    break;
                                case 4:
                                    cout << "Game Top Up";
                                    main_topup(id);
                                    break;
                                case 5:
                                    cout << "Exit"; // ออก
                                    main();
                                    break;
                                default:
                                    main();
                                    break;
                                }
                            case 6:
                                // Exit
                                system("cls"); // clear the console
                                cout << char(201) ; windows(); cout << char(187) << endl;
                                cout << char(186) << "                  Exit                 " << char(186) << endl;
                                cout << char(200) ; windows(); cout << char(188) << endl;
                                cout << "Thank you for using this ATM. Goodbye!\n";
                                Sleep(2000); // Wait for 1000 milliseconds
                                main();      // Return to login page
                                break;
                            }

                            return 0;
                        }
                        else
                        {
                            Login_failed();
                        }

            break;
        }

    }
