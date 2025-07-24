//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // set the seed for random numbers
    
    int temp = rand() % 30;  // generate a random temperature between 0 and 29
    int wind = rand() % 30;  // generate a random wind speed between 0 and 29
    
    printf("Temperature: %d degrees Celsius\nWind Speed: %d km/h\n\n", temp, wind);
    
    if (temp <= 10 && wind >= 20) {  // if it's cold and windy
        printf("Brrr! It's freezing out here with a wind chill factor of %d degrees Celsius!\n", temp - wind);
    } else if (temp < 0) {  // if it's below freezing
        printf("Warning! It's dangerously cold out here with a temperature of %d degrees Celsius!\n", temp);
    } else if (temp < 10) {  // if it's chilly
        printf("Better wear a jacket! It's only %d degrees Celsius out here.\n", temp);
    } else if (temp < 20 && wind >= 20) {  // if it's warm but windy
        printf("Hold on to your hats! It's breezy with a wind speed of %d km/h.\n", wind);
    } else if (temp >= 20) {  // if it's hot
        printf("Phew! It's boiling out here at %d degrees Celsius.\n", temp);
    } else {  // catch-all statement
        printf("The weather is quite pleasant at %d degrees Celsius and %d km/h wind.\n", temp, wind);
    }
    
    return 0;
}