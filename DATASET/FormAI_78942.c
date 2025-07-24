//FormAI DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define NORMAL_TEMP 37

int get_random_temperature() {
    return (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
}

int main() {
    srand(time(NULL)); // Initialize random number generator with current time
    
    int temp = get_random_temperature();
    printf("Current temperature is %d degrees Celsius.\n", temp);
    
    if (temp < NORMAL_TEMP) {
        printf("Temperature is below normal.\n");
    } else if (temp > NORMAL_TEMP) {
        printf("Temperature is above normal.\n");
    } else {
        printf("Temperature is normal.\n");
    }
    
    return 0;
}