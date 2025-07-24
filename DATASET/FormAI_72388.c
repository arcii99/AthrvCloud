//FormAI DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int main(void) {
    char text[MAXLEN] = {0}; // initialize buffer to all zeros
    size_t len = 0;

    printf("Enter some text (max length %d):\n", MAXLEN);
    fgets(text, MAXLEN, stdin); // read input from user

    len = strlen(text);
    if (len > 0 && text[len-1] == '\n') { // remove newline if present
        text[len-1] = '\0';
        len--;
    }

    printf("\nOriginal text:\n%s\n", text);

    // reverse the text
    for (int i = 0; i < len/2; i++) {
        char temp = text[i];
        text[i] = text[len-i-1];
        text[len-i-1] = temp;
    }

    printf("\nReversed text:\n%s\n", text);

    // count the number of vowels
    int vowel_count = 0;
    for (int i = 0; i < len; i++) {
        switch (text[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel_count++;
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowel_count++;
                break;
            default: // do nothing
                break;
        }
    }

    printf("\nNumber of vowels: %d\n", vowel_count);

    return 0;
}