#include <iostream>
#include "../sceneManagement/quickTest.hpp"
#include "storyMenu.hpp"
#include "makeMenu.hpp"

storyMenu::storyMenu(scene * entry){
    activeScene = entry;
    return;
}

void storyMenu::setParent(makeMenu* mm){
    make = mm;
    return;
}

void storyMenu::setRoot(titleMenu * titleM){
    title = titleM;
    return;
}

void storyMenu::setQT(quickTest * qt){
    qT = qt;
    return;
}

void storyMenu::backPedal(){
    setActive = false;
    make->setActive = true;
    return;
}

void storyMenu::returnToMenu(){
    title->setActive = true;
    setActive = false;
    return;
}

void storyMenu::printMenu(){
    int userInput;
    std::cout << "========================================================" << std::endl;
    std::cout << "|                      Edit a Story                    |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "| 1) Read Story                                        |" << std::endl;
    std::cout << "| 2) Return to Make Menu                               |" << std::endl;
    std::cout << "| 3) Quit                                              |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cin >> userInput;
        switch(userInput){
        case 1:{
            qT.run(activeScene);
            break;
        }
        case 2:{
            backPedal();
            break;
        }
        case 3:{
            quit();
            break;
        }
        default:{
            std::cin.ignore();
            std::cin.clear();
        }
    };
    std::cin.ignore();
    std::cin.clear();
    return;
}

void storyMenu::quit(){
    setActive = false;
    return;
}
