//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// define a structure for locations
struct location {
    char label[20];
    float latitude;
    float longitude;
};

// main function
int main() {
    // define sample locations
    struct location location1 = {"City Market", 42.5322, -83.1458};
    struct location location2 = {"Detroit Institute of Arts", 42.3594, -83.0669};
    struct location location3 = {"Fox Theatre", 42.3379, -83.0533};
    
    // print a welcome message
    printf("Welcome to the GPS navigation simulation!\n");
    
    // ask for user input
    char start[20];
    char end[20];
    printf("Enter your starting location: ");
    fgets(start, 20, stdin);
    printf("Enter your destination: ");
    fgets(end, 20, stdin);
    
    // remove new-line characters from input
    start[strcspn(start, "\n")] = '\0';
    end[strcspn(end, "\n")] = '\0';
    
    // check if input matches a known location and assign corresponding structure
    struct location start_location, end_location;
    bool start_found = false, end_found = false;
    if (strcmp(start, location1.label) == 0) {
        start_location = location1;
        start_found = true;
    } else if (strcmp(start, location2.label) == 0) {
        start_location = location2;
        start_found = true;
    } else if (strcmp(start, location3.label) == 0) {
        start_location = location3;
        start_found = true;
    }
    
    if (strcmp(end, location1.label) == 0) {
        end_location = location1;
        end_found = true;
    } else if (strcmp(end, location2.label) == 0) {
        end_location = location2;
        end_found = true;
    } else if (strcmp(end, location3.label) == 0) {
        end_location = location3;
        end_found = true;
    }
    
    // print error message if input doesn't match a known location
    if (!start_found) {
        printf("Starting location not found.\n");
        return 0;
    }
    if (!end_found) {
        printf("Destination not found.\n");
        return 0;
    }
    
    // calculate distance between locations using haversine formula
    float d_lat = end_location.latitude - start_location.latitude;
    float d_lon = end_location.longitude - start_location.longitude;
    float a = pow(sin(d_lat / 2), 2) + cos(start_location.latitude) * cos(end_location.latitude) * pow(sin(d_lon / 2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float distance = 3961 * c; //assign the value to variable distance
    
    // print results
    printf("You are travelling from %s to %s.\n", start_location.label, end_location.label);
    printf("The distance between them is %.2f miles.\n", distance);
    
    return 0;
}