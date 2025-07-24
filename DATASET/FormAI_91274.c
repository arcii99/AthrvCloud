//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int temperature = 25;
    int weather = 0;
    int time_of_day = 0;
    
    srand(time(NULL));
    
    printf("Welcome to the weather simulation program!\n\n");
    
    while(1) {
        printf("Temperature: %d°C\n", temperature);
        
        // Randomly generate weather
        weather = rand() % 4;
        
        // Determine time of day
        if(time_of_day < 12) {
            printf("Good morning!\n");
        }
        else if(time_of_day >= 12 && time_of_day < 18) {
            printf("Good afternoon!\n");
        }
        else {
            printf("Good evening!\n");
        }
        
        // Output weather conditions
        switch(weather) {
            case 0: 
                printf("Looks like it's sunny today. Enjoy the nice weather!\n");
                temperature += 5;
                break;
            case 1:
                printf("It's cloudy outside. Don't forget your umbrella.\n");
                temperature -= 5;
                break;
            case 2:
                printf("Rain, rain, go away. It's going to be a wet day!\n");
                temperature -= 10;
                break;
            case 3: 
                printf("Looks like it's going to be a snowy day. Bundle up and grab your shovel!\n");
                temperature -= 15;
                break;
            default:
                break;
        }
        
        // Adjust time of day and temperature
        time_of_day += 6;
        if(time_of_day >= 24) {
            time_of_day = 0;
        }
        if(temperature <= -10) {
            temperature = 0;
            printf("Brrr, it's too cold! The simulation has ended.\n");
            break;
        }
        if(temperature >= 40) {
            temperature = 0;
            printf("It's too hot to handle! The simulation has ended.\n");
            break;
        }
        
        printf("Time: %d:00\n\n", time_of_day);
        
        // Wait for user to continue
        printf("Press Enter to move on\n");
        while(getchar() != '\n');
        system("clear");
    }
    
    return 0;
}