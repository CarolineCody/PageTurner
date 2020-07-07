#include <vector>
#include <iostream>
#include <fstream>
#include "saveManager.hpp"
#include "../sceneManagement/scene.hpp"
#include "../dataStructs/choice.hpp"
#include "../dataStructs/tag.hpp"

saveManager::saveManager(){
    //Does nothing for now.
}

void saveManager::setScenes(std::vector<scene> scene){
    scenes = scene;
    return;
}

void saveManager::save(){
    //Deletes old content.
    std::ofstream ofs;
    ofs.open("saveFiles/test.txt", std::ofstream::out | std::ofstream::trunc);
    if(!ofs.is_open()){
        std::cout << "Failed to open file." << std::endl;
    }
    ofs.close();
    //Reads through file and saves new content.
    //ends.
    std::ofstream writer;
    //Opens the provided file.
    writer.open("saveFiles/test.txt");
    //Iterates through all provided scenes and prints their data into a file.
    //Needs to recieve every scene!
    for(int c = 0; c < scenes.size(); c++){
        //Do scene save schema in here.
    }
    //Always close your file once done writing to it!
    writer.close();

    //No method of resolving save data for player as of yet...
    return;
}

std::vector<scene> saveManager::transferSaves(){
    //Opens file.
    //Reads content.
    std::ifstream reader;
    std::string line;
    reader.open("saveFiles/text.txt");
    //Checks to see if file is open.
    if(reader.is_open()){
        while(getline(reader,line)){
            //Need some method to check line depth and what have you.
            //Process line content here.
        }
    }
    reader.close();
    //Stores it under scenes.
    return scenes;
}

