#include <iostream>
#include <conio.h> // for getch() function
#include <iomanip>
#include <windows.h> //sleep
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int id, password; // login
char ch;          // login && ATM
int choice = 1;   // ATM
float balance;    // ลบออก

int main();
struct Dataformat
{
    vector<int> Pass;
    vector<int> ID;
    vector<double> money;
};

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
    cout << "+-------------------------------------+\n";
    cout << "|         Create your account         |\n";
    cout << "|    Want to create a new account?    |\n";
    cout << "+-------------------------------------+\n";
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
        string identification = to_string(UserID);
        string filename = to_string(UserID) + ".txt";
        ofstream outfile(filename);
        if (outfile.is_open())
        {
            outfile << UserPass1 << "," << identification << "," << money;
            outfile.close();
            cout << "Created successfully" << identification << endl;
        }
    }
    else
    {
        do
        {
            system("cls");
            cout << "+-------------------------------------+\n";
            cout << "|        Passwords do not match       |\n";
            cout << "+-------------------------------------+\n";
            cout << setw(28) << "Please try again.\n";
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
        cout << "Cancal Deposition";
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
        cout << "+-------------------------------------+\n";
        cout << "|               Deposit               |\n";
        cout << "+-------------------------------------+\n";
        // display the menu options
        for (int i = 1; i < 8; i++)
        {
            cout << "| ";
            higlight_deposit(i, i == choice);
        }
        // cout << "|                                     |\n";
        cout << "+-------------------------------------+\n";

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
        cout << "Successfully deposited $20 to your account. Current balance is $" << ID1.money[0] << ".";
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 2:
        // cout << "2 - $50" ;
        ID1.money[0] = ID1.money[0] + 50;
        cout << "Successfully deposited $50 to your account. Current balance is $" << ID1.money[0] << ".";
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 3:
        // cout << "3 - $100" ;
        ID1.money[0] = ID1.money[0] + 100;
        cout << "Successfully deposited $100 to your account. Current balance is $" << ID1.money[0] << ".";
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 4:
        // cout << "4 - $200" ;
        ID1.money[0] = ID1.money[0] + 200;
        cout << "Successfully deposited $200 to your account. Current balance is $" << ID1.money[0] << ".";
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 5:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] + 500;
        cout << "Successfully deposited $500 to your account. Current balance is $" << ID1.money[0] << ".";
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 6:
        // cout << "6 - choose your own deposition amount" ;
        cout << "How manny do you want to Deposit.";
        cin >> amount;
        if (amount > 0)
        {
            ID1.money[0] = ID1.money[0] + amount;
            cout << "Successfully deposited " << setprecision(1000000) << ID1.money[0] << "to your account. Current balance is $" << setprecision(1000000) << ID1.money[0] << "." << endl;
            notfinished = false;
            writefile_1.open(userfile_1);
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
            writefile_1.close();
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
        // cout << "7 - cancal deposition \n";
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
    cout << "+-------------------------------------+\n";
    cout << "|             Login failed.           |\n";
    cout << "|       Incorrect ID or password.     |\n";
    cout << "+-------------------------------------+\n";
    cout << setw(28) << "Please try again.\n";
    cout << "+-------------------------------------+\n";
}

void ImportFile(Dataformat &ID, string fileindex, bool check) // ใช้ฝากถอนโอน
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    double balnace;
    if (check = false)
    {
        if (data.is_open())
        {
            while (getline(data, line)) // importfile
            {
                sscanf(line.c_str(), "%d,%d,%lf", &pass, &idnumber, &balnace);
                ID.Pass.push_back(pass);
                ID.ID.push_back(idnumber);
                ID.money.push_back(balnace);
            }
        }
        else
        {
            do
            {
                system("cls");
                cout << "+-------------------------------------+\n";
                cout << "|             Login failed.           |\n";
                cout << "|           account not found         |\n";
                cout << "+-------------------------------------+\n";
                cout << "+-------------------------------------+\n";
                cout << "|     If you don't have an accoun     |\n";
                cout << "|    Want to create a new account?    | ";
                for (int i = 1; i < 3; i++)
                {
                    cout << "\n| ";
                    higlight_Yes_or_No(i, i == choice);
                }
                cout << "\n+-------------------------------------+\n";

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
                Sleep(2000);
                main();
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
    else if (check = true)
    {
        if (data.is_open())
        {
            while (getline(data, line)) // importfile
            {
                sscanf(line.c_str(), "%d,%d,%lf", &pass, &idnumber, &balnace);
                ID.Pass.push_back(pass);
                ID.ID.push_back(idnumber);
                ID.money.push_back(balnace);
            }
        }
        else
        {
            system("cls");
            cout << "+-------------------------------------+\n";
            cout << "|       Don't have ID in Databas      |\n";
            cout << "+-------------------------------------+\n";
            
            Sleep(2000);
            main();
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
            cout << "Now you have : " << ID1.money[0] << " You can't tranfer money\n";
        }
        else
        {
            ID1.money[0] = ID1.money[0] - amount;
            ID2.money[0] = ID2.money[0] + amount;
            cout << "You Tranfer Money From ID To ID \n"
                 << ID1.ID[0] << " -----> " << ID2.ID[0] << endl;
            Sleep(1500);
            cout << "Now : ID : " << ID1.ID[0] << " Is "<< setprecision(10000) << ID1.money[0] << endl;
            cout << "Now : ID : " << ID2.ID[0] << " Is "<< setprecision(10000) << ID2.money[0] << endl;
            Sleep(2000);
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
        l = 32;
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
    cout << "+-------------------------------------+\n";
    cout << "|              Login ATM              |\n";
    cout << "+-------------------------------------+\n";
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
        l = 11;
        cout << "Choose your own Withdraw";
        break;
    case 7:
        l = 20;
        cout << "Cancal Withdraw";
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
        cout << "+-------------------------------------+\n";
        cout << "|              Withdraw               |\n";
        cout << "+-------------------------------------+\n";
        // display the menu options
        for (int i = 1; i < 8; i++)
        {
            cout << "| ";
            higlight_Withdraw(i, i == choice);
        }
        // cout << "|                                     |\n";
        cout << "+-------------------------------------+\n";

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
        cout << "Successfully Withdraw $20 to your account. Current balance is $" << ID1.money[0] << ".";
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 2:
        // cout << "2 - $50" ;
        ID1.money[0] = ID1.money[0] - 50;
        cout << "Successfully Withdraw $50 to your account. Current balance is $" << ID1.money[0] << ".";
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 3:
        // cout << "3 - $100" ;
        ID1.money[0] = ID1.money[0] - 100;
        cout << "Successfully Withdraw $100 to your account. Current balance is $" << ID1.money[0] << ".";
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 4:
        // cout << "4 - $200" ;
        ID1.money[0] = ID1.money[0] - 200;
        cout << "Successfully Withdraw $200 to your account. Current balance is $" << ID1.money[0] << ".";
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 5:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] + 500;
        cout << "Successfully Withdraw $500 to your account. Current balance is $" << ID1.money[0] << ".";
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
        writefile_1.close();
        Sleep(1500);
        main();
        break;
    case 6:
        // cout << "6 - choose your own Withdraw amount" ;
        cout << "How manny do you want to Withdraw.";
        cin >> amount;
        if (amount > 0)
        {
            ID1.money[0] = ID1.money[0] - amount;
            cout << "Successfully Withdraw. " << setprecision(1000000) << ID1.money[0] << "to your account. Current balance is $" << setprecision(1000000) << ID1.money[0] << "." << endl ; 
            writefile_1.open(userfile_1);
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0];
            writefile_1.close();
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
        // cout << "7 - cancal deposition \n";
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
            cout << "Now you have : " << setprecision(1000000) << ID1.money[0] << " You can't withdraw money\n";
        }
        else
        {
            ID1.money[0] = ID1.money[0] - amount;
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

int main()
{
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
        cout << "+-------------------------------------+\n";
        cout << "|          Login successful!          |\n";
        cout << "+-------------------------------------+\n";
        Sleep(1000); // Wait for 1000 milliseconds
        // ATM
        do
        {
            system("cls"); // clear the console
            cout << "+-------------------------------------+\n";
            cout << "|              ATM Menu               |\n";
            cout << "+-------------------------------------+\n";
            // display the menu options
            for (int i = 1; i < 6; i++)
            {
                cout << "| ";
                highlight_ATM_MENU(i, i == choice);
            }
            cout << "|                                     |\n";
            cout << "+-------------------------------------+\n";

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
            system("cls");
            cout << "+-------------------------------------+\n";
            cout << "|           Balance Inquiry           |\n";
            cout << "+-------------------------------------+\n";
            cout << "Your current balance is: $" << fixed << setprecision(2) << ID1.money[0] << "\n";
            Sleep(2000);   // Wait for 1000 milliseconds
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
            main_deposit(ID1, fileindex);
            break;

        case 3:
            // Withdraw
            mainWithdraw(ID1, fileindex);
            break;

        case 4:
            // Transfers money
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
