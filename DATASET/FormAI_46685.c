//FormAI DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMPERATURE -40
#define MAX_TEMPERATURE 50
#define MIN_HUMIDITY 0.0
#define MAX_HUMIDITY 100.0

float generate_random_float(float min, float max) {
    float random = (float) rand() / RAND_MAX;
    return min + random * (max - min);
}

int generate_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_weather(float temperature, float humidity, int wind_speed) {
    printf("Current temperature: %.1f C\n", temperature);
    printf("Current humidity: %.1f%%\n", humidity);
    printf("Current wind speed: %d km/h\n", wind_speed);
    printf("\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random temperature and humidity
    float temperature = generate_random_float(MIN_TEMPERATURE, MAX_TEMPERATURE);
    float humidity = generate_random_float(MIN_HUMIDITY, MAX_HUMIDITY);
    
    // Calculate the wind speed based on temperature and humidity
    int wind_speed = 0;
    if (temperature > 20 && humidity > 70) {
        wind_speed = generate_random_int(10, 30);
    } else if (temperature > 10 && humidity > 60) {
        wind_speed = generate_random_int(5, 20);
    } else if (temperature > 0 && humidity > 50) {
        wind_speed = generate_random_int(2, 10);
    } else {
        wind_speed = generate_random_int(0, 5);
    }
    
    // Print the current weather conditions
    printf("Today's weather:\n");
    print_weather(temperature, humidity, wind_speed);
    
    // Simulate weather changes over the next 3 days
    for (int day = 1; day <= 3; day++) {
        printf("Day %d's weather:\n", day);
        
        // Randomly adjust the temperature and humidity
        float temperature_change = generate_random_float(-5.0, 5.0);
        float humidity_change = generate_random_float(-10.0, 10.0);
        temperature += temperature_change;
        humidity += humidity_change;
        
        // Calculate the wind speed based on temperature and humidity
        if (temperature > 20 && humidity > 70) {
            wind_speed = generate_random_int(10, 30);
        } else if (temperature > 10 && humidity > 60) {
            wind_speed = generate_random_int(5, 20);
        } else if (temperature > 0 && humidity > 50) {
            wind_speed = generate_random_int(2, 10);
        } else {
            wind_speed = generate_random_int(0, 5);
        }
        
        // Print the current weather conditions
        print_weather(temperature, humidity, wind_speed);
    }
    
    return 0;
}