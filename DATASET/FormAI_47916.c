//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
// A Genius Word Frequency Counter Program
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_SIZE 1000

int main() {
    char text[MAX_SIZE];
    int freq[MAX_SIZE];
    int i, j, totalchars = 0;
    bool isUnique;

    // Read input text from user
    printf("Enter text: ");
    fgets(text, MAX_SIZE, stdin);
    
    // Calculate total character count in input text
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            totalchars++;
        }
    }
    
    // Count frequency of each word in input text
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int count = 1;
            for (j = i + 1; text[j] != '\0'; j++) {
                if (tolower(text[i]) == tolower(text[j])) {
                    count++;
                    text[j] = '*'; // mark duplicate characters with *
                }
            }
            freq[i] = count;
        }
    }
    
    // Print frequency of each unique word
    printf("\nFrequency of each word:\n");
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ' && text[i] != '*') {
            isUnique = true;
            for (j = i + 1; text[j] != '\0'; j++) {
                if (tolower(text[i]) == tolower(text[j])) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                printf("%c: %d/%d\n", tolower(text[i]), freq[i], totalchars);
            }
        }
    }

    return 0;
}