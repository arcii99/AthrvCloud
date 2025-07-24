//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's have some fun with this RAM usage monitor!
int main() {
    srand(time(0)); // Seed the random number generator with current time
    
    printf("Welcome to the RAM usage monitor... or should I say, the party!\n");
    printf("We're going to use some RAM, but don't worry, we'll clean up after ourselves.\n\n");
    
    printf("Press enter to start the party...\n");
    getchar(); // Wait for user to press enter
    
    while(1) { // Infinite loop to keep the party going
        int *p = (int*)malloc(sizeof(int)); // Allocate memory using malloc
        *p = rand() % 1000; // Assign random value to memory location
        
        printf("New partygoer has arrived! They are using %d bytes of RAM.\n", sizeof(int));
        printf("Total RAM usage is now %ld bytes.\n", sizeof(int) + (*p / 2)); // Print total RAM usage
        
        if(*p % 3 == 0) { // Sometimes, a partygoer might leave the party
            printf("Uh oh, partygoer has left the party! They were using %d bytes of RAM.\n", sizeof(int));
            free(p); // Release memory using free
            printf("Total RAM usage is now %ld bytes.\n", (*p / 2)); // Print total RAM usage
        }
        
        printf("Press enter to invite more partygoers or press 'q' to end the party...\n");
        char c = getchar(); // Wait for user input
        
        if(c == 'q' || c == 'Q') { // Exit the party if user presses 'q'
            printf("Sad to see you go... but the cleanup must begin. Goodbye!\n");
            free(p); // Release memory using free
            break;
        }
    }
    
    return 0; // End of party
}