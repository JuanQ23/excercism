#include "power_of_troy.h"

namespace troy {
    // make_unique creates the artifact under exclusive ownership.
    void give_new_artifact(human& person, std::string artifact_name) {
        person.possession = std::make_unique<artifact>(artifact_name);
    }

    // Swapping unique_ptrs transfers the artifacts without copying them.
    void exchange_artifacts(std::unique_ptr<artifact>& artifact_one,
                            std::unique_ptr<artifact>& artifact_two) {
        artifact_one.swap(artifact_two);
    }

    // Creates one shared power object and assigns it to the human.
    void manifest_power(human& person, std::string power_name){
        power effect = power(power_name);
        person.own_power = std::make_shared<power>(effect);
    }

    // The target's shared_ptr keeps the caster's power alive and tracks influence.
    void use_power(human& caster, human& target){
        target.influenced_by = caster.own_power;
    }

    // shared_ptr::use_count includes the caster and all influenced humans.
    int power_intensity(human& caster){
        return caster.own_power.use_count();
    }
}  // namespace troy
