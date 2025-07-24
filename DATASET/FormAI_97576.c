//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX_DOWNLOAD_SPEED 1000 // Maximum download speed in Mbps
#define MAX_UPLOAD_SPEED 100 // Maximum upload speed in Mbps
#define BUFFER_SIZE 1024 // Buffer size for downloading/uploading data

void download_speed_test() {
    printf("Starting download speed test...\n");
    float speed = (float) (rand() % MAX_DOWNLOAD_SPEED) + ((float) rand() / RAND_MAX);
    printf("Download speed: %.2f Mbps\n", speed);
}

void upload_speed_test() {
    printf("Starting upload speed test...\n");
    float speed = (float) (rand() % MAX_UPLOAD_SPEED) + ((float) rand() / RAND_MAX);
    printf("Upload speed: %.2f Mbps\n", speed);
}

int main() {
    char input[10];
    srand(time(NULL)); // Seed the random number generator
    
    while (1) {
        printf("Enter 'download' for download speed test, 'upload' for upload speed test, or 'exit' to quit: ");
        fgets(input, 10, stdin); // Get user's choice
        
        if (strcmp(input, "download\n") == 0) {
            download_speed_test();
        }
        else if (strcmp(input, "upload\n") == 0) {
            upload_speed_test();
        }
        else if (strcmp(input, "exit\n") == 0) {
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    printf("Thanks for using our internet speed test!\n");
    
    return 0;
}