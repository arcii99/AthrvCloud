//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
 
int main() {
    srand(time(NULL)); // Initializing the random number generator
    
    // Creating 2D arrays to store the baggage information
    int baggage_time[MAX][2];
    int baggage_location[MAX][2];
    int sorted_time[MAX][2];
    int sorted_location[MAX][2];
    int loading_time[MAX][2];
 
    // Inputting the baggage information and calculating the sort time
    for (int i = 0; i < MAX; i++) {
        baggage_time[i][0] = i + 1; // Assigning a unique ID to each baggage
        baggage_time[i][1] = rand() % 100; // Generating a random baggage arrival time
        baggage_location[i][0] = i + 1;
        baggage_location[i][1] = rand() % 20; // Generating a random baggage location
        sorted_time[i][0] = baggage_time[i][0];
        sorted_time[i][1] = baggage_time[i][1] + rand() % 60; // Calculating the sort time
        sorted_location[i][0] = baggage_location[i][0];
        sorted_location[i][1] = baggage_location[i][1] + rand() % 5; // Simulating the sorting area
 
        if (sorted_time[i][1] - baggage_time[i][1] > 10) { // If sort time is more than 10, loading time increases
            loading_time[i][0] = sorted_time[i][0];
            loading_time[i][1] = sorted_location[i][1] + rand() % 10;
        } else { 
            loading_time[i][0] = sorted_time[i][0];
            loading_time[i][1] = sorted_location[i][1] + rand() % 5;
        }
    }

    // Displaying the obtained data
    printf("Baggage ID\tArrival Time\tLocation\tSort Time\tLoading Time\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", baggage_time[i][0], baggage_time[i][1], baggage_location[i][1], sorted_time[i][1], loading_time[i][1]);
    }
    return 0; 
}