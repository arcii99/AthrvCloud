//FormAI DATASET v1.0 Category: Temperature monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate a random temperature reading between -20 and 50 degrees Celsius
int generateTemp() {
    return (rand() % 71) - 20;
}

int main() {
    int currentTemp;
    time_t t;

    //initialize random seed
    srand((unsigned) time(&t));

    while(1) {
        //generate current temperature reading
        currentTemp = generateTemp();

        printf("Current temperature: %d degrees Celsius\n", currentTemp);

        if(currentTemp >= 30) {
            printf("High temperature alert! Seek shade and stay hydrated.\n");
        } else if(currentTemp >= 20) {
            printf("Comfortable temperature. Enjoy your day!\n");
        } else {
            printf("Low temperature alert! Dress warmly and stay indoors if possible.\n");
        }

        //wait for 5 seconds before generating the next reading
        sleep(5);
    }

    return 0;
}