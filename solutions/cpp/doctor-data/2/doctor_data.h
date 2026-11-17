#include <string>

namespace star_map{
    // Systems that a vessel can travel to.
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}
namespace heaven {
    // Represents a vessel, including its identity and buster state.
    class Vessel{
        private:
            // Vessel details used by the member functions.
            std::string name;
            int number;
            star_map::System system;
        public:
            // Create a vessel with the default system or an explicitly chosen system.
            Vessel(std::string name, int num);
            Vessel(std::string name, int num, star_map::System system);

            // Create a copy of this vessel with a new name.
            Vessel replicate(std::string name);

            // Load one buster, or fire it if one is available.
            void make_buster();
            bool shoot_buster();

            // Accessors for the vessel's identifying information.
            int get_number();
            std::string get_name();

            // Public state used by the exercise tests.
            int generation = 1;
            bool busters = 0;
            star_map::System get_current_system();
            star_map::System current_system = star_map::System::Sol;
    };

    // Compare two vessels by number and compare their current systems.
    std::string get_older_bob(Vessel bob, Vessel other);
    bool in_the_same_system(Vessel one, Vessel other);

}
