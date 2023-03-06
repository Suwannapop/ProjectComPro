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
    string name ;
};

void ImportFile(Dataformat &ID, string fileindex) // ใช้ฝากถอนโอ
{
    ifstream data;
    data.open(fileindex);
    string line;
    int idnumber, pass;
    double balnace;
    char name1[99] ;
    if (data.is_open())
        {
            while (getline(data, line)) // importfile
            {
                sscanf(line.c_str(), "%d,%d,%lf,%s" , &pass,&idnumber,&balnace,name1);
                ID.Pass.push_back(pass);
                ID.ID.push_back(idnumber);
                ID.money.push_back(balnace);
                ID.name = name1 ;
                cout << ID.Pass[0] << " " << ID.ID[0] << " "<< ID.money[0] << " " << ID.name ;
            }
        }else {
            cout << "KKKKKK" ;
        }
           
}


int main(){
    Dataformat ID ;
    string ID1 ;
    cout << "ID :" ;
    cin >> ID1 ;
    string fileindex = ID1 + ".txt";
    ImportFile(ID,fileindex);
}