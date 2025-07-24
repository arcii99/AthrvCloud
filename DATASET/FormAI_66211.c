//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int wordCount = 0;
    printf("Enter text: ");
    fgets(text, 1000, stdin); // Allows for spaces and special characters

    // Convert the text to lowercase
    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    // Initialize an array to store frequencies of each character
    int charFreq[26] = {0};

    // Loop through the text and count the frequency of each character
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            int index = text[i] - 'a';
            charFreq[index]++;
        }
        else if (text[i] == ' ' || text[i] == '\n') {
            wordCount++;
        }
    }

    // Output the frequency of each character and the total word count
    printf("Character frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', charFreq[i]);
    }
    printf("Total word count: %d\n", wordCount);
    
    return 0;
}