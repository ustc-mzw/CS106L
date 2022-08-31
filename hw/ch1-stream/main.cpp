/*
 * @Author: ustc-mzw 2875226921@qq.com
 * @Date: 2022-08-31 21:09:40
 * @LastEditors: ustc-mzw 2875226921@qq.com
 * @LastEditTime: 2022-08-31 21:26:39
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

int main()
{
    cout << typeid(convert_int_to_string(89)) << endl;

    return 0;
}