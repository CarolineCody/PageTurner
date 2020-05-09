#include <string>
#include <vector>
#include "tag.hpp"

#ifndef CH_HPP
#define CH_HPP
struct choice{
    std::string text;                                   //The text that is printed whenever a choice is presented as part of a scene.
    std::vector<tag> required;                         //List of template vectors that is required for this choice to become visible as part of a scene.
    std::vector<tag> gives;                            //List of all the tags that will be granted to the player upon selecting this choice.
    std::string scene;                                  //The name of the scene this choice will link to when the player makes a choice.
};
#endif

//Creation notes: May want to rework this to have mutliple scenes as an option
//                As well as some function or a random chance of a certain things happen.