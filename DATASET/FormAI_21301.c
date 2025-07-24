//FormAI DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random float between min and max values
float generate_random_float(float min_value, float max_value) {
    float random_val = ((float) rand() / RAND_MAX) * (max_value - min_value) + min_value;
    return random_val;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define variables to store weather parameters
    float temperature, humidity, wind_speed, wind_direction;
    int uv_index;

    // Generate random values for weather parameters
    temperature = generate_random_float(20.0f, 35.0f); // Temperature in degrees Celsius
    humidity = generate_random_float(40.0f, 80.0f); // Relative humidity percentage
    wind_speed = generate_random_float(0.0f, 30.0f); // Wind speed in kilometers per hour
    wind_direction = generate_random_float(0.0f, 360.0f); // Wind direction in degrees
    uv_index = (int) generate_random_float(0.0f, 10.0f); // UV index on a scale of 0 to 10

    // Output weather information to console
    printf("Current Weather Conditions:\n");
    printf("- Temperature: %.1f degrees Celsius\n", temperature);
    printf("- Humidity: %.1f%%\n", humidity);
    printf("- Wind Speed: %.1f km/h\n", wind_speed);
    printf("- Wind Direction: %.1f degrees\n", wind_direction);
    printf("- UV Index: %d\n", uv_index);

    // Determine weather conditions based on parameters
    if (temperature > 30.0f) {
        printf("It's hot outside, make sure to stay hydrated!\n");
    }
    if (humidity > 60.0f) {
        printf("It's quite humid today, be prepared to sweat.\n");
    }
    if (wind_speed > 20.0f) {
        printf("It's windy outside, be careful of flying debris.\n");
    }
    if (uv_index >= 8) {
        printf("The UV index is high, make sure to wear sunscreen and seek shade.\n");
    }
    
    return 0;
}