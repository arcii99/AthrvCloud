//FormAI DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); //initialize random seed
    float temperature = (float)(rand() % 50) - 20; //random temperature between -20 to 30 degrees Celsius
    int humidity = rand() % 101; //random humidity between 0% to 100%
    char* sky[4] = {"clear", "partly cloudy", "mostly cloudy", "overcast"}; //array of possible sky conditions
    int skyIndex = rand() % 4; //random index for sky condition
    char* windDirection[8] = {"north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest"}; //array of possible wind directions
    int windIndex = rand() % 8; //random index for wind direction
    int windSpeed = rand() % 51; //random wind speed between 0 to 50 km/h 

    //output the weather simulation
    printf("Today's weather:\n");
    printf("Temperature: %.1f degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Sky condition: %s\n", sky[skyIndex]);
    printf("Wind direction: %s\n", windDirection[windIndex]);
    printf("Wind speed: %d km/h\n", windSpeed);

    return 0; //end program
}