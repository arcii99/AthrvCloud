//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 10

int main() {
    srand(time(NULL)); // seed the random number generator
    int buffer[BUFFER_SIZE] = {0}; // initialize the buffer to zero
    int front = 0, rear = 0; // initialize the front and rear pointers to zero
    int cars_created = 0, cars_passed = 0; // initialize the counters to zero

    while (cars_created < 100) { // generate 100 random cars
        int car_length = rand() % 4 + 1; // generate a random car length between 1 and 4
        int car_speed = rand() % 11 + 20; // generate a random car speed between 20 and 30 m/s
        int car_distance = car_speed * car_length; // calculate the distance the car will travel before its front reaches the end of the road

        if ((rear + 1) % BUFFER_SIZE != front) { // check if the buffer is not full
            buffer[rear] = car_distance; // add the car to the buffer
            rear = (rear + 1) % BUFFER_SIZE; // update the rear pointer
            cars_created++; // increment the cars created counter
        }
    }

    while (cars_passed < cars_created) { // simulate the traffic flow until all cars have passed the end of the road
        if (buffer[front] == 0) { // check if the front car has passed the end of the road
            front = (front + 1) % BUFFER_SIZE; // update the front pointer
            cars_passed++; // increment the cars passed counter
        }

        for (int i = front + 1; i != rear; i = (i + 1) % BUFFER_SIZE) { // simulate the movement of the cars
            if (buffer[i] > 0) {
                buffer[i]--; // decrement the distance of the car from the end of the road
            }
        }

        printf("Time elapsed: %d s\n", cars_passed); // print the elapsed time in seconds
    }

    return 0;
}