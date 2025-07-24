//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int count[26] = {0}; // Initialize counter for each letter

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++; // Increment counter for current letter
        }
        else if (c >= 'A' && c <= 'Z') {
            count[c - 'A']++; // Increment counter for current letter
        }
    }
  
    printf("Result:\n");
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            printf("'%c' appears %d times.\n", (char) (i + 'a'), count[i]);
        }
    }

    return 0;
}