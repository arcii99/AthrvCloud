//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize the random generator with the current time
    int temp = rand() % 101; // Generate a random temperature between 0 and 100 degrees Celsius

    printf("Welcome to the post-apocalyptic world temperature monitor!\n\n");
    printf("Current temperature: %d degrees Celsius\n", temp);

    if(temp >= 50) {
        printf("WARNING: Temperature is dangerously high. Seek shelter immediately!\n");
    } else {
        printf("Temperature is within safe range.\n");
    }

    return 0;
}