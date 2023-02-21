#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

struct user
{
    string ID;
    string pass;
    double money;
};
int main()
{
    user u1 = {"650612100", "2100", 1000};
    user u2 = {"650612082", "2082", 1000};
    double MoneyData[] = {};
    MoneyData[0] = u1.money;
    MoneyData[1] = u2.money;

}
