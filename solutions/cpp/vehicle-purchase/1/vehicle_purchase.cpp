#include "vehicle_purchase.h"

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    // TODO: Return true if you need a license for that kind of vehicle.
    return kind == "car" || kind == "truck";
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    // TODO: Return the final decision in a sentence.

    if (option1 < option2){
        return option1 + " is clearly the better choice.";
    }
    else{
        return option2 + " is clearly the better choice.";
    }
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    // TODO: Return the age-corrected resell price.
    double vehicle_price{0.0};
    if (age < 3){
        vehicle_price = .80 * original_price;
    }
    else if(age>=10){
        vehicle_price = .5 * original_price;
    }
    else{
        // else if the vehicle price is 3 - 10.
        // it's cleaner to have this statement above line 33
        // because it removes a two condition boolean operation.
        // but maybe slightly more efficient like this depending on
        // how many vehicles are between 3-10? 
        vehicle_price = .7 * original_price;
    }
    return vehicle_price;
}

}  // namespace vehicle_purchase
