//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateDownloadSpeed(double fileSize, double downloadTime);
double calculateUploadSpeed(double fileSize, double uploadTime);

int main()
{
    double fileSize = 50;  // in MB
    double downloadTime, uploadTime;
    printf("Welcome to the Internet Speed Test Application\n");
    printf("Please wait while we measure your download and upload speeds\n");
    printf("Downloading a %0.2f MB test file...\n", fileSize);

    // Simulating download time
    srand(time(NULL));
    downloadTime = rand() % 20 + 1; // in seconds
    printf("Your download speed is: %0.2f Mbps\n", calculateDownloadSpeed(fileSize, downloadTime));

    printf("Uploading the test file...\n");

    // Simulating upload time
    uploadTime = rand() % 20 + 1; // in seconds
    printf("Your upload speed is: %0.2f Mbps\n", calculateUploadSpeed(fileSize, uploadTime));

    printf("Thank you for using this application!\n");
    return 0;
}

double calculateDownloadSpeed(double fileSize, double downloadTime)
{
    double speed = (fileSize / (downloadTime * 1024 * 1024)) * 8; // in Mbps
    return speed;
}

double calculateUploadSpeed(double fileSize, double uploadTime)
{
    double speed = (fileSize / (uploadTime * 1024 * 1024)) * 8; // in Mbps
    return speed;
}