//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum internet speed in Mbps
#define MAX_SPEED 1000
// Define the time interval between speed tests in seconds
#define TIME_INTERVAL 3600

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    while (1) { // Run the test continuously
        int speed = rand() % (MAX_SPEED + 1); // Generate a random speed between 0 and MAX_SPEED
        
        printf("Your internet speed is: %d Mbps\n", speed);
        printf("Press any key to run the test again in %d seconds\n", TIME_INTERVAL);
        
        fflush(stdin); // Clear the input buffer
        getchar(); // Wait for user input
        
        system("clear"); // Clear the console screen
    }
    
    return 0;
}