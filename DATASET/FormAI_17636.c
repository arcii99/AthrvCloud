//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initializing variables
    float temperature;
    time_t current_time;
    char* c_time_string;

    // Generating random temperature between -20C to 40C
    srand(time(NULL));
    temperature = (rand() % (400 - (-200) + 1)) - 200;
    temperature /= 10;

    //Getting the current time using time()
    current_time = time(NULL);

    //Converting current time to a string
    c_time_string = ctime(&current_time);

    //Printing the current time and the temperature
    printf("Current time is %s", c_time_string);
    printf("The temperature is %.2fC\n", temperature);

    //Checking if the temperature is below 0C
    if (temperature < 0) {
        printf("Warning: Temperature is below freezing point.\n");
    }
    return 0;
}