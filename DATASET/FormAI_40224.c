//FormAI DATASET v1.0 Category: Word Count Tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_string[10000];
    int count = 0;
    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter a sentence or paragraph:\n");
    fgets(input_string, 10000, stdin);
    char *word = strtok(input_string, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    printf("Your input has %d words!\n", count);
    if (count >= 69) {
        printf("Nice\n");
    }
    printf("Would you like to try again? (Y/N)\n");
    char response = getchar();
    if (response == 'Y' || response == 'y') {
        printf("Yay! Let's do it again!\n");
        main();
    } else {
        printf("Goodbye! Thanks for using the C Word Count Tool, hope it counted up to your expectations!\n");
    }
    return 0;
}