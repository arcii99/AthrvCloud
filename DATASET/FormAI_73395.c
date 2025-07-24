//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char download[20], upload[20];
    int download_speed = 0, upload_speed = 0;
    int i;

    printf("Welcome to the Internet Speed Test Application!\n\n");

    for (i = 0; i < 3; i++) {
        printf("Testing download speed... ");
        fflush(stdout);

        // Simulate download speed test
        srand(time(NULL));
        download_speed = rand() % 100 + 1; // Random download speed between 1 and 100 Mbps

        sprintf(download, "%d Mbps", download_speed);

        printf("%s\n", download);
        sleep(1);

        printf("Testing upload speed... ");
        fflush(stdout);

        // Simulate upload speed test
        upload_speed = rand() % 100 + 1; // Random upload speed between 1 and 100 Mbps

        sprintf(upload, "%d Mbps", upload_speed);

        printf("%s\n\n", upload);
        sleep(1);
    }

    printf("Results:\n\n");
    printf("Download speed: %s\n", download);
    printf("Upload speed: %s\n", upload);

    return 0;
}