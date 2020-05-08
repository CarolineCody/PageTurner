#include <iostream>
#include "./menu/makeMenu.hpp"
#include "./menu/playMenu.hpp"
#include "./menu/titleMenu.hpp"
#include "./menu/storyMenu.hpp"
#include "scene.hpp"

int main(){
    //Constructs all the menus.
    storyMenu * story = new storyMenu();
    makeMenu * make = new makeMenu(story);
    story->setParent(make);
    playMenu * play = new playMenu();
    titleMenu * title = new titleMenu(make,play);
    story->setRoot(title);
    make->setParent(title);
    play->setParent(title);
    title->setActive = true;
    scene * bip = new scene();
    //This generates a switch pattern between all the different menus, allowing them all to loop without every having to really share
    //The objects between them. This is pretty clever but I am sure there are smarter ways of doing this. This is just how my coding
    //monkey brain went about this.
    while( title->setActive || story->setActive || make->setActive || play->setActive){
        if(title->setActive){
            title->printMenu();
        }
        else if(story->setActive){
            story->printMenu();
        }
        else if(make->setActive){
            make->printMenu();
        }
        else if(play->setActive){
            play->printMenu();
        }
        else{
            std::cout << "Error! Invalid comupnace has happened. The coding gremlins are at it again!" << std::endl;
        }
    }
    std::cout << "Till next time!" << std::endl;
    return 0;
}