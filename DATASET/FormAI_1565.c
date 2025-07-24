//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <ctype.h>

/* Function prototypes */
void countWords(char* str, int* freq);
void printWords(int* freq);

int main() {
    char str[1000];
    int freq[26] = {0};

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    countWords(str, freq);
    printWords(freq);

    return 0;
}

/* Function to count words in a string */
void countWords(char* str, int* freq) {
    int i;

    while (*str) {
        /* If the current character is alpha */
        if (isalpha(*str)) {
            /* Increment the frequency counter for the character */
            freq[tolower(*str) - 'a']++;
        }

        /* Move to the next character */
        str++;
    }
}

/* Function to print the word frequency */
void printWords(int* freq) {
    int i;

    printf("\n\nWord Frequency:\n");
    printf("-----------------\n");

    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, freq[i]);
    }
}