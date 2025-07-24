//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int milli_seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    int download_speed = 0;
    int upload_speed = 0;
    printf("Welcome to the Brave Internet Speed Test Application!\n");
    delay(2000);
    printf("Testing the download speed...\n");
    delay(2000);
    srand(time(NULL));
    download_speed = rand() % 1000 + 1; // randomly generate a download speed between 1 and 1000 Mbps
    printf("Download speed: %d Mbps\n", download_speed);
    delay(2000);
    printf("Testing the upload speed...\n");
    delay(2000);
    upload_speed = rand() % 1000 + 1; // randomly generate an upload speed between 1 and 1000 Mbps
    printf("Upload speed: %d Mbps\n", upload_speed);
    delay(1000);
    printf("Thank you for using the Brave Internet Speed Test Application!\n");
    return 0;
}