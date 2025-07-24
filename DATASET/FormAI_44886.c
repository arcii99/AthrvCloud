//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    char* conspiracyTheories[] = {
        "Did you know that the government is controlling our thoughts through chemtrails?",
        "I heard that the moon landing was actually fake, do you believe it?",
        "The Illuminati is controlling the world, I'm telling you!",
        "The Earth is actually flat, have you ever seen a curve?",
        "Have you heard of the lizard people who run the world?",
        "The Coronavirus is a hoax created by Big Pharma to make us all sick!",
        "The government is hiding the cure for cancer to keep us all under their control!",
        "Did you know that the JFK assassination was actually planned by the CIA?",
        "9/11 was an inside job, wake up people!",
        "The Denver airport is a secret underground bunker for the world's elite!",
        "Did you know that the Simpsons predict the future?",
        "The world is going to end in 2021, I'm telling you!"
    };

    int numTheories = sizeof(conspiracyTheories) / sizeof(char*);
    int randIndex = rand() % numTheories;

    printf("%s\n", conspiracyTheories[randIndex]);

    return 0;
}