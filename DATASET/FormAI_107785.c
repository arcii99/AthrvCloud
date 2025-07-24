//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000
#define NUM_ALPHA 26

void countFrequency(char* str, int* freq) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(isalpha(str[i])) {
            freq[tolower(str[i])-'a']++;
        }
    }
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    // Remove trailing newline character
    int len = strlen(str);
    if(str[len-1] == '\n') str[len-1] = '\0';

    int freq[NUM_ALPHA] = {0};
    countFrequency(str, freq);

    // Print frequency of each character
    printf("Character frequency:\n");
    for(int i = 0; i < NUM_ALPHA; i++) {
        printf("%c: %d\n", i+'a', freq[i]);
    }

    return 0;
}