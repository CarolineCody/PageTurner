#include <vector>
#include <string>
#include <iostream>
#include "scene.hpp"
#include "./dataStructs/choice.hpp"

scene::scene(){
    std::string userInput;
    //Sets the name and text within a scene. Choices will have to be implemented seperately.
    //Half for ease of diverse implementation and half because I am to tired to do more now.
    std::cout << "New scene created. What would you like to call this scene?" << std::endl;
    std::getline(std::cin, userInput);
    std::cin.clear();
    setTitle(userInput);
    editText();
}

void scene::addChoice(choice * newChoice){
    //Iterates through the list of choices checking to see if the requested choice exists or not.
    //Choice similarity is determined by similar dialogue. If duplicate dialogue is found, the system
    //should ask the user witch version they want to keep. The old one or the new one.
    for(int c = 0; c < choices.size(); c++){
        //If an entry of duplicate text is found then the user isprompted by a selection prompt to do away with one of the two copies.
        if(choices[c]->text == newChoice->text){
            //Keeps track for the for loop if a valid choice was selected.
            bool userChoiceMade = false;
            while(!userChoiceMade){
                //Keeps track of user selection.
                char userChoice;
                std::cout << "Duplicate entry has been found." <<std::endl;
                std::cout <<"Would you like to replace the old copy with this one? (y/n)" << std::endl;
                std::cin >> userChoice;
                switch(userChoice){
                    case 'y':{
                        choices.erase(choices.begin()+c);
                        userChoiceMade = true;
                        break;
                    }
                    case 'n':{
                        std::cout << "Both copies will be saved." << std::endl;
                        userChoiceMade = true;
                        break;
                    }
                    default:{
                        std::cin.clear();
                        std::cin.ignore();
                        break;
                    }
                };
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
    choices.push_back(newChoice);
    return;
}

void scene::removeChoice(std::string choiceName){
    //Iterates through the list of choices checking to see if the requested choice exists or not.
    //Choice similarity is determined by similar dialogue. If duplicate dialogue is found, the system
    //should ask the user witch version they want to keep. The old one or the new one.
    for(int c = 0; c < choices.size(); c++){
        //If an entry of duplicate text is found then the user isprompted by a selection prompt to do away with one of the two copies.
        if(choices[c]->text == choiceName){
            //Keeps track for the for loop if a valid choice was selected.
            bool userChoiceMade = false;
            while(!userChoiceMade){
                //Keeps track of user selection.
                char userChoice;
                std::cout << "Duplicate entry has been found." <<std::endl;
                std::cout <<"Would you like to replace the old copy with this one? (y/n)" << std::endl;
                std::cin >> userChoice;
                switch(userChoice){
                    case 'y':{
                        choices.erase(choices.begin()+c);
                        userChoiceMade = true;
                        break;
                    }
                    case 'n':{
                        std::cout << "Both copies will be saved." << std::endl;
                        userChoiceMade = true;
                        break;
                    }
                    default:{
                        std::cin.clear();
                        std::cin.ignore();
                        break;
                    }
                };
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
    return;
}

choice * scene::getChoice(std::string choiceName){
    choice * foundChoice = NULL;
    for(int c = 0; c < choices.size(); c++){
        if(choiceName == choices[c]->text){
            foundChoice = choices[c];
        }
    }
    return foundChoice;
}

std::string scene::getTitle(){
    return title;
}

void scene::setTitle(std::string newTitle){
    title = newTitle;
    std::cout << "Title has been set to \"" << newTitle << "\"." << std::endl;
    return;
}

void scene::editText(){
    //Keeps track of if the user is done with the text editor window and if they can leave.
    bool userIsDone = false;
    while(!userIsDone){
        //Keeps track of what line the user has selected to change.
        int userLineSelection = 0;
        //Keeps track of what the user wants to do with that line.
        int userAction = 0;
        std::cout << "========================================================" << std::endl;
        std::cout << "|    Text editor for Scene: \"" << title << "\"" << std::endl;
        std::cout << "========================================================" << std::endl;
        //Prints out all the text into the terminal number from lines (0,n-1).
        //Formated: "n) <text at index>".
        for(int c = 0; c < text.size(); c++){
            std::cout << c << ") " << text[c] << std::endl;
        }
        std::cout << "========================================================" << std::endl;
        std::cout << "| Select a line you would like to manipulate.          |" << std::endl;
        std::cout << "| Or enter -1 to quit.                                 |" << std::endl;
        std::cout << "| Line #: ";
        std::cin >> userLineSelection;
        std::cin.clear();
        std::cin.ignore();
        std::cout << std::endl;
        //Checks to see if the user wanted to quit wanted to actually edit a line, or just quit.
        if(userLineSelection == -1){
            userIsDone = true;
        }
        else if((userLineSelection >= 0 && userLineSelection < text.size()) || (text.size() == 0)){
            //Keeps track of if the user is done editing lines or not.
            bool userDoneEditing = false;
            while(!userDoneEditing){
                userAction = 0;
                std::cout << "========================================================" << std::endl;
                std::cout << "| What would you like to do with this line?            |" << std::endl;
                std::cout << "| 1) Add a new line.                                   |" << std::endl;
                std::cout << "| 2) Delete this line.                                 |" << std::endl;
                std::cout << "| 3) Change this line.                                 |" << std::endl;
                std::cout << "| 4) Quit.                                             |" << std::endl;
                std::cout << "========================================================" << std::endl;
                std::cin >> userAction;
                std::cin.clear();
                std::cin.ignore();
                switch(userAction){
                    case 1:{
                        //Records the new line that the user wants to add.
                        std::string newLine;
                        std::cout << "Write in what you would like to add." << std::endl;
                        std::getline(std::cin,newLine);
                        if(text.size() == 0){
                            text.push_back(newLine);
                        }
                        else{
                            text.insert(text.begin()+userLineSelection,newLine);
                        }
                        break;
                    }
                    case 2:{
                        //Remove this line.
                        if(text.size() > 0){
                            text.erase(text.begin()+userLineSelection);
                        }
                        else{
                            std::cout << "Unable to delete from text with length of zero." << std::endl;
                        }
                        break;
                    }
                    case 3:{
                        //Replaces a line.
                        if(text.size() > 0){
                            text.erase(text.begin()+userLineSelection);
                            std::string newLine;
                            std::cout << "Write in what you would like to replace this line." << std::endl;
                            std::getline(std::cin,newLine);
                            if(text.size() == 0){
                                text.push_back(newLine);
                            }
                            else{
                                text.insert(text.begin()+userLineSelection,newLine);
                            }
                        }
                        else{
                            std::cout << "Cannot replace a line that does not exist." << std::endl;
                        }
                        break;
                    }
                    case 4:{
                        userDoneEditing = true;
                        break;
                    }
                    default:{
                        break;
                    }
                    std::cin.clear();
                    std::cin.ignore();
                };
            }
        }
        else{
            std::cin.clear();
            std::cin.ignore();
        }
    }
    std::cout << "Edits to scene \"" << title << "\" are now complete." << std::endl; 
    return;
}

void scene::printText(){
    for(int c = 0; c < text.size(); c++){
        std::cout << text[c] << std::endl;
    }
    return;
}