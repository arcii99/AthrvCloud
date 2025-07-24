//FormAI DATASET v1.0 Category: Weather simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = rand() % 101; // generate random temperature between 0 and 100
    int wind_speed = rand() % 51; // generate random wind speed between 0 and 50
    int precipitation = rand() % 101; // generate random precipitation between 0 and 100

    printf("Today's weather simulation:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Precipitation: %d%%\n", precipitation);

    if (temperature < 0) {
        printf("It's freezing outside. Stay warm!.\n");
    } else if (temperature < 10) {
        printf("It's very cold outside. Dress warmly.\n");
    } else if (temperature < 20) {
        printf("It's fairly cold outside. You might need a jacket.\n");
    } else if (temperature < 30) {
        printf("It's warm outside. Enjoy the weather!\n");
    } else if (temperature < 40) {
        printf("It's hot outside. Stay hydrated!\n");
    } else {
        printf("It's very hot outside. Stay cool and avoid the sun if possible.\n");
    }

    if (wind_speed < 10) {
        printf("It's calm outside. The wind won't be an issue.\n");
    } else if (wind_speed < 30) {
        printf("It's windy outside. Hold on to your hats!\n");
    } else {
        printf("It's very windy outside. Be careful and stay away from tall structures.\n");
    }

    if (precipitation < 30) {
        printf("There's hardly any rain today. You won't need an umbrella.\n");
    } else if (precipitation < 60) {
        printf("It may rain today. Don't forget your umbrella!\n");
    } else {
        printf("It's going to rain heavily today. Better stay indoors and avoid getting wet.\n");
    }

    return 0;
}