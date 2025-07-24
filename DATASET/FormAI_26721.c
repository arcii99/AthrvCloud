//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int count = 0;
    int i, j;
    int randNum;
    char inputChar;
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int alphabetLength = sizeof(alphabet) / sizeof(alphabet[0]);
    int timeTaken;
    clock_t start, end;

    printf("Welcome to the Typing Speed Test Program!\n\n");
    printf("You will be given 10 random letters to type out as fast as you can.\n");
    printf("Let's begin...\n\n");

    // Loop for 10 random letters
    for (i = 0; i < 10; i++) {
        // Generate random letter from alphabet array
        srand(time(0));
        randNum = rand() % alphabetLength;
        printf("Please type the letter: %c\n", alphabet[randNum]);

        // Record start time
        start = clock();

        // Get user input until correct letter is typed
        do {
            inputChar = getchar();
        } while (inputChar != alphabet[randNum]);

        // Record end time and calculate time taken
        end = clock();
        timeTaken = (end - start) / CLOCKS_PER_SEC;

        printf("Time taken: %d seconds\n\n", timeTaken);

        // Keep track of how many letters were typed correctly on first try
        if (timeTaken <= 5) {
            count++;
        }
    }

    printf("You correctly typed %d out of 10 letters on the first try.\n", count);

    return 0;
}