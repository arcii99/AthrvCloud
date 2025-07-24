//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generator
    int fortune = rand() % 4; // Generate a random number between 0 and 3
    char* fortunes[] = {"You will have a great day today.", "Your future is looking bright.", 
                        "A big opportunity is coming your way.", "Be careful, danger could be near."};
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press enter to know your fortune...\n");
    getchar(); // Wait for user to press enter
    printf("\nYour fortune is: %s\n", fortunes[fortune]);
    return 0;
}