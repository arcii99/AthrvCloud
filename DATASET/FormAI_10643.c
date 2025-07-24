//FormAI DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_temperature() { // function to simulate temperature readings
    return rand() % 20 + 20;
}

int main() {
    srand(time(NULL)); // set the seed of the random number generator
    
    int temperature = 0;
    int max_temp = 0;
    int min_temp = 100;
    int readings = 0;
    float avg_temp = 0.0;
    
    while(readings < 10) { // take 10 readings
        temperature = get_temperature();
        avg_temp += temperature;
        if(temperature > max_temp) {
            max_temp = temperature;
        }
        if(temperature < min_temp) {
            min_temp = temperature;
        }
        printf("Reading %d: %d degrees Celsius\n", readings+1, temperature); // print the readings
        readings++;
    }
    
    avg_temp /= readings; // calculate the average temperature
    
    printf("\nMaximum temperature: %d degrees Celsius\n", max_temp);
    printf("Minimum temperature: %d degrees Celsius\n", min_temp);
    printf("Average temperature: %.2f degrees Celsius\n", avg_temp);
    
    return 0;
}