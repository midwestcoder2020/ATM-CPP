//
//  System.cpp
//  EyTeeUmm
//
//  Created by mwcsur on 9/30/22.
//

#include "ATMSystem.hpp"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

ATMSystem::ATMSystem(){
    Init();
    accs.clear();
    AccLoad();
}

void ATMSystem::AccLoad(){
    accs.clear();

    fstream file;
    string line;
    file.open("backend.csv", ios::in);
    while(getline(file,line)){
        accs.push_back(line);
        cout << line << endl;
    }
    file.close();
}

char* stringToInts(string s);

char* stringToInts(string s){
    char* ints;
    
    for ( size_t i = 0; i < strlen(ints); i++ )
    {
        int tData = (int) ints[i];
        ints[i] = tData;
    }

    return ints;
}

void ATMSystem::Init(){
    fstream backend;
    backend.open ("backend.csv", fstream::app);
//    backend << "admin" << "," << 1234 << "," << 0 << endl;
    backend.close();
}

string ATMSystem::GetPin(){
    string pin;
    cin >> pin;
    return pin;
}
void ATMSystem::SetPin(string p){
    pin = p;
}

int ATMSystem::GetCurrBalance(string accName,string uPin){
        
    int res =-1;
    
    //test,1234,0
    
    for(auto& it:accs){

        string t1 = it;
        
        string delim = ",";
        
        string name = t1.substr(0,t1.find(delim));
        
        string rest = t1.substr(name.length()+1,t1.length()-1);
        
        string pin =rest.substr(0,rest.find(delim));
        
        string balance = t1.substr(name.length()+pin.length()+2,t1.length()-1);
        
        if(strcmp(name.c_str(), accName.c_str()) ==0 && strcmp(pin.c_str(), uPin.c_str()) == 0){
            res =  stoi(balance);
        }
        
    }
    
    
    return res;
}


int ATMSystem::UpdateUserPin(string uPin, string accName, string newPin){
    if(AccExists(accName)==0)return -1;
    
    for(auto& it:accs){

        string t1 = it;
        
        string delim = ",";
        
        string name = t1.substr(0,t1.find(delim));
        
        string rest = t1.substr(name.length()+1,t1.length()-1);
        
        string pin =rest.substr(0,rest.find(delim));
        
        string balance = t1.substr(name.length()+pin.length()+2,t1.length()-1);
        
        if(strcmp(name.c_str(), accName.c_str()) ==0 && strcmp(pin.c_str(), uPin.c_str()) == 0){
            pin = newPin;
        }
        
        it = name+","+pin+","+balance;
    }
    
    fstream file;
    file.open("backend.csv",ios::out);
    for(auto& it:accs){
        file << it<<endl;
    }
    file.close();
    return 0;
}

int ATMSystem::Deposit(int amt, string uPin, string accName){
    
    if(AccExists(accName)==0)return -1;
    
    int res = 0;
    
    for(auto& it:accs){

        
        string t1 = it;
        
        string delim = ",";
        
        string name = t1.substr(0,t1.find(delim));
        
        string rest = t1.substr(name.length()+1,t1.length()-1);
        
        string pin =rest.substr(0,rest.find(delim));
        
        string balance = t1.substr(name.length()+pin.length()+2,t1.length()-1);
        
        if(strcmp(name.c_str(), accName.c_str()) ==0 && strcmp(pin.c_str(), uPin.c_str()) == 0){
            int balanceT = stoi(balance);
            balanceT += amt;
            balance = to_string(balanceT);
        }
        
        it = name+","+pin+","+balance;
    }
    
    fstream file;
    file.open("backend.csv",ios::out);
    for(auto& it:accs){
        file << it<<endl;
    }
    file.close();
    
    return 0;
}

int ATMSystem::Withdraw(int amt, string uPin, string accName){
    
    int res =0;
    
    if(AccExists(accName)==0)return -1;
    
    for(auto& it:accs){
        
        
        string t1 = it;
        
        string delim = ",";
        
        string name = t1.substr(0,t1.find(delim));
        
        string rest = t1.substr(name.length()+1,t1.length()-1);
        
        string pin =rest.substr(0,rest.find(delim));
        
        string balance = t1.substr(name.length()+pin.length()+2,t1.length()-1);
        
        if(strcmp(name.c_str(), accName.c_str()) ==0 && strcmp(pin.c_str(), uPin.c_str()) == 0){
            int balanceT = stoi(balance);
            
            if(balanceT >=amt){
            balanceT -= amt;
            balance = to_string(balanceT);
            }
            else{
                res = -1;
            }
        }
        
        it = name+","+pin+","+balance;
    }
    
    fstream file;
    file.open("backend.csv",ios::out);
    for(auto& it:accs){
        file << it<<endl;
    }
    file.close();
    return res;
}

int ATMSystem::CreateNewAccount(string AccName, string pin){
    
    if(AccExists(AccName) !=0) return -1;
    
    fstream fout;
    fout.open("backend.csv",ios::out|ios::app);
    fout << AccName << "," << pin << "," << "0" << endl;
    fout.close();
    
    return 0;
}

bool ATMSystem::AccExists(string accName){
    bool found = false;
    
    string line;
    fstream in;
    
    in.open("backend.csv",ios::in);
    
    while(getline(in,line)){
        string delim = ",";
        string token = line.substr(0,line.find(delim));
        if(strcmp(token.c_str(), accName.c_str()) ==0){
            found = true;
        }
    }
        
    return found;
}
