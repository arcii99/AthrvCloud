//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int randNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Arrays of words to use
    char* subjects[5] = {"The government", "Corporations", "Aliens", "The Illuminati", "Time Travelers"};
    char* verbs[5] = {"are controlling", "are watching", "are manipulating", "are brainwashing", "are experimenting on"};
    char* objects[5] = {"us", "the weather", "animals", "our dreams", "our thoughts"};
    char* reasons[5] = {"to gain power", "to advance their technology", "to prepare for an invasion", "to create a new world order", "to control the population"};
    
    // Generate the conspiracy theory
    printf("Did you know that %s %s %s %s?\n", subjects[randNum(0,4)], verbs[randNum(0,4)], objects[randNum(0,4)], reasons[randNum(0,4)]);

    return 0;
}