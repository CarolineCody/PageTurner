#include <vector>
#include "scene.hpp"
#include "./dataStructs/choice.hpp"
#include "./dataStructs/tag.hpp"

class sceneManager{
    public:
        sceneManager();                    //Default constructor for the scene.
        void sceneSelection();             //Sets the active scene to be manipualted by the user and then allows user to manage that scene and its tags.
        void tagsManager();                //Manages and handles the creation and removal of tags within this story.
    private:
        std::vector<scene> scenes;         //Manages all the scenes owned by this story.
        std::vector<tag> tags;             //Stores a reference to all tags within the scene for reference.
};

//Tags are required because at this level they are managed but there is no definite data structures for them.