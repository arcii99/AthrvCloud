//FormAI DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define TEMP_THRESHOLD 30  // Define the temperature threshold as 30 degrees Celsius

// Function to retrieve current Celsius temperature reading from sensor
float get_temperature_reading() {
    // Placeholder function that would actually retrieve the temperature reading from a temperature sensor
    float temp = (float)rand()/((float)RAND_MAX/100);  // Random temperature reading between 0-100 degrees Celsius
    return temp;
}

// Function to convert Celsius to Fahrenheit
float convert_to_fahrenheit(float celsius_temp) {
    float fahrenheit_temp = celsius_temp * 1.8 + 32.0;
    return fahrenheit_temp;
}

// Function to check if temperature reading exceeds threshold
int temperature_exceeds_threshold(float temp_reading) {
    if (temp_reading > TEMP_THRESHOLD) {
        return 1;  // Temperature exceeds threshold
    }
    else {
        return 0;  // Temperature within threshold
    }
}

// Main function
int main() {
    float celsius_temp;  // Variable to store Celsius temperature reading
    float fahrenheit_temp;  // Variable to store Fahrenheit temperature reading
    
    // Retrieve current temperature reading 
    celsius_temp = get_temperature_reading();  
    
    // Convert Celsius temperature to Fahrenheit
    fahrenheit_temp = convert_to_fahrenheit(celsius_temp); 
    
    // Display temperature readings
    printf("Current temperature: %.2f degrees Celsius / %.2f degrees Fahrenheit\n", celsius_temp, fahrenheit_temp);
    
    // Check if temperature reading exceeds threshold 
    if (temperature_exceeds_threshold(celsius_temp)) {
        printf("WARNING: Temperature has exceeded threshold of %d degrees Celsius\n", TEMP_THRESHOLD);
    }
    else {
        printf("Temperature within threshold\n");
    }
    
    return 0;
}