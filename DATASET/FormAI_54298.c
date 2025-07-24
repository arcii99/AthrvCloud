//FormAI DATASET v1.0 Category: Weather simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int temperature = rand() % 50 - 20; // simulating temperature between -20C and 30C
    int humidity = rand() % 100; // simulating humidity between 0% and 100%
    int wind_speed = rand() % 80; // simulating wind speed between 0km/h and 80km/h
    
    // Creating a Romeo and Juliet style weather report
    printf("Oh Juliet, I fear that the weather today is not suitable for our love...\n\n");
    printf("The temperature is %d degrees Celsius, my dear.\n", temperature);
    if (temperature <= 0) {
        printf("It is quite chilly outside! Perhaps we should stay indoors today?\n");
    } else if (temperature <= 10) {
        printf("It is a bit cold, but with a warm coat we can still enjoy some time together outside.\n");
    } else if (temperature <= 20) {
        printf("The temperature is pleasant enough for a walk.\n");
    } else if (temperature <= 30) {
        printf("The weather is perfect for a romantic picnic, my love.\n");
    } else {
        printf("Oh my, it is scorching hot outside! Let us find some shade, my dear.\n");
    }
    
    printf("\nThe humidity today is %d%%.\n", humidity);
    if (humidity <= 30) {
        printf("The air is quite dry, perhaps a visit to the spa would do us some good?\n");
    } else if (humidity <= 60) {
        printf("The humidity is just right for a lovely stroll in the park.\n");
    } else {
        printf("It is quite humid outside today, let us stay indoors and sip on some cool iced tea.\n");
    }
    
    printf("\nThe wind speed today is %dkm/h.\n", wind_speed);
    if (wind_speed <= 20) {
        printf("The air is calm and still, just like our love.\n");
    } else if (wind_speed <= 50) {
        printf("The wind is picking up, but we can manage if we hold on tight.\n");
    } else {
        printf("Oh my, the wind is quite strong today! Let us find shelter before it blows us away.\n");
    }

    return 0;
}