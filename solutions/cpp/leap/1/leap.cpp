#include "leap.h"

namespace leap {

    bool is_leap_year(int year) {
        // A year must be divisible by 4 to be a leap year.
        if ((year % 4) == 0) {
            // Century years are leap years only when divisible by 400.
            if (year % 100 == 0) {
                if (year % 400 == 0) return true;
                return false;
            }
            return true;
        }
        return false;
    }

}  // namespace leap