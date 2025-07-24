//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input_string[1000];
    int count[26] = {0};
    int i, j; 
    printf("Please enter a string: ");
    fgets(input_string, 1000, stdin);
    int len = strlen(input_string);

    for (i=0; i<len; i++) {
        char curr = input_string[i];
        if(isalpha(curr)) {
            int index = tolower(curr) - 'a';
            count[index]++;
        }
    }

    for (i=0; i<26; i++) {
        printf("%c - %d", (char)('a'+i), count[i]);
    }

    return 0;
}