//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 100

// Function to get random coordinates
void getRandomCoordinates(double *latitude, double *longitude) {
    *latitude = (double)rand() / RAND_MAX * 90;
    *longitude = (double)rand() / RAND_MAX * 180;
}

int main() {
    srand(time(NULL)); // Set seed for random numbers
    
    double currentLatitude, currentLongitude, destinationLatitude, destinationLongitude;
    char input[LENGTH], command[LENGTH], address[LENGTH], city[LENGTH], state[LENGTH], zip[LENGTH];
    
    // Get starting coordinates
    getRandomCoordinates(&currentLatitude, &currentLongitude);
    printf("Starting coordinates: (%lf, %lf)\n", currentLatitude, currentLongitude);
    
    while (1) {
        printf("Enter command (\"sim\" to simulate location, \"nav\" to navigate to address, or \"exit\" to quit): ");
        fgets(input, LENGTH, stdin);
        sscanf(input, "%s", command);
        
        if (strcmp(command, "sim") == 0) {
            printf("Simulating location...\n");
            getRandomCoordinates(&currentLatitude, &currentLongitude);
            printf("Current coordinates: (%lf, %lf)\n", currentLatitude, currentLongitude);
        } else if (strcmp(command, "nav") == 0) {
            printf("Enter address: ");
            fgets(input, LENGTH, stdin);
            sscanf(input, "%[^\n]", address);
            printf("Enter city: ");
            fgets(input, LENGTH, stdin);
            sscanf(input, "%[^\n]", city);
            printf("Enter state: ");
            fgets(input, LENGTH, stdin);
            sscanf(input, "%[^\n]", state);
            printf("Enter zip code: ");
            fgets(input, LENGTH, stdin);
            sscanf(input, "%[^\n]", zip);
            printf("Navigating to %s, %s, %s %s...\n", address, city, state, zip);
            getRandomCoordinates(&destinationLatitude, &destinationLongitude);
            printf("Destination coordinates: (%lf, %lf)\n", destinationLatitude, destinationLongitude);
            
            // Calculate distance and duration of drive
            double distance = sqrt(pow(destinationLatitude - currentLatitude, 2) + pow(destinationLongitude - currentLongitude, 2));
            double speed = (double)rand() / RAND_MAX * 40 + 20; // Random speed between 20 and 60 mph
            double duration = distance / speed;
            printf("Distance: %lf miles\n", distance);
            printf("Average speed: %lf mph\n", speed);
            printf("Duration: %lf hours\n", duration);
            
            // Calculate expected arrival time
            time_t current_time;
            time(&current_time);
            struct tm *time_info = localtime(&current_time);
            char arrival_time[LENGTH];
            time_info->tm_hour += (int)duration;
            time_info->tm_min += (int)((duration - (int)duration) * 60);
            mktime(time_info);
            strftime(arrival_time, LENGTH, "%I:%M %p", time_info);
            printf("Expected arrival time: %s\n", arrival_time);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}