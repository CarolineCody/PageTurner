#include "../menu/storyMenu.hpp"
#include "../menu/playMenu.hpp"
#include "scene.hpp"

//Handles the test play section. This allows the user to quickly test out the scene without having to hop through a bunch of menus.
#ifndef QT_HPP
#define QT_HPP
class quickTest{
    private:
        storyMenu * story;                          //Refers to the storyMenu that this menu is connected to.
        playMenu * play;                            //Only there to track owned tags.
        scene * activeScene;                        //The scene to start the story from.
    public:
        quickTest(storyMenu * stry, playMenu * ply);//Constructs an object of this class that sets the menu that this menu can back connect to.
        void run(scene * activeScene);              //Runs the scene just created.
        void quit();                                //Ends the program by first backPedaling and quiting from there to save all prior work.
        bool setActive;                             //Declares this menu as the active area that the user is interacting with.
};
#endif