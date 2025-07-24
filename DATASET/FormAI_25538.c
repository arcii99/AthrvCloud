//FormAI DATASET v1.0 Category: Temperature monitor ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    double current_temperature;
    time_t current_time;
    struct tm* time_info;
    char time_string[10];

    //Open file for logging temperature data
    FILE* fp = fopen("temperature_log.txt", "w");

    //Ensure file opened successfully
    if (fp == NULL) {
        printf("Error: File could not be opened.");
        return 1;
    }

    //Print header to log file
    fprintf(fp, "Temperature Log (in Celsius)\n\n");

    //Continuously monitor temperature
    while(1) {
        //Generate random temperature between -10 and 40 degrees Celsius
        current_temperature = ((double) rand() / (RAND_MAX)) * 50 - 10;
        //Get current time
        current_time = time(NULL);
        time_info = localtime(&current_time);
        //Format time string
        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
        //Print current temperature and time to console
        printf("Current temperature: %.2f degrees Celsius. Time: %s\n", current_temperature, time_string);
        //Write temperature and time info to log file
        fprintf(fp, "Temperature: %.2f Time: %s\n", current_temperature, time_string);
        //Sleep for a second before checking temperature again
        sleep(1);
    }
    return 0;
}