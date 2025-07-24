//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer
int random_int(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate space travel
void space_travel(int distance){
    int time = random_int(1, 5);
    printf("Traveling through space...\n");
    printf("Estimated time of arrival: %d days\n", time);
    printf("Arrived at destination after %d days\n\n", time);
}

int main(){

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer between 100 and 1000
    int distance = random_int(100, 1000);
    printf("Welcome to the procedural space adventure!\n");
    printf("You need to travel %d light years to reach the target.\n\n", distance);

    // Begin the space travel simulation
    while (distance > 0){
        space_travel(distance);
        distance -= 50;
    }

    // Display the final message
    printf("Congratulations, you have reached your destination! Mission complete.");

    return 0;
}