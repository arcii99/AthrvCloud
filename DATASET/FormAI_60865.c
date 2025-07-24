//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds) {
    // Converting time into ms
    int milli_seconds = 1000 * number_of_seconds;
    
    // Storing start time
    clock_t start_time = clock();
    
    // looping until required time is reached
    while (clock() < start_time + milli_seconds);
}

int main() {
    int speed, download_time, upload_time;
    float download_speed, upload_speed;

    printf("Welcome to the Internet Speed Test Application! \n");
    printf("Please enter the download speed in Mbps: ");
    scanf("%d", &speed);

    // Download Speed Test
    printf("Testing Download Speed...\n");
    delay(5000); // Wait for 5 seconds to simulate downloading of 50MB file.
    download_time = rand() % 10 + 1; // Random time taken to download in seconds.
    download_speed = (50 / download_time) * 8; // Speed in Mbps
    printf("Your Download Speed is: %.2f Mbps.\n\n", download_speed);

    // Upload Speed Test
    printf("Testing Upload Speed...\n");
    delay(5000); // Wait for 5 seconds to simulate uploading of 50MB file.
    upload_time = rand() % 10 + 1; // Random time taken to upload in seconds.
    upload_speed = (50 / upload_time) * 8; // Speed in Mbps
    printf("Your Upload Speed is: %.2f Mbps.\n", upload_speed);
    
    return 0;
}