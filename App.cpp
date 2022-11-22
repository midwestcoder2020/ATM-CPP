//
//  App.cpp
//  EyTeeUmm
//
//  Created by mwcsur on 9/30/22.
//

#include "App.hpp"
#include <stdio.h>
#include "iostream"
#include <string>
#include <cstring>
using namespace std;

void App::Quit(){
    SetIsDone(true);
}

void App::SetIsDone(bool done){
    isDone = done;
}

App::App(){
    isDone = false;
}

bool App::GetIsDone(){
    return isDone;
}

void App::MainLoop(){
    
    while(GetIsDone()==false){
        menu.ShowMenu("\nWelcome To the ATM System");
        menu.ShowMenu("See Your Choices Below\n");
        menu.ShowMenu("1- See Balance\n");
        menu.ShowMenu("2- Withdraw\n");
        menu.ShowMenu("3- Deposit\n");
        menu.ShowMenu("4- Change Pin\n");
        menu.ShowMenu("5- Create New ATM Account\n");
        menu.ShowMenu("6- Exit\n");
        
        menu.ShowMenu("Enter choice below: \n");
        menu.GetUserInput1();
    
        
        switch (stoi(menu.GetCurrentInput1())) {
            case 1:
            {
                cout << "Checking balance.." << endl;
                
                menu.ShowMenu("Enter Account Name");
                menu.GetUserInput1();
                
                menu.ShowMenu("Enter Account Pin");
                menu.GetUserInput2();
                
                //atm system check if account exists
                int res =atmSystem.GetCurrBalance(menu.GetCurrentInput1(), menu.GetCurrentInput2());
                
                if(res <0){
                    cout << "\nUnable to complete inquiry" << endl;
                }
                else{
                cout << "\nYour current balance is: $" << res << endl;
                }
                break;
            }
            
            case 2:
            {
                cout << "Withdrawing funds..." << endl;
                
                menu.ShowMenu("Enter Account Name");
                menu.GetUserInput1();
                
                menu.ShowMenu("Enter Account Pin");
                menu.GetUserInput2();
                
                menu.ShowMenu("Enter Amount: ");
                int amt;
                cin >> amt;
                
                //atm system check if account exists
                int res =atmSystem.Withdraw(amt, menu.GetCurrentInput2(), menu.GetCurrentInput1());
                
//                cout << res << endl;
                
                if(res <0){
                    cout << "\nUnable to complete transaction" << endl;
                }
                else{
                cout << "\nWithdrew " << amt << endl;
                }
                
                break;
            }
                
            case 3:
            {
                cout << "Depositing funds..." << endl;
                
                menu.ShowMenu("Enter Account Name");
                menu.GetUserInput1();
                
                menu.ShowMenu("Enter Account Pin");
                menu.GetUserInput2();
                
                menu.ShowMenu("Enter Amount: ");
                int amt;
                cin >> amt;
                
                //atm system check if account exists
                int res =atmSystem.Deposit(amt, menu.GetCurrentInput2(), menu.GetCurrentInput1());
                
                cout << res << endl;
                
                if(res <0){
                    cout << "\nUnable to complete transaction." << endl;
                }
                else{
                cout << "\nDeposited " << amt << endl;
                }
                
                break;
                
            }
            case 4:
            {
                cout << "Changing pin code..." << endl;
                
                menu.ShowMenu("Enter Account Name");
                menu.GetUserInput1();
                
                menu.ShowMenu("Enter Account Pin");
                menu.GetUserInput2();
                
                menu.ShowMenu("Enter New Pin: ");
                string nPin;
                cin >> nPin;
                
                //atm system check if account exists
                int res =atmSystem.UpdateUserPin(menu.GetCurrentInput2(), menu.GetCurrentInput1(),nPin);
                
                cout << res << endl;
                
                if(res <0){
                    cout << "\nUnable to complete transaction." << endl;
                }
                else{
                cout << "\nPin Updated for User Account " << menu.GetCurrentInput1() << endl;
                }
                
                break;
            }
            case 5:
            {
                cout << "Creating New Account..." << endl;
                
                menu.ShowMenu("Enter Desired Account Name: ");
                menu.GetUserInput1();
                
                menu.ShowMenu("Enter Your Desired Account Pin:");
                menu.GetUserInput2();
                
                cout << "Creating Account With Account Name "<< menu.GetCurrentInput1()<< " and Account Pin "<< menu.GetCurrentInput2() << " ? <yes>: " << endl;
                
                string confirmNewAcc = "";
                
                cin >> confirmNewAcc;
                
                
                
                if(strcmp(confirmNewAcc.c_str(), "yes")==0){
                    
                    string tempAccName = menu.GetCurrentInput1();
                    
                    string tempAccPin = menu.GetCurrentInput2();
                    
                    cout << tempAccName << " || " << tempAccPin << endl;
                    
                    int res =atmSystem.CreateNewAccount(tempAccName, tempAccPin);
                    
                    cout << res << endl;
                    //create accunt on atm system
                    if(res <0){
                        cout << "Unable to create account with Account Name " << tempAccName << " and Account Pin " << tempAccPin << endl;
                    }
                    else{
                        cout << "Account created with Account Name " << tempAccName << " and Account Pin " << tempAccPin << endl << ". Please do not lose your account name or pin";
                        
                        atmSystem.AccLoad();
                    }
                    
                }else{
                    cout << "Account not created" << endl;
                }
                
                break;
            }
            case 6:
            {
                cout << "Exiting program..." << endl;
                SetIsDone(true);
                break;
            }
                
            default:
            {
                cout << "Invalid choice. Try again!" << endl;
                break;
            }
        }
    }
}
