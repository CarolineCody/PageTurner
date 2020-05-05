#include "titleMenu.hpp"
#include "storyMenu.hpp"

//Handles the test play section. This allows the user to quickly test out the scene without having to hop through a bunch of menus.
#ifndef QT_HPP
#define QT_HPP
class quickTest{
    private:
        titleMenu* title;                           //Refers to the titleMenu that this menu is connected to.   
        storyMenu * story;                          //Refers to the storyMenu that this menu is connected to.
    public:
        quickTest(storyMenu * stry);                //Constructs an object of this class that sets the menu that this menu can back connect to.
        void backPedal();                           //Sets the current active menu to the menu that came before this menu.
        void run();                                 //Runs the scene just created.
        void printMenu();                           //Prints the menu of this test section after the function is done running.
        void quit();                                //Ends the program by first backPedaling and quiting from there to save all prior work.
        bool setActive;                             //Declares this menu as the active area that the user is interacting with.
};
#endif