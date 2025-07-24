//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int downloadSpeed, uploadSpeed;
    srand(time(NULL));
    downloadSpeed = rand() % 100; // Random download speed between 0-99 Mbps
    uploadSpeed = rand() % 100; // Random upload speed between 0-99 Mbps
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Analyzing your internet speed...\n");
    printf("Your current download speed is %d Mbps.\n", downloadSpeed);
    printf("Your current upload speed is %d Mbps.\n", uploadSpeed);
    if (downloadSpeed >= 50 && uploadSpeed >= 50) {
        printf("Great news! Your internet connection is lightning fast!\n");
    } else if (downloadSpeed >= 20 && uploadSpeed >= 20) {
        printf("Your internet connection is decent, but could be faster. Consider upgrading your internet plan.\n");
    } else {
        printf("Uh oh, it looks like your internet connection is quite slow. You may want to contact your ISP to troubleshoot the issue.\n");
    }
    return 0;
}