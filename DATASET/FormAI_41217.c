//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("Welcome to the Internet Speed Test!\n");
    printf("Please wait while we measure your internet speed...\n");
    srand(time(NULL));
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    int latency = rand() % 50 + 1;
    printf("Latency: %d ms\n", latency);
    int jitter = rand() % 10 + 1;
    printf("Jitter: %d ms\n", jitter);
    int packet_loss = rand() % 5 + 1;
    printf("Packet Loss: %d %%\n", packet_loss);
    printf("Thank you for using our Internet Speed Test!\n");
    return 0;
}