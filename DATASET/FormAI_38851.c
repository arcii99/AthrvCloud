//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize seed for random number generator
    int downloadSpeed = rand() % 101; // generate random download speed between 0 and 100
    int uploadSpeed = rand() % 101; // generate random upload speed between 0 and 100
    int pingTime = rand() % 201; // generate random ping time between 0 and 200

    printf("WELCOME TO THE POST-APOCALYPTIC INTERNET SPEED TEST\n\n");
    printf("Measuring download speed... \n");
    printf("Your download speed is %d Mbps.\n", downloadSpeed);
    printf("Measuring upload speed... \n");
    printf("Your upload speed is %d Mbps.\n", uploadSpeed);
    printf("Measuring ping time... \n");
    printf("Your ping time is %d ms.\n", pingTime);

    printf("\n\nWOULD YOU LIKE TO COMPARE YOUR SPEEDS TO YOUR NEIGHBORS?\n");
    printf("ENTER 'Y' FOR YES OR 'N' FOR NO: ");

    char input = getchar(); // get user input
    if(input == 'y' || input == 'Y') {
        int neighborDownload = rand() % 101; // generate random neighbor download speed between 0 and 100
        int neighborUpload = rand() % 101; // generate random neighbor upload speed between 0 and 100
        int neighborPing = rand() % 201; // generate random neighbor ping time between 0 and 200

        printf("\n\nYOUR NEIGHBOR'S INTERNET SPEEDS ARE:\n");
        printf("Download speed: %d Mbps\n", neighborDownload);
        printf("Upload speed: %d Mbps\n", neighborUpload);
        printf("Ping time: %d ms\n", neighborPing);

        if(downloadSpeed > neighborDownload && uploadSpeed > neighborUpload && pingTime < neighborPing) {
            printf("\n\nYOUR SPEEDS ARE FASTER THAN YOUR NEIGHBOR'S!\n\n");
        } else {
            printf("\n\nYOU SHOULD CONSIDER TRADING WITH YOUR NEIGHBOR!\n\n");
        }
    } else {
        printf("THANK YOU FOR USING THE POST-APOCALYPTIC INTERNET SPEED TEST!\n\n");
    }

    return 0;
}