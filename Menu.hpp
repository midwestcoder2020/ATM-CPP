//
//  Menu.hpp
//  EyTeeUmm
//
//  Created by mwcsur on 9/30/22.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Menu{
    
public:
    
    
    void ShowMenu(string p);
    void GetUserInput1();
    void GetUserInput2();
    
    string GetCurrentInput1();
    string GetCurrentInput2();

    
    
    
private:
    
    string input1;
    string input2;
    
    
};

#endif /* Menu_hpp */
