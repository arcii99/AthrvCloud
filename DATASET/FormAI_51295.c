//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* subjects[] = {"The government", "Aliens", "Secret societies", "The Illuminati", "The Deep State", "Big Pharma", "The Reptilians", "The New World Order"};
const char* verbs[] = {"are controlling", "are manipulating", "are experimenting on", "are brainwashing", "are hiding", "are planning to take over", "are sabotaging", "are covering up"};
const char* objects[] = {"our minds", "the weather", "our DNA", "the stock market", "the media", "the education system", "the internet", "the world's water supply"};

int main() {
    srand(time(NULL)); // Initialize random seed

    for(int i = 0; i < 10; i++) { // Generate 10 conspiracy theories
        int subjectIndex = rand() % (sizeof(subjects) / sizeof(subjects[0])); // Select random index from subjects array
        int verbIndex = rand() % (sizeof(verbs) / sizeof(verbs[0])); // Select random index from verbs array
        int objectIndex = rand() % (sizeof(objects) / sizeof(objects[0])); // Select random index from objects array

        printf("%s %s %s.\n", subjects[subjectIndex], verbs[verbIndex], objects[objectIndex]); // Print conspiracy theory
    }

    return 0;
}