//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_PLAYERS 2
#define MIN_SPEED 1
#define MAX_SPEED 50

int get_random_speed() {
    return MIN_SPEED + (rand() % (MAX_SPEED - MIN_SPEED + 1));
}

int main() {
    int player_speeds[NUM_OF_PLAYERS];
    int fastest_speed = 0;
    int fastest_player = 0;
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random speeds for each player
    for (i = 0; i < NUM_OF_PLAYERS; i++) {
        player_speeds[i] = get_random_speed();
        printf("Player %d speed: %d\n", i+1, player_speeds[i]);
    }

    // Determine the fastest player
    for (i = 0; i < NUM_OF_PLAYERS; i++) {
        if (player_speeds[i] > fastest_speed) {
            fastest_speed = player_speeds[i];
            fastest_player = i+1;
        }
    }

    // Print the winner
    printf("\nPlayer %d is the winner with a speed of %d!\n", fastest_player, fastest_speed);

    return 0;
}