//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    char* subjects[] = {"Aliens", "Illuminati", "Big Pharma", "Globalists", "Reptilians", "Deep State", "Flat Earth society", "Time Travelers", "Clones", "CERN", "AI Robots", "Ghost in the Machine", "Superhumans", "Interdimensional Beings", "Crypto Miners", "NWO"};
    char* actions[] = {"control", "manipulate", "spy on", "brainwash", "influence", "alter", "dominate", "destroy", "consume", "take over", "shape shift into", "teleport", "simulate", "program"};
    char* objects[] = {"humanity", "weather patterns", "political systems", "healthcare", "currency", "pop culture", "food supply", "technology", "environment", "history", "celebrities", "TV programming", "religion", "democracy", "sports", "the internet"};

    printf("Random Conspiracy Theory Generator: \n");

    while (1) {
        int subject_choice = rand() % (sizeof(subjects)/sizeof(subjects[0]));
        int action_choice = rand() % (sizeof(actions)/sizeof(actions[0]));
        int object_choice = rand() % (sizeof(objects)/sizeof(objects[0]));
        
        printf("%s %s %s.\n", subjects[subject_choice], actions[action_choice], objects[object_choice]);

        printf("Press any key to generate another theory or 'q' to quit. \n");
        char input = getchar();
        if (input == 'q') {
            break;
        }
    }

    return 0;
}