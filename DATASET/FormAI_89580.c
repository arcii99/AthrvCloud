//FormAI DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int temperature = 0;
    int humidity = 0;
    int wind_speed = 0;
    int cloud_coverage = 0;
    int chance_of_storm = 0;

    printf("Welcome to the paranoid weather simulator.\n");
    printf("This program simulates weather conditions that can trigger your paranoia.\n");
    printf("Stay calm and let's get started.\n");

    while(1) {
        temperature = rand() % 60 - 10;
        humidity = rand() % 70 + 30;
        wind_speed = rand() % 51;
        cloud_coverage = rand() % 101;
        chance_of_storm = rand() % 11;

        if (temperature < 0) {
            printf("The temperature is below freezing at %d degrees Celsius. Don't leave the house unless you absolutely have to.\n", temperature);
        } else if (temperature >= 0 && temperature < 10) {
            printf("It's very cold outside at %d degrees Celsius. Make sure to wear a warm jacket and hat.\n", temperature);
        } else if (temperature >= 10 && temperature < 20) {
            printf("It's chilly outside at %d degrees Celsius. You might want to grab a light jacket.\n", temperature);
        } else if (temperature >= 20 && temperature < 30) {
            printf("It's a comfortable temperature outside at %d degrees Celsius.\n", temperature);
        } else if (temperature >= 30 && temperature < 40) {
            printf("It's quite hot outside at %d degrees Celsius. Make sure to drink plenty of water and try to stay inside during peak sun hours.\n", temperature);
        } else if (temperature >= 40) {
            printf("It's dangerously hot outside at %d degrees Celsius. Stay inside and use air conditioning if possible.\n", temperature);
        }

        if (humidity >= 90) {
            printf("The air is very humid. Stay inside and drink plenty of fluids.\n");
        } else if (humidity >= 70 && humidity < 90) {
            printf("The air is quite humid. Stay inside if possible.\n");
        }

        if (wind_speed > 40) {
            printf("The winds are quite strong. Avoid outdoor activities that involve heights or flying objects.\n");
        }

        if (cloud_coverage > 70 && humidity > 50) {
            printf("The sky is overcast and it might start raining soon. Don't forget your umbrella.\n");
        }

        if (chance_of_storm > 5) {
            printf("There's a chance of thunderstorms later today. Make sure to keep your electronics unplugged and stay away from tall objects.\n");
        }

        printf("\n");

        // Wait for one second before printing the next simulation
        // This is to make the program seem more realistic
        sleep(1);
    }

    return 0;
}