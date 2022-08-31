#include<iostream>
#include<string>

using namespace std;

int main(int argc, char* argv[])
{
  int dummyInt;
    string dummyString;
    cin >> dummyInt;
    getline(cin, dummyString); 

    cout << dummyInt << "|" << dummyString << endl;
    return 0;
}