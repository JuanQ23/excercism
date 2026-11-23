#pragma once

#include <string>
#include <memory>
#include <iostream>
namespace troy {

    // An artifact is exclusively owned by one human at a time.
    struct artifact {
        artifact(std::string name) : name(name) {}
        std::string name;
    };

    // A power can be shared by its caster and every human it influences.
    struct power {
        power(std::string effect) : effect(effect) {}
        std::string effect;
    };

    // Tracks a human's artifact, personal power, and current influence.
    class human {
        public:
            std::unique_ptr<artifact> possession = nullptr;
            std::shared_ptr<power> own_power = nullptr;
            std::shared_ptr<power> influenced_by = nullptr;
    };

    // Creates a new artifact and gives its exclusive ownership to person.
    void give_new_artifact(human& person, std::string artifact_name);

    // Exchanges the exclusive ownership of two artifacts.
    void exchange_artifacts(std::unique_ptr<artifact>& artifact_one, 
                            std::unique_ptr<artifact>& artifact_two);

    // Creates a power and assigns it as the person's own power.
    void manifest_power(human& person, std::string power);

    // Makes target share the caster's power as an influence.
    void use_power(human& caster, human& target);

    // Returns the number of shared owners of the person's power, or zero.
    int power_intensity(human& person);
}
