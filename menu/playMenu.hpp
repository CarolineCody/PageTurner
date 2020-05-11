#include <vector>
#include "titleMenu.hpp"
#include "../scene.hpp"

//Handles the play menu where the user selects what story they want to read at the start or midway through.
#ifndef PM_HPP
#define PM_HPP
class playMenu{
    private:
        titleMenu* title;                           //References the titleMenu that the this menu connects to.
        std::vector<scene> stories;                 //Stores a reference to all the starting scene of every story.
    public:
    playMenu();                                     //Default constructor that also handles and assigns what node to travel back to.
    void setParent(titleMenu * titleM);              //Sets the parent of this menu.
    void printMenu();                               //Handles and manages all inputs and outputs of the class that is being taken in.
    void backPedal();                               //Access the menu that came before this menu and sets that menu to the active menu.
    void quit();                                    //Closes the program and saves users progress.
    bool setActive;                                 //Declares this menu as the active area that the user is interacting with.
};
#endif