//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int download_speed = rand() % 51;
    int upload_speed = rand() % 51;

    printf("Welcome to the Internet Speed Test App\n");
    printf("--------------------------------------\n");
    printf("Testing download speed...\n");
    printf("Your download speed is %d Mbps.\n", download_speed);
    printf("Testing upload speed...\n");
    printf("Your upload speed is %d Mbps.\n", upload_speed);

    if(download_speed > 30 && upload_speed > 30) {
        printf("Wow! Your internet connection is lightning fast.\n");
    } else if(download_speed > 20 && upload_speed > 20) {
        printf("Your internet connection is good.\n");
    } else if(download_speed > 10 && upload_speed > 10) {
        printf("Your internet connection is slow.\n");
    } else {
        printf("Your internet connection is very slow. Please upgrade.\n");
    }

    return 0;
}