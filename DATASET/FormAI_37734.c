//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the Website Uptime Monitor!\n");

    // Get user input for website URL and interval
    char url[100];
    int interval;
    printf("Please enter the URL of the website you would like to monitor: ");
    scanf("%s", url);
    printf("Please enter the interval (in minutes) at which you want to check the website: ");
    scanf("%d", &interval);

    // Set up loop to monitor website at specified intervals
    while(1){
        // Get current time to display in log
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        printf("%02d:%02d:%02d - ", t->tm_hour, t->tm_min, t->tm_sec);

        // Check website status using command line tool "curl"
        char command[200];
        sprintf(command, "curl --head --silent %s | head -n 1 | grep \"HTTP/1.[01] [23]\"", url);
        int status = system(command);

        // Display status based on HTTP status code
        if(status == 0){
            printf("%s is up\n", url);
        }
        else{
            printf("%s is down\n", url);
        }

        // Sleep for interval
        sleep(interval*60);
    }

    return 0;
}