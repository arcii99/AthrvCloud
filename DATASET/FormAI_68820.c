//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[] = "This is an example program illustrating text processing in C programming language. The program reads a string from user and performs various operations like counting words, counting characters, capitalizing the first letter of each word, and printing the string in reverse.";
    int text_length = strlen(text);
    int word_count = 1;
    int capital_letter_count = 0;
    int white_space_count = 0;

    printf("Original Text:\n%s\n", text);

    // Count the number of words in the text
    for(int i = 0; i < text_length; i++) {
        if(text[i] == ' ')
            word_count++;
    }

    printf("\nWord count: %d\n", word_count);

    // Count the number of characters in the text
    printf("Character count: %d\n", text_length);

    // Capitalize the first letter of each word in the text
    for(int i = 0; i < text_length; i++) {
        if(i == 0 || (text[i-1] == ' ' && i > 0)) {
            if(text[i] >= 'a' && text[i] <= 'z') {
                text[i] = text[i] - 32;
                capital_letter_count++;
            }
        }
    }

    printf("\nCapitalized text:\n%s\n", text);
    printf("Number of capitalized letters: %d\n", capital_letter_count);

    // Reverse the text
    char temp;
    for(int i = 0, j = text_length - 1; i < text_length / 2; i++, j--) {
        temp = text[i];
        text[i] = text[j];
        text[j] = temp;
    }

    printf("\nReversed text:\n%s\n", text);

    return 0;
}