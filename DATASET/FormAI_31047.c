//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 100

int current_location = 0; //initialize current location to be 0
int destination = 0; //initialize destination to be 0

struct location {
    int id;
    char name[50];
    float latitude;
    float longitude;
};

struct location locations[MAX_SIZE]; //location array to hold all the locations
int num_locations = 0; //total number of locations

//function to calculate distance between two locations
double calculate_distance(float lat1, float lon1, float lat2, float lon2) {
    float dlat = (lat2 - lat1) * M_PI / 180.0;
    float dlon = (lon2 - lon1) * M_PI / 180.0;
    float a = (sin(dlat / 2) * sin(dlat / 2)) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * (sin(dlon / 2) * sin(dlon / 2));
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c;
    return distance;
}

//function to add a new location
void add_location(char *name, float lat, float lon) {
    num_locations++;
    locations[num_locations].id = num_locations;
    strcpy(locations[num_locations].name, name);
    locations[num_locations].latitude = lat;
    locations[num_locations].longitude = lon;
}

//function to display all the locations
void display_locations() {
    printf("\nID\tName\t\t\tLatitude\tLongitude\n");
    printf("-------------------------------------------------------\n");
    for (int i = 1; i <= num_locations; i++) {
        printf("%d\t%s\t\t\t%.2f\t\t%.2f\n", locations[i].id, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

//function to find the nearest location from the current location
int find_nearest_location() {
    int nearest_location = 0;
    double min_distance = INFINITY;
    for (int i = 1; i <= num_locations; i++) {
        double distance = calculate_distance(locations[current_location].latitude, locations[current_location].longitude, locations[i].latitude, locations[i].longitude);
        if (i != current_location && distance < min_distance) {
            min_distance = distance;
            nearest_location = i;
        }
    }
    return nearest_location;
}

//function to navigate to a location
void navigate(int destination) {
    int nearest_location = find_nearest_location();
    printf("\nNavigating from %s to %s...\n", locations[current_location].name, locations[destination].name);
    printf("Starting from nearest location - %s\n", locations[nearest_location].name);
    double distance1 = calculate_distance(locations[current_location].latitude, locations[current_location].longitude, locations[nearest_location].latitude, locations[nearest_location].longitude);
    printf("Travelling %.2f KMs to reach %s\n", distance1, locations[nearest_location].name);
    double distance2 = calculate_distance(locations[nearest_location].latitude, locations[nearest_location].longitude, locations[destination].latitude, locations[destination].longitude);
    printf("Travelling %.2f KMs to reach %s\n", distance2, locations[destination].name);
    printf("Arrived at %s\n", locations[destination].name);
    current_location = destination;
}

int main() {
    //Adding locations
    add_location("Delhi", 28.7041, 77.1025);
    add_location("Mumbai", 19.0760, 72.8777);
    add_location("Kolkata", 22.5726, 88.3639);
    add_location("Chennai", 13.0827, 80.2707);
    add_location("Bangalore", 12.9716, 77.5946);
    add_location("Hyderabad", 17.3850, 78.4867);

    //Displaying all locations
    display_locations();

    //Choosing current location
    printf("\nEnter your current location ID: ");
    scanf("%d", &current_location);

    //Choosing destination
    printf("\nEnter your destination ID: ");
    scanf("%d", &destination);

    while (destination <= 0 || destination > num_locations) {
        printf("\nInvalid destination ID. Try again.\n");
        printf("\nEnter your destination ID: ");
        scanf("%d", &destination);
    }

    //start navigation
    navigate(destination);

    return 0;
}