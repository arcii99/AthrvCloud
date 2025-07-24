//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// Shape-shifting conspiracy theory generator

int main() {
    char* theories[] = {
        "The moon landing was faked by lizard people.",
        "The government is covering up the existence of time travel.",
        "Aliens are living among us, disguised as humans.",
        "Bigfoot is actually a government experiment gone wrong.",
        "The Illuminati controls the world's governments and financial systems.",
        "Chemtrails are actually a mind control experiment.",
        "The Earth is hollow and there is a secret civilization living inside.",
        "The Bermuda Triangle is a portal to another dimension controlled by the government.",
        "The Denver International Airport is a secret government headquarters.",
        "The world is controlled by a secret society of shape-shifting reptilian humanoids."
    };
    int num_theories = sizeof(theories)/sizeof(theories[0]);

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Shape-Shifting Conspiracy Theory Generator!\n");

    while(1) {
        printf("\nPress enter to generate a new theory or type 'exit' to quit.\n");
        char input[50];
        fgets(input, 50, stdin);
        strtok(input, "\n"); // Remove newline character from input
        if(strcmp(input, "exit") == 0) {
            break;
        } else {
            int rand_index = rand() % num_theories;
            char* theory = theories[rand_index];
            int theory_len = strlen(theory);

            for(int i = 0; i < theory_len; i++) {
                if(theory[i] == ' ') {
                    printf(" ");
                } else {
                    printf("%c", (char)((int)theory[i] + rand()%26 - 12));
                }
            }
        }
    }

    printf("\nThanks for using the Shape-Shifting Conspiracy Theory Generator!\n");
    return 0;
}