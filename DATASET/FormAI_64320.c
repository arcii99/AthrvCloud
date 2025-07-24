//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printSpeed(int speed) {
    printf("Your internet speed is %d Mbps.\n", speed);
    if (speed < 10) {
        printf("This is unacceptable! There must be something wrong with your connection.\n");
    } else if (speed >= 10 && speed < 50) {
        printf("This speed is decent, but you could do better. Try upgrading your plan.\n");
    } else if (speed >= 50 && speed < 100) {
        printf("This is a very good speed. You should have no problem streaming or downloading large files.\n");
    } else if (speed >= 100) {
        printf("Wow! You have lightning-fast internet. You can do pretty much anything you want with this speed.\n");
    }
}

int main() {
    int downloadSpeed, uploadSpeed;
    srand(time(NULL));
    downloadSpeed = rand() % 100 + 1;
    uploadSpeed = rand() % 100 + 1;
    printf("Welcome to the Sherlock Holmes Internet Speed Test Application!\n");
    printf("I am going to test your download and upload speeds now.\n");
    printf("Please wait while I gather the results...\n");
    printf("...");
    printf("...");
    printf("...\n");
    printf("Okay, got it! Your download speed is %d Mbps and your upload speed is %d Mbps.\n", downloadSpeed, uploadSpeed);
    printf("Based on these results, let me give you my analysis.\n");
    printSpeed(downloadSpeed);
    printSpeed(uploadSpeed);
    printf("Thank you for using the Sherlock Holmes Internet Speed Test Application!\n");
    return 0;
}