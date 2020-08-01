#include <vector>
#include <iostream>
#include <fstream>
#include "scene.hpp"
#include "sceneManager.hpp"
#include "../dataStructs/choice.hpp"
#include "../dataStructs/tag.hpp"

sceneManager::sceneManager(){
    return;
}

std::vector<scene *> sceneManager::sceneSelection(){
    scene * activeScene;
    int sceneSelectionNumber;
    int userActionChoice;
    bool validActionTaken = false;
    //Initiates scene management.
    std::cout << "========================================================" << std::endl;
    std::cout << "|                   Select a Scene                     |" << std::endl;
    std::cout << "========================================================" << std::endl;
    for(int c = 0; c < scenes.size(); c++){
        std::cout << "|" << c+1 << ") " << scenes[c]->getTitle() << std::endl;
    }
    while(!validActionTaken){
        //Loops until the user makes a valid selection.
        std::cout << "Enter in the number of the scene you would like to activly edit." << std::endl;
        std::cin >> sceneSelectionNumber;
        if(sceneSelectionNumber > 0 && sceneSelectionNumber <= scenes.size()){
            activeScene = scenes[sceneSelectionNumber-1];
            validActionTaken = true;
        }
        else{
            std::cin.clear();
            std::cin.ignore();
        }
    }
    validActionTaken = false;
    //Once a scene is selected the choices and settings are made.
    while(!validActionTaken){
        std::cout << "========================================================" << std::endl;
        std::cout << "|                    Scene Manager                     |" << std::endl;
        std::cout << "========================================================" << std::endl;
        std::cout << "| 1) Edit tags of choices.                             |" << std::endl;
        std::cout << "| 2) Add choice to Scene.                              |" << std::endl;
        std::cout << "| 3) Edit choice title.                                |" << std::endl;
        std::cout << "| 4) Remove choice from Scene.                         |" << std::endl;
        std::cout << "| 5) Set Scene title.                                  |" << std::endl;
        std::cout << "| 6) Edit Scene text.                                  |" << std::endl;
        std::cout << "| 7) Set the scene that a choice connects to.          |" << std::endl;
        std::cout << "| 8) Return to Edit menu.                              |" << std::endl;
        std::cout << "========================================================" << std::endl;
        std::cin >> userActionChoice;
        std::cin.clear();
        std::cin.ignore();
        //No prper management from here on in.
        switch(userActionChoice){
            case 1:{
                //Handles case where the file has nothing to show.
                if(activeScene->choices.size() == 0){
                    std::cout << "No choices available, therefore no tags can be added at this time." << std::endl;
                    break;
                }
                int choiceSelection = 0;
                bool doneMakingChoice;
                choice * activeChoice;
                //Prints all choices in this scene.
                std::cout << "Here are the choices listed under this scene. Select the number of the scene you would like to edit." << std::endl;
                for(int c = 0; c < activeScene->choices.size(); c++){
                    std::cout << c+1 << ") " << activeScene->choices[c]->text << std::endl;
                }
                std::cin >> choiceSelection;
                if(choiceSelection > 0 && choiceSelection <= activeScene->choices.size()){
                    activeChoice = activeScene->choices[choiceSelection-1];
                }
                //Handles the add/remove for require and give.
                while(!doneMakingChoice){
                    int tagChoice = 0;
                    bool validTagNumber = false;
                    std::cout << "Select the number representing the tag you would like to add/remove to/from this choice." << std::endl;
                    std::cout << "Enter -1 to quit." << std::endl;
                    if(tags.size() == 0){
                        std::cout << "No choices available at this time." << std::endl;
                        doneMakingChoice = true;
                    }
                    else
                    {
                        for(int c = 0; c< tags.size(); c++){
                            std::cout << c+1 << ") " << tags[c].name << std::endl;
                        }
                        //Prompts for exact actions after the tag has been selected.
                        while(!validTagNumber){
                            std::cin >> tagChoice;
                            char userCharChoice;
                            if(tagChoice > 0 && tagChoice <= tags.size()){
                                validTagNumber = true;
                                std::cout << "Would you like to add this tag or remove this tag (+/-)?" << std::endl;
                                std::cout << "Enter anything else to quit."                             << std::endl;
                                std::cin >> userCharChoice;
                                switch(userCharChoice){
                                    case '+':{
                                        //Handles add.
                                        int giveOrRequire = 0;
                                        std::cout << "Would you like it to be given upon selecting this choice? Or Required to select this choice?" << std::endl;
                                        std::cout << "1) Give." << std::endl;
                                        std::cout << "2) Take." << std::endl;
                                        std::cout << "Enter anything else to quit." << std::endl;
                                        std::cin >> giveOrRequire;
                                        //For Give.
                                        if(giveOrRequire == 1){
                                            activeChoice->gives.push_back(tags[tagChoice-1]);
                                            bool quantityFound = false;
                                            int quantity;
                                            while(!quantityFound){
                                                std::cout << "How many of these tags would you like to give?" << std::endl;
                                                std::cin >> quantity;
                                                if(!std::cin.fail()){
                                                    quantityFound = true;
                                                    activeChoice->gives[activeChoice->gives.size()-1].amount = quantity;
                                                }
                                                std::cin.clear();
                                                std::cin.ignore();
                                            }
                                        }
                                        //For Require.
                                        else if(giveOrRequire == 2){
                                            activeChoice->gives.push_back(tags[tagChoice-1]);
                                            bool quantityFound = false;
                                            int quantity;
                                            while(!quantityFound){
                                                std::cout << "How many of these tags would you like to require?" << std::endl;
                                                std::cin >> quantity;
                                                if(!std::cin.fail()){
                                                    quantityFound = true;
                                                    activeChoice->gives[activeChoice->gives.size()-1].amount = quantity;
                                                }
                                                std::cin.clear();
                                                std::cin.ignore();
                                            }
                                        }
                                        break;
                                    }
                                case '-':{
                                    //Handles remove.
                                    int giveOrRequire = 0;
                                    std::cout << "From where would you like to remove from?" << std::endl;
                                    std::cout << "1) Give." << std::endl;
                                    std::cout << "2) Take." << std::endl;
                                    std::cout << "Enter anything else to quit." << std::endl;
                                    std::cin >> giveOrRequire;
                                    //Handles give.
                                    if(giveOrRequire == 1){
                                        for(int c = 0; c < activeChoice->gives.size(); c++){
                                            if(activeChoice->gives[c].name == tags[tagChoice-1].name){
                                                if(activeChoice->gives.size() > 1){
                                                    activeChoice->gives.erase(activeChoice->gives.begin()+c);
                                                }
                                                else{
                                                    activeChoice->gives.pop_back();
                                                }
                                            }
                                        }
                                    }
                                    //Handles require.
                                    else if(giveOrRequire == 2){
                                        for(int c = 0; c < activeChoice->required.size(); c++){
                                            if(activeChoice->required[c].name == tags[tagChoice-1].name){
                                                if(activeChoice->gives.size() > 1){
                                                    activeChoice->gives.erase(activeChoice->gives.begin()+c);
                                                }
                                                else{
                                                        activeChoice->gives.pop_back();
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            //Stops loop.
                            else if(tagChoice == -1){
                                doneMakingChoice = true;
                                validTagNumber = true;
                            }
                            //Handles edge cases.
                            else{
                                tagChoice = 0;
                            }
                        }
                        //Deletes irrelevant data once done.
                        std::cin.clear();
                        std::cin.ignore();
                    }

                }
                break;
            }
            case 2:{
                choice * newChoice = new choice();
                std::string newChoiceText;
                bool doneMakingChoice = false;
                int choiceMenuInput;
                //Sets choice name.
                std::cout << "What would you like to this new choice to say?" << std::endl;
                std::getline(std::cin,newChoiceText);
                newChoice->text = newChoiceText;
                //Handles tag selection insertion and management.
                while(!doneMakingChoice){
                    int tagChoice = 0;
                    bool validTagNumber = false;
                    std::cout << "Select the number of the tag you would like to add/remove to/from this choice." << std::endl;
                    std::cout << "Press -1 to quit." << std::endl;
                    for(int c = 0; c< tags.size(); c++){
                        std::cout << c+1 << ") " << tags[c].name << std::endl;
                    }
                    if(tags.size() == 0){
                        std::cout << "No tags available at this time." << std::endl;
                    }
                    while(!validTagNumber){
                        std::cin >> tagChoice;
                        char userCharChoice;
                        if(tagChoice > 0 && tagChoice <= tags.size()){
                            validTagNumber = true;
                            std::cout << "Would you like to add this tag or remove this tag (+/-)?" << std::endl;
                            std::cout << "Enter anything else to quit."                             << std::endl;
                            std::cin >> userCharChoice;
                            switch(userCharChoice){
                                case '+':{
                                    //Scene is added.
                                    int giveOrRequire = 0;
                                    std::cout << "Would you like it to be given upon selecting this choice? Or Required to select this choice?" << std::endl;
                                    std::cout << "1) Give." << std::endl;
                                    std::cout << "2) Take." << std::endl;
                                    std::cout << "Enter anything else to quit." << std::endl;
                                    std::cin >> giveOrRequire;
                                    //Adds to give.
                                    if(giveOrRequire == 1){
                                        newChoice->gives.push_back(tags[tagChoice-1]);
                                    }
                                    //Adds to require.
                                    else if(giveOrRequire == 2){
                                        newChoice->gives.push_back(tags[tagChoice-1]);
                                    }
                                    break;
                                }
                                case '-':{
                                    //Handles removal.
                                    int giveOrRequire = 0;
                                    std::cout << "From where would you like to remove from?" << std::endl;
                                    std::cout << "1) Give." << std::endl;
                                    std::cout << "2) Take." << std::endl;
                                    std::cout << "Enter anything else to quit." << std::endl;
                                    std::cin >> giveOrRequire;
                                    if(giveOrRequire == 1){
                                        for(int c = 0; c < newChoice->gives.size(); c++){
                                            if(newChoice->gives[c].name == tags[tagChoice-1].name){
                                                //Handles give for removal, if there is enough to do an erase, otherwise it is pop_back.
                                                if(newChoice->gives.size() > 1){
                                                    newChoice->gives.erase(newChoice->gives.begin()+c);
                                                }
                                                else{
                                                    newChoice->gives.pop_back();
                                                }
                                            }
                                        }
                                    }
                                    else if(giveOrRequire == 2){
                                        for(int c = 0; c < newChoice->required.size(); c++){
                                            if(newChoice->required[c].name == tags[tagChoice-1].name){
                                                if(newChoice->gives[c].name == tags[tagChoice-1].name){
                                                //Handles require for removal, if there is enough to do an erase, otherwise it is pop_back.
                                                if(newChoice->gives.size() > 1){
                                                    newChoice->gives.erase(newChoice->gives.begin()+c);
                                                }
                                                else{
                                                    newChoice->gives.pop_back();
                                                }
                                            }
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        else if(tagChoice == -1){
                            std::cout << "Quiting tag adding." << std::endl;
                            tagChoice = 0;
                            return scenes;
                        }
                        else{
                            std::cout << "Invalid input." << std::endl;
                        }
                        //maybe create a new function that allows the user to make a new tag on the spot or at leat a quit feature.
                        std::cin.clear();
                        std::cin.ignore();
                    }

                }
                activeScene->choices.push_back(newChoice);
                break;
            }
            case 3:{
                //Handles choice changing.
                bool userIsDone = false;
                int userChoice = 0;
                while(!userIsDone){
                    std::cout << "Which choice would you like to change?" << std::endl;
                    for(int c = 0; c < activeScene->choices.size(); c++){
                        std::cout << c+1 << ") " << activeScene->choices[c] << std::endl;
                    }
                    //Handles choice check.
                    std::cin >> userChoice;
                    std::cin.clear();
                    std::cin.ignore();
                    if(userChoice > 0 && userChoice <= activeScene->choices.size()){
                        userIsDone = true;
                        std::string newText;
                        bool nameChoosen = false;
                        while(!nameChoosen){
                            //Reassigns text choice.
                            std::cout << "What would you like it to say?" << std::endl;
                            std::getline(std::cin,newText);
                            if(newText.length() > 0){
                                activeScene->choices[userChoice-1]->text = newText;
                            }
                            std::cin.clear();
                            std::cin.ignore();
                        }
                    }
                }
                break;
            }
            case 4:{
                std::string choiceName;
                int choice;
                bool validChoice = false;
                std::cout << "Select the line number that represents the choice you would like to remove?" << std::endl;
                for(int c = 0; c < activeScene->choices.size(); c++){
                    std::cout << c+1 << ") " << activeScene->choices[c]->text << std::endl;
                }
                //Sets and handles scene removal.
                while(!validChoice){
                    std::cin >> choice;
                    if(choice > 0 && choice <= activeScene->choices.size()){
                        validChoice = true;
                    }
                    else{
                        std::cout << "Invalid choice selected. Please select a new line number for a choice." << std::endl;
                    }
                    std::cin.clear();
                    std::cin.ignore();
                }
                choiceName = activeScene->choices[choice-1]->text;
                activeScene->removeChoice(choiceName);
                break;
            }
            case 5:{
                //Reassigns title.
                std::string newTitle;
                std::cout << "What would you like to change the scene title to?" << std::endl;
                std::getline(std::cin,newTitle);
                activeScene->setTitle(newTitle,false);
                std::cout << "Title is now set to \"" << newTitle << "\"." << std::endl;
                break;
            }
            case 6:{
                //Handles text management.
                activeScene->editText();
                break;
            }
            case 7:{
                //Handles text management.
                int choiceSelection = 0;
                int sceneSelection = 0;
                choice * activeChoice;
                scene * linkedScene;
                std::cout << "Here are the choices listed under this scene. Select the number of the scene you would like to edit." << std::endl;
                for(int c = 0; c < activeScene->choices.size(); c++){
                    std::cout << c+1 << ") " << activeScene->choices[c]->text << std::endl;
                }
                std::cin >> choiceSelection;
                if(choiceSelection > 0 && choiceSelection <= activeScene->choices.size()){
                    activeChoice = activeScene->choices[choiceSelection-1];
                }
                std::cout << "Select a scene you would like to connect to this choice." << std::endl;
                for(int c = 0; c < scenes.size(); c++){
                    std::cout << c+1 << ") " << scenes[c]->getTitle() << std::endl;
                }
                std::cin >> sceneSelection;
                if(sceneSelection > 0 && sceneSelection <= scenes.size()){
                    activeChoice->linkScene = scenes[sceneSelection-1];
                }
                else{
                    std::cout << "Invalid scene selected." << std::endl;
                }
                break;
            }
            case 8:{
                //Stops the scene.
                validActionTaken = true;
                break;
            }
            std::cin.clear();
            std::cin.ignore();
        };
    }
    return scenes;
}

void sceneManager::tagsManager(){
    bool userIsDone = false;
    int userAction;
    while(!userIsDone){
        //Checks the menu.
        std::cout << "========================================================" << std::endl;
        std::cout << "|                       Tags Manager                   |" << std::endl;
        std::cout << "========================================================" << std::endl;
        std::cout << "| 1) Add a Tag.                                        |" << std::endl;
        std::cout << "| 2) Remove a Tag.                                     |" << std::endl;
        std::cout << "| 3) Quit.                                             |" << std::endl;
        std::cout << "========================================================" << std::endl;
        std::cin >> userAction;
        switch(userAction){
            case 1:{
                tag newTag;
                std::string tagName;
                int tagAmount;
                //Sets new tagName.
                std::cout << "Enter the name of the tag you would like to create." << std::endl;
                std::getline(std::cin,tagName);
                std::cin.clear();
                std::cin.ignore();
                //Enter the tag value.
                std::cout << "Enter the amount of the tag." << std::endl;
                std::cin >> tagAmount;
                std::cin.clear();
                std::cin.ignore();
                newTag.name = tagName;
                newTag.amount = tagAmount;
                tags.push_back(newTag);
                std::cout << "New tag added." << std::endl;
                break;
            }
            case 2:{
                int indexToRemove;
                std::cout << "Select a tag to remove." << std::endl;
                for(int c = 0; c < tags.size(); c++){
                    std::cout << c+1 << ") " << tags[c].name << std::endl;
                }
                std::cin >> indexToRemove;
                //Handles removal of tags.
                if(indexToRemove > 0 && indexToRemove <= tags.size()){
                    //Handles removal makses sure that erase is an option.
                    if(tags.size() > 1){
                        tags.erase(tags.begin()+indexToRemove-1);
                    }
                    else{
                        tags.pop_back();
                    }
                    std::cout << "Tag has been removed." << std::endl; 
                }
                else{
                    std::cout << "Removal was unsuccessful, invalid line found." << std::endl;
                }
                break;
            }
            case 3:{
                userIsDone = true;
                break;
            }
            std::cin.clear();
            std::cin.ignore();
        };
    }
}

void sceneManager::setScenes(std::vector<scene> scns){
    scenes.clear();
    for(int c = 0; c < scns.size(); c++){
        scenes.push_back(&scns[c]);
    }
    return;
}