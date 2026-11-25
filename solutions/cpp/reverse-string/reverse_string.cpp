#include <iostream>
#include "reverse_string.h"

namespace reverse_string {

std::string reverse_string(std::string input){
    // Walk backward through the input and append each character to the result.
    int string_size = input.size();

    std::string reversed_string = "";
    for (int i = string_size - 1; i >= 0; i--){
        reversed_string += input[i];
    }

    // Return the newly built string; the input is left unchanged.
    return reversed_string;
}

}  // namespace reverse_string