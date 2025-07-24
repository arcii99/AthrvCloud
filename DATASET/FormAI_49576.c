//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");

    srand(time(NULL));

    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;

    printf("Testing Download Speed...\n");
    for (int i = 0; i < 10; i++) {
        printf("Downloading packet %d of 10\n", i+1);
        for (int j = 0; j < download_speed * 10000000; j++) {
            // Downloading...
        }
    }

    printf("Testing Upload Speed...\n");
    for (int i = 0; i < 10; i++) {
        printf("Uploading packet %d of 10\n", i+1);
        for (int j = 0; j < upload_speed * 10000000; j++) {
            // Uploading...
        }
    }

    printf("Speed Test Complete!\n");
    printf("Download Speed: %d Mbps\n", download_speed);
    printf("Upload Speed: %d Mbps\n", upload_speed);

    return 0;
}