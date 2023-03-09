#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 9);
    for (int i = 650610000; i <= 650610000; i++) {
        int id_user = 650610000;
        string id = to_string(i);
        string filename = to_string(i) + ".txt";
        ofstream outfile(filename);
        if (outfile.is_open()) {
            int num = dist(gen) * 1000;
            outfile  << i-id_user << "," << id << "," << num ;
            outfile.close();
            cout << "File created: " << id << endl;
        } else {
            cout << "Error creating file: " << id << endl;
        }
    }
    return 0;
}