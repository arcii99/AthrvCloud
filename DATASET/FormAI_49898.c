//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>

#define MAX_LOCATIONS 10 // maximum number of locations a user can save
#define MAX_LOCATION_NAME_LENGTH 256 // maximum length of a location name
#define MAX_HISTORY 100 // maximum number of navigation history
#define MAX_HISTORY_ENTRY_LENGTH 512 // maximum length of a history entry

// structure to hold a location
typedef struct Location {
    char name[MAX_LOCATION_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

// structure to hold navigation history
typedef struct NavigationHistory {
    char entry[MAX_HISTORY_ENTRY_LENGTH];
} NavigationHistory;

// global variables
Location locations[MAX_LOCATIONS];
int numLocations = 0;
NavigationHistory navigationHistory[MAX_HISTORY];
int numHistoryEntries = 0;
int currentLocationIndex = -1;

// function to simulate GPS navigation from current location to destination
void* navigate(void* destination) {
    Location* dest = (Location*) destination;
    char instruction[256];
    sprintf(instruction, "Start navigation from current location to %s", dest->name);
    printf("%s\n", instruction);
    sleep(1);

    // simulate driving to the destination
    sprintf(instruction, "Drive to latitude %.6f, longitude %.6f", dest->latitude, dest->longitude);
    printf("%s\n", instruction);
    sleep(5);

    // simulate arrival at the destination
    sprintf(instruction, "Arrived at %s", dest->name);
    printf("%s\n", instruction);
    sleep(1);

    // add navigation history entry
    sprintf(navigationHistory[numHistoryEntries].entry, "Navigated from current location to %s", dest->name);
    numHistoryEntries++;

    // update current location index
    for (int i = 0; i < numLocations; i++) {
        if (strcmp(locations[i].name, dest->name) == 0) {
            currentLocationIndex = i;
            break;
        }
    }

    pthread_exit(NULL);
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // add some sample locations
    Location london;
    strcpy(london.name, "London");
    london.latitude = 51.507222;
    london.longitude = -0.127758;
    locations[numLocations++] = london;

    Location newyork;
    strcpy(newyork.name, "New York");
    newyork.latitude = 40.712776;
    newyork.longitude = -74.005974;
    locations[numLocations++] = newyork;

    Location paris;
    strcpy(paris.name, "Paris");
    paris.latitude = 48.856613;
    paris.longitude = 2.352222;
    locations[numLocations++] = paris;

    // simulate user selecting a location from saved locations
    int selectionIndex = rand() % numLocations;
    Location selectedLocation = locations[selectionIndex];
    printf("Selected location: %s\n", selectedLocation.name);

    // simulate navigation to selected location
    pthread_t navigationThread;
    pthread_create(&navigationThread, NULL, navigate, (void*) &selectedLocation);
    pthread_join(navigationThread, NULL);

    // print navigation history
    printf("Navigation history:\n");
    for (int i = 0; i < numHistoryEntries; i++) {
        printf("%d: %s\n", i+1, navigationHistory[i].entry);
    }

    return 0;
}