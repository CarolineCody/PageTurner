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
    //Toggles the Story Selection Menu, and the change story option.
    bool setActiveStory = false;
    //Handes if the user wants to quit or not.
    bool userWantsToQuit = false;
    //Controls what scene is being viewed by the user.
    scene activeScene;
    while(!setActiveStory){
        std::cout << "========================================================" << std::endl;
        std::cout << "|                    Select a Story                    |" << std::endl;
        std::cout << "========================================================" << std::endl;
        for(int c = 0; c < stories.size(); c++){
            std::cout << "| " << c+1 << ")" << stories[c].getTitle() << std::endl;
        }
        std::cout << "| " << stories.size()+2 << ") Return to Title Screen                            |" << std::endl;
        std::cout << "| " << stories.size()+3 << ") Quit                                              |" << std::endl;
        std::cout << "========================================================" << std::endl;
        std::cin >> userInput;
        if(userInput > 0 && userInput <= stories.size()){
            setActiveStory = true;
            activeScene = stories[userInput-1];
        }
        else if(userInput == stories.size()+2){
            backPedal();
        }
        else if(userInput == stories.size()+3){
            quit();
        }
        std::cin.ignore();
        std::cin.clear();
    }
    while(setActiveStory){
        int userAction
        std::cout << "========================================================" << std::endl;
        std::cout << activeScene.getTitle() << std::endl;
        std::cout << "========================================================" << std::endl;
        //Need some way to manage choices.
        std::cout << "Type -1 to end this program." << std::endl;
        std::cout << "Type -2 to go back to the story selection menu." << std::endl;
        std::cout << "Type -3 to go back to the main menu." << std::endl;
        //Need some way to handle choices and update the scene.
        if()
    }
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