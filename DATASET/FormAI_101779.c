//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int download_speed, upload_speed;
    // Get random values for download and upload speed
    srand(time(NULL));
    download_speed = rand() % 100 + 1;
    upload_speed = rand() % 100 + 1;

    // Print out the results
    printf("Your download speed is: %d Mbps\n", download_speed);
    printf("Your upload speed is: %d Mbps\n", upload_speed);

    // Determine internet quality based on speed
    if (download_speed < 10 || upload_speed < 5) {
        printf("Your internet quality is poor!\n");
    } else if (download_speed >= 10 && download_speed < 50 || upload_speed >= 5 && upload_speed < 25) {
        printf("Your internet quality is average!\n");
    } else {
        printf("Your internet speed is great! Keep it up!\n");
    }

    return 0;
}