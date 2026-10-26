namespace targets {
    class Alien{
        //A alien's coordinates and health points.
        //with functions to  decrement health and
        //check for collision
        public:
            int x_coordinate;
            int y_coordinate;
            Alien(int x, int y){
                x_coordinate = x;
                y_coordinate = y;
                health = 3;
            }
        int get_health(){
            //returns the current health of the alien.
            return health;
        }
        bool hit(){
            //reduces hit points by 1.
            if (health >0) health--;
            return true;
        }
        bool is_alive(){
            //if health is 0, then false will return
            //if health is anything other than 0 then true
            if (health>0) return true;
            else return false;
        }
        bool teleport(int x, int y){
            //A function that updates a players coordinates.
            x_coordinate = x;
            y_coordinate = y;
            return true;
        }
        bool collision_detection(Alien other_alien){
            //checks if the current alien shares the same
            //coordinates as the second alien. 
            if (x_coordinate == other_alien.x_coordinate && 
                y_coordinate == other_alien.y_coordinate){
                    return true;
                }
            else return false;
        }
        private:
            int health;
    };
}  // namespace targets
