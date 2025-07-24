//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_CARS 10
#define TRACK_LENGTH 100

struct car {
    int position;
    int speed;
};

void initialize(struct car cars[], int num_of_cars) {
    srand(time(NULL)); // Initialize random seed

    for (int i = 0; i < num_of_cars; i++) {
        cars[i].position = rand() % TRACK_LENGTH; // Random position between 0 and track length
        cars[i].speed = rand() % 10 + 1; // Random speed between 1 and 10
    }
}

void update_positions(struct car cars[], int num_of_cars) {
    for (int i = 0; i < num_of_cars; i++) {
        cars[i].position += cars[i].speed;

        // If car reaches end of track, wrap around to beginning
        if (cars[i].position >= TRACK_LENGTH) {
            cars[i].position -= TRACK_LENGTH;
        }
    }
}

void print_track(struct car cars[], int num_of_cars) {
    char track[TRACK_LENGTH];

    // Fill track with empty spaces
    for (int i = 0; i < TRACK_LENGTH; i++) {
        track[i] = ' ';
    }

    // Place cars on track
    for (int i = 0; i < num_of_cars; i++) {
        track[cars[i].position] = 'X';
    }

    // Print track
    for (int i = 0; i < TRACK_LENGTH; i++) {
        printf("%c", track[i]);
    }
    printf("\n");
}

int main() {
    struct car cars[NUM_OF_CARS];

    initialize(cars, NUM_OF_CARS);

    for (int i = 0; i < 10; i++) { // Simulate 10 time steps
        update_positions(cars, NUM_OF_CARS);
        print_track(cars, NUM_OF_CARS);
    }

    return 0;
}