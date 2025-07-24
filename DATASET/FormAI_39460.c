//FormAI DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to generate random temperature
float get_temperature(){
    float min_temp = 30.0, max_temp = 45.0;
    return (rand() / (float)RAND_MAX) * (max_temp - min_temp) + min_temp;
}

int main(){
    float current_temp = 0.0, temp_sum = 0.0;
    int temp_count = 0, high_count = 0, low_count = 0;

    // Set the number of temperature readings to take
    int num_readings = 10;

    // Take temperature readings
    for (int i = 1; i <= num_readings; i++){
        current_temp = get_temperature();
        temp_sum += current_temp;

        // Check if temperature is high or low
        if (current_temp > 40.0){
            high_count++;
        } else if (current_temp < 35.0){
            low_count++;
        }

        // Display current temperature reading
        printf("Reading %d:\t%.1f°C\n", i, current_temp);
    }

    // Calculate average temperature
    float average_temp = temp_sum / num_readings;

    // Display results
    printf("\n");
    printf("Total readings:\t%d\n", num_readings);
    printf("High readings:\t%d\n", high_count);
    printf("Low readings:\t%d\n", low_count);
    printf("Average temp:\t%.1f°C\n", average_temp);

    return 0;
}