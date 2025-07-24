//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\nWelcome to the C Internet Speed Test Application!\n");

    // Get the current time
    time_t start_time = time(NULL);
    
    // Simulate a 10 MB download
    int bytes_downloaded = 0;
    for (int i = 0; i < 10000000; i++) {
        bytes_downloaded++;
    }

    // Simulate a 5 MB upload
    int bytes_uploaded = 0;
    for (int i = 0; i < 5000000; i++) {
        bytes_uploaded++;
    }

    // Get the current time again
    time_t end_time = time(NULL);

    // Calculate the total time taken and the speed
    double total_time = difftime(end_time, start_time);
    double download_speed = bytes_downloaded / total_time;
    double upload_speed = bytes_uploaded / total_time;

    // Print out the results
    printf("\nDownload speed: %.2f MB/s\n", download_speed / (1024 * 1024));
    printf("\nUpload speed: %.2f MB/s\n", upload_speed / (1024 * 1024));

    return 0;
}