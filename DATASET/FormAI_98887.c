//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int speed, latency;
    float download_speed, upload_speed;
    printf("Welcome to the Internet Speed Test!\n");
    printf("Please enter your internet speed in Mbps: ");
    scanf("%d", &speed);
    printf("Please enter your internet latency in milliseconds: ");
    scanf("%d", &latency);
    srand(time(NULL));
    int random_num = rand() % 100 + 1;
    download_speed = (float) speed * (1 - (random_num / 100.0));
    upload_speed = (float) (speed * 0.75) * (1 - (random_num / 100.0));
    printf("Testing download speed...\n");
    int download_time = (int) (1024 * 1024 * 8) / download_speed; //converting from Mbps to MB/s and calculating time to download 8 MB file;
    printf("Your download speed is %.2f Mbps, it will take approximately %d seconds to download an 8 MB file.\n", download_speed, download_time);
    printf("Testing upload speed...\n");
    int upload_time = (int) (1024 * 1024 * 8) / upload_speed;
    printf("Your upload speed is %.2f Mbps, it will take approximately %d seconds to upload an 8 MB file.\n", upload_speed, upload_time);
    printf("Testing latency...\n");
    int min_latency = latency - 10, max_latency = latency + 10;
    int random_latency = (rand() % (max_latency - min_latency + 1)) + min_latency;
    printf("Your latency is %d milliseconds.\n", random_latency);
    if (random_latency <= 30) {
        printf("Your latency is excellent!\n");
    } else if (random_latency <= 60) {
        printf("Your latency is good.\n");
    } else if (random_latency <= 100) {
        printf("Your latency is fair.\n");
    } else {
        printf("Your latency is poor.\n");
    }
    return 0;
}