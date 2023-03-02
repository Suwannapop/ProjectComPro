#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    int UserPass, UserID, money ;
    cout << "Hello welcome to Create your account menu" ;
    cout << "write your password" ;
    cin >> UserPass ;
    cout << "write your ID" ;
    cin >> UserID ;
    cout << "write your money";
    cin >> money ;


        string identification = to_string(UserID);
        string filename = to_string(UserID) + ".txt" ;
        ofstream outfile(filename);
        if (outfile.is_open()){
            outfile << UserPass << "," << identification << ";" << money ;
            outfile.close();
            cout << "Created successfully" << identification <<";" << endl;
        }else {
            cout << "Failed to create accout" << identification <<";" <<endl ;
        }
        return  0 ;
        
        
        
}