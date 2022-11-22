//
//  Menu.cpp
//  EyTeeUmm
//
//  Created by mwcsur on 9/30/22.
//

#include "Menu.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

void Menu::ShowMenu(string p){
    cout << p << endl;
}

void Menu::GetUserInput1(){
    cin >> input1;
}

void Menu::GetUserInput2(){
    cin >> input2;
}

string Menu::GetCurrentInput1(){
    return input1;
}

string Menu::GetCurrentInput2(){
    return input2;
}

