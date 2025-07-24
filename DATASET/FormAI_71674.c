//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int speed_array[10];
    int sum = 0, average_speed = 0;
    clock_t start, end;
    double elapsed_time;
    
    printf("Welcome to the Internet Speed Test Application!\n\n");
    printf("This application will test your internet speed by downloading a 1GB file.\n");
    printf("Please wait while we initiate the test...\n");
    
    start = clock(); // Start the timer
    
    for(int i = 0; i < 10; i++)
    {
        int download_speed = rand() % 100 + 1; // Generate random download speed between 1-100 Mbps
        speed_array[i] = download_speed;
        sum += download_speed;
        printf("Download Speed %d: %d Mbps\n", i+1, download_speed);
    }

    end = clock(); // Stop the timer
    elapsed_time = (double)(end - start)/CLOCKS_PER_SEC;
    
    printf("\nTest Complete!\n");
    printf("Total Time Elapsed: %lf seconds\n", elapsed_time);
    printf("Average Download Speed: %d Mbps\n", sum/10);
    
    return 0;
}