//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int current_pos_x = rand() % 100; // current position x coordinate
    int current_pos_y = rand() % 100; // current position y coordinate
    int dest_pos_x, dest_pos_y; // destination position x and y coordinates
    printf("Current position: (%d, %d)\n", current_pos_x, current_pos_y);
    printf("Enter destination position (x, y): ");
    scanf("%d %d", &dest_pos_x, &dest_pos_y);
    int dist_to_travel_x = abs(dest_pos_x - current_pos_x);
    int dist_to_travel_y = abs(dest_pos_y - current_pos_y);
    int total_distance = dist_to_travel_x + dist_to_travel_y;
    printf("Total distance to travel: %d\n", total_distance);
    printf("Turn left ");
    if (dest_pos_x < current_pos_x) {
        printf("%d times ", dist_to_travel_x);
    }
    printf("and go straight for %d meters.\n", dist_to_travel_y);
    printf("You have arrived at your destination!.\n");
    return 0;
}