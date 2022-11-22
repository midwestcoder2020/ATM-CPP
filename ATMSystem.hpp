//
//  System.hpp
//  EyTeeUmm
//
//  Created by mwcsur on 9/30/22.
//

#ifndef ATMSystem_hpp
#define ATMSystem_hpp

#include <stdio.h>
#include <string>
#include "Menu.hpp"
#include <vector>
using namespace std;



class ATMSystem{
    
public:
    ATMSystem();
    
    vector<string> accs;
    
    string GetPin();
    
    void SetPin(string pin);
    
    int GetCurrBalance(string pin,string accName);
    
    int UpdateUserPin(string pin, string accName, string newPin);
    
    int Deposit(int amt, string pin, string accName);
    int Withdraw(int amt, string pin, string accName);
    
    int CreateNewAccount(string AccName,string pin);
    
    void Init();
    void AccLoad();
    bool AccExists(string accName);
    
    //Menu System
    Menu menu;
    
private:
    string pin;
    int acc;
    int currBalance;
    
    
    
};

#endif /* ATMSystem_hpp */
