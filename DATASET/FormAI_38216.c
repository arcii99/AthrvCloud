//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int download_speed, upload_speed;
    int download_time, upload_time;
    int i;
    srand((unsigned) time(NULL));

    printf("Starting Speed Test...\n");
    sleep(1);

    printf("Measuring download speed...\n");
    download_speed = rand() % 1000 + 1;
    download_time = 10 + rand() % 10;
    printf("Your download speed is %d Mbps and it took %d seconds.\n", download_speed, download_time);

    printf("Measuring upload speed...\n");
    upload_speed = rand() % 100 + 1;
    upload_time = 5 + rand() % 5;
    printf("Your upload speed is %d Mbps and it took %d seconds.\n", upload_speed, upload_time);

    printf("\nSpeed Test completed!\n");

    return 0;
}