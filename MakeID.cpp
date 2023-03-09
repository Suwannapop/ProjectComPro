#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int ID_USER , PASS_USER , money  ;
    string name ;
    cout << "What is your name " ;
    getline(cin , name) ;
    cout << "ID :" ;
    cin >> ID_USER ;
    cout << "Pass :" ;
    cin >> PASS_USER ;
    cout << "Money :" ;
    cin >> money ;
        string id = to_string(ID_USER);
        string filename = to_string(ID_USER) + ".txt";
        ofstream outfile(filename);
        if (outfile.is_open()) {
            outfile  << PASS_USER << "," << id << "," << money << "," << name  ;
            outfile.close();
            cout << "File created: " << id << endl;
        } else {
            cout << "Error creating file: " << id << endl;
        }
    return 0;
}