#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char* argv[])
{
    string my_file("myfile.txt");

    ofstream output;
    output.open(my_file.c_str());
    output << "new" << endl;

    ifstream input("myfile.txt");
    if(!input.is_open())
        cerr << "couldn't open the file my file.txt" << endl;
    else
        cout << "successfully open the file" << endl;

}