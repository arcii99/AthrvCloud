//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download_speed, upload_speed;
    srand(time(NULL));
    download_speed = rand() % 50 + 50;
    upload_speed = rand() % 20 + 20;

    printf("Welcome to the Internet Speed Test Application!\n\n");
    printf("Testing Download Speed... \n\n");
    printf("Download Speed: %d Mbps\n\n", download_speed);

    printf("Testing Upload Speed... \n\n");
    printf("Upload Speed: %d Mbps\n\n", upload_speed);

    if(download_speed >= 50 && upload_speed >= 20){
        printf("Great! You have a fast internet connection.\n\n");
    } else if(download_speed >= 30 && upload_speed >= 10){
        printf("Your internet connection is average.\n\n");
    } else {
        printf("Your internet connection is below average.\n\n");
    }

    return 0;
}