//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_CARS 1000
#define MAX_SECONDS 3600

// Structs
typedef struct car {
    int num;
    int speed;
    int lane;
    int position;
} Car;

// Function Prototypes
void initializeCars(Car cars[], int numberOfCars);
void updateCars(Car cars[], int numberOfCars, int time);
void displaySimulation(Car cars[], int numberOfCars, int time);

// Main Function
int main() {
    srand(time(NULL)); // seed random number generator
    Car cars[MAX_CARS]; // array to hold cars
    int numberOfCars = rand() % MAX_CARS + 1; // random number of cars
    initializeCars(cars, numberOfCars); // initialize car attributes
    for (int i = 0; i < MAX_SECONDS; i++) { // loop through each second of simulation
        updateCars(cars, numberOfCars, i); // update car positions
        displaySimulation(cars, numberOfCars, i); // display simulation
    }
    return 0;
}

// Function to initialize car attributes
void initializeCars(Car cars[], int numberOfCars) {
    for (int i = 0; i < numberOfCars; i++) {
        cars[i].num = i + 1; // car number
        cars[i].speed = rand() % 60 + 40; // random speed between 40-100 mph
        cars[i].lane = rand() % 3; // random lane 0-2
        cars[i].position = rand() % 1000; // random position on road 0-999
    }
}

// Function to update car positions
void updateCars(Car cars[], int numberOfCars, int time) {
    for (int i = 0; i < numberOfCars; i++) {
        // calculate next position of car based on speed and time elapsed
        int nextPosition = cars[i].position + ((cars[i].speed * (time + 1)) / 3600);
        if (nextPosition >= 1000) { // if car passes finish line
            nextPosition = nextPosition - 1000; // move car back to start
        }
        // check if car collides with another car in same lane
        for (int j = 0; j < numberOfCars; j++) {
            if (i != j && cars[i].lane == cars[j].lane && nextPosition < cars[j].position + 4 && nextPosition > cars[j].position - 4) {
                cars[i].speed--; // reduce speed if collision is imminent
                break;
            }
        }
        cars[i].position = nextPosition; // update car position
    }
}

// Function to display simulation
void displaySimulation(Car cars[], int numberOfCars, int time) {
    printf("Time: %d seconds\n", time);
    for (int i = 0; i < 3; i++) { // loop through each lane
        printf("Lane %d: ", i + 1);
        for (int j = 0; j < numberOfCars; j++) { // loop through each car in lane
            if (cars[j].lane == i) {
                for (int k = 0; k < cars[j].position; k++) { // print empty space before car
                    printf(" ");
                }
                printf("C%d", cars[j].num); // print car number
                for (int k = cars[j].position + 2; k < 1000; k++) { // print empty space after car
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}