#include <iostream>
#include "titleMenu.hpp"
#include "makeMenu.hpp"
#include "playMenu.hpp"

titleMenu::titleMenu(makeMenu* mm, playMenu * pm){
    make = mm;
    play = pm;
    setActive = true;
}

void titleMenu::printMenu(){
    int userInput = 0;
    //Main menu print.
    std::cout << "========================================================" << std::endl;
    std::cout << "|                 Welcome to PageTurner                |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "| 1) Create a Story                                    |" << std::endl;
    std::cout << "| 2) Play a Story                                      |" << std::endl;
    std::cout << "| 3) Quit                                              |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cin >> userInput;
    //Prints the menu options.
    switch(userInput){
        case 1:
            setActive = false;
            make->setActive = true;
            break;
        case 2:
            setActive = false;
            play->setActive = true;
            break;
        case 3:
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

void titleMenu::quit(){
    setActive = false;
    return;
}