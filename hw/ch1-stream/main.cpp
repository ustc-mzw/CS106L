/*
 * @Author: ustc-mzw 2875226921@qq.com
 * @Date: 2022-08-31 21:09:40
 * @LastEditors: ustc-mzw 2875226921@qq.com
 * @LastEditTime: 2022-09-01 19:15:15
 * @FilePath: /undefined/mnt/d/Linux/CS106L/hw/ch1-stream/main.cpp
 * @Description: CS106L chapter1:stream practice 
 * 
 * Copyright (c) 2022 by ustc-mzw 2875226921@qq.com, All Rights Reserved. 
 */


#include<iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<typeinfo>

using namespace std;

/**
 * @description: 读取一行，返回一行（去掉newline）
 * @return {*}
 */
string GetLine()
{
    string result;
    getline(cin, result);
    return result;
}


/**
 * @description: 控制台反复读取一个整型，直到读取成功
 * @return {*}
 */
double GetReal()
{
    while(true)
    {
        stringstream converter;
        converter << GetLine();
        double result;
        if(converter >> result)
        {
            char leftover;
            if(converter >> leftover)
                cout << "unexpected character" << leftover << endl;
            else
                return result;
        }
        else
            cout << "please enter an real number" << endl;
        cout << "Retry:";
    }
}

/**
 * @description: 控制台反复读取一个整型，直到读取成功
 * @return {*}
 */
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


/**
 * @description: 将一个整型转变为string类型
 * @param {int} n
 * @return {*}
 */
string convert_int_to_string(int n)
{
    stringstream converter;
    string result;
    converter << n;
    converter >> result;
    return result;
}

/**
 * @description:用户输入true,false,返回相应布尔值 
 * @return {*}
 */
bool GetBoolean()
{
    bool result;
    cin >> boolalpha;
    result = GetInteger();
    cin >> noboolalpha;
    return result;
}

/**
 * @description: return a integer's hexadecimal decription
 * @param {int} dec_num
 * @return {*}
 */
string HasHexLetters(int dec_num)
{
    stringstream converter;
    string result; 
    converter << hex << dec_num;
    converter >> result;
    return result;
}

/**
 * @description: takes in an int corresponding to the height of the triangle and a char representing a character to print, 
 *               then draws a triangle of the specified height using that character.
 * @param {int} height
 * @param {char} ch
 * @return {*}
 */
void DrawTriangle(int height, char ch)
{
    for(int i = 1; i <= height; i++)
    {
        cout << setfill(' ') << setw(height-i) << "";
        cout << setfill(ch) << setw(2*i - 1) << "" <<endl;
    }
    cout << setfill(' ');
}

/**
 * @description: open a file until it succees
 * @return {*}
 */
ifstream OpenFile()
{
    ifstream file;
    string filename;
    cout << "Pleae enter the name of file:";
    filename = GetLine();
    while(!file.is_open())
    {
        file.clear();
        cout << "can't find the file " << filename << endl;
        cout << "Retry:";
        filename = GetLine();
        file.open(filename.c_str());
    }
    return file;
}

int main()
{
    OpenFile();
    return 0;


}