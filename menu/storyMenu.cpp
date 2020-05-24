#include <iostream>
#include "../sceneManagement/quickTest.hpp"
#include "storyMenu.hpp"
#include "makeMenu.hpp"

//5/20/20
storyMenu::storyMenu(){
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

void storyMenu::setScene(scene * entry){
    activeScene = entry;
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
    std::cout << "| 2) Select Story                                      |" << std::endl;
    std::cout << "| 3) Return to Make Menu                               |" << std::endl;
    std::cout << "| 4) Quit                                              |" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cin >> userInput;
        switch(userInput){
        case 1:{
            qT->run(activeScene);
            break;
        }
        case 2:{
            //Need to do some mass story selection drop down for the user. starting and recieving from main. So retrieval has to be done by main.
            bool wantToQuit = false;
            while(titleScenes.size() > 0 && !wantToQuit){
                int entry = 0;
                for(int c = 0; c < titleScenes.size(); c++){
                    std::cout << c+1 << ") " << titleScenes[c]->getTitle() << std::endl;
                }
                std::cin >> entry;
                if(entry >= 1 && entry <= titleScenes.size()){
                    activeScene = titleScenes[entry-1];
                    wantToQuit = true;
                    std::cout << "Active scene selected. Returning to \"Story Menu\"" << std::endl;
                }
                else{
                    std::cout << "Invalid Entry." << std::endl;
                }
                std::cin.clear();
                std::cin.ignore();
            }
            if(titleScenes.size() == 0){
                std::cout << "No stories found." << std::endl;
            }
            break;
        }
        case 3:{
            backPedal();
            break;
        }
        case 4:{
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
