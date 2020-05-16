#include <vector>
#include "../sceneManagement/scene.hpp"

//Handles the old story menu that asks teh user which story they want to edit.
#ifndef OSM_HPP
#define OSM_HPP
class makeMenu;
class titleMenu;
class storyMenu{
    private:
    makeMenu* make;                               //References to the makeMenu that is connected to this menu.
    titleMenu* title;                               //References to the titleMenu that is connected to this menu.
    std::vector<scene> entries;                   //Stores all scenes within the new story written.
    public:
    storyMenu();                                  //Default constructor that finds all relevant user information.
    void setParent(makeMenu* mm);                 //Sets the parent menu of the new story menu.
    void backPedal();                             //Sets the active menu to the makeMenu.
    void setRoot(titleMenu* titleM);              //Sets the reroute menu to the titleMenu.
    void returnToMenu();                          //Sets the active menu to the titleMenu.
    void printMenu();                             //Prints out the menu and its prompts for this menu.
    void quit();                                  //Just quits the program AFTER SAVIING ALL THE WORK AS A OLDSTORY MENU.
    bool setActive;                               //Declares this menu as the active area that the user is interacting with.
};
#endif