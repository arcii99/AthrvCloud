//FormAI DATASET v1.0 Category: File handling ; Style: multiplayer
// Multiplayer File Handling Game
// Player 1 writes a sentence to a file, and Player 2 has to guess the sentence.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int random = rand() % 5 + 1; // generate a random number between 1 and 5
    char file_name[20] = "sentence_";
    char sentence[100];

    // create the file name based on the random number
    char number[2];
    sprintf(number, "%d", random);
    strcat(file_name, number);
    strcat(file_name, ".txt");

    // prompt user 1 to enter a sentence and write it to the file
    printf("Player 1: Enter a sentence to write to the file:\n");
    fgets(sentence, 100, stdin);
    FILE *file = fopen(file_name, "w");
    fprintf(file, "%s", sentence);
    fclose(file);
    printf("Your sentence has been written to %s.\n", file_name);

    // prompt user 2 to guess the sentence from the file
    char guess[100];
    printf("Player 2: Try to guess the sentence from %s:\n", file_name);
    fgets(guess, 100, stdin);

    // read the sentence from the file and compare it to the guess
    char read_sentence[100];
    file = fopen(file_name, "r");
    fgets(read_sentence, 100, file);
    fclose(file);

    if (strcmp(read_sentence, guess) == 0) {
        // the guess is correct
        printf("You guessed correctly!\n");
    } else {
        // the guess is incorrect
        printf("Sorry, your guess is incorrect.\n");
    }

    return 0;
}