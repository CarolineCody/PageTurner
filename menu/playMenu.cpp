#include <iostream>
#include "playMenu.hpp"
#include "../sceneManagement/scene.hpp"
#include "../dataStructs/tag.hpp"

playMenu::playMenu(){
    //Nothing much to set but just sets it innactive to prevent multiple scenes being active at once.
    setActive = false;
}

void playMenu::setParent(titleMenu * titleM){
    //Sets the active titleMenu active.
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
    //Once a valid scene is found, the function then generates a secondary menu that prints the title, the choices, and its text.
    while(!userWantsToQuit && setActiveStory){
        int userAction = 0;
        //Prints title.
        std::cout << "========================================================" << std::endl;
        std::cout << activeScene.getTitle() << std::endl;
        std::cout << "========================================================" << std::endl;
        //Prints text.
        activeScene.printText();
        //Prints choices.
        for(int c = 0; c < activeScene.choices.size(); c++){
            for(int r = 0; r < ownedTags->size(); r++){
                for(int x = 0; x < activeScene.choices[c]->required.size(); x++){
                    if(ownedTags->operator[](r).name == activeScene.choices[c]->required[x].name){
                        if(ownedTags->operator[](r).amount >= activeScene.choices[c]->required[x].amount){
                            std::cout << c+1 << ") " << activeScene.choices[c]->text << std::endl;
                        }
                    }
                }
            }
        }
        std::cout << "Type -1 to end this program." << std::endl;
        std::cout << "Type -2 to go back to the story selection menu." << std::endl;
        std::cout << "Type -3 to go back to the main menu." << std::endl;
        std::cin >> userAction;
        //Handles a line selection.
        if(!std::cin.fail() && userAction > 0 && userAction <= activeScene.choices.size()){
            activeScene = activeScene.choices[userAction-1]->scene;
            for(int c = 0; c < activeScene.choices[userAction-1]->gives.size(); c++){
                bool foundSlot = false;
                for(int r = 0; r < ownedTags->size(); r++){
                    if(ownedTags->operator[](r).name == activeScene.choices[userAction-1]->gives[c].name){
                        ownedTags->operator[](r).amount += activeScene.choices[userAction-1]->gives[c].amount;
                        foundSlot = true;
                    }
                }
                if(!foundSlot){
                    tag bip;
                    bip.amount = activeScene.choices[userAction-1]->gives[c].amount;
                    bip.name = activeScene.choices[userAction-1]->gives[c].name;
                    ownedTags->push_back(bip);
                }
            }
        }
        //Handles any and all user actions that are for quit or leaving this scene.
        switch(userAction){
            case -3:{
                userWantsToQuit = true;
                backPedal();
                break;
            }
            case -2:{
                setActiveStory = false;
                break;
            }
            case -1:{
                quit();
                break;
            }
        };
    }
    return;
}

void playMenu::quit(){
    //Sets the scene inactive with no successor so it will get shut down.
    setActive = false;
    return;
}

void playMenu::backPedal(){
    //Turns parent active.
    setActive = false;
    title->setActive = true;
}