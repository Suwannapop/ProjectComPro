#include <iostream>
#include <fstream>
#include <string>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 9);
    for (int i = 650610000; i <= 650610005; i++) {
        int id_user = 650610000;
        std::string id = std::to_string(i);
        std::string filename = std::to_string(i) + ".txt";
        std::ofstream outfile(filename);
        if (outfile.is_open()) {
            int num = dist(gen) * 1000;
            outfile << id << "," << num << ".00" << "," << i-id_user;
            outfile.close();
            std::cout << "File created: " << id << std::endl;
        } else {
            std::cout << "Error creating file: " << id << std::endl;
        }
    }
    return 0;
}

