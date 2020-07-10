#include <vector>
#include "../sceneManagement/scene.hpp"

#ifndef save_HPP
#define save_HPP
class saveManager{
    private:
        std::vector<scene*> scenes;                      //Stores all the relevant scenes that are to be stored.
    public:
        saveManager();
        void setScenes(std::vector<scene*> scene);       //Assigns all the relevant scenes to the vector scenes.
        void save();                                    //Saves information into an external file.
        std::vector<scene*> transferSaves();             //Transfers data relevant to the scenes to anything that requests it.
};
#endif