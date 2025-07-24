//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_SIZE 20
#define TEXT_SIZE 1000

int main() {
    char text[TEXT_SIZE] = "The quick brown fox jumps over the lazy dog.";
    char input[TEXT_SIZE];
    char word[WORD_SIZE];
    int index = 0;
    int mistakes = 0;
    clock_t start, end;
    double time_used;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following text as fast and as accurately as possible:\n\n");
    printf("%s\n\n", text);
    printf("Press enter when you are ready to start.\n");
    getchar();

    start = clock();

    for (int i = 0; i < strlen(text) - 1; i++) {
        if (isspace(text[i])) {
            word[index] = '\0';
            index = 0;
            printf("%s ", word);
            scanf("%s", input);
            if (strcmp(word, input) != 0) {
                mistakes++;
            }
        } else {
            word[index++] = tolower(text[i]);
        }
    }

    end = clock();

    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nCongratulations, you have completed the Typing Speed Test!\n");
    printf("You made %d mistakes and it took you %0.2f seconds.\n", mistakes, time_used);

    return 0;
}