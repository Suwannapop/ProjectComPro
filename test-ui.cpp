#include <iostream>
#include <iomanip>
#include <windows.h> //sleep higlight

using namespace std;

int windows(){
    for (int i = 0; i < 39 ; i++)
    {
        cout << char(196);
    }
}

int main(){


    cout << char(201) ; windows(); cout << char(187) << endl;
    cout << char(186) << "               Login ATM               " << char(186) << endl;
    cout << char(200) ; windows(); cout << char(188) << endl;


}