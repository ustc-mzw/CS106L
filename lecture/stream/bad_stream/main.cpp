#include<iostream>
#include<string>

using namespace std;

int main(int argc, char* argv[])
{
    string password;
    cout << "Enter administrator password: ";
    cin >> password;
    if(password == "password") { // Use a better password, by the way!
        cout << "Do you want to erase your hard drive (Y or N)? ";
        char yesOrNo;
        cin >> yesOrNo;
        if(yesOrNo == 'y')
            cout << "!" << endl;
    }
}