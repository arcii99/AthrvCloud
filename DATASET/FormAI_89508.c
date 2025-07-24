//FormAI DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_THRESHOLD 25.0    //Temperature threshold set to 25 Degree Celsius
#define TEMP_SENSOR_MIN 10.0    //Minimum temperature reading of the sensor
#define TEMP_SENSOR_MAX 40.0    //Maximum temperature reading of the sensor

/*
 * A structure defining the temperature and timestamp
 */
typedef struct{
    float temperature;
    time_t timestamp;
} Temperature;

/*
 * Generate random Temperature readings between the specified range
 */
float generateRandomTemperature(){
    return (float)rand()/(float)(RAND_MAX/((TEMP_SENSOR_MAX-TEMP_SENSOR_MIN)))+TEMP_SENSOR_MIN;
}

/*
 * A method to get the current timestamp in seconds
 */
time_t getCurrentTimestamp(){
    return time(NULL);
}

/*
 * A method to compare the two temperature readings and return the higher one
 */
float getHigherTemperature(float temp1, float temp2){
    if(temp1 > temp2)
        return temp1;
    else
        return temp2;
}

/*
 * Main Program
 */
int main() {
    printf("Welcome to the Temperature Monitor Program!\n\n");

    Temperature currentTemp = {0.0, 0};   //Initialise the current and previous temperature readings with default values
    Temperature previousTemp = {0.0, 0};
    float temp = 0.0;

    while(1){
        // Simulate reading temperature from a sensor
        temp = generateRandomTemperature();
        currentTemp.temperature = temp;
        currentTemp.timestamp = getCurrentTimestamp();

        // Display the current temperature reading
        printf("Current Temperature Reading is: %.2f\n", currentTemp.temperature);

        // Check if the temperature has crossed the threshold value
        if(currentTemp.temperature > TEMP_THRESHOLD){
            printf("WARNING!! Temperature has crossed the threshold value of %.2f\n", TEMP_THRESHOLD);
        }

        // Check if the current temperature is higher or lower than the previous temperature
        if(currentTemp.temperature > previousTemp.temperature){
            printf("Current Temperature Reading is HIGHER than the Previous Temperature Reading\n");
        } else if(currentTemp.temperature < previousTemp.temperature){
            printf("Current Temperature Reading is LOWER than the Previous Temperature Reading\n");
        } else{
            printf("Current Temperature Reading is SAME as the Previous Temperature Reading\n");
        }

        //Update the previous temperature with the current temperature
        previousTemp = currentTemp;

        //Wait for 5 seconds before reading temperature again
        sleep(5);
    }

    return 0;
}