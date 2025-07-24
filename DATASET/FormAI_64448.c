//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main(){
    printf("Welcome to Internet Speed Test Application\n");

    printf("Please wait for a moment while the application checks your internet speed...\n");

    // We are going to generate some random numbers to simulate the speed check
    srand(time(NULL));
    int download_speed = rand() % 1000;
    int upload_speed = rand() % 1000;

    printf("Your download speed is %d Mbps\n", download_speed);
    printf("Your upload speed is %d Mbps\n", upload_speed);

    if(download_speed < 50 || upload_speed < 5){
        printf("Your internet speed is below average!\n");
    }
    else if(download_speed < 100 || upload_speed < 10){
        printf("Your internet speed is average.\n");
    }
    else{
        printf("Your internet speed is above average!\n");
    }

    printf("Thank you for using Internet Speed Test Application. Goodbye!\n");

    return 0;
}