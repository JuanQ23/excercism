#include "doctor_data.h"

// Initialize a vessel in its default system.
heaven::Vessel::Vessel(std::string name, int num){
    this->name = name;
    this->number = num;
}

// Initialize a vessel in the system supplied by the caller.
heaven::Vessel::Vessel(std::string name, int num, star_map::System system){
    this->name = name;
    this->number = num;
    this->system = system;
}

// Replication preserves the vessel's number and system, and advances its generation.
heaven::Vessel heaven::Vessel::replicate(std::string name){
    heaven::Vessel new_vessel(name, this->number, this->system);
    new_vessel.generation = this->generation + 1;
    return new_vessel;
}

// Mark that this vessel has one buster available.
void heaven::Vessel::make_buster(){
    this->busters = 1;
}

// Fire a buster if available; return whether firing succeeded.
bool heaven::Vessel::shoot_buster(){
    if(this->busters > 0){
        this->busters = 0;
        return true;
    }
    return false;
}

// Return the vessel's identifying number.
int heaven::Vessel::get_number(){
    return this->number;
}

// Return the vessel's name.
std::string heaven::Vessel::get_name(){
    return this->name;
}

// Return the name belonging to the vessel with the lower number.
std::string heaven::get_older_bob(Vessel bob, Vessel other){
    if(bob.get_number() < other.get_number()){
        return bob.get_name();
    }
    return other.get_name();
}

// Return the system stored for this vessel.
star_map::System heaven::Vessel::get_current_system(){
    return this->system;
}

// Check whether both vessels report the same current system.
bool heaven::in_the_same_system(Vessel one, Vessel other){
    return one.get_current_system() == other.get_current_system();
}
