//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DOWNLOAD_SPEED 1024*1024 // Download speed in bytes per second
#define UPLOAD_SPEED 512*1024 // Upload speed in bytes per second
#define FILE_SIZE 50*1024 // File size in kilobytes

double downloadTime(double fileSize, double downloadSpeed) {
    return (fileSize*1024)/downloadSpeed;
}

double uploadTime(double fileSize, double uploadSpeed) {
    return (fileSize*1024)/uploadSpeed;
}

int main() {
    srand(time(NULL)); // Seed for rand() function
    double downloadSpeed = rand() % DOWNLOAD_SPEED + 1; // Download speed randomly generated
    double uploadSpeed = rand() % UPLOAD_SPEED + 1; // Upload speed randomly generated
    double fileSize = FILE_SIZE; // File size in kilobytes fixed at 50 KB
    
    printf("Welcome to the Internet Speed Test Application\n\n");
    printf("Testing download speed...\n");
    usleep(1000000); // Simulating download time delay
    printf("Download speed: %.2f bytes per second\n\n", downloadSpeed);
    printf("Testing upload speed...\n");
    usleep(1000000); // Simulating upload time delay
    printf("Upload speed: %.2f bytes per second\n\n", uploadSpeed);
    printf("Calculating download time for a %d KB file...\n", (int)fileSize);
    usleep(1000000); // Simulating download time delay
    printf("Download time: %.2f seconds\n\n", downloadTime(fileSize, downloadSpeed));
    printf("Calculating upload time for a %d KB file...\n", (int)fileSize);
    usleep(1000000); // Simulating upload time delay
    printf("Upload time: %.2f seconds\n\n", uploadTime(fileSize, uploadSpeed));
    return 0;
}