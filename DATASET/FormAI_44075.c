//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temperature, max_temp = -273.15, min_temp = 1000.00, avg_temp = 0.00;
    int num_readings, i;

    //Ask for the number of readings
    printf("Enter the number of temperature readings: ");
    scanf("%d", &num_readings);

    //Loop through the readings
    for(i = 1; i <= num_readings; i++) {
        printf("Enter temperature reading #%d: ", i);
        scanf("%f", &temperature);

        //Validate temperature readings
        if(temperature < -273.15) {
            printf("Invalid temperature reading! Below absolute zero.\n");

            //Decrement index counter to repeat current reading
            --i;
            continue;
        }

        //Calculate maximum temperature
        if(temperature > max_temp)
            max_temp = temperature;

        //Calculate minimum temperature
        if(temperature < min_temp)
            min_temp = temperature;

        //Calculate average temperature
        avg_temp += temperature;
    }

    //Calculate and display average temperature
    avg_temp /= num_readings;
    printf("Average temperature: %.2f\n", avg_temp);

    //Display maximum temperature
    printf("Maximum temperature: %.2f\n", max_temp);

    //Display minimum temperature
    printf("Minimum temperature: %.2f\n", min_temp);

    return 0;
}