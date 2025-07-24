//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Starting internet speed test...\n");
    srand(time(NULL));
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;
    printf("Download Speed: %d Mbps\n", download_speed);
    printf("Upload Speed: %d Mbps\n", upload_speed);
    printf("Test completed successfully.\n");
    return 0;
}