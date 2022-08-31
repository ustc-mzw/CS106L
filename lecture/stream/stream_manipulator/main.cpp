#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMNS_WIDTH = 20;

void PrintTableHeader()
{
    for(int column = 0; column < NUM_COLUMNS-1; ++column)
        cout << setfill('-') << setw(COLUMNS_WIDTH) << "" << "+";
    cout << setw(COLUMNS_WIDTH) << "" << setfill(' ') << endl;
    

}

void PrintTableBody()
{
    ifstream table_file("table-data.txt");
    if(!table_file.is_open())    
        cerr << "couldn't open file table-data.txt" << endl;
    for(int k = 0; k < NUM_LINES; k++)
    {
        int intValue;
        double doubleValue;
        table_file >> intValue >> doubleValue;
       cout << setw(COLUMNS_WIDTH) << k+1 << "|";
       cout << setw(COLUMNS_WIDTH) << intValue << "|";
       cout << setw(COLUMNS_WIDTH) << doubleValue << endl;

    }


}

int main(int argc, char* srgv[])
{
    PrintTableHeader();
    PrintTableBody();
    return 0;
}