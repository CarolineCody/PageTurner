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
        //Prints the scene title.
        writer << scenes[c].getTitle();
        //Gets the text of the scene
        for(int r = 0; r < scenes[c].text.size(); r++){
            writer << " " << scenes[c].text[r] << std::endl;
        }
        for(int r = 0; r < scenes[c].choices.size(); r++){
            //Prints choice text.
            writer << "  " << scenes[c].choices[r]->text << std::endl; //Two spaces.
            //Prints required tags for choice.
            for(int x = 0; x < scenes[c].choices[r]->required.size(); x++){
                writer << "   " << scenes[c].choices[r]->required[x].name << std::endl; //Three spaces.
                writer << "    " << scenes[c].choices[r]->required[x].amount << std::endl; //Four spaces.
            }
            //Prints the give tags for the chioce.
            for(int x = 0; x < scenes[c].choices[r]->gives.size(); x++){
                writer << "     " << scenes[c].choices[r]->gives[x].name << std::endl; //Five spaces.
                writer << "      " << scenes[c].choices[r]->gives[x].amount << std::endl; //Six spaces.
            }
            //Prints out the title of the scene that this choice is linked to.
            writer << "       " << scenes[c].choices[r]->linkScene->getTitle() << std::endl; //Seven spaces;
        }
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
    int lineCount = 0;
    reader.open("saveFiles/text.txt");
    //Checks to see if file is open.
    if(reader.is_open()){
        while(getline(reader,line)){
            lineCount++;
            //Need some method to check line depth and what have you.
            //Found title of scene.
            if(line.length() > 0 && line[0] != ' '){
                //Makes a new scene;
                scene temp;
                temp.setTitle(line);
                //Gets scene title.
                while(getline(reader,line) && line.length() > 1 && line[0] == ' ' && line[1] != ' '){
                    lineCount++;
                    temp.text.push_back(line.substr(1));
                }
                //Creates a choice for the scene (both gives and requires) and then adds them to the scene.
                while(getline(reader,line) && line.length() > 2 && line[1] == ' ' && line[2] != ' '){
                    lineCount++;
                    choice * tempi = new choice();
                    tempi->text = line.substr(2);
                    //Handles giving the new choice its tags. Both amount and name for requires.
                    if(getline(reader,line) && line.length() > 3 && line[2] == ' ' && line[3] != ' '){
                        lineCount++;
                        tag tempo;
                        tempo.name = line.substr(3);
                        if(getline(reader,line) && line.length() > 4 && line[3] == ' ' && line[4] != ' '){
                            lineCount++;
                            tempo.amount = stoi(line.substr(4));
                        }
                        else{
                            //If no amount tag is found the program will end.
                            lineCount++;
                            std::cout << "Invalid require tag amount found. Please fix file before continuing." << std::endl;
                            std::cout << "Error found on line " << lineCount << " of save file." << std::endl;
                            reader.close();
                        }
                        tempi->required.push_back(tempo);
                    }
                    else{
                        //If no name is found the program will end.
                        lineCount++;
                        std::cout << "Invalid give tag name found. Please fix file before continuing." << std::endl;
                        std::cout << "Error found on line " << lineCount << " of save file." << std::endl;
                        reader.close();
                    }
                    //Handles the give tags.
                    if(getline(reader,line) && line.length() > 5 && line[4] == ' ' && line[5] != ' '){
                        lineCount++;
                        tag tempo;
                        tempo.name = line.substr(3);
                        if(getline(reader,line) && line.length() > 6 && line[5] == ' ' && line[6] != ' '){
                            lineCount++;
                            tempo.amount = stoi(line.substr(4));
                        }
                        else{
                            lineCount++;
                            std::cout << "Invalid give tag amount found. Please fix file before continuing." << std::endl;
                            std::cout << "Error found on line " << lineCount << " of save file." << std::endl;
                            reader.close();
                        }
                        tempi->gives.push_back(tempo);
                    }
                    else{
                        lineCount++;
                        std::cout << "Invalid require tag name found. Please fix file before continuing." << std::endl;
                        std::cout << "Error found on line " << lineCount << " of save file." << std::endl;
                        reader.close();
                    }
                    if(getline(reader,line) && line.length() > 7 && line[6] == ' ' && line[7] != ' '){
                        lineCount++;
                        //Need to impliment the scene content!
                        /*
                        
                        
                                      Maybe RetroActivley Add?
                                      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                        
                        
                        
                        */
                    }
                    else{
                        lineCount++;
                        std::cout << "Invalid require link scene found. Please fix file before continuing." << std::endl;
                        std::cout << "Error found on line " << lineCount << " of save file." << std::endl;
                        reader.close();
                    }
                    temp.choices.push_back(tempi);
                }
                //Finally adds the completed scene back into the library of scenes.
                scenes.push_back(temp);
            }
            //Title not found, need to end the program and kill it with fire!
            else{
                lineCount++;
                std::cout << "File has been corrupted. Scene was not found at the top of the save file." << std::endl;
                std::cout << "Error found on line " << lineCount << " of save file." << std::endl;
                reader.close();
            }
        }
    }
    reader.close();
    //Stores it under scenes.
    return scenes;
}

