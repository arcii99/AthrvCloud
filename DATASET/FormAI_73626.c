//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>

int main() {
    char str[1000];
    int count[26] = {0};  // Initialize the counter array with all zeros
    int i, max_count = 0;
    char max_char;

    printf("Welcome to the C Word Frequency Counter!\n\n");
    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    // Count the frequency of each character in the string
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            count[str[i] - 'a']++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            count[str[i] - 'A']++;
        }
    }

    // Find the character with the maximum frequency count
    for(i = 0; i < 26; i++) {
        if(count[i] > max_count) {
            max_count = count[i];
            max_char = i + 'a';
        }
    }

    printf("\nFrequency of each character:\n\n");
    for(i = 0; i < 26; i++) {
        if(count[i] != 0) {
            printf("%c: %d\n", i + 'a', count[i]);
        }
    }

    printf("\nThe character with highest frequency is '%c' with frequency %d.\n", max_char, max_count);

    return 0;
}