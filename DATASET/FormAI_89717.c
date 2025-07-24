//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>

// function to calculate brightness level based on time and weather
int calculateBrightness(int time, int weather) {
    int brightness = 0;
    if (time < 7 || time > 20) { // night time, low brightness
        brightness = 5;
    } else {
        brightness = time - 6; // increase brightness from 6am to 8pm
    }
    if (weather == 1) { // cloudy day, reduce brightness by 2
        brightness = brightness - 2;
    } else if (weather == 2) { // rainy day, reduce brightness by 4
        brightness = brightness - 4;
    }
    if (brightness < 0) { // minimum brightness should be 0
        brightness = 0;
    }
    return brightness;
}

int main() {
    int time, weather, brightness;
    printf("Enter current time (0-23): ");
    scanf("%d", &time);
    printf("Enter weather conditions (0-sunny, 1-cloudy, 2-rainy): ");
    scanf("%d", &weather);
    brightness = calculateBrightness(time, weather);
    printf("The recommended brightness level for your smart home lights is %d.\n", brightness);
    return 0;
}