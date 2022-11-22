//
//  main.cpp
//  EyTeeUmm
//
//  Created by mwcsur on 9/30/22.
//

#include <iostream>
#include <stdio.h>
#include "App.hpp"
using namespace std;

int main(int argc, const char * argv[]) {

    cout << "ATM Sytem loading..." << endl;
    
    App app;
    app.MainLoop();
    
    cout << "System Exited..." << endl;
}
