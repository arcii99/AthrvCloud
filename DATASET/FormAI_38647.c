//FormAI DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initializing variables for random temperature and weather conditions
    int temp;
    char* weather;


    srand(time(NULL)); // Setting up random seed

    printf("Welcome to the Happy Weather Simulation Program!\n");
    printf("************************************************\n\n");

    for(int i=0; i<7; i++) {
        int random_num = rand() % 4; // Random number for weather conditions

        // Assigning weather conditions based on random number
        switch(random_num) {
            case 0:
                weather = "Sunny";
                temp = rand() % 21 + 25; // Random temperature between 25 and 45 degrees Celsius
                break;
            case 1:
                weather = "Cloudy";
                temp = rand() % 16 + 10; // Random temperature between 10 and 25 degrees Celsius
                break;
            case 2:
                weather = "Rainy";
                temp = rand() % 11 + 5; // Random temperature between 5 and 15 degrees Celsius
                break;
            case 3:
                weather = "Snowy";
                temp = rand() % 11 - 5; // Random temperature between -5 and 5 degrees Celsius
                break;
        }

        printf("On Day %d, the weather is %s and the temperature is %d degrees Celsius.\n", i+1, weather, temp);
        printf("Enjoy your day!\n\n");
    }

    printf("Thank you for using the Happy Weather Simulation Program!\n");

    return 0;
}