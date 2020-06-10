#include <iostream>
#include "makeMenu.hpp"
#include "storyMenu.hpp"

makeMenu::makeMenu(storyMenu* stry){
    story = stry;
    //Makes sure that the story is not set active by default as this will cause multiple scenes to become active upon initialization.
    setActive = false;
}

void makeMenu::setParent(titleMenu* titleM){
    //Assigns the name to the title menu for back tracking.
    title = titleM;
    return;
}

void makeMenu::backPedal(){
    //Changes the activity of the two menus to set active.
    setActive = false;
    title->setActive = true;
    return;
}

void makeMenu::printMenu(){
    //Prints and proccesses user input.
    int userInput;
    std::cout << "========================================================" << std::endl;
    std::cout << "|                       Make Menu                      |" << std::endl;
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
        bool notDone = true;
    while(notDone){
        std::cout << "Are you sure you want to close this whole program? (y/n)" << std::endl;
        char input;
        std::cin >> input;
        switch(input){
            case 'y':{
                notDone = false;
                setActive = false;
                break;
            }
            case 'n':{
                notDone = false;
                break;
            }
            default:{
                std::cin.clear();
                std::cin.ignore();
                break;
            }
        };
    }
    return;
}