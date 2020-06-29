#include <iostream>
#include "titleMenu.hpp"
#include "playMenu.hpp"

titleMenu::titleMenu(storyMenu* sty, playMenu * pm){
    story = sty;
    play = pm;
    setActive = true;
}

void titleMenu::printMenu(){
    int userInput = 0;
    //Main menu print.
    std::cout << "========================================================" << std::endl;
    std::cout << "|                 Welcome to PageTurner                |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "| 1) Create or Edit a Story                            |" << std::endl;
    std::cout << "| 2) Play a Story                                      |" << std::endl;
    std::cout << "| 3) Quit                                              |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cin >> userInput;
    //Prints the menu options.
    switch(userInput){
        //Handles editing or making a story.
        case 1:
            setActive = false;
            story->setActive = true;
            break;
        //Handles playing a story.
        case 2:
            setActive = false;
            play->setActive = true;
            break;
        //Quits program.
        case 3:
            quit();
            break;
        //Otherwise input is invalidated and the program loops.
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
    bool notDone = true;
    //Loops until the user enters 'y' or 'n' to end the loop.
    while(notDone){
        std::cout << "Are you sure you want to close this whole program? (y/n)" << std::endl;
        char input;
        std::cin >> input;
        switch(input){
            //Upon selecting y the program ends.
            case 'y':{
                notDone = false;
                setActive = false;
                break;
            }
            //Upon selectin n the program resumes.
            case 'n':{
                notDone = false;
                break;
            }
            //Clears content and stops.
            default:{
                std::cin.clear();
                std::cin.ignore();
                break;
            }
        };
    }
    return;
}