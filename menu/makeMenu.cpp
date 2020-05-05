#include <iostream>
#include "makeMenu.hpp"
#include "storyMenu.hpp"

makeMenu::makeMenu(storyMenu* stry){
    story = stry;
    setActive = false;
}

void makeMenu::setParent(titleMenu* titleM){
    title = titleM;
    return;
}

void makeMenu::backPedal(){
    setActive = false;
    title->setActive = true;
    return;
}

void makeMenu::printMenu(){
    int userInput;
    std::cout << "========================================================" << std::endl;
    std::cout << "|                   Choose an Action                   |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "| 1) Create a New Story                                |" << std::endl;
    std::cout << "| 2) Edit a Premade Story                              |" << std::endl;
    std::cout << "| 3) Return to Title Screen                            |" << std::endl;
    std::cout << "| 4) Quit                                              |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cin >> userInput;
        switch(userInput){
        case 1:
            setActive = false;
            story->setActive = true;
            break;
        case 2:
            setActive = false;
            story->setActive = true;
            break;
        case 3:
            backPedal();
            break;
        case 4:
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

void makeMenu::quit(){
    setActive = false;
    return;
}