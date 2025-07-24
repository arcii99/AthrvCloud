//FormAI DATASET v1.0 Category: Browser Plugin ; Style: enthusiastic
//Are you tired of constantly scrolling through the same websites every day?
//Introducing the "Random Website" browser plugin!

#include <stdlib.h> //For random number generation
#include <string.h> //For string manipulation
#include <stdio.h> //For input and output

#define NUM_SITES 5 //Number of sites to choose from

char* sites[NUM_SITES] = {"https://www.google.com", "https://www.youtube.com",
                            "https://www.reddit.com", "https://www.twitter.com", "https://www.wikipedia.org"};

int main() {

    //Seed the random number generator
    srand(time(NULL));
    
    //Choose a random index for the site array
    int rand_index = rand() % NUM_SITES;
    
    //Open the random website in a new tab
    char* command = malloc(strlen(sites[rand_index]) + 20); //Allocate memory for command string
    sprintf(command, "open -a Safari %s", sites[rand_index]); //Construct command string
    system(command); //Execute command
    
    printf("Opening a random website!");// Show enthusiasm!

    return 0;
}