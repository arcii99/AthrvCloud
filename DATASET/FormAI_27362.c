//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(){

    printf("Welcome to the Mind-Bending Website Uptime Monitor!\n\n");

    srand(time(0));

    int uptime;
    int downtime;
    int i = 0;

    while(i < 5){

        uptime = rand() % 100 + 1; // Generating random uptime values between 1-100%
        downtime = 100 - uptime; // Calculating the downtime

        printf("Monitoring Website Uptime...\n");

        for(int j=0; j<10; j++){

            printf("Uptime: %d%%   Downtime: %d%%\n", uptime, downtime);
            sleep(1);

        }

        i++;

    }

    printf("\nMonitoring Completed!\n");

    return 0;

}