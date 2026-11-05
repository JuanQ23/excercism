namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus{troll, guest, user, mod};
    
// TODO: Task 1 - Define an `Action` enumeration to represent the three
enum class Action{read, write, remove};
// permission types: `read`, `write`, and `remove`.

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster_status, 
                  AccountStatus viewer_status){
    switch(poster_status){
        case AccountStatus::troll:
            if (viewer_status == AccountStatus::troll){
                return true;
            }
            else return false;
        break;
        default:
            return true;
            break;
    }
}

    
// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus status){

    //trolls and users can read and write
    //guests can read
    //mods can do it all
    switch (status){
        case AccountStatus::troll:
        case AccountStatus::user:
            if(action == Action::read ||
               action == Action::write) return true;
            else return false;
            break;
        
        case AccountStatus::guest: 
            if(action==Action::read) return true;
            else return false;
            break;

        case AccountStatus::mod:
            return true;
            break;
    }
}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
    
bool valid_player_combination(AccountStatus player1, AccountStatus player2){
    //checks if the palter can join the same game

    // guests cannot play
    if (player1 == AccountStatus::guest ||
        player2 == AccountStatus::guest){
            return false;
    }
    // trolls can only play with trolls
    if (player1 == AccountStatus::troll ||
        player2 == AccountStatus::troll)
            return player1 == AccountStatus::troll &&
                   player2 == AccountStatus::troll;
    
    // everything else is fair game 
    return true;

}
        
// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus accnt1, AccountStatus accnt2){

    return static_cast<int>(accnt1) > static_cast<int>(accnt2);
}
}  // namespace hellmath
