//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to check if website is up or not
int checkWebsite(char *url)
{
    int status = system("ping -c 3 google.com > /dev/null"); // pinging the website 3 times and discarding the output
    return status == 0; // if status is 0, website is up
}

int main()
{
    char url[100]; // variable to store url of website
    
    printf("Enter the URL of website: ");
    scanf("%s", url); // user inputs the url of website
    
    time_t startTime, endTime; // variables to store start time and end time
    
    startTime = time(NULL); // start time of checking the website
    
    if (checkWebsite(url)) // checking if website is up
    {
        printf("Website is up and running!\n");
    }
    else
    {
        printf("Website is down!\n");
    }
    
    endTime = time(NULL); // end time of checking the website
    
    printf("Total time taken: %ld seconds", endTime - startTime); // calculating and displaying total time taken
    
    return 0;
}