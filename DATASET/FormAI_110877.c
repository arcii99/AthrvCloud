//FormAI DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int temperature = rand() % 40 - 10; // generate a random temperature between -10 and 30 degrees Celsius
    float humidity = (float) (rand() % 100) / 100; // generate a random humidity between 0 and 1
    
    printf("Today's weather simulation:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %.2f\n", humidity);
    
    if (temperature < 0) {
        printf("Brrr... it's freezing out there!");
    } else if (temperature < 10) {
        printf("You might want to wear a jacket.");
    } else if (temperature < 20) {
        printf("The weather is quite pleasant today.");
    } else if (temperature < 30) {
        printf("It's getting a bit warm out here.");
    } else {
        printf("It's scorching hot!");
    }
    
    if (humidity > 0.8) {
        printf(" It's also quite humid, so be prepared to sweat!");
    } else if (humidity > 0.6) {
        printf(" It's a bit humid out here.");
    } else if (humidity > 0.4) {
        printf(" The humidity is just right.");
    } else {
        printf(" It's a bit dry today.");
    }
    
    return 0;
}