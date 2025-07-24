//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Happy Internet Speed Test!\n");

    srand(time(NULL));

    int download_speed = rand() % 101; // generate random download speed from 0 to 100 Mbps
    int upload_speed = rand() % 101; // generate random upload speed from 0 to 100 Mbps
    int ping = rand() % 200 + 1; // generate random ping from 1 to 200 ms

    printf("Your download speed is %d Mbps.\n", download_speed);
    printf("Your upload speed is %d Mbps.\n", upload_speed);
    printf("Your ping is %d ms.\n", ping);

    if (download_speed >= 50 && upload_speed >= 50 && ping <= 50) {
        printf("Great news! Your internet speed is amazing! You can stream, game, and download with ease.\n");
    } else if (download_speed >= 25 && upload_speed >= 25 && ping <= 100) {
        printf("Your internet speed is good enough for most activities, but you may lag in some online games.\n");
    } else if (download_speed >= 10 && upload_speed >= 10 && ping <= 150) {
        printf("Your internet speed is decent, but you may experience buffering when streaming HD videos.\n");
    } else {
        printf("Unfortunately, your internet speed is too slow for most activities. Please contact your service provider.\n");
    }

    printf("Thank you for using the Happy Internet Speed Test! Have a wonderful day.\n");

    return 0;
}