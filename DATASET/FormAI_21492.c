//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int downloadSpeed, pingSpeed; // variables to store internet speed values
    srand(time(0)); // Seed for random number generator

    // Display welcome message to user
    printf("Welcome to the Medieval Internet Speed Test!\n");
    printf("Press Enter to begin the test.\n");
    getchar(); // Wait for user to press Enter

    // Generate download speed value between 1-20 Mbps
    downloadSpeed = (rand() % 20) + 1;
    printf("Your download speed is %d Mbps.\n", downloadSpeed);

    // Generate ping speed value between 50-150 ms
    pingSpeed = (rand() % (150 - 50 + 1)) + 50;
    printf("Your ping speed is %d ms.\n", pingSpeed);

    // Evaluate user's internet speed based on generated values
    if(downloadSpeed >= 10 && pingSpeed < 100){
        printf("Congrats! Your internet speed is lightning-fast!\n");
    } else if(downloadSpeed >= 5 && pingSpeed < 150){
        printf("Your internet speed is decent, but there is room for improvement.\n");
    } else {
        printf("Yikes! Your internet speed is slower than molasses in January.\n");
    }

    return 0;
}