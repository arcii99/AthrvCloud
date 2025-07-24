//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to measure internet speed
float testInternetSpeed(int size, int time) {
    // Get current time
    clock_t start_time = clock();
    
    // Create buffer of given size
    char* buffer = (char*) malloc(size * sizeof(char));
    
    // Try to download buffer for given time
    while (clock() - start_time < time * CLOCKS_PER_SEC) {
        // Simulate downloading data by writing zeros to buffer
        for (int i = 0; i < size; i++) {
            buffer[i] = '0';
        }
    }
    
    // Calculate time elapsed and number of bytes downloaded
    float elapsed_time = (float) (clock() - start_time) / CLOCKS_PER_SEC;
    float bytes_downloaded = elapsed_time * size;
    
    // Calculate speed in bytes per second and convert it to megabits
    float speed = bytes_downloaded / elapsed_time / 125000;
    
    // Free allocated memory
    free(buffer);
    
    // Return speed in Mbps
    return speed;
}

int main() {
    // Define buffer size and test time
    int size = 100000000; // 100 MB
    int time = 10; // 10 seconds
    
    // Call the internet speed test function
    float speed = testInternetSpeed(size, time);
    
    // Print the result
    printf("Your internet speed is %.2f Mbps\n", speed);
    
    return 0;
}