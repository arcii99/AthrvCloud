//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 100 // maximum value of x-axis
#define MAX_Y 100 // maximum value of y-axis
#define MAX_DISTANCE 200 // maximum value of distance per move
#define MAX_DELAY 5 // maximum value of delay between moves

typedef struct {
    int x;
    int y;
} Location;

int main() {
    srand(time(NULL)); // seed the random number generator
    
    Location current_location = {0, 0}; // start at origin
    
    // generate randomly placed and sized destinations
    int num_destinations = rand() % 10 + 1;
    Location destinations[num_destinations];
    int i;
    for (i = 0; i < num_destinations; i++) {
        destinations[i].x = rand() % MAX_X;
        destinations[i].y = rand() % MAX_Y;
    }
    
    // print starting location and destinations
    printf("Starting location: (%d,%d)\n", current_location.x, current_location.y);
    printf("Destinations:\n");
    for (i = 0; i < num_destinations; i++) {
        printf("(%d,%d)\n", destinations[i].x, destinations[i].y);
    }
    
    // simulate navigation
    while (num_destinations > 0) {
        // choose a random destination
        int dest_index = rand() % num_destinations;
        Location destination = destinations[dest_index];
        
        // calculate distance to destination
        int delta_x = destination.x - current_location.x;
        int delta_y = destination.y - current_location.y;
        int distance = (int) sqrt(delta_x*delta_x + delta_y*delta_y);
        
        // move towards destination
        int moves = distance / MAX_DISTANCE + 1;
        int j;
        for (j = 0; j < moves; j++) {
            int move_distance = distance / moves + 1;
            if (move_distance > MAX_DISTANCE) {
                move_distance = MAX_DISTANCE;
            }
            delta_x = destination.x - current_location.x;
            delta_y = destination.y - current_location.y;
            double ratio = (double)move_distance / distance;
            current_location.x += (int)(delta_x * ratio);
            current_location.y += (int)(delta_y * ratio);
            printf("Moved to (%d,%d)\n", current_location.x, current_location.y);
            distance = (int) sqrt((delta_x - (int)(delta_x * ratio))*(delta_x - (int)(delta_x * ratio)) + (delta_y - (int)(delta_y * ratio))*(delta_y - (int)(delta_y * ratio)));
            int delay = rand() % MAX_DELAY + 1;
            printf("Delaying for %d seconds...\n", delay);
            sleep(delay);
        }
        
        // remove destination from list
        destinations[dest_index] = destinations[num_destinations-1];
        num_destinations--;
    }
    
    // print final location
    printf("Reached all destinations! Final location: (%d,%d)\n", current_location.x, current_location.y);
    
    return 0;
}