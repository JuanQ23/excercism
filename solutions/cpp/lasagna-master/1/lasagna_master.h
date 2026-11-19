#pragma once

#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};
    // return the estimate for the total preparation time based on the number of layers as an `int`.
    // If the average preparation time is not passed then the default value of `2` should be used.
    int preparationTime(std::vector<std::string> layers, int prep_time = 2);
    amount quantities(std::vector<std::string> layers);
    void addSecretIngredient(std::vector<std::string> &mylist, const std::vector<std::string> &friend_list);
    void addSecretIngredient(std::vector<std::string> &mylist, std::string secret_ingredient);
    std::vector<double> scaleRecipe(std::vector<double> amounts_needed, int portions);
}  // namespace lasagna_master
