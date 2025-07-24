//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 10
#define MAX_TEMP 50
#define NORMAL_TEMP 25

int currentTemp() {
    int temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    return temp;
}

void printTemp(int temp) {
    printf("The current temperature is: %d°C\n", temp);
    if (temp < NORMAL_TEMP) {
        printf("The temperature is too low, please turn up the heat.\n");
    } else if (temp > NORMAL_TEMP) {
        printf("The temperature is too high, please turn down the heat.\n");
    } else {
        printf("The temperature is normal.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random function with time
    
    printf("Welcome to the Cyberpunk Temperature Monitor.\n");
    printf("Checking temperature...\n");
    
    while(1) { // Loop infinitely, monitoring temperature
        int temp = currentTemp();
        printTemp(temp);
        sleep(2); // Wait for 2 seconds before checking the temperature again
    }
    
    return 0;
}