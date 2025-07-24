//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the C Ebook Reader!\n");
    printf("We know how much you love reading, so we've created a program just for you!\n");
    printf("Please enter the name of the Ebook you want to read: \n");

    char bookName[50];

    scanf("%s", bookName);

    printf("\nGreat choice! You've selected %s\n\n", bookName);

    printf("Here's a fun fact while your Ebook loads: Did you know that the first book ever printed was the Gutenberg Bible in 1455?\n");

    int totalPages;

    printf("\nNow, tell us how many pages %s has: ", bookName);

    scanf("%d", &totalPages);

    printf("\nAwesome! %s has %d pages!\n\n", bookName, totalPages);

    printf("Are you ready to start reading %s? (y/n)\n", bookName);

    char response;

    do {
        scanf(" %c", &response);
    } while (response != 'y' && response != 'n');

    if (response == 'y') {
        printf("\nHappy Reading! Enjoy your Ebook!");
    } else {
        printf("\nWe understand. Maybe next time! Have a nice day!");
    }

    return 0;
}