//
//  App.hpp
//  EyTeeUmm
//
//  Created by mwcsur on 9/30/22.
//

#ifndef App_hpp
#define App_hpp

#include <stdio.h>

#include "ATMSystem.hpp"
#include "Menu.hpp"



class App{
public:
    App();
    void MainLoop();
    void Quit();
    
    void SetIsDone(bool isDone);
    bool GetIsDone();
    
    Menu menu;
    ATMSystem atmSystem;
    
private:
    bool isDone = false;
    
    
};
#endif /* App_hpp */
