#include <vector>
#include <string>
#include "../dataStructs/choice.hpp"

//Handles the scene menu that allows the user to manipulate and change a scene.
#ifndef SCN_HPP
#define SCN_HPP
class scene{
    private:
        std::string title;                  //The title and indetnifying name associated with this scene.
        std::vector<std::string> text;      //The actual text that is part of the scene and constitutes what the player is reacting to.
    public:
        scene();                           //Handles scene construction including building the title, and setting the text.
        void editScene();                  //Handles scene construction with set features such as name and relevant information.
        void addChoice(choice * newChoice);//Handles new choice creation and adding it into the choices vector.
        void removeChoice(std::string choiceName);//Handles removing a given choice within name.
        choice * getChoice(std::string choiceName);//Returns a choice for manipulation and any changes necessary.
        void printChoices();               //Prints out the choices of this scene to anyone who needs it.
        std::string getTitle();            //Returns the title of the scene.
        void setTitle(std::string newTitle);//Changes the text to this new value.
        void editText();                   //Really messy and hazerdous menu to both my own and everyones health. Manages adding new text
                                           //Removing old text, and even insert text dead in the middle of other text.
        void printText();                  //Prints all text in file one line at a time.
        std::vector<choice *> choices;     //Contains the list of choices that the player can select.
};
#endif