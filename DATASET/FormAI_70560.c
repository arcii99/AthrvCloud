//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature = 0;
    srand(time(NULL));
    temperature = rand() % 20 + 10; // generate a random temperature between 10-30 degree Celsius
    printf("Welcome to the Medieval Temperature Monitor!\n");
    printf("The current temperature is %d degree Celsius.\n", temperature);
    if (temperature >= 25) {
        printf("The weather is hot and dry, be sure to stay hydrated!\n");
    } else if (temperature >= 20) {
        printf("The weather is just perfect, enjoy your day!\n");
    } else if (temperature >= 15) {
        printf("The weather is mild, but make sure to wear a coat!\n");
    } else {
        printf("The weather is cold and harsh, make sure to keep yourself warm!\n");
    }
    return 0;
}