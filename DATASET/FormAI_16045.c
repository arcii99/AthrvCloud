//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    int download_speed = 0;
    int upload_speed = 0;
    
    printf("Welcome to the Internet Speed Test Application\n\n");
    printf("Please wait while we test your download speed...\n");
    delay(5);
    download_speed = rand() % 100 + 1;
    printf("Your download speed is: %d Mbps\n\n", download_speed);
    printf("Please wait while we test your upload speed...\n");
    delay(5);
    upload_speed = rand() % 50 + 1;
    printf("Your upload speed is: %d Mbps\n\n", upload_speed);
    
    if (download_speed >= 50 && upload_speed >= 25) {
        printf("Congratulations! Your internet speed is above average\n");
    } else if (download_speed >= 25 && upload_speed >= 10) {
        printf("Your internet speed is average\n");
    } else {
        printf("Sorry, your internet speed is below average\n");
        printf("We recommend upgrading to a faster internet plan\n");
    }
    
    return 0;
}