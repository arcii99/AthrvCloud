//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download_speed, upload_speed, ping_time;
    srand(time(0)); //ensuring randomization
    printf("Welcome to the Chuck Norris Internet Speed Test!\n");
    printf("Please wait while we try to establish a connection with the internet...\n");
    sleep(3); //adding some suspense
    printf("Connection established successfully!\n\n");
    printf("Checking download speed...\n");
    download_speed = rand() % 101; //randomizing download speed from 0 to 100 Mbps
    printf("Download speed: %d Mbps\n", download_speed);
    if (download_speed >= 90)
    {
        printf("Chuck Norris approves!\n");
    }
    else if (download_speed >= 70 && download_speed < 90)
    {
        printf("Not bad, but Chuck Norris expects more!\n");
    }
    else
    {
        printf("Chuck Norris is not impressed!\n");
    }
    printf("\nChecking upload speed...\n");
    upload_speed = rand() % 101; //randomizing upload speed from 0 to 100 Mbps
    printf("Upload speed: %d Mbps\n", upload_speed);
    if (upload_speed >= 90)
    {
        printf("Chuck Norris approves!\n");
    }
    else if (upload_speed >= 70 && upload_speed < 90)
    {
        printf("Not bad, but Chuck Norris expects more!\n");
    }
    else
    {
        printf("Chuck Norris is not impressed!\n");
    }
    printf("\nChecking ping time...\n");
    ping_time = rand() % 51; //randomizing ping time from 0 to 50 ms
    printf("Ping time: %d ms\n", ping_time);
    if (ping_time <= 5)
    {
        printf("Chuck Norris approves!\n");
    }
    else if (ping_time > 5 && ping_time <= 20)
    {
        printf("Not bad, but Chuck Norris expects more!\n");
    }
    else
    {
        printf("Chuck Norris is not impressed!\n");
    }
    printf("\nThank you for taking the Chuck Norris Internet Speed Test!\n");
    return 0;
}