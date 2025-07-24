//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to return random integer between min and max
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // seed random number generator
    srand(time(0));
    
    // array of conspiracy theories
    char* theories[] = {
        "The moon landing was fake.",
        "The government controls the weather.",
        "The pharmaceutical companies are hiding the cure for cancer.",
        "The Illuminati control world events.",
        "Aliens are among us.",
        "The earth is flat.",
        "The government created AIDS as a bioweapon.",
        "9/11 was an inside job.",
        "Vaccines cause autism.",
        "The Denver airport has a secret bunker for the elite.",
        "The Bilderberg group controls the world.",
        "The world will end in 2021."
    };
    
    // get random conspiracy theory
    int index = getRandomNumber(0, 11);
    char* theory = theories[index];
    
    // print out theory
    printf("Conspiracy Theory: %s\n", theory);
    return 0;
}