//FormAI DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <ctype.h>

int main() {
    char string[500];
    int c_count = 0;

    printf("Welcome to the Cheerful C Word Count Tool!\n");
    printf("Please enter your text below:\n");

    fgets(string, 500, stdin);

    for (int i = 0; string[i]!='\0'; i++) {
        if (isalpha(string[i])) {
            c_count++;
        }
    }

    printf("\n");
    printf("Great job! You used %d C words in your text.\n", c_count);
    printf("Thanks for using the Cheerful C Word Count Tool - have a wonderful day!\n");

    return 0;
}