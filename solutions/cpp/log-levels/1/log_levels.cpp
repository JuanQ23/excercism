#include <string>

namespace log_line {
    std::string message(std::string line) {

        int strIndex = line.find(":");
        std::string message = line.substr(strIndex+2);
        return message;
        // return the message
    }
    
    std::string log_level(std::string line) {
        
        
        return line.substr(1, line.find("]")-1);
        // return the log level
    }
    
    std::string reformat(std::string line) {
        
        return message(line) + " " + "(" + log_level(line) + ")";
        // return the reformatted message
    }
}  // namespace log_line
