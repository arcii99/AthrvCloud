//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* GPS coordinates of the starting and destination locations */
float start_lat = 37.7749;
float start_long = -122.4194;
float dest_lat = 40.7128;
float dest_long = -74.0060;

/* Function to simulate the GPS navigation */
void simulate_navigation() {
    /* Print the starting location */
    printf("Starting location: %.4f N, %.4f W\n", start_lat, start_long);

    /* Calculate the distance and direction to the destination */
    float phi1 = start_lat * 3.14159 / 180.0;
    float phi2 = dest_lat * 3.14159 / 180.0;
    float delta_phi = (dest_lat - start_lat) * 3.14159 / 180.0;
    float delta_lambda = (dest_long - start_long) * 3.14159 / 180.0;

    float a = sin(delta_phi/2) * sin(delta_phi/2) + cos(phi1) * cos(phi2) * sin(delta_lambda/2) * sin(delta_lambda/2);
    float c = 2 * atan2(sqrt(a), sqrt(1-a));
    float distance = 6371 * c;

    printf("Distance to destination: %.2f km\n", distance);

    float y = sin(delta_lambda) * cos(phi2);
    float x = cos(phi1)*sin(phi2) - sin(phi1)*cos(phi2)*cos(delta_lambda);
    float bearing = atan2(y, x) * 180 / 3.14159;

    printf("Direction of destination: %.2f degrees\n", bearing);
    
    /* Simulate the movement towards the destination */
    srand(time(NULL));
    float curr_lat = start_lat;
    float curr_long = start_long;
    float curr_bearing = bearing + (rand() % 10 - 5);
    float speed = (rand() % 10 + 30) / 3.6; // km/h to m/s conversion
    float time_elapsed = 0;
    float distance_to_dest = distance;

    while (distance_to_dest > 0.1) { // stop when within 100m of destination
        /* Calculate the new position based on speed and bearing */
        curr_lat += speed * sin(curr_bearing * 3.14159 / 180.0) / (6371 * 3.14159 / 180.0);
        curr_long += speed * cos(curr_bearing * 3.14159 / 180.0) / (6371 * 3.14159 / 180.0);
        time_elapsed += 1;
        distance_to_dest = sqrt(pow(curr_lat - dest_lat, 2) + pow(curr_long - dest_long, 2)) * 6371;
        printf("Current location: %.4f N, %.4f W\n", curr_lat, curr_long);
        printf("Distance to destination: %.2f km\n", distance_to_dest);
        printf("Time elapsed: %.0f s\n", time_elapsed);
        printf("Bearing to destination: %.2f degrees\n", curr_bearing);
        curr_bearing += (rand() % 10 - 5);
        if (curr_bearing > 180) {
            curr_bearing -= 360;
        } else if (curr_bearing < -180) {
            curr_bearing += 360;
        }
        speed += (rand() % 5 - 2) / 10.0;
        if (speed < 0) {
            speed = 0;
        }
        printf("\n");
    }

    printf("You have arrived at your destination!\n");

    /* Print the total time taken */
    printf("Total time elapsed: %.0f s\n", time_elapsed);
}

int main() {
    simulate_navigation();
    return 0;
}