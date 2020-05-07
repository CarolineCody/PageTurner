#include <vector>
#include <string>
#include "./dataStructs/choice.hpp"

//Handles the scene menu that allows the user to manipulate and change a scene.
#ifndef SCN_HPP
#define SCN_HPP
class scene{
    private:
        std::string title;                  //The title and indetnifying name associated with this scene.
        std::vector<std::string> text;      //The actual text that is part of the scene and constitutes what the player is reacting to.
        std::vector<choice *> choices;      //Contains the list of choices that the player can select.
    public:
        scene();                           //Handles scene construction including building the title, and setting the text.
        void addChoice(choice * newChoice);//Handles new choice creation and adding it into the choices vector.
        void removeChoice(std::string choiceName);//Handles removing a given choice within name.
        void setTitle(std::string newTitle);//Changes the text to this new value.
        void editText();                   //Really messy and hazerdous menu to both my own and everyones health. Manages adding new text
                                           //Removing old text, and even insert text dead in the middle of other text.
};
#endif