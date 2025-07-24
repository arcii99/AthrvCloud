//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Internet Speed Test!\n");
    printf("We know you're eager to find out how fast your internet is, so let's get started!\n");

    srand(time(NULL));
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;
    
    printf("Testing download speed...\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d Mbps\n", download_speed);
        download_speed += rand() % 20 - 10;
    }
    
    printf("\nTesting upload speed...\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d Mbps\n", upload_speed);
        upload_speed += rand() % 20 - 10;
    }
    
    printf("\nGreat news! Your internet speed is lightning fast!\n");
    printf("Just kidding, there's no such thing as lightning-fast internet...\n");
    printf("But your internet is definitely faster than a snail riding a turtle!\n");
    
    return 0;
}