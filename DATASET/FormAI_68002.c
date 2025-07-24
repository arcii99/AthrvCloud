//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    int choice = rand() % 5; // Generate a random number between 0 and 4

    // Switch case for conspiracy theories
    switch(choice) {
        case 0: 
            printf("Did you know that the moon landing was fake?\n");
            break;
        case 1: 
            printf("The government is hiding evidence of aliens on Earth.\n");
            break;
        case 2: 
            printf("Chemtrails are actually chemicals the government is using to control our minds.\n");
            break;
        case 3: 
            printf("Vaccines are causing harmful side effects and the government doesn't want us to know.\n");
            break;
        case 4: 
            printf("The Illuminati controls all major world events.\n");
            break;
        default:
            printf("Something went wrong.\n");
    }
    return 0;
}