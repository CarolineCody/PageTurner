#include <iostream>
#include "playMenu.hpp"

playMenu::playMenu(){
    setActive = false;
}

void playMenu::setParent(titleMenu * titleM){
    title = titleM;
}

void playMenu::printMenu(){
    int userInput;
    std::cout << "========================================================" << std::endl;
    std::cout << "|                    Select a Story                    |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "| 1) Return to Title Screen                            |" << std::endl;
    std::cout << "| 2) Quit                                              |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cin >> userInput;
        switch(userInput){
        case 1:
            backPedal();
            break;
        case 2:
            quit();
            break;
        default:{
            std::cin.ignore();
            std::cin.clear();
        }
    };
    std::cin.ignore();
    std::cin.clear();
    return;
}

void playMenu::quit(){
    setActive = false;
    return;
}

void playMenu::backPedal(){
    setActive = false;
    title->setActive = true;
}