#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void writeWinner(string winnerName)
{
    ofstream my_file("winners.txt", std::ios::app);
    my_file << winnerName << endl;
}

int main()
{
    writeWinner("Blake");
    writeWinner("Libby");
    return 0;
}