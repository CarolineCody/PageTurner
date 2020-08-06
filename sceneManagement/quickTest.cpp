#include "../menu/playMenu.hpp"
#include "scene.hpp"
#include "quickTest.hpp"
#include <iostream>

quickTest::quickTest(storyMenu * stry, playMenu * ply){
    //Assigns the story and play feature that the program can return to.
    story = stry;
    play = ply;
}

void quickTest::quit(){
    //Determines when a valid selection has been made.
    bool notDone = true;
    //Loops until the user wants to quit.
    while(notDone){
        //Prompts user for action to determine next action.
        std::cout << "Are you sure you want to close this whole program? (y/n)" << std::endl;
        char input;
        std::cin >> input;
        //Processes input.
        switch(input){
            //Ends program.
            case 'y':{
                notDone = false;
                story->setActive = false;
                break;
            }
            //Keeps running program.
            case 'n':{
                notDone = false;
                break;
            }
            //Clears input otherwise.
            default:{
                std::cin.clear();
                std::cin.ignore();
                break;
            }
        };
    }
    return;
}

void quickTest::run(scene * activeScene){
        bool userWantsToQuit = false;
        while(!userWantsToQuit){
        int userAction = 0;
        //Prints title.
        std::cout << "========================================================" << std::endl;
        std::cout << activeScene->getTitle() << std::endl;
        std::cout << "========================================================" << std::endl;
        //Prints text.
        activeScene->printText();
        //Prints choices.
        for(int c = 0; c < activeScene->choices.size(); c++){
            for(int r = 0; r < play->ownedTags->size(); r++){
                for(int x = 0; x < activeScene->choices[c]->required.size(); x++){
                    if(play->ownedTags->operator[](r).name == activeScene->choices[c]->required[x].name && play->ownedTags->operator[](r).amount >= activeScene->choices[c]->required[x].amount){
                        std::cout << c+1 << ") " << activeScene->choices[c]->text << std::endl;
                    }
                }
            }
        }
        std::cout << "Type -1 to end this program." << std::endl;
        std::cout << "Type -2 to go back to the main menu." << std::endl;
        std::cin >> userAction;
        //Handles a line selection.
        if(!std::cin.fail() && userAction > 0 && userAction <= activeScene->choices.size()){
            activeScene = activeScene->choices[userAction-1]->linkScene;
            for(int c = 0; c < activeScene->choices[userAction-1]->gives.size(); c++){
                bool foundSlot = false;
                for(int r = 0; r < play->ownedTags->size(); r++){
                    if(play->ownedTags->operator[](r).name == activeScene->choices[userAction-1]->gives[c].name){
                        play->ownedTags->operator[](r).amount += activeScene->choices[userAction-1]->gives[c].amount;
                        foundSlot = true;
                    }
                }
                if(!foundSlot){
                    tag newTag;
                    newTag.amount = activeScene->choices[userAction-1]->gives[c].amount;
                    newTag.name = activeScene->choices[userAction-1]->gives[c].name;
                    play->ownedTags->push_back(newTag);
                }
            }
        }
        //Handles any and all user actions that are for quit or leaving this scene.
        switch(userAction){
            case -2:{
                userWantsToQuit = true;
                break;
            }
            case -1:{
                quit();
                userWantsToQuit = !story->setActive;
                break;
            }
        };
    }
}

