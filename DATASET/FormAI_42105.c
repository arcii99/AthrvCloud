//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define THRESHOLD 1000 // Define the threshold for the number of API calls within a second
#define MAX_API_CALLS 2000 // Define a maximum number of API calls that can be made within a second
#define TIMEOUT 10 // Define the timeout in seconds after which the system resets

int main() {
    int count = 0; // Initialize the count variable
    time_t start = time(NULL); // Initialize the start time
    
    while(true) {
        time_t current_time = time(NULL); // Get the current time
        double elapsed_time = difftime(current_time, start); // Calculate the elapsed time since the start time
        
        if(elapsed_time >= TIMEOUT) { // Check if the timeout has exceeded
            printf("\nTimeout exceeded! System reset.\n");
            count = 0; // Reset the count variable
            start = time(NULL); // Reset the start time
        }
        
        int api_calls = rand() % MAX_API_CALLS; // Generate a random number of API calls
        
        if(api_calls > THRESHOLD) { // Check if the API call threshold has been exceeded
            count += api_calls; // Increment the count variable
            if(count > THRESHOLD) { // Check if the count variable has exceeded the threshold
                printf("\nIntrusion detected! Number of API calls within a second: %d\n", count);
                count = 0; // Reset the count variable
                start = time(NULL); // Reset the start time
            }
        }
    }
    
    return 0;
}