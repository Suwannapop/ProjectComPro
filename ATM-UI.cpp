#include <iostream>
#include <conio.h> // for getch() function
#include <iomanip>
#include <windows.h> //sleep higlight
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int id, password; // login
char ch;          // login && ATM
int choice = 1;   // ATM
//float balance;    // ลบออก

int main();
struct Dataformat
{
    vector<int> Pass;
    vector<int> ID;
    vector<double> money;
    string name;
};

// higlight_back_to_menu use in receipt
void higlight_back_to_menu(int index, bool selected)
{
    //int l = 0;
    if (selected)
    {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    //cout << index << ". ";

    // print the option label
    switch (index)
    {
    case 1:
        //l = 12;
        cout  << "\n|           Back To Login Menu          |"; 
        break;
    default:
        break;
    }

    cout << "\033[0m" ;//<< setw(l) << " |"; // window
}

void receipt_depos(Dataformat ID1,float amount){
     do
        {
            system("cls");
            cout << " _______________________________________\n";
            cout << "|                                       |\n";
            cout << "|               + RECEIPT +             |\n";
            cout << "|                 DEPOSIT               |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "| Account :"<< setw(30) << ID1.ID[0] <<  " |\n";
            cout << "| Deposit Amount :  "<< setw(19) << amount << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "| Total"<< setw(32) << ID1.money[0] << setw(3) << "|\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "|               Skrt Bank <3            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                higlight_back_to_menu(i, i == choice);
            }
            cout << "\n|_______________________________________|\n";

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
            break;
        }
}

void receipt_wdraw(Dataformat ID1,float amount){
    do
        {
            system("cls"); // clear the console
            cout << " _______________________________________\n";
            cout << "|                                       |\n";
            cout << "|               + RECEIPT +             |\n";
            cout << "|                 WITHDRAW              |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "| Account :"<< setw(30) << ID1.ID[0] <<  " |\n";
            cout << "| Withdraw Amount : "<< setw(19) << amount << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "| Total"<< setw(32) << ID1.money[0] << setw(3) <<"|\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "|               Skrt Bank <3            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                higlight_back_to_menu(i, i == choice);
            }
            cout << "\n|_______________________________________|\n";

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
            break;
        }
}

void receipt_transf(Dataformat ID1,Dataformat ID2,float amount){
    do
        {
            system("cls"); // clear the console
            cout << " _______________________________________\n";
            cout << "|                                       |\n";
            cout << "|               + RECEIPT +             |\n";
            cout << "|             TRANSFER MONEY            |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "| Account :"<< setw(30) << ID1.ID[0] <<  " |\n";
            cout << "| Transfer Amount : "<< setw(19) << amount <<  " |\n";
            cout << "| Total"<< setw(32) << ID1.money[0] << setw(3) <<  "|\n";
            cout << "|                                       |\n";
            cout << "| ------------- transfer to ----------- |\n";
            cout << "|                                       |\n";
            cout << "| Account :"<< setw(30) << ID2.ID[0] <<  " |\n";
            cout << "| Total"<< setw(32) << ID2.money[0] << setw(3) <<  "|\n";
            cout << "|                                       |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "|               Skrt Bank <3            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                higlight_back_to_menu(i, i == choice);
            }
            cout << "\n|_______________________________________|\n";

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
            break;
        }
}

void receipt_paybill(Dataformat ID1,float amount){
    do
        {
            system("cls"); // clear the console
            cout << " _______________________________________\n";
            cout << "|                                       |\n";
            cout << "|               + RECEIPT +             |\n";
            cout << "|                 PAYBILL               |\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "| Account :"<< setw(30) << ID1.ID[0] <<  " |\n";
            cout << "| Pay Amount :  "<< setw(25) << setprecision(2) << amount  << setw(3) <<"|\n";
            cout << "|                                       |\n";
            cout << "| Total"<< setw(31) << setprecision(2) << ID1.money[0] << setw(3) << "|\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "|               Skrt Bank <3            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
                higlight_back_to_menu(i, i == choice);
            }
            cout << "\n|_______________________________________|\n";

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
            break;
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
        l = 25;
        cout << "Try again";
        break;
    case 2:
        l = 30;
        cout << "Exit";
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << " |"; // window
}

// new_account
int new_account()
{
    system("cls");
    int UserPass1, UserPass2, UserID, money;
    cout << "+_____________________________________+\n";
    cout << "|         Create your account         |\n";
    cout << "|    Want to create a new account?    |\n";
    cout << "+_____________________________________+\n";
    cout << "Enter your ID: ";
    cin >> UserID;
    cout << "Enter your password: ";
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

    cout << "\nConfirm password: ";
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
        cout << "\nEnter your money: ";
        cin >> money;
        if(money >= 0){
            string identification = to_string(UserID);
            string filename = to_string(UserID) + ".txt";
            ofstream outfile(filename);
            if (outfile.is_open())
            {
                outfile << UserPass1 << "," << identification << "," << money;
                outfile.close();
                cout << "Created successfully" << identification << endl;
            }
        }else
        {
            do
            {
                system("cls");
                cout << "+_____________________________________+\n";
                cout << "|            Invalid amount           |\n";
                cout << "+_____________________________________+\n";
                cout << setw(30) << "Please try again.\n";
                cout << "+-------------------------------------+";
                // display the menu options
                for (int i = 1; i < 3; i++)
                {
                    cout << "\n| ";
                    higlight_new_account_Yes_or_No(i, i == choice);
                }
                cout << "\n+-------------------------------------+\n";

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
                break;
            }
        }
    }
    else
    {
        do
        {
            system("cls");
            cout << "+_____________________________________+\n";
            cout << "|        Passwords do not match       |\n";
            cout << "+_____________________________________+\n";
            cout << setw(30) << "Please try again.\n";
            cout << "+-------------------------------------+";
            // display the menu options
            for (int i = 1; i < 3; i++)
            {
                cout << "\n| ";
                higlight_new_account_Yes_or_No(i, i == choice);
            }
            cout << "\n+-------------------------------------+\n";

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
        l = 29;
        cout << "20 THB";
        break;
    case 2:
        l = 29;
        cout << "50 THB";
        break;
    case 3:
        l = 28;
        cout << "100 THB";
        break;
    case 4:
        l = 28;
        cout << "200 THB";
        break;
    case 5:
        l = 28;
        cout << "500 THB";
        break;
    case 6:
        l = 9;
        cout << "Choose your own Deposition";
        break;
    case 7:
        l = 18;
        cout << "cancel Deposition";
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << " |\n"; // window
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
        cout << "+_____________________________________+\n";
        cout << "|               Deposit               |\n";
        cout << "+_____________________________________+\n";
        // display the menu options
        for (int i = 1; i < 8; i++)
        {
            cout << "| ";
            higlight_deposit(i, i == choice);
        }
        // cout << "|                                     |\n";
        cout << "+_____________________________________+\n";

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
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_depos(ID1,20);
        break;
    case 2:
        // cout << "2 - $50" ;
        ID1.money[0] = ID1.money[0] + 50;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_depos(ID1,50);
        break;
    case 3:
        // cout << "3 - $100" ;
        ID1.money[0] = ID1.money[0] + 100;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_depos(ID1,100);
        break;
    case 4:
        // cout << "4 - $200" ;
        ID1.money[0] = ID1.money[0] + 200;
        receipt_depos(ID1,200);
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        break;
    case 5:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] + 500;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_depos(ID1,500);
        break;
    case 6:
        // cout << "6 - choose your own deposition amount" ;
        cout << "How much do you want to Deposit.";
        cin >> amount;
        if (amount > 0)
        {
            ID1.money[0] = ID1.money[0] + amount;
            notfinished = false;
            writefile_1.open(userfile_1);
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
            writefile_1.close();
            receipt_depos(ID1,amount);
            break;
        }
        else
        {
            cout << "Invalid! Please try again.";
            Sleep(1500);
            main();
            break;
        }

    case 7:
        // cout << "7 - cancel deposition \n";
        cout << "Deposition canceled.";
        notfinished = false;
        Sleep(1500);
        main();
        break;
    default:
        cout << "Invalid! Please try again.";
        Sleep(1500);
        main();
        break;
    }
}
// higlight_yes_or_No
void higlight_Yes_or_No(int index, bool selected)
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
        l = 31;
        cout << "Yes";
        break;
    case 2:
        l = 32;
        cout << "No";
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << " |"; // window
}

// Login failed
int Login_failed()
{
    system("cls");
    cout << "+_____________________________________+\n";
    cout << "|             Login failed.           |\n";
    cout << "|       Incorrect ID or password.     |\n";
    cout << "+_____________________________________+\n";
    cout << setw(30) << "Please try again.\n";
    cout << "+_____________________________________+\n";
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
                cout << " _______________________________________ \n";
                cout << "|                                       |\n";
                cout << "|        Don't have ID in Databas       |\n";
                cout << "|                                       |\n";
                cout << "| ===================================== |";

                for (int i = 1; i < 2; i++)
                {
                    higlight_back_to_menu(i, i == choice);
                }
                cout << "\n|_______________________________________|";

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
                break;
                }
        }
    }
}

void TransferMoney(double amount, Dataformat &ID1, Dataformat &ID2) // เเปปปกติ
{
    if (amount > 0)
    {
        if (amount > ID1.money[0])
        {
            cout << "You don't have enough money\n";
            cout << "Now you have money : " << ID1.money[0] << " You can't tranfer money\n";
        }
        else
        {
            ID1.money[0] = ID1.money[0] - amount;
            ID2.money[0] = ID2.money[0] + amount;
        }
    }
    else if (amount <= 0)
    {
        cout << "You can't tranfer money less than 0 or = 0\n";
        Sleep(2000);
    }
}


void mainTransferMoney(string id)
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
    ImportFile(ID2, userfile_2 , true);
    cout << "How much money : ";
    cin >> amount;
    TransferMoney(amount, ID1, ID2);
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << ID2.money[0] << endl;
    writefile_1.close();
    writefile_2.close();

    receipt_transf(ID1,ID2,amount);
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
        l = 23;
        cout << "Balance Inquiry"; // เช็ค
        break;
    case 2:
        l = 31;
        cout << "Deposit"; // ฝาก
        break;
    case 3:
        l = 30;
        cout << "Withdraw"; // ถอน
        break;
    case 4:
        l = 23;
        cout << "Transfers money"; // โอน
        break;
    case 5:
        l = 34;
        cout << "Exit"; // ออก
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << " | \n"; // window
}

// Login ATM
int login(string &id, int &password)
{
    char ch;
    // Display login window frame
    system("cls");
    cout << "+---------------------------------------+\n";
    cout << "|               Login ATM               |\n";
    cout << "+---------------------------------------+\n";
    // Display prompts for ID and password
    cout << "\nEnter your ID: ";
    cin >> id;
    cout << "Enter your password: ";

    // Read in password character by character without displaying on screen
    password = 0;
    while ((ch = _getch()) != '\r')
    { // Stop reading when user presses Enter key
        if (ch == '\b')
        { // Handle backspace character
            if (password > 0)
            {
                password /= 10;
                cout << "\b \b"; // Move cursor back and overwrite character with space
            }
        }
        else if (isdigit(ch))
        { // Handle numeric characters
            password = password * 10 + (ch - '0');
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
        l = 31;
        cout << "20 THB";
        break;
    case 2:
        l = 31;
        cout << "50 THB";
        break;
    case 3:
        l = 30;
        cout << "100 THB";
        break;
    case 4:
        l = 30;
        cout << "200 THB";
        break;
    case 5:
        l = 30;
        cout << "500 THB";
        break;
    case 6:
        l = 13;
        cout << "Choose your own Withdraw";
        break;
    case 7:
        l = 22;
        cout << "cancel Withdraw";
        break;
    default:
        break;
    }

    cout << "\033[0m" << setw(l) << " |\n"; // window
}


void Withdraw(double, Dataformat&);
int mainWithdraw(Dataformat ID1 , string userfile_1)
{
    float amount;
    ofstream writefile_1;
    ImportFile(ID1,userfile_1);
    Withdraw(amount, ID1);
    
    do
    {
        system("cls"); // clear the console
        cout << "+---------------------------------------+\n";
        cout << "|               Withdraw                |\n";
        cout << "+---------------------------------------+\n";
        // display the menu options
        for (int i = 1; i < 8; i++)
        {
            cout << "| ";
            higlight_Withdraw(i, i == choice);
        }
        // cout << "|                                     |\n";
        cout << "+---------------------------------------+\n";

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
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_wdraw(ID1,20);
        break;
    case 2:
        // cout << "2 - $50" ;
        ID1.money[0] = ID1.money[0] - 50;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_wdraw(ID1,50);
        break;
    case 3:
        // cout << "3 - $100" ;
        ID1.money[0] = ID1.money[0] - 100;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_wdraw(ID1,100);
        break;
    case 4:
        // cout << "4 - $200" ;
        ID1.money[0] = ID1.money[0] - 200;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_wdraw(ID1,200);
        break;
    case 5:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] + 500;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        receipt_wdraw(ID1,500);
        break;
    case 6:
        // cout << "6 - choose your own Withdraw amount" ;
        cout << "How much do you want to Withdraw.";
        cin >> amount;
        if (ID1.money[0]-amount >= 0 && amount >= 0)
        {
            ID1.money[0] = ID1.money[0] - amount;
            writefile_1.open(userfile_1);
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
            writefile_1.close();
            receipt_wdraw(ID1,amount);
            break;
        }
        else if(ID1.money[0]-amount < 0 && amount >= 0)
        {
            cout << "You don't have enough money\n";
            cout << "Now you have money : " << ID1.money[0] << " You can't withdraw money\n";
            Sleep(1500);
            main();
            break;
        }
        else
        {
            cout << "Invalid! Please try again.";
            Sleep(1500);
            main();
            break;

        }

    case 7:
        // cout << "7 - cancel deposition \n";
        cout << "Withdraw canceled.";
        Sleep(1500);
        main();
        break;
    default:
        cout << "Invalid! Please try again.";
        Sleep(1500);
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


int main()
{
    system("Color 9");
/*  0 = Black       8 = Gray    
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White */
    int password;
    int pass_id;
    string id;
    Dataformat ID1;
    // login
    login(id, password);
    string fileindex = id + ".txt";
    ImportFile(ID1, fileindex);
    ifstream myfile;
    myfile.open(id + ".txt");

    if (ID1.Pass[0] == password)
    {
        system("cls");
        cout << "+---------------------------------------+\n";
        cout << "|           Login successful!           |\n";
        cout << "+---------------------------------------+\n";
        Sleep(1000); // Wait for 1000 milliseconds
        // ATM
        do
        {
            system("cls"); // clear the console
            cout << "+---------------------------------------+\n";
            cout << "|               ATM Menu                |\n";
            cout << "+---------------------------------------+\n";
            // display the menu options
            for (int i = 1; i < 6; i++)
            {
                cout << "| ";
                highlight_ATM_MENU(i, i == choice);
            }
            cout << "|                                       |\n";
            cout << "+---------------------------------------+\n";

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
            // Balance Inquiry
                    do
                    {
                        system("cls");
                        cout << "+---------------------------------------+\n";
                        cout << " _______________________________________ \n";
                        cout << "|                                       |\n";
                        cout << "|        Don't have ID in Databas       |\n";
                        cout << "|                                       |\n";
                        cout << "| ===================================== |";

                        for (int i = 1; i < 2; i++)
                        {
                            higlight_back_to_menu(i, i == choice);
                        }
                        cout << "\n|_______________________________________|";

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
                        break;
                        }
            system("cls");
            cout << "+---------------------------------------+\n";
            cout << "|            Balance Inquiry            |\n";
            cout << "+---------------------------------------+\n";
            cout << "Your current balance is: $" << fixed << setprecision(2) << ID1.money[0] << "\n";
            Sleep(2000);   // Wait for 1000 milliseconds
            system("cls"); // clear the console
            cout << "+---------------------------------------+\n";
            cout << "|            Balance Inquiry            |\n";
            cout << "+---------------------------------------+\n";
            cout << "Thank you for using this ATM. Goodbye!\n";
            Sleep(2000); // Wait for 1000 milliseconds
            main();
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
            system("cls"); // clear the console
            cout << "+---------------------------------------+\n";
            cout << "|            Transfers money            |\n";
            cout << "+---------------------------------------+\n";
            mainTransferMoney(id);
            break;

        case 5:
            // Exit
            system("cls"); // clear the console
            cout << "+---------------------------------------+\n";
            cout << "|                  Exit                 |\n";
            cout << "+---------------------------------------+\n";
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
        Sleep(2000);
        main();
    }
}
