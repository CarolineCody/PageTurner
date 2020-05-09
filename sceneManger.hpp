#include <vector>
#include "scene.hpp"
#include "./dataStructs/choice.hpp"
#include "./dataStructs/tag.hpp"

class sceneManager{
    public:
        sceneManager();                    //Default constructor for the scene.
        void sceneSelection();             //Sets the active scene to be manipualted by the user.
        void tagsManager();                //Manages and handels teh creation and removal of tags within this story.
        void sceneTagMaanger();            //Handles adding/removing/changing tags within a scene.
    private:
        std::vector<scene> scenes;         //Manages all the scenes owned by this story.
};

//Tags are required because at this level they are managed but there is no definite data structures for them.