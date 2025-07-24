//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random conspiracy theory
void getRandomConspiracy(char conspiracy[100]) {
    int randNum = rand() % 10;
    switch(randNum) {
        case 0:
            sprintf(conspiracy, "The moon landing was faked.");
            break;
        case 1:
            sprintf(conspiracy, "Aliens walk among us in human form.");
            break;
        case 2:
            sprintf(conspiracy, "9/11 was an inside job.");
            break;
        case 3:
            sprintf(conspiracy, "The government is hiding the cure for cancer.");
            break;
        case 4:
            sprintf(conspiracy, "Bigfoot is real and is being kept a secret by the government.");
            break;
        case 5:
            sprintf(conspiracy, "The Illuminati control everything.");
            break;
        case 6:
            sprintf(conspiracy, "The Earth is flat.");
            break;
        case 7:
            sprintf(conspiracy, "Vaccines cause autism.");
            break;
        case 8:
            sprintf(conspiracy, "The government is spying on us through our electronic devices.");
            break;
        case 9:
            sprintf(conspiracy, "Area 51 has evidence of extraterrestrial life.");
            break;
        default:
            sprintf(conspiracy, "The world is controlled by lizard people.");
            break;
    }
}

int main() {
    // Set up random number generator
    srand(time(NULL));

    // Generate and print out 10 random conspiracy theories
    for(int i=0; i<10; i++) {
        char conspiracy[100];
        getRandomConspiracy(conspiracy);
        printf("Conspiracy %d: %s\n", i+1, conspiracy);
    }

    return 0;
}