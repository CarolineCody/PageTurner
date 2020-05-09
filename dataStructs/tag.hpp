#include <string>

#ifndef TG_HPP
#define TG_HPP
struct tag{
    std::string name;                   //Keeps track of the name of this tag for user convenience and identification.
    int amount;                         //Keeps track of the quantity of this tag that the user has or the number of these tags that 
                                        //are required for various actions.
};
#endif