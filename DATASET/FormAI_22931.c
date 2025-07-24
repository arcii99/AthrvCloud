//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that generates a random number within the given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {

    // List of all possible fortunes
    char fortunes[10][100] = {
        "You will have a great day today.",
        "You will meet someone special soon.",
        "A big promotion is coming your way.",
        "Your hard work will pay off.",
        "A new opportunity is on its way to you.",
        "You will make a big decision soon.",
        "Your dreams will become a reality.",
        "Love and happiness are in your future.",
        "A great adventure awaits you.",
        "You will have good luck today."
    };

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random fortune from the list
    int fortuneIndex = generateRandomNumber(0, 9);
    char* fortune = fortunes[fortuneIndex];

    // Print the fortune to the console
    printf("%s\n", fortune);

    return 0;
}