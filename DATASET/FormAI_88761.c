//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000 // maximum length of input string
#define ALPHABET_SIZE 26 // number of lowercase alphabetical characters

void countFrequency(char *str, int *freq) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(isalpha(str[i]) && islower(str[i])) {
            freq[str[i] - 'a']++;
        }
    }
}

void printFrequency(int *freq) {
    printf("Character Frequency:\n");
    for(int i=0; i<ALPHABET_SIZE; i++) {
        printf("%c : %d\n", i+'a', freq[i]);
    }
}

int main() {
    char input_str[MAX_LEN];
    int frequency[ALPHABET_SIZE] = {0};

    printf("Enter a string:\n");
    fgets(input_str, MAX_LEN, stdin);

    countFrequency(input_str, frequency);
    printFrequency(frequency);

    return 0;
}