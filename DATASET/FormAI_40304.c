//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random number between 1 and 100
int generateRandomNumber() {
    srand(time(0));
    return (rand() % 100) + 1;
}

// Function to convert the speed from bytes/second to mbps
float convertToMbps(float bytesPerSecond) {
    return ((bytesPerSecond * 8) / 1000000);
}

int main() {
    float downloadSpeed = 0, uploadSpeed = 0;
    int downloadTime = 0, uploadTime = 0;
    int fileSize = 500; // 500 MB

    printf("\nWelcome to the Internet Speed Test Application\n");

    printf("\nTesting Download Speed...\n");
    clock_t startDownload = clock();
    FILE* downloadFile = fopen("exampleDownloadFile.txt", "w");
    int i;
    for (i = 0; i < fileSize; i++) {
        fprintf(downloadFile, "%d\n", generateRandomNumber());
    }
    fclose(downloadFile);
    downloadTime = clock() - startDownload;
    downloadSpeed = convertToMbps(fileSize / (float)downloadTime);

    printf("\nTesting Upload Speed...\n");
    clock_t startUpload = clock();
    FILE* uploadFile = fopen("exampleUploadFile.txt", "r");
    int readData, counter = 0;
    while (fscanf(uploadFile, "%d", &readData) == 1) {
        counter++;
    }
    fclose(uploadFile);
    uploadTime = clock() - startUpload;
    uploadSpeed = convertToMbps((counter * sizeof(int)) / (float)uploadTime);

    printf("\nDownload Speed: %.2f mbps", downloadSpeed);
    printf("\nUpload Speed: %.2f mbps\n", uploadSpeed);

    remove("exampleDownloadFile.txt");
    remove("exampleUploadFile.txt");

    return 0;
}