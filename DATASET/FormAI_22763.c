//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int uptime = 1; //start the uptime at 1 minute
    int num_checks = 0; //start with 0 checks
    int average_uptime = 0; //initialize the average uptime to 0

    while(1) //run the program indefinitely
    {
        time_t current_time = time(NULL); //get the current time
        printf("Checking website at %s", ctime(&current_time)); //print the time of check

        int website_status = rand() % 2; //generate a random number to simulate website status
        if(website_status == 0) //if website is down
        {
            printf("Website is down!\n");
            average_uptime = (uptime*num_checks)/(num_checks+1); //calculate the new average uptime
            printf("The average uptime is now %d minutes.\n", average_uptime);
            num_checks = 0; //reset the number of checks
            uptime = 1; //reset the uptime to 1 minute
            printf("Sleeping for 1 minute...\n");
            sleep(60); //sleep for 1 minute
        }
        else //if website is up
        {
            printf("Website is up!\n");
            num_checks++; //increment the number of checks
            uptime++; //increment the uptime
            sleep(10); //wait for 10 seconds before checking again
        }
    }

    return 0; //exit the program
}