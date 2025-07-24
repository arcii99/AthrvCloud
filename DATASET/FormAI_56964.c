//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed based on current time
    int i, j;

    // generate 10 random numbers between 1 and 100 and print them out
    printf("10 random numbers between 1 and 100:\n");
    for (i = 0; i < 10; i++) {
        j = rand() % 100 + 1;
        printf("%d ", j);
    }

    // generate 5 random uppercase letters and print them out
    printf("\n5 random uppercase letters:\n");
    for (i = 0; i < 5; i++) {
        j = rand() % 26 + 65; // ASCII code for uppercase letters
        printf("%c ", j);
    }

    // generate a random word with 10 characters and print it out
    printf("\nRandom word with 10 characters:\n");
    char word[11];
    for (i = 0; i < 10; i++) {
        j = rand() % 26 + 97; // ASCII code for lowercase letters
        word[i] = (char) j;
    }
    word[10] = '\0'; // add null terminator to end of string
    printf("%s\n", word);

    return 0;
}