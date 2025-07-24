//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int freq[26];
    int paranoid_count = 0;

    // Initialize all frequencies to 0
    for(int i=0; i<26; i++) {
        freq[i] = 0;
    }

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    // Calculate frequency of each character
    for(int i=0; i<strlen(input); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            freq[input[i]-'A']++;
        }
        else if(input[i] >= 'a' && input[i] <= 'z') {
            freq[input[i]-'a']++;
        }
    }

    // Print frequencies of each character
    printf("Character Frequency\n");
    for(int i=0; i<26; i++) {
        if(freq[i] > 0) {
            printf("%c \t\t %d\n", i+'a', freq[i]);
        }
    }

    // Check for paranoid words
    if(freq['C'-'A'] > 0 && freq['r'-'a'] > 0 && freq['a'-'a'] > 1 && freq['z'-'a'] > 0 && freq['y'-'a'] > 0) {
        paranoid_count++;
    }
    if(freq['h'-'a'] > 0 && freq['a'-'a'] > 0 && freq['c'-'a'] > 0 && freq['k'-'a'] > 0) {
        paranoid_count++;
    }
    if(freq['b'-'a'] > 0 && freq['a'-'a'] > 0 && freq['c'-'a'] > 0 && freq['k'-'a'] > 0) {
        paranoid_count++;
    }

    printf("\nNumber of paranoid words found: %d\n", paranoid_count);

    return 0;
}