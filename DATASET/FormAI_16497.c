//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int temperature;
    srand(time(0)); // randomizing the temperature value
    temperature = rand() % 50 + 1; // temperature range between 1 to 50 degree celsius
    printf("The current temperature is: %d degree Celsius\n", temperature);

    if (temperature < 10) { // if temperature is less than 10 degree celsius
        printf("It's quite cold outside, make sure you wear warm clothes!\n");
    } else if (temperature > 30) { // if temperature is greater than 30 degree celsius
        printf("It's quite hot outside, make sure you stay hydrated!\n");
    } else { // if temperature is between 10 to 30 degree celsius
        printf("The weather is pleasant today!\n");
    }

    return 0;
}