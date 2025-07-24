//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Running Internet Speed Test...\n...\n...\n\n");
    sleep(3);
    srand(time(NULL));
    int download_speed = rand() % 200 + 1;
    int upload_speed = rand() % 100 + 1;
    
    if(download_speed > 100 && upload_speed > 50) {
        printf("Congratulations! Your download speed is %d Mbps and upload speed is %d Mbps.\n", download_speed, upload_speed);
        printf("Your internet speed is above average. Keep it up!\n");
    }
    else if(download_speed > 80 && upload_speed > 40) {
        printf("Not bad! Your download speed is %d Mbps and upload speed is %d Mbps.\n", download_speed, upload_speed);
        printf("Your internet speed is average. You can improve it by contacting your ISP.\n");
    }
    else {
        printf("Oh no! Your download speed is %d Mbps and upload speed is %d Mbps.\n", download_speed, upload_speed);
        printf("Your internet speed is below average. Contact your ISP to improve your internet speed.\n");
    }

    return 0;
}