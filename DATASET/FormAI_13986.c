//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    int speed;
    printf("Welcome to the Internet Speed Test Application!\n\n");
    printf("We will test your download speed by downloading a 100MB file from our server.\n");
    printf("Please wait while we connect to the server...\n\n");
    delay(3);
    printf("Connected!\n\n");
    printf("Testing download speed, please wait...\n");
    delay(5);
    speed = rand() % 50 + 50;  // Generate random speed between 50 and 100 Mbps
    printf("Download speed: %d Mbps\n", speed);
    return 0;
}