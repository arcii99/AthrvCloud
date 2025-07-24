//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download_speed, upload_speed;
    srand(time(0));  //set random seed to current time

    //Generate download and upload speeds between 0 and 100 Mbps
    download_speed = rand() % 101;
    upload_speed = rand() % 101;

    //Display download and upload speeds to user
    printf("Your download speed is: %d Mbps\n", download_speed);
    printf("Your upload speed is: %d Mbps\n", upload_speed);

    //Determine internet connection quality based on speeds
    if(download_speed >= 75 && upload_speed >= 10)
    {
        printf("Excellent internet connection!\n");
    }
    else if(download_speed >= 50 && upload_speed >= 5)
    {
        printf("Good internet connection.\n");
    }
    else if(download_speed >= 25 && upload_speed >= 2)
    {
        printf("Average internet connection.\n");
    }
    else
    {
        printf("Poor internet connection.\n");
    }

    return 0;
}