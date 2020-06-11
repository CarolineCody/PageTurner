#include "storyMenu.hpp"
//Title menu header that appears at the start of the program call.
#ifndef TM_HPP
#define TM_HPP
class playMenu;
class titleMenu{
    private:
        storyMenu* story;                         //Refers to the storyMenu that the titleMenu can possibly guide to.
        playMenu* play;                           //Refers to the playMenu that the titleMenu can possibly guide to.
    public:
        titleMenu(storyMenu* sty, playMenu* pm);  //Handles class construction where the pointers make and play are set upon construction.
        void printMenu();                         //Prints out the menu for the title menu and handles action/responses to what the user is doing.
        void quit();                              //Quits the entire program immediatley.
        bool setActive;                           //Declares this menu as the active area that the user is interacting with.
};
#endif