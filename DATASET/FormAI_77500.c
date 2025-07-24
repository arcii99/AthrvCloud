//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random number generator with current time
    int temperature = rand() % 101 - 50; // Generate random temperature between -50 and 50
    float humidity = ((float) rand() / (RAND_MAX)) * 100; // Generate random humidity between 0 and 100
    int windspeed = rand() % 76; // Generate random windspeed between 0 and 75
    int winddirection = rand() % 361; // Generate random wind direction between 0 and 360 degrees
    int cloudy = rand() % 101; // Generate random cloudiness percentage between 0 and 100
    
    // Print weather report
    printf("Today's weather:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %.2f%%\n", humidity);
    printf("Wind: %d km/h from %d degrees\n", windspeed, winddirection);
    printf("Cloudiness: %d%%\n", cloudy);
    
    // Determine weather conditions based on generated values
    if (temperature <= 0) {
        printf("It's freezing outside, make sure to dress warmly!\n");
    } else if (temperature <= 10) {
        printf("It's quite cold outside, don't forget a coat!\n");
    } else if (temperature <= 20) {
        printf("It's a bit chilly outside, a sweater might be nice.\n");
    } else if (temperature <= 25) {
        printf("It's a pleasant temperature outside, enjoy your day!\n");
    } else if (temperature <= 30) {
        printf("It's quite warm outside, make sure to stay hydrated!\n");
    } else {
        printf("It's hot outside, stay in the shade if possible.\n");
    }
    
    if (humidity >= 80) {
        printf("It's very humid outside, take it slow and stay hydrated.\n");
    } else if (humidity >= 60) {
        printf("It's a bit humid outside, don't forget to drink water!\n");
    } else {
        printf("Humidity levels are low today, enjoy the crisp air.\n");
    }
    
    if (windspeed <= 5) {
        printf("The wind is calm today, perfect weather for a picnic!\n");
    } else if (windspeed <= 30) {
        printf("It's a bit breezy outside, hang on to your hats!\n");
    } else {
        printf("The wind is really picking up, be careful when driving.\n");
    }
    
    if (cloudy <= 30) {
        printf("It's a sunny day, go outside and soak up the rays!\n");
    } else if (cloudy <= 70) {
        printf("It's partly cloudy, a beautiful day to be outside.\n");
    } else {
        printf("It's a cloudy day today, but the weather is still perfect for a walk.\n");
    }
    
    return 0; // End program
}