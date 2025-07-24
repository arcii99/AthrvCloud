//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

int main() {
    char text[MAX_CHARS];
    char search[MAX_CHARS];
    int count = 0;

    printf("Enter text: ");
    fgets(text, MAX_CHARS, stdin);

    printf("Enter search word: ");
    fgets(search, MAX_CHARS, stdin);

    // Remove newline character from strings
    text[strcspn(text, "\n")] = 0;
    search[strcspn(search, "\n")] = 0;

    // Search for occurrences of search word in text
    char *ptr = text;
    while ((ptr = strstr(ptr, search)) != NULL) {
        count++;
        ptr++;
    }

    // Output number of occurrences
    printf("Number of occurrences: %d\n", count);

    return 0;
}