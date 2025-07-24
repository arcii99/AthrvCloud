//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Array of random conspiracy theories
    char* conspiracyTheories[] = {"The moon landing was faked by the government",
                                  "Aliens are living among us in disguise",
                                  "COVID-19 was created in a lab as a bioweapon",
                                  "The Illuminati controls the world's governments",
                                  "9/11 was an inside job orchestrated by the US government",
                                  "The Loch Ness Monster is real and the government is hiding it",
                                  "The earth is flat and the government is covering it up",
                                  "The Bermuda Triangle is a doorway to another dimension",
                                  "Bigfoot is real and the government is hiding it",
                                  "The government is hiding evidence of time travel"};
    
    // Pick a random conspiracy theory from the array
    int index = generateRandomNumber(0, 9);
    char* theory = conspiracyTheories[index];
    
    // Print the conspiracy theory
    printf("Did you know that %s?\n", theory);
    
    return 0;
}