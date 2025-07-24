//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    // Welcome message
    printf("Welcome to the Internet Speed Test!\n\n");

    // Ask the user to enter their download and upload speed
    float download_speed, upload_speed;
    printf("Please enter your download speed (in Mbps): ");
    scanf("%f", &download_speed);
    printf("Please enter your upload speed (in Mbps): ");
    scanf("%f", &upload_speed);

    // Display the user's input
    printf("\nYou entered %f Mbps for download speed and %f Mbps for upload speed.\n\n", download_speed, upload_speed);

    // Start the timer
    clock_t start_time = clock();

    // Generate random data to simulate download and upload
    char download_data[200000000], upload_data[10000000];

    // Calculate the time taken for download and upload
    float download_time = (float)strlen(download_data)/(download_speed/8);
    float upload_time = (float)strlen(upload_data)/(upload_speed/8);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the elapsed time
    float elapsed_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;

    // Display the results
    printf("Download speed: %f Mbps\n", download_speed);
    printf("Time taken to download: %f seconds\n", download_time);
    printf("Upload speed: %f Mbps\n", upload_speed);
    printf("Time taken to upload: %f seconds\n", upload_time);
    printf("Elapsed time: %f seconds\n", elapsed_time);

    // Exit message
    printf("\nThank you for using the Internet Speed Test!\n\n");

    return 0;
}