//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
 
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a spooky old house. Do you want to enter? (y/n)\n");
 
    char choice;
    scanf("%c", &choice);
 
    if (choice == 'y') {
        printf("You cautiously enter the haunted house...\n");
        int steps = 0;
 
        while (steps < 10) { // explore the house for 10 steps
            int rand_choice = rand() % 3; // generate a random number between 0 and 2
 
            if (rand_choice == 0) {
                printf("You hear creaking floorboards beneath your feet...\n");
            } else if (rand_choice == 1) {
                printf("A ghostly apparition materializes in front of you!\n");
            } else {
                printf("You feel a cold chill run down your spine...\n");
            }
 
            steps++;
        }
 
        printf("You've explored the haunted house. Do you want to leave now? (y/n)\n");
 
        char exit_choice;
        scanf(" %c", &exit_choice); // note the space before %c - this is to consume the newline character left in the input stream
 
        if (exit_choice == 'y') {
            printf("You quickly leave the haunted house and breathe a sigh of relief...\n");
        } else {
            printf("You decide to stay a little longer...\n");
        }
 
    } else {
        printf("You chicken out and decide not to enter the haunted house.\n");
    }
 
    return 0;
}