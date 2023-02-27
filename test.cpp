#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int value3;
    ifstream inFile("650610000.txt"); // open the file for reading
    if (inFile.is_open()) { // check if the file was successfully opened
        inFile.ignore(1000, ','); // ignore the first value
        inFile.ignore(1000, ','); // ignore the second value
        inFile >> value3; // read the third value
        inFile.close(); // close the file
        cout << "The value in the third position is: " << value3 << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
    return 0;
}
