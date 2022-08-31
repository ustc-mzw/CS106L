#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
    ifstream capitals("world-capitals.txt");
    if(!capitals.is_open())
    {
        cout << "can't find the file world-capital.txt" << endl;
    }

    string capital, country;
    while(getline(capitals,capital) && getline(capitals, country))
    {
        cout << capital << "is the capital of" << country << endl;
    }
    return 0;
}