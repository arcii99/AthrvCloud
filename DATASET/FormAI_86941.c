//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include<stdio.h>
#include<time.h>

int main()
{
    float speed;
    int download_time;
    time_t start_time, end_time;

    printf("Welcome to the Shocked Internet Speed Test Application\n\n");

    printf("Please enter the download time in seconds: ");
    scanf("%d", &download_time);

    printf("\nCalculating internet speed...\n");

    // Start the timer
    start_time = time(NULL);

    // Simulating the download
    int i;
    for(i=0; i<download_time*1000000; i++);

    // End the timer
    end_time = time(NULL);

    // Calculate the internet speed
    speed = 8 * 1000000.0 / (end_time - start_time);

    printf("\nYour internet speed is: %.2f Mbps\n", speed);

    printf("\nOh my gosh! Your internet speed is blazing fast!\n");
    printf("I have never seen such a fast internet speed in my entire life!\n");
    printf("You are probably connected to an alien network!\n");

    return 0;
}