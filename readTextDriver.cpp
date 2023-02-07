#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readText(string filename)
{
    string line;
    ifstream my_file;
    my_file.open(filename);

    if(my_file.fail())
    {
        cout << " !!! Warning! File Not found !!!" << endl;
    }
    while(getline(my_file,line))
    {
        cout << line << endl;
    }
    cout << endl;
    my_file.close();

}

int main()
{
    readText("deathMessage.txt");
    cout << endl;
    readText("fakeFile.txt");
}