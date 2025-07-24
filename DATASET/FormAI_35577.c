//FormAI DATASET v1.0 Category: Weather simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random generator with current time
    int temperature = (rand() % 40) - 20; // random temperature ranging from -20 to 20
    int humidity = rand() % 101; // random humidity percentage ranging from 0 to 100
    int wind_speed = rand() % 101; // random wind speed in km/h ranging from 0 to 100
    int precipitation_chance = rand() % 101; // random chance of precipitation ranging from 0 to 100
    char* precipitation_type = NULL; // initialize precipitation type to be empty
    if (precipitation_chance > 70) { // if chance of precipitation is greater than 70
        int precipitation_type_num = rand() % 3; // random number from 0 to 2
        switch (precipitation_type_num) {
            case 0:
                precipitation_type = "rain"; // set precipitation type to rain
                break;
            case 1:
                precipitation_type = "snow"; // set precipitation type to snow
                break;
            case 2:
                precipitation_type = "hail"; // set precipitation type to hail
                break;
        }
    }
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    if (precipitation_type != NULL) { // if there is precipitation
        printf("Chance of %s: %d%%\n", precipitation_type, precipitation_chance);
    } else {
        printf("Chance of precipitation: %d%%\n", precipitation_chance);
    }
    return 0;
}