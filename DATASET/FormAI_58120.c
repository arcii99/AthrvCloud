//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int speed = 0;  //variable to hold internet speed
    srand(time(0)); //to make use of random numbers


    for (int i = 0; i < 3; i++)
    {
        // to simulate internet speed test
        int download_speed = rand() % 101; //random number between 0 and 100
        printf("Testing download speed... %d Mbps\n", download_speed);
        speed += download_speed; //adding up the speeds to calculate average later
        printf("Testing upload speed... ");
        //random delay to simulate actual upload speed test
        for(int j = 0; j < rand() % 10 + 1; j++) 
        {
            printf(". ");
        }
        int upload_speed = rand() % 101;
        printf("%d Mbps\n\n", upload_speed);
        speed += upload_speed;
    }

    //calculating and printing average speed
    speed /= 6;
    printf("Overall, your internet speed is %d Mbps\n", speed);

    return 0;
}