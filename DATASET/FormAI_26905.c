//FormAI DATASET v1.0 Category: Weather simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Variables for weather simulation
    char weather[5][20] = {"Sunny", "Cloudy", "Rainy", "Stormy", "Snowy"};
    int temp_min = 10, temp_max = 30;
    int humidity_min = 30, humidity_max = 80;
    int wind_min = 0, wind_max = 30;
    int pressure_min = 900, pressure_max = 1100;
    srand(time(NULL)); // Seed for random numbers
    
    // Introduce the program
    printf("Welcome to Weather Simulator 9000!\n\n");
    printf("This program will randomly generate weather reports for you.\n\n");
    printf("Press enter to continue.\n");
    getchar();
    printf("\n");
    
    // Loop for generating weather reports
    for (int i = 1; i <= 10; i++) {
        int temp = rand() % (temp_max - temp_min + 1) + temp_min;
        int humidity = rand() % (humidity_max - humidity_min + 1) + humidity_min;
        int wind = rand() % (wind_max - wind_min + 1) + wind_min;
        int pressure = rand() % (pressure_max - pressure_min + 1) + pressure_min;
        int weather_choice = rand() % 5;
        
        // Generate the weather report
        printf("Weather Report #%d:\n", i);
        printf("Temperature: %dC\n", temp);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %dkm/h\n", wind);
        printf("Barometric Pressure: %dhPa\n", pressure);
        printf("Weather Conditions: %s\n\n", weather[weather_choice]);
        
        // Wait for user to continue or exit
        printf("Press enter to generate another report, or type 'exit' to quit.\n");
        char input[10];
        fgets(input, 10, stdin);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            printf("\nThanks for using Weather Simulator 9000! Goodbye!\n");
            return 0;
        } else {
            printf("\n");
        }
    }
}