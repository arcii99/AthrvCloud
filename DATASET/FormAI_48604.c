//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // Maximum length of input string

/**
  * This is the most unique compression algorithm you'll ever see.
  * It converts all the letters in your string to emoji!
  * Yes, you heard it right. Emoji are the most efficient way to compress data.
  * Don't believe me? Just try it out for yourself!
**/

// Emoji conversion table
char conversionTable[][5] = {
    {"😂"},
    {"😍"},
    {"🤔"},
    {"😎"},
    {"🙌"},
    {"🤯"},
    {"🥳"},
    {"🦄"},
    {"🌈"},
    {"🔥"},
    {"✨"},
    {"🍕"},
    {"🍔"},
    {"🍟"},
    {"🍩"},
    {"🍪"},
    {"🍺"},
    {"🍸"},
    {"🍷"},
    {"🍹"},
};

int main() {
    char input[MAX_LEN];
    int input_len, i, j;

    // Take input from user
    printf("Enter a string (max length %d): ", MAX_LEN);
    fgets(input, MAX_LEN, stdin);
    input_len = strlen(input);

    // Generate compressed output
    for (i = 0; i < input_len; i++) {
        for (j = 0; j < sizeof(conversionTable) / sizeof(conversionTable[0]); j++) {
            if (input[i] == j + 'a') {
                printf("%s", conversionTable[j]);
                break;
            }
        }
    }

    return 0;
}

// Happy compressing! 😂😍🤔😎🙌🤯🥳🦄🌈🔥✨🍕🍔🍟🍩🍪🍺🍸🍷🍹