//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int download = 0, upload = 0, download_speed = 0, upload_speed = 0, max_speed = 150, min_speed = 10;
    srand(time(0));
    download_speed = (rand() % (max_speed - min_speed + 1)) + min_speed;
    upload_speed = (rand() % (max_speed - min_speed + 1)) + min_speed;
    printf("\nWelcome to the Internet Speed Test!\n\n");
    printf("Calculating Download Speed.\n\n");

    for (int i = 0; i <= 100; i+=10)
    {
        download += download_speed;
        printf("Downloaded %d%%. Speed: %d Mbps\n", i, download_speed);
        download_speed = (rand() % (max_speed - min_speed + 1)) + min_speed;
    }

    printf("Calculating Upload Speed.\n\n");
    for (int i = 0; i <= 100; i+=10)
    {
        upload += upload_speed;
        printf("Uploaded %d%%. Speed: %d Mbps\n", i, upload_speed);
        upload_speed = (rand() % (max_speed - min_speed + 1)) + min_speed;
    }

    printf("\nYour Download Speed is: %dMbps!\n", download/10);
    printf("Your Upload Speed is: %dMbps!\n", upload/10);

    return 0;
}