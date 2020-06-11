#include <iostream>
#include "./menu/playMenu.hpp"
#include "./menu/titleMenu.hpp"
#include "./menu/storyMenu.hpp"
#include "./sceneManagement/scene.hpp"
#include "./sceneManagement/quickTest.hpp"

int main(){
    //Constructs all the menus.
    storyMenu * story = new storyMenu();
    playMenu * play = new playMenu();
    titleMenu * title = new titleMenu(story,play);
    quickTest * qT = new quickTest(story, play);
    story->setParent(title);
    story->setQT(qT);
    title->setActive = true;
    //direct scene selection.
    //scene * bip = new scene();
    //This generates a switch pattern between all the different menus, allowing them all to loop without every having to really share
    //The objects between them. This is pretty clever but I am sure there are smarter ways of doing this. This is just how my coding
    //monkey brain went about this.
    while( title->setActive || story->setActive || play->setActive){
        if(title->setActive){
            title->printMenu();
        }
        else if(story->setActive){
            story->printMenu();
        }
        else if(play->setActive){
            play->printMenu();
        }
        else{
            std::cout << "Error! Invalid computation has happened. The coding gremlins are at it again!" << std::endl;
        }
    }
    std::cout << "Till next time!" << std::endl;
    return 0;
}