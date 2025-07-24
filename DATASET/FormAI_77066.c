//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL));
    int speed = rand() % 100 + 1;
    printf("Welcome to the post-apocalyptic internet speed test!\n\n");
    printf("Your connection speed is: %d Mbps\n\n", speed);
    printf("Measuring upload speed...\n");
    sleep(1); // Simulating measurement
    int upload = rand() % 10 + 1;
    printf("Upload speed: %d Mbps\n", upload);
    printf("Measuring download speed...\n");
    sleep(1); // Simulating measurement
    int download = rand() % 50 + 1;
    printf("Download speed: %d Mbps\n\n", download);
    if (speed <= 10) {
        printf("Your internet speed is too slow, you will have trouble staying connected to the few remaining survivors.\n");
    } else if (speed <= 50) {
        printf("Your internet speed is decent, you should be able to communicate with other survivors without much trouble.\n");
    } else {
        printf("Your internet speed is excellent, you will have no trouble connecting with other survivors and accessing valuable information.\n");
    }
    if (upload <= 1) {
        printf("Your upload speed is painfully slow, sending messages and files will be a struggle.\n");
    } else {
        printf("Your upload speed is sufficient, you should be able to send messages and files without much trouble.\n");
    }
    if (download <= 10) {
        printf("Your download speed is slow, it may take a while to access important information and files.\n");
    } else {
        printf("Your download speed is good, you should be able to access important information and files quickly.\n");
    }
    return 0;
}