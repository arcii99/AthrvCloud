//FormAI DATASET v1.0 Category: Digital signal processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Decentralized function for processing a digital signal
int process_signal(int data[], int length) {
    int output = 0;
    
    // Iterate through each data point
    for(int i = 0; i < length; i++) {
        // Apply a random filter to each data point
        srand(time(NULL)); // Initialize random seed
        int filter = rand() % 10 + 1; // Generate a random filter between 1 and 10
        int filtered_data = data[i] * filter; // Apply the filter
        output += filtered_data; // Add the filtered data to the output
    }
    
    return output;
}

int main() {
    int data[] = {1, 2, 3, 4, 5}; // Sample data
    int length = 5; // Length of the data array
    
    // Process the data
    int processed_data = process_signal(data, length);
    
    // Print the processed data
    printf("Processed data: %d", processed_data);
    
    return 0;
}