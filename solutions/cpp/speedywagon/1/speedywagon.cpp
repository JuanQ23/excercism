#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* sensor) {
    // A non-null pointer means the sensor is connected and safe to inspect.
    return sensor != nullptr;
}  // namespace speedywagon

int activity_counter(pillar_men_sensor* sensors, int size) {
    int count = 0;
    // Walk the sensor array and add each activity reading.
    for (int i = 0; i < size; ++i) {
        count += sensors[i].activity;
    }
    return count;
}
bool alarm_control(pillar_men_sensor* sensor) {
    if (sensor == nullptr) return false;
    // Only positive activity should trigger the alarm.
    if (sensor->activity > 0) return true;
    else return false;
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool uv_alarm(pillar_men_sensor* sensor){
    if (sensor == nullptr) return false;
    // Compare the heuristic's anomaly count with the sensor's activity level.
    int uv_hueristic = uv_light_heuristic(&(sensor->data));
    if(uv_hueristic > sensor->activity) return true;
    else return false;
}

}
