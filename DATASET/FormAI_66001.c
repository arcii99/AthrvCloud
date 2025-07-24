//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// function to generate a random number between 0 and 4
int generateRandomNumber() {
    return rand() % 5;
}

int main() {
    // initialize the list of fortunes
    char* fortunes[] = {
        "You will find food today.",
        "You will meet a stranger who will offer help.",
        "Beware of bandits lurking around the corner.",
        "Your journey will be long and arduous.",
        "You will encounter a mutated creature."
    };

    // generate a random index for the fortunes array
    int index = generateRandomNumber();

    // print the fortune
    printf("Fortune Teller: %s\n", fortunes[index]);

    return 0;
}