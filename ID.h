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

// higlight_back_to_menu use in receipt
void higlight_back_to_menu(int index, bool selected)
{
    int l = 0;
    cout << char(186) << "           ";
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
        l = 11;
        cout << "Back To Login Menu";
        break;
    default:
        break;
    }
    cout << "\033[0m" << setw(l) << char(186); //<< setw(l)
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