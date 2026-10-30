#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.

int vote_count(ElectionResult &profile){
    return profile.votes;
}
// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.

void increment_vote_count(ElectionResult &profile, int num_votes){
    profile.votes+= num_votes;
}
// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.

ElectionResult& determine_result(std::vector<ElectionResult>& final_count){
    //loop to find the person with the most votes.    
     int curr_winner_index = 0;
     int max_vote = 0;
     for(int i{0}; i < final_count.size(); i++){
        if(max_vote < final_count[i].votes){
            max_vote = final_count[i].votes;
            curr_winner_index = i;
         }
     }
    //updating the name of the winner
    final_count[curr_winner_index].name = "President "+
        final_count[curr_winner_index].name;

    /* a note on refferences.

    Refferences can be declared like this. it is best used
    like this to create an alias to something.
    ElectionResult& refference_to_winner = 
                                final_count[curr_winner_index];

    weird gotchas with the &.

    1) & does not imply refference in the context of expressions.
    so if &y does not mean refference to y automatically.
    it depends on the context.

    context A: int& x = y CORRECT IT DOES.
    
    context B: int x=&some_y INCORRECT this assigns a pointer.
                             an address

    
    2) when in a the context of a function that returns a 
    pointer. the return statement automatically casts the 
    object into a refference. This seems to be true at least 
    in this version of C.

    */
    return final_count[curr_winner_index];
 }
}  // namespace election
