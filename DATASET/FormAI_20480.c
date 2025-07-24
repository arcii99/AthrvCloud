//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: medieval
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int count = 0;
    printf("Welcome to the Alien Language Translator!\n\n");
    printf("Please enter a phrase in the Alien Language: ");
    while ((c = getchar()) != '\n') {
        if (islower(c)) {
            putchar(toupper(c));
            count++;
        }
        else if (isupper(c)) {
            putchar(tolower(c));
            count++;
        }
        else {
            putchar(c);
        }
    }
    printf("\n\nTranslation complete! Number of letters translated: %d", count);
    return 0;
}