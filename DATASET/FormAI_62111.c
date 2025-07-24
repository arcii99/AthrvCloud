//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
    char website[100];
    int response_time;

    printf("Welcome to Happy Website Uptime Monitor!\n");
    printf("Enter website url or domain name to monitor: ");
    scanf("%s", website);

    printf("Website uptime monitoring started...\n");

    while(1){
        clock_t start_time = clock();

        // Code to check website status goes here
        // We are assuming the website status checking module exists for now
        // It will return either "UP" or "DOWN"

        char status[10] = "UP";

        response_time = (int)(clock() - start_time) * 1000 / CLOCKS_PER_SEC;

        if(strcmp(status, "UP") == 0){
            printf("Yay! %s is up and running. Response time: %dms\n", website, response_time);
        }
        else{
            printf("Uh-oh! %s seems to be down. Response time: %dms\n", website, response_time);
        }
        printf("Monitoring again in 30 seconds...\n");

        // Let's take a nap for 30 seconds
        // We are assuming the sleep function exists for now
        sleep(30);
    }   
    return 0;
}