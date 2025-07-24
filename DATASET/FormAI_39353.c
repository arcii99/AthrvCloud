//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void downloadSpeedTest() {
    int fileSize = 100; // in megabytes
    int downloadSpeed = -1; // in megabits per second
    clock_t start, end;
    double elapsedTime;

    printf("Starting download of %d MB file...\n", fileSize);

    // simulate download by waiting for certain amount of time
    start = clock();
    while (downloadSpeed == -1) {
        for (int i = 1; i <= fileSize*10; i++) {
            for (int j = 1; j <= 1000000; j++);
        }
        end = clock();
        elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC; // in seconds
        downloadSpeed = (double) fileSize*8 / elapsedTime; // convert to megabits per second
    }

    printf("Download complete!\n");
    printf("Your download speed is %.2f Mbps.\n", (double) downloadSpeed);
}

void uploadSpeedTest() {
    int fileSize = 10; // in megabytes
    int uploadSpeed = -1; // in megabits per second
    clock_t start, end;
    double elapsedTime;

    printf("Starting upload of %d MB file...\n", fileSize);

    // simulate upload by waiting for certain amount of time
    start = clock();
    while (uploadSpeed == -1) {
        for (int i = 1; i <= fileSize*10; i++) {
            for (int j = 1; j <= 1000000; j++);
        }
        end = clock();
        elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC; // in seconds
        uploadSpeed = (double) fileSize*8 / elapsedTime; // convert to megabits per second
    }

    printf("Upload complete!\n");
    printf("Your upload speed is %.2f Mbps.\n", (double) uploadSpeed);
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This program will test your internet speed by downloading and uploading files.\n");

    // run download and upload speed tests
    downloadSpeedTest();
    printf("\n");
    uploadSpeedTest();

    return 0;
}