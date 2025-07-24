//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of cars that can be waiting at a traffic light
#define MAX_CARS 10

// Enumeration to define the states of the traffic light
typedef enum {
    RED,
    YELLOW,
    GREEN
} LightState;

// Structure to represent a car that is waiting at the traffic light
typedef struct {
    int num;
    time_t arrivalTime;
} Car;

// Function to get the current time in seconds
int getCurrentTime() {
    return (int)time(NULL);
}

int main() {
    LightState state = RED;
    int redTime = 15;   // Number of seconds for which the red light should stay on
    int yellowTime = 3; // Number of seconds for which the yellow light should stay on
    int greenTime = 30; // Number of seconds for which the green light should stay on

    int timeRemaining = redTime;
    bool isYellow = false;

    Car waitingCars[MAX_CARS];
    int numWaitingCars = 0;

    while (true) {
        // Print the current state of the traffic light
        printf("Traffic Light: ");
        if (state == RED) {
            printf("RED\n");
        } else if (state == YELLOW) {
            printf("YELLOW\n");
        } else if (state == GREEN) {
            printf("GREEN\n");
        }

        // Check if any cars are waiting
        if (numWaitingCars > 0) {
            printf("Waiting cars: %d\n", numWaitingCars);
            printf("Car %d has been waiting for %d seconds\n", waitingCars[0].num, getCurrentTime() - waitingCars[0].arrivalTime);
        }

        // Wait for 1 second
        sleep(1);

        // Decrement the time remaining in the current light state
        timeRemaining--;

        // If the time has run out for the current state,
        // switch to the next state
        if (timeRemaining == 0) {
            if (state == RED) {
                state = GREEN;
                timeRemaining = greenTime;
            } else if (state == YELLOW) {
                state = RED;
                timeRemaining = redTime;

                // Move the cars waiting at the traffic light to the front of the line
                for (int i = 1; i < numWaitingCars; i++) {
                    waitingCars[i - 1] = waitingCars[i];
                }
                numWaitingCars--;
            } else if (state == GREEN) {
                state = YELLOW;
                timeRemaining = yellowTime;
            }
        }

        // If the current state is green and there are no cars waiting,
        // randomly generate a new car that arrives at the traffic light
        if (state == GREEN && numWaitingCars == 0 && rand() % 5 == 0) {
            Car newCar = { .num = rand(), .arrivalTime = getCurrentTime() };
            waitingCars[numWaitingCars++] = newCar;
        }

        // If the current state is red and there are cars waiting,
        // let the first car in line through the traffic light
        if (state == RED && numWaitingCars > 0) {
            printf("Car %d has passed through the traffic light\n", waitingCars[0].num);

            // Move the cars waiting at the traffic light to the front of the line
            for (int i = 1; i < numWaitingCars; i++) {
                waitingCars[i - 1] = waitingCars[i];
            }
            numWaitingCars--;
        }
    }

    return 0;
}