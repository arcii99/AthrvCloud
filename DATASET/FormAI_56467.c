//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    time_t t; 

    // Intializes random number generator 
    srand((unsigned) time(&t)); 

    // Random number between 1 and 10 
    int randomNumber = rand() % 10 + 1;

    if (randomNumber <= 8) { // 80% chance of website being up
        printf("Website is up!\n");
    } else { // 20% chance of website being down
        printf("Website is down!\n");
    }

    return 0; 
}