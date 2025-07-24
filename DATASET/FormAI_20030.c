//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_seconds) //function to delay the execution of program
{
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

int main()
{
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This program will determine the speed of your internet connection.\n");
    printf("Please wait while we perform the test...\n\n");

    int download_speed, upload_speed;
    srand(time(0)); 
    delay(3);
    download_speed = rand() % 100 + 1; //generating random download speed between 1 to 100 Mbps
    delay(2);
    upload_speed = rand() % 50 + 1; //generating random upload speed between 1 to 50 Mbps

    printf("Your download speed is %d Mbps.\n", download_speed);
    printf("Your upload speed is %d Mbps.\n", upload_speed);
    printf("\n");

    //determining the quality of internet connection based on download speed
    if(download_speed > 70)
    {
        printf("Your internet connection is excellent!\n");
    }
    else if(download_speed > 50)
    {
        printf("Your internet connection is good.\n");
    }
    else if(download_speed > 30)
    {
        printf("Your internet connection is average.\n");
    }
    else
    {
        printf("Your internet connection is poor.\n");
    }

    return 0;
}