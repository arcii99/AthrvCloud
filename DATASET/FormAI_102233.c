//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); // Seed the random generator
    
    int downloadSpeed, uploadSpeed; // Variables to store speed values
    
    // Simulate download and upload speeds between 1 and 100 Mbps
    downloadSpeed = rand() % 100 + 1;
    uploadSpeed = rand() % 100 + 1;
    
    // Display download and upload speeds
    printf("Your download speed is %d Mbps\n", downloadSpeed);
    printf("Your upload speed is %d Mbps\n", uploadSpeed);
    
    return 0; // End program
}