//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator with the current time
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    // Generate a random conspiracy theory
    int conspiracy = rand() % 5;
    switch (conspiracy) {
        case 0:
            printf("The moon landing was faked.\n");
            break;
        case 1:
            printf("The government is controlling our thoughts through chemtrails.\n");
            break;
        case 2:
            printf("The Illuminati is secretly ruling the world.\n");
            break;
        case 3:
            printf("The Earth is actually flat.\n");
            break;
        case 4:
            printf("The coronavirus was created in a lab by the government.\n");
            break;
    }

    // Generate a random detail to add to the conspiracy theory
    int detail_type = rand() % 3;
    switch (detail_type) {
        case 0:
            printf("Did you know that there is no wind on the moon, yet the American flag was waving in the 'wind' during the moon landing?\n");
            break;
        case 1:
            printf("Many people believe that the chemtrails are a way for the government to control our minds and keep us in line.\n");
            break;
        case 2:
            printf("The Illuminati is said to be composed of the top 1% of wealthy individuals and their goal is to create a New World Order.\n");
            break;
    }

    // Generate a random source to cite for the conspiracy theory
    int source_type = rand() % 3;
    switch (source_type) {
        case 0:
            printf("I heard this information from my cousin's friend's sister who works for NASA.\n");
            break;
        case 1:
            printf("This information was leaked by a government insider who wishes to remain anonymous.\n");
            break;
        case 2:
            printf("This theory is based on a book written by a world-renowned expert in the field.\n");
            break;
    }

    printf("\nThink about it. Stay woke.\n");

    return 0;
}