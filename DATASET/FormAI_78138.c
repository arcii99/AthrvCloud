//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter a sentence or paragraph:\n");

    char input[1000];
    fgets(input, 1000, stdin);

    int count = 0;
    char* word = strtok(input, " ");

    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    printf("Wow! Your sentence or paragraph contains %d words!\n", count);

    printf("But wait, there's more!\n");

    if (count <= 10) {
        printf("That's a pretty short sentence or paragraph. Did you know the shortest complete sentence in English is 'I am.'?\n");
    } else if (count >= 100) {
        printf("That's a pretty long sentence or paragraph. Did you take a break in the middle of writing it?\n");
    } else {
        printf("Your sentence or paragraph is just the right length!\n");
    }

    printf("Thank you for using the C Word Count Tool. Have a nice day!\n");

    return 0;
}