//FormAI DATASET v1.0 Category: Weather simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int temperature, humidity;
    char *condition;
    srand(time(0)); // initialize random seed

    printf("Current weather conditions: \n");

    // generate random temperature
    temperature = (rand() % 50) - 10;
    printf("Temperature: %d degC\n", temperature);

    // generate random humidity
    humidity = rand() % 100;
    printf("Humidity: %d%%\n", humidity);

    // generate random weather condition based on humidity and temperature
    if (humidity > 70 && temperature > 20){
        condition = "Rainy with Thunderstorm";
    }
    else if (humidity > 50 && temperature > 15){
        condition = "Cloudy with Drizzle";
    }
    else if (humidity > 30 && temperature > 10){
        condition = "Partly Cloudy";
    }
    else if (humidity > 10 && temperature > 5){
        condition = "Sunny with Clear Sky";
    }
    else {
        condition = "Cold and Foggy";
    }

    printf("Condition: %s\n", condition);

    return 0;
}