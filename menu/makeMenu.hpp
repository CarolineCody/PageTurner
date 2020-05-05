#include "storyMenu.hpp"
#include "titleMenu.hpp"

//Make Menu that prompts for either making a new story or editing a prexisting one.
#ifndef MM_HPP
#define MM_HPP
class makeMenu{
    private:
        storyMenu* story;                          //Refers to the newStoryNode that makeMenu can possible guide to.
        titleMenu* title;                          //Refers to the titleMenu that makeMenu can back track to.
    public:
        makeMenu(storyMenu* stry);                 //Constructs the class with all of its children menus.
        void setParent(titleMenu* titleM);         //Assigns the parent menu for ease of backtraveling.
        void backPedal();                          //Takes the user back a menu.
        void printMenu();                          //Prints out its menu and redirects based on user intput.
        void quit();                               //Just ends the whole program.
        bool setActive;                            //Declares this menu as the active area that the user is interacting with.
};
#endif