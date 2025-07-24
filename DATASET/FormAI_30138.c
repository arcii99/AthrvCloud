//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
// Welcome to the Website Uptime Monitor!
// This program will help you keep track of your website uptime and downtime.
// Let's get coding in C language!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


// Function to generate a random number between 1 and 100
int generateRandomNumber() 
{
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    return randomNumber;
}


int main()
{
    // Variables to hold website status and random number
    int websiteStatus = 1;
    int randomNumber = generateRandomNumber();

    // Set the threshold for website status change
    int threshold = 50;

    // Print brief information
    printf("Welcome to the Website Uptime Monitor!\n\n");
    printf("This program will help you keep track of your website uptime and downtime.\n\n");
    printf("Let's get started!\n\n");

    // Infinite loop to keep checking website status
    while (1) 
    {
        // Generate a new random number
        randomNumber = generateRandomNumber();

        // Check if the random number is greater than the threshold
        if(randomNumber > threshold) 
        {
            websiteStatus = 1; // Website is up
            printf("\n*** WEBSITE IS UP! ***\n\n");
        }
        else 
        {
            websiteStatus = 0; // Website is down
            printf("\n*** WEBSITE IS DOWN! ***\n\n");
        }

        // Delay of 5 seconds before the next check
        sleep(5);
    }

    return 0;
}