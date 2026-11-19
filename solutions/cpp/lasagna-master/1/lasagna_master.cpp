#include "lasagna_master.h"

namespace lasagna_master {

    int preparationTime(std::vector<std::string> layers, int prep_time){
        return layers.size() * prep_time;
    }

    amount quantities(std::vector<std::string> layers){
        
        amount needed{0, 0.0};
        
        for(const std::string &layer: layers){
            if(layer == "noodles") needed.noodles += 50;
            else if(layer == "sauce") needed.sauce += 0.2;
        }
        return needed;
    }
    void addSecretIngredient(std::vector<std::string> &mylist, const std::vector<std::string> &friend_list){
        std::string secret_ingridient = friend_list.back();    //grabbing the last element which is the secret 
        mylist.back() = secret_ingridient;                      //setting the last element

        //a nice little note. back() returns refference to the last element.
        // which is an alias to the last string in the vector
        // so that means I can access and update the last element in this way.
        }
    void addSecretIngredient(std::vector<std::string> &mylist, std::string secret_ingredient){
        mylist.back() = secret_ingredient;                      //setting the last element
    }

        std::vector<double> scaleRecipe(std::vector<double> amount_needed, int portions){

            for(double &element: amount_needed){
                element = element * (portions / 2.0); //divide  by two to get it into a single serving and then multiply by the number of portions  
            }
        return amount_needed;
        }
}  // namespace lasagna_master


