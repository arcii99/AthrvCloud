//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <time.h> 

int main() { 
    printf("Welcome to Ken Thompson's Internet Speed Test Application!\n"); 

    // Initialize variables for time taken and file size
    double time_taken, file_size = 500.0; 

    // Record start time
    clock_t t = clock(); 

    // Simulate download of file
    for (int i = 0; i < file_size*1024*1024; i++) { 
        // Simulate download speed of 1Mbps
        for (int j = 0; j < 12500; j++) { } 
    } 

    // Record end time
    t = clock() - t; 

    // Calculate time taken in seconds
    time_taken = ((double)t)/CLOCKS_PER_SEC; 

    // Calculate download speed
    double download_speed = (file_size/time_taken)/1000000; 

    printf("Download speed: %.2f Mbps\n", download_speed); 
    printf("Thank you for using Ken Thompson's Internet Speed Test Application!"); 

    return 0; 
}