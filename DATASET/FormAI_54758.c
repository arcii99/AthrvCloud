//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
    int download_speed,upload_speed, ping_time;
    srand(time(NULL));
    download_speed = rand()%100 + 1; // generates a random download speed between 1 to 100 Mbps
    upload_speed = rand()%100 + 1; // generates a random upload speed between 1 to 100 Mbps
    ping_time = rand()%100 + 1; // generates a random ping time between 1 to 100 ms
    printf("Welcome to the Internet Speed Test Application\n\n");
    printf("Testing Download Speed: %d Mbps\n",download_speed);
    printf("Testing Upload Speed: %d Mbps\n",upload_speed);
    printf("Testing Ping Time: %d ms\n\n",ping_time);
    if(download_speed>=50 && upload_speed>=50 && ping_time<=20) {
        printf("Congratulations! Your internet speed is excellent\n");
    }
    else if(download_speed>=30 && upload_speed>=30 && ping_time<=50) {
        printf("Your internet speed is good\n");
    }
    else if(download_speed>=10 && upload_speed>=10 && ping_time<=100) {
        printf("Your internet speed is average\n");
    }
    else {
        printf("Your internet speed is poor. Kindly contact your ISP\n");
    }
    return 0;
}