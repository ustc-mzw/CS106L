#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

string GetLine()
{
    string result;
    getline(cin, result);
    return result;
}

int GetInteger()
{
    while(true)
    {
        stringstream converter;
        converter << GetLine();
        int result;
        if(converter >> result)
        {
            char leftover;
            if(converter >> leftover)
                cout << "unexpected character" << leftover << endl;
            else
                return result;
        }
        else
            cout << "please enter an integer" << endl;
        cout << "Retry:";
    }
}

int main()
{

    GetInteger();
    return 0;
}