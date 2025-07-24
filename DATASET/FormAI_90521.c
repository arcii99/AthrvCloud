//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function to calculate Internet speed in MB/s */
double calculateSpeed(double fileSize, double totalTime) {
    return fileSize / totalTime;
}

int main() {
    double fileSize; // Size of file to be downloaded
    double totalTime; // Total time taken to download the file
    double speed; // Internet speed in MB/s

    printf("Enter size of file in MB: ");
    scanf("%lf", &fileSize);
    
    printf("Enter total time taken to download file in seconds: ");
    scanf("%lf", &totalTime);

    speed = calculateSpeed(fileSize, totalTime);

    printf("Your Internet speed is: %.2f MB/s\n", speed);

    return 0;
}