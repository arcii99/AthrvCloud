//FormAI DATASET v1.0 Category: Weather simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to Weather Simulator 9001!\n");
    printf("Preparing your weather report...\n");
    
    // Generate random temperatures
    srand(time(NULL));
    int temperature = rand() % 86 - 30;
    
    // Generate random precipitation type
    int precipitation = rand() % 5;
    char* precipitation_type = "";
    switch (precipitation) {
        case 0:
            precipitation_type = "Rain";
            break;
        case 1:
            precipitation_type = "Snow";
            break;
        case 2:
            precipitation_type = "Sleet";
            break;
        case 3:
            precipitation_type = "Hail";
            break;
        case 4:
            precipitation_type = "Meteor Shower";
            break;
    }
    
    // Generate random wind speed
    int wind_speed = rand() % 60;
    
    printf("\nYour weather report is ready!\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Precipitation: %s\n", precipitation_type);
    printf("Wind speed: %d km/h\n\n", wind_speed);
    
    // Give advice based on the weather conditions
    if (temperature < 0) {
        printf("Stay indoors, it's freezing out there!\n");
    }
    else if (temperature < 10) {
        printf("Bundle up, it's cold outside!\n");
    }
    else if (temperature < 20) {
        printf("Nice weather today, perfect for a picnic!\n");
    }
    else {
        printf("It's a scorcher out there, don't forget your sunscreen!\n");
    }
    
    switch (precipitation) {
        case 0:
            printf("Don't forget your umbrella!\n");
            break;
        case 1:
            printf("Time to build a snowman!\n");
            break;
        case 2:
            printf("Watch out for the slippery roads!\n");
            break;
        case 3:
            printf("Take cover or else you'll get bruises!\n");
            break;
        case 4:
            printf("Quick, make a wish!\n");
            break;
    }
    
    if (wind_speed > 30) {
        printf("Hold on to your hats, it's windy out there!\n");
    }
    
    printf("\nThanks for using Weather Simulator 9001! Have fun out there!");
    
    return 0;
}