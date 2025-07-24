//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Using current time as seed for random number generator

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Your connection will now be analyzed in a medieval style.\n");

    int download_speed = rand() % 500 + 1; // Generating random download speed between 1 and 500
    int upload_speed = rand() % 200 + 1; // Generating random upload speed between 1 and 200
    int latency = rand() % 200 + 1; // Generating random latency between 1 and 200

    printf("\nAnalyzing connection...\n");
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    printf("Latency: %d ms\n", latency);

    if (download_speed >= 400 && upload_speed >= 150 && latency <= 50) {
        printf("\nThe results are in and thy internet doth befit a noble lord!\n");
        printf("Thou art able to streameth thine videos with nary a hiccup and playeth thine games with haste!\n");
    } else if (download_speed >= 250 && upload_speed >= 100 && latency <= 100) {
        printf("\nThe results are in and thy internet doth befit a common serf!\n");
        printf("Thou art able to browse thine websites and streameth videos with tolerable speed!\n");
    } else {
        printf("\nAlas, the results are in and thy internet doth befit a lowly peasant!\n");
        printf("Thou art bound to suffereth through long buffering times and slow downloads!\n");
    }

    printf("\nFare thee well and may thy internet provider be merciful!\n");

    return 0;
}