//FormAI DATASET v1.0 Category: Weather simulation ; Style: multivariable
/*
  This program simulates the weather of a city by taking into account multiple variables such as temperature, humidity, wind speed etc. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max (inclusive)
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// function to display the current weather conditions
void display_weather(int temperature, int humidity, int wind_speed) {
    printf("\nCurrent Weather Conditions:\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d %%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
}

int main() {
    // random seed based on current time
    srand(time(NULL));
    
    // variables to store weather conditions
    int temperature, humidity, wind_speed;
    
    // initializing weather conditions with random values
    temperature = random_number(20, 35);   // temperature between 20 and 35 C
    humidity = random_number(50, 80);      // humidity between 50% and 80%
    wind_speed = random_number(5, 30);     // wind speed between 5 and 30 km/h
    
    // display initial weather conditions
    display_weather(temperature, humidity, wind_speed);
    
    // simulate weather changes for next 24 hours
    for(int i = 0; i < 24; i++) {
        // update temperature
        if(i >= 6 && i <= 18) {         // temperature peaks between 12 pm and 2 pm
            temperature += random_number(1, 2);     // temperature increases by 1 or 2 C per hour
        } else {
            temperature -= random_number(1, 2);     // temperature decreases by 1 or 2 C per hour
        }
        
        // update humidity
        if(i >= 9 && i <= 18) {         // humidity peaks between 9 am and 6 pm
            humidity += random_number(-1, 1);      // humidity increases or decreases by 1% per hour
        } else {
            humidity += random_number(-2, 2);      // humidity increases or decreases by 2% per hour
        }
        
        // update wind speed
        if(i >= 6 && i <= 21) {         // wind speed peaks between 12 pm and 9 pm
            wind_speed += random_number(-2, 2);    // wind speed increases or decreases by 2 km/h per hour
        } else {
            wind_speed += random_number(-1, 1);    // wind speed increases or decreases by 1 km/h per hour
        }
        
        // display updated weather conditions
        display_weather(temperature, humidity, wind_speed);
        
        // wait for 1 second to simulate 1 hour of time
        printf("\nWaiting for next hour...\n");
        sleep(1);
    }
    
    printf("\nSimulation over.\n");
    
    return 0;
}