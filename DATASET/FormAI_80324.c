//FormAI DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); //seeding random number generator with current time

    float temperature = (float) (rand() % 50) - 20; //generating a random temperature between -20 and 30
    float humidity = (float) (rand() % 101); //generating a random humidity value between 0 and 100
    int rain = rand() % 2; //generating a random rain value (0 or 1)

    printf("Today's weather simulation:\n");

    //checking the temperature range
    if(temperature < 0){
        printf("It is freezing cold today with a temperature of %.2f degrees Celsius.\n", temperature);
    } else if (temperature >= 0 && temperature < 10) {
        printf("It is very cold today with a temperature of %.2f degrees Celsius.\n", temperature);
    } else if (temperature >= 10 && temperature < 20) {
        printf("It is cold today with a temperature of %.2f degrees Celsius.\n", temperature);
    } else if (temperature >= 20 && temperature < 30) {
        printf("It is warm today with a temperature of %.2f degrees Celsius.\n", temperature);
    } else {
        printf("It is extremely hot today with a temperature of %.2f degrees Celsius!\n", temperature);
    }

    //checking the humidity level
    if(humidity < 30){
        printf("The air is very dry with a humidity level of %.2f percent.\n", humidity);
    } else if(humidity >= 30 && humidity < 60){
        printf("The air is moderate with a humidity level of %.2f percent.\n", humidity);
    } else {
        printf("The air is very humid with a humidity level of %.2f percent.\n", humidity);
    }

    //checking if it is raining
    if(rain){
        printf("It is raining today!\n");
    } else {
        printf("There is no rain today.\n");
    }

    return 0;
}