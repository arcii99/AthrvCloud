//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct coordinates {
    double latitude;
    double longitude;
};

struct drive_state {
    struct coordinates current_loc;
    struct coordinates target_loc;
    double speed;
    double distance_to_target;
};

// Simulate GPS readings at random intervals
void simulate_gps_reading(struct drive_state* state) {
    srand(time(NULL));
    int delay_time = rand() % 10 + 1; // simulate random delay time between 1-10 seconds
    state->current_loc.latitude += (double)rand()/RAND_MAX * 0.001; // simulate random latitude movement
    state->current_loc.longitude += (double)rand()/RAND_MAX * 0.001; // simulate random longitude movement
    printf("Current location: (%.6f, %.6f)\n", state->current_loc.latitude, state->current_loc.longitude);
    printf("Distance to target: %.3f m\n", state->distance_to_target);
    printf("Simulating GPS reading for %d seconds...\n\n", delay_time);
    sleep(delay_time); // simulate delay time between GPS readings
}

// Calculate distance between two coordinates in meters using Haversine formula
double calculate_distance(struct coordinates coord1, struct coordinates coord2) {
    double R = 6371000; // radius of Earth in meters
    double phi1 = coord1.latitude * 3.141592653589793 / 180; // convert to radians
    double phi2 = coord2.latitude * 3.141592653589793 / 180;
    double delta_phi = (coord2.latitude - coord1.latitude) * 3.141592653589793 / 180;
    double delta_lambda = (coord2.longitude - coord1.longitude) * 3.141592653589793 / 180;
    double a = sin(delta_phi/2) * sin(delta_phi/2) + cos(phi1) * cos(phi2) * sin(delta_lambda/2) * sin(delta_lambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

// Asynchronous main function
int main() {
    struct drive_state state = {{47.6062, -122.3321}, {47.6150, -122.3480}, 0.0, 0.0};
    double max_speed = 13.4; // maximum speed limit in Seattle, WA is 30 mph (13.4 m/s)
    double min_distance = 5.0; // minimum distance between GPS readings in meters
    double max_distance = 100.0; // maximum distance between GPS readings in meters
    
    while(state.distance_to_target > 10.0 || state.speed > 0.1) { // simulate driving until within 10 meters of target and speed is close to 0
        state.distance_to_target = calculate_distance(state.current_loc, state.target_loc); // calculate distance to target
        state.speed = max_speed * (state.distance_to_target/max_distance); // calculate speed based on distance to target and max speed
        printf("Target location: (%.6f, %.6f)\n", state.target_loc.latitude, state.target_loc.longitude);
        printf("Current speed: %.2f m/s\n", state.speed);
        printf("Distance to target: %.3f m\n", state.distance_to_target);
        printf("-------\n");
        if(state.distance_to_target <= min_distance) { // if close to target, set current location to target location and break
            state.current_loc = state.target_loc;
            break;
        }
        simulate_gps_reading(&state); // simulate GPS reading
    }
    
    printf("You have arrived at your destination!\n");
    return 0;
}