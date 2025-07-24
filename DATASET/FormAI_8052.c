//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    time_t rawtime; //create time structure
    struct tm * timeinfo; //create pointer to time structure
    char time_string[50]; //array to store formatted time

    //get current time
    time(&rawtime);
    //convert time to local time
    timeinfo = localtime(&rawtime);
    //convert time to string format
    strftime(time_string, 50, "%Y-%m-%d %H:%M:%S", timeinfo);

    //print current time
    printf("Current time is: %s\n\n",time_string);

    //ask user for time travel input
    int years;
    printf("Enter the number of years you want to travel back in time: ");
    scanf("%d",&years);

    //calculate the new time
    time_t new_rawtime = rawtime - (years * 365 * 24 * 60 * 60); //subtract the number of seconds in a year for the number of years travelled
    timeinfo = localtime(&new_rawtime); //convert new time to local time
    strftime(time_string, 50, "Back in time %Y years it was: %Y-%m-%d %H:%M:%S", timeinfo); //format new time string

    //print new time
    printf("\n%s\n",time_string);

    return 0;
}