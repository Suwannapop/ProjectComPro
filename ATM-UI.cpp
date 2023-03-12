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
    int l = 0;
    cout  << "\n|           "; 
    if (selected)
    {
        //cout  << "\n|           "; 
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    //cout << index << ". ";

    // print the option label  cout << "|           Back To Login Menu          |\n";
    switch (index)
    {
    case 1:
        l = 11;
        cout  << "Back To Login Menu"; 
        break;
    default:
        break;
    }
    cout << "\033[0m" << setw(l) << " |"; //<< setw(l)
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
            cout << "| Name :"<< setw(31) << ID1.name <<  " |\n";
            cout << "| Account :"<< setw(28) << ID1.ID[0] <<  " |\n";
            cout << "| Deposit Amount :  "<< setw(19) << setprecision(1000) << amount << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "| Total"<< setw(32) << setprecision(1000) << ID1.money[0] << setw(3) << "|\n";
            cout << "| ===================================== |\n";
            cout << "|                                       |\n";
            cout << "|               Skrt Bank <3            |\n";
            cout << "|_______________________________________|\n";
            cout << "|                                       |";
            // display the menu options
            for (int i = 1; i < 2; i++)
            {
            //cout << "|                                       |\n";
                higlight_back_to_menu(i, i == choice);
            }
            cout << "\n|_______________________________________|\n";

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
            cout  << "\n|           "; 
            cout << "Back To Login Menu";
            main();
            break;
        default:
            main();
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
            cout << "| Name :"<< setw(31) << ID1.name <<  " |\n";
            cout << "| Account :"<< setw(28) << ID1.ID[0] <<  " |\n";
            cout << "| Withdraw Amount : "<< setw(19) << setprecision(1000) << amount << setw(3) << "|\n";
            cout << "|                                       |\n";
            cout << "| Total"<< setw(32) << setprecision(1000) << ID1.money[0] << setw(3) <<"|\n";
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
            cout << "| Name :"<< setw(31) << ID1.name <<  " |\n";
            cout << "| Account :"<< setw(28) << ID1.ID[0] <<  " |\n";
            cout << "| Transfer Amount : "<< setw(19) << setprecision(1000) << amount <<  " |\n";
            cout << "| Total"<< setw(32) << setprecision(1000) << ID1.money[0] << setw(3) <<  "|\n";
            cout << "|                                       |\n";
            cout << "| ------------- transfer to ----------- |\n";
            cout << "|                                       |\n";
            cout << "| Name :"<< setw(31) << ID2.name <<  " |\n";
            cout << "| Account :"<< setw(28) << ID2.ID[0] <<  " |\n";
            cout << "| Total"<< setw(32) << setprecision(1000) << ID2.money[0] << setw(3) <<  "|\n";
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
            cout << "| Name :"<< setw(31) << ID1.name <<  " |\n";
            cout << "| Account :"<< setw(28) << ID1.ID[0] <<  " |\n";
            cout << "| Pay Amount :  "<< setw(25) << setprecision(1000) << amount  << setw(3) <<"|\n";
            cout << "|                                       |\n";
            cout << "| Total"<< setw(31) << setprecision(1000) << ID1.money[0] << setw(3) << "|\n";
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
    string name ;
    cout << "+_____________________________________+\n";
    cout << "|         Create your account         |\n";
    cout << "|    Want to create a new account?    |\n";
    cout << "+_____________________________________+\n";
    cout << "What is your name: " ;
    getline(cin , name) ;
    cin >> name;
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
                outfile << UserPass1 << "," << identification << "," << money << "," << name  ;
                outfile.close();
                 do
                    {
                        system("cls"); // clear the console
                        cout << "+_______________________________________+\n";
                        cout << "|          Created successfully         |\n";
                        cout << "|=======================================|\n";
                        cout << "| Created successfully " << setw(16)<< name << " |\n" ;
                        cout << "| Now you have money : " << setw(12) << money <<  " THB |\n";
                        cout << "|=======================================|\n";
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
                        main();
                        break;
                    }

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
        else if (ch == 80 && choice < 7)
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
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name ;
        writefile_1.close() ;
        receipt_depos(ID1,20);
        break;
    case 2:
        // cout << "2 - $50" ;
        ID1.money[0] = ID1.money[0] + 50;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1,50);
        break;
    case 3:
        // cout << "3 - $100" ;
        ID1.money[0] = ID1.money[0] + 100;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1,100);
        break;
    case 4:
        // cout << "4 - $200" ;
        ID1.money[0] = ID1.money[0] + 200;
        receipt_depos(ID1,200);
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
        writefile_1.close();
        break;
    case 5:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] + 500;
        notfinished = false;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
        writefile_1.close();
        receipt_depos(ID1,500);
        break;
    case 6:
        // cout << "6 - choose your own deposition amount" ;
        system("cls"); // clear the console
        cout << "+_____________________________________+\n";
        cout << "|               Deposit               |\n";
        cout << "|          Enter your amout.          |\n";
        cout << "|=====================================|\n";
        cout << "          THB : " ; cin >> amount;
        if (amount > 0)
        {
            ID1.money[0] = ID1.money[0] + amount;
            notfinished = false;
            writefile_1.open(userfile_1);
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
            writefile_1.close();
            receipt_depos(ID1,amount);
            break;
        }
        else
        {
            do
                {
                    system("cls"); // clear the console
                    cout << "+_______________________________________+\n";
                    cout << "|                 Deposit               |\n";
                    cout << "|       Invalid! Please try again.      |\n";
                    cout << "|=======================================|\n";
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

    case 7:
        // cout << "7 - cancel deposition \n";
        notfinished = false;
        do
                {
                    system("cls"); // clear the console
                    cout << "+_______________________________________+\n";
                    cout << "|                 Deposit               |\n";
                    cout << "|          Deposition canceled.         |\n";
                    cout << "|=======================================|\n";
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
        //l = 5;
        cout << "Yes";
        break;
    case 2:
        //l = 5;
        cout << "No";
        break;
    default:
        break;
    }

    cout << "\033[0m" << "  "; //<< setw(l)  // window
}

// Login failed
int Login_failed()
{
    do
    {
        system("cls");
        cout << "+_______________________________________+\n";
        cout << "|              Login failed.            |\n";
        cout << "|        Incorrect ID or password.      |\n";
        cout << "+_______________________________________+\n";
        cout << setw(30) << "Please try again.\n";
        cout << "+_______________________________________+\n";
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
                cout << " _______________________________________ \n";
                cout << "|                                       |\n";
                cout << "|        Don't have ID in Databas       |\n";
                cout << "|                                       |\n";
                cout << "| ===================================== |\n";
                cout << "|     If you don't have an account      |\n";
                cout << "|     Want to create a new account?     |\n";
                cout << "|               ";
                    // display the menu options
                    //higlight_Yes_or_No
                    for (int i = 1; i < 3; i++)
                    {
                        higlight_Yes_or_No(i, i == choice);
                    }
                    cout << "               |";
                    cout << "\n+_______________________________________+\n";

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


//ใช้สำหรับแก้บัคตอนโอนเงิน
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
                cout << " _______________________________________ \n";
                cout << "|                                       |\n";
                cout << "|        Don't have ID in Databas       |\n";
                cout << "|                                       |\n";
                cout << "| ===================================== |\n";
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
    cout << "+_______________________________________+\n";
    cout << "|             TransferMoney             |\n";
    cout << "|=======================================|\n";
    cout << "        What ID you want to tranfe       \n";
    cout << "             ID : "; cin >> IdTranfer;
    string userfile_1 = id + ".txt";
    string userfile_2 = IdTranfer + ".txt";
    ofstream writefile_1, writefile_2;
    ImportFile(ID1, userfile_1); // importfile
    ImportFile_T(ID2, userfile_2 , true); //Bug , true

    if (userfile_1 == userfile_2)
    {
        do
            {
            system("cls"); // clear the console
            cout << "+_______________________________________+\n";
            cout << "|             TransferMoney             |\n";
            cout << "|=======================================|\n";
            cout << "|            I SUS I May Yes            |";
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
    cout << "|=======================================|\n";
    cout << "             How much money  \n";
    cout << "             THB : "; cin >> amount;
    if (amount > 0)
    {
        if (amount > ID1.money[0])
        {
            do
                {
                system("cls"); // clear the console
                cout << "+_______________________________________+\n";
                cout << "|             TransferMoney             |\n";
                cout << "|=======================================|\n";
                cout << "|       You don't have enough money     |\n";
                cout << "| Now you have money : " << setw(12) << ID1.money[0] <<  " THB |\n";
                cout << "|         You can't tranfer money       |\n";
                cout << "|=======================================|\n";
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
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0] << "," << ID1.name<< endl;
            writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << ID2.money[0] << "," << ID2.name<< endl;
            writefile_1.close();
            writefile_2.close();

            receipt_transf(ID1,ID2,amount);
        }
    }
    else if (amount <= 0)
    {
        do
            {
            system("cls"); // clear the console
            cout << "+_______________________________________+\n";
            cout << "|             TransferMoney             |\n";
            cout << "|=======================================|\n";
            cout << "|            invalid amount             |\n"; //ม่ายมีตังค่าาา แก้ให้ถูกด้วย
            cout << "|=======================================|\n";
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
        l = 31 ;
        cout << "Payment" ; // จ่ายบิลลลลลลลลล
        break;
    case 6:
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
        cout << "+_______________________________________+\n";
        cout << "|                Withdraw               |\n";
        cout << "|       You don't have enough money.    |\n";
        cout << "|=======================================|\n";
        // display the menu options
        for (int i = 1; i < 8; i++)
        {
            cout << "| ";
            higlight_Withdraw(i, i == choice);
        }
        // cout << "|                                     |\n";
        cout << "|=======================================|\n";

        ch = getch(); // wait for a key press

        // update the choice variable based on the arrow key input
        if (ch == 72 && choice > 1)
        { // up arrow key
            choice--;
        }
        else if (ch == 80 && choice < 7)
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
        receipt_wdraw(ID1,20);
        break;
    case 2:
        // cout << "2 - $50" ;
        ID1.money[0] = ID1.money[0] - 50;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1,50);
        break;
    case 3:
        // cout << "3 - $100" ;
        ID1.money[0] = ID1.money[0] - 100;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1,100);
        break;
    case 4:
        // cout << "4 - $200" ;
        ID1.money[0] = ID1.money[0] - 200;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1,200);
        break;
    case 5:
        // cout << "5 - $500" ;
        ID1.money[0] = ID1.money[0] - 500;
        writefile_1.open(userfile_1);
        writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
        writefile_1.close();
        receipt_wdraw(ID1,500);
        break;
    case 6:
        // cout << "6 - choose your own Withdraw amount" ;
        system("cls"); // clear the console
        cout << "+_____________________________________+\n";
        cout << "|              Withdraw               |\n";
        cout << "|          Enter your amout.          |\n";
        cout << "|=====================================|\n";
        cout << "          THB : " ; cin >> amount;
        if (ID1.money[0]-amount >= 0 && amount >= 0)
        {
            ID1.money[0] = ID1.money[0] - amount;
            writefile_1.open(userfile_1);
            writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << ID1.money[0]<< "," << ID1.name;
            writefile_1.close();
            receipt_wdraw(ID1,amount);
            break;
        }
        else if(ID1.money[0]-amount < 0 && amount >= 0)
        {
            do
                {
                    system("cls"); // clear the console
                    cout << "+_______________________________________+\n";
                    cout << "|                Withdraw               |\n";
                    cout << "|       You don't have enough money.    |\n";
                    cout << "|=======================================|\n";
                    cout << "| Now you have money : " << setw(12) << ID1.money[0] <<  " THB |\n";
                    cout << "|=======================================|\n";
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
                    cout << "+_______________________________________+\n";
                    cout << "|                Withdraw               |\n";
                    cout << "|       Invalid! Please try again.      |\n";
                    cout << "|=======================================|\n";
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

    case 7:
        // cout << "7 - cancel deposition \n";
            do
                {
                    system("cls"); // clear the console
                    cout << "+_______________________________________+\n";
                    cout << "|                Withdraw               |\n";
                    cout << "|          Deposition canceled.         |\n";
                    cout << "|=======================================|\n";
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
            cout << "Now you have money : " << setprecision(1000) << ID1.money[0] << " You can't withdraw money\n";
        }
        else
        {
            ID1.money[0] = ID1.money[0] - amount;
        }
    }
}

void payebill(double amount, Dataformat &ID1, Dataformat &ID2);

void main_payebill(string id)//ไฟฟ้า ไม่เขียนดีๆ ก๋อง ขก แก้ละตามนี้เลย555
{
    Dataformat ID1;
    Dataformat ID2;
    //string id, Idbill;
    float amount;
    //cout << "input your id : ";
    //cin >> id;
    //cout << "What ID you want to pay bill : ";
    //cin >> Idbill;
    system("cls"); // clear the console
    cout << "+_______________________________________+\n";
    cout << "|           Electricity Bill            |\n";
    cout << "|=======================================|\n";
    cout << "              How much money            \n";
    cout << "              THB : "; cin >> amount;

    string userfile_1 = id + ".txt";
    string userfile_2 = "777777777.txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID1, userfile_1);
    ImportFile(ID2, userfile_2);
    payebill(amount, ID1, ID2);

    //ถ้าใส่ฟังก์ชั่นสลีปละลบอันนี้ด้วย
    cout << "You Pay Bill from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    Sleep(2000);
    //


    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(10000) << ID1.money[0] << ","<< ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(10000) << ID2.money[0] << ","<< ID2.name << endl;
    writefile_1.close();
    writefile_2.close();

    //เรียกฟังก์ชั่นสลีปใบเสร็จตรงนี้นะ
}

void payebill(double amount, Dataformat &ID1, Dataformat &ID2) 
{
    if (amount > ID1.money[0])
    {
        cout << "You don't have enough money\n";
        cout << "Now you have : " << ID1.money[0] << " You can't pay this bill\n";
    }
    else
    {
        ID1.money[0] = ID1.money[0] - amount;
        ID2.money[0] = ID2.money[0] + amount;
    }
}


void paywaterbill(double amount, Dataformat &ID1, Dataformat &ID2);
void main_paywaterbill(string id)
{
    Dataformat ID1;
    Dataformat ID2;
    float amount;
    //cout << "input your id : ";
    //cin >> id;
    system("cls"); // clear the console
    cout << "+_______________________________________+\n";
    cout << "|               Water Bill              |\n";
    cout << "|=======================================|\n";
    cout << "              How much money            \n";
    cout << "              THB : "; cin >> amount;

    string userfile_1 = id + ".txt";
    string userfile_2 = "666666666.txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID1, userfile_1);
    ImportFile_T(ID2, userfile_2 , true);
    paywaterbill(amount, ID1, ID2);

    //ถ้าใส่ฟังก์ชั่นสลีปละลบอันนี้ด้วย
    cout << "You Pay Bill from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    Sleep(2000);
    //
    
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(10000) << ID1.money[0] << ","<< ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(10000) << ID2.money[0] << ","<< ID2.name << endl;
    writefile_1.close();
    writefile_2.close();

    //เรียกฟังก์ชั่นสลีปใบเสร็จตรงนี้นะ
}

void paywaterbill(double amount, Dataformat &ID1, Dataformat &ID2) 
{
    if (amount > ID1.money[0])
    {
        cout << "You don't have enough money\n";
        cout << "Now you have : " << ID1.money[0] << " You can't pay this bill\n";
    }
    else
    {
        ID1.money[0] = ID1.money[0] - amount;
        ID2.money[0] = ID2.money[0] + amount;
    }
}


void topup(double amount, Dataformat &ID1, Dataformat &ID2);
void main_topup(string id)
{
    Dataformat ID1;
    Dataformat ID2;
    //string id, IdTopup;
    float amount;
    //cout << "input your id : ";
    //cin >> id;
    string userfile_1 = id + ".txt";
    //cout << "What Game ID you want to top up: ";
    //cin >> IdTopup;
    system("cls"); // clear the console
    cout << "+_______________________________________+\n";
    cout << "|               Game Topup              |\n";
    cout << "|=======================================|\n";
    cout << "   How much money do you want to top up \n";
    cout << "              THB : "; cin >> amount;

    string userfile_2 = "999999999.txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID1, userfile_1);
    ImportFile_T(ID2, userfile_2 , true);
    topup(amount, ID1, ID2);

    //ถ้าใส่ฟังก์ชั่นสลีปละลบอันนี้ด้วย
    cout << "You top up money from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    Sleep(2000);
    //
    
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(1000) << ID1.money[0] << ","<< ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(1000) << ID2.money[0] << ","<< ID2.name << endl;
    writefile_1.close();
    writefile_2.close();

    //เรียกฟังก์ชั่นสลีปใบเสร็จตรงนี้นะ
}

void topup(double amount, Dataformat &ID1, Dataformat &ID2) 
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


void PhoneBill(double amount, Dataformat &ID1, Dataformat &ID2);
void main_PhoneBill(string id)
{
    Dataformat ID1;
    Dataformat ID2;
    //string id, IdTopup;
    float amount;
    //cout << "input your id : ";
    //cin >> id;
    system("cls"); // clear the console
    cout << "+_______________________________________+\n";
    cout << "|               Phone Bill              |\n";
    cout << "|=======================================|\n";
    cout << "              How much money            \n";
    cout << "              THB : "; cin >> amount;

    string userfile_1 = id + ".txt";
    string userfile_2 = "888888888.txt";
    ofstream writefile_1, writefile_2; // importfile
    ImportFile(ID1, userfile_1);
    ImportFile_T(ID2, userfile_2 , true);
    PhoneBill(amount, ID1, ID2);

    //ถ้าใส่ฟังก์ชั่นสลีปละลบอันนี้ด้วย
    cout << "You top up money from ID to ID \n"
         << ID1.name << " -----> " << ID2.name << endl;
    cout << "Your current balance is " << ID1.money[0] << endl;
    Sleep(2000);
    //

    
    writefile_1.open(userfile_1);
    writefile_2.open(userfile_2);
    writefile_1 << ID1.Pass[0] << "," << ID1.ID[0] << "," << setprecision(1000) << ID1.money[0] << ","<< ID1.name << endl;
    writefile_2 << ID2.Pass[0] << "," << ID2.ID[0] << "," << setprecision(1000) << ID2.money[0] << ","<< ID2.name << endl;
    writefile_1.close();
    writefile_2.close();

    //เรียกฟังก์ชั่นสลีปใบเสร็จตรงนี้นะ
}

void PhoneBill(double amount, Dataformat &ID1, Dataformat &ID2) 
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
        l = 22;
        cout << "Electricity Bill";
        break;
    case 2:
        l = 28;
        cout << "Water Bill"; 
        break;
    case 3:
        l = 28 ;
        cout << "Phone Bill";
        break;
    case 4:
        l = 29;
        cout << "Gametopup"; 
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


int main()
{
    //system("Color 9");
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
            for (int i = 1; i < 7; i++)
            {
                cout << "| ";
                highlight_ATM_MENU(i, i == choice);
            }
            cout << "|                 CPE102                |\n";
            cout << "+---------------------------------------+\n";

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
                        cout << "+---------------------------------------+\n";
                        cout << "|            Balance Inquiry            |\n";
                        cout << "+---------------------------------------+\n";
                        cout << "  =====================================  \n";
                        cout << "   Your current balance is: $" << fixed << setprecision(2) << ID1.money[0] << "\n" ; //setprecision(1000)
                        cout << "  =====================================  \n";
                        cout << "+---------------------------------------+";
                        for (int i = 1; i < 2; i++)
                        {
                            higlight_back_to_menu(i, i == choice);
                        }
                        //cout << "\n|_______________________________________|";
                        cout << "\n+---------------------------------------+";

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
                        system("cls"); // clear the console
                        cout << "+---------------------------------------+\n";
                        cout << "|            Balance Inquiry            |\n";
                        cout << "+---------------------------------------+\n";
                        cout << "Thank you for using this ATM. Goodbye!\n";
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
            //payment
            do
                {
                    system("cls");
                    cout << "+---------------------------------------+\n";
                    cout << "|              Payment MENU             |\n";
                    //cout << "+---------------------------------------+\n";
                    //cout << "  =====================================  \n";
                   // cout << "   Your current balance is: $" << fixed << setprecision(2) << ID1.money[0] << "\n" ; //setprecision(1000)
                    //cout << "  =====================================  \n";
                    cout << "+---------------------------------------+\n";
                    for (int i = 1; i < 6; i++)
                    {
                        cout << "| ";
                        highlight_Payment_MENU(i, i == choice);
                    }
                    //cout << "|_______________________________________|";
                    //cout << "\n+---------------------------------------+";
                    cout << "|                 CPE102                |\n";
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
                    cout << "Gametopup"; 
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
    }
}
