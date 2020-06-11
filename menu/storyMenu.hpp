#include <vector>
#include "../sceneManagement/scene.hpp"

//Handles the old story menu that asks teh user which story they want to edit.
#ifndef OSM_HPP
#define OSM_HPP
class titleMenu;
class quickTest;
class storyMenu{
    private:
    titleMenu* title;                             //References to the titleMenu that is connected to this menu.
    quickTest* qT;                                //References to the quick play tool.
    scene * activeScene;                          //Stores the first scene of a story.
    std::vector<scene*> titleScenes;              //Stores all the starting scenes from every story on record.
    public:
    storyMenu();                                  //Default constructor that finds all relevant user information.
    void setParent(titleMenu* mm);                //Sets the parent menu of the new story menu.
    void setScene(scene * entry);                 //Sets the scene that the quickTest will interact with.
    void setQT(quickTest * qt);                   //Sets the quickTest tool that the user can access.
    void backPedal();                             //Sets the active menu to the makeMenu.
    void returnToMenu();                          //Sets the active menu to the titleMenu.
    void printMenu();                             //Prints out the menu and its prompts for this menu.
    void quit();                                  //Just quits the program AFTER SAVIING ALL THE WORK AS A OLDSTORY MENU.
    bool setActive;                               //Declares this menu as the active area that the user is interacting with.
};
#endif