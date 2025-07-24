//FormAI DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    printf("Enter some text: ");
    scanf("%[^\n]", text); // Read until new line character
    printf("\nOriginal text:\n%s\n", text);

    // Removing vowels from the text
    char new_text[1000];
    int j = 0;
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            new_text[j++] = c;
        }
    }
    new_text[j] = '\0';
    printf("\nText without vowels:\n%s\n", new_text);

    // Reversing the text
    char reversed_text[1000];
    j = 0;
    for (int i = strlen(text) - 1; i >= 0; i--) {
        reversed_text[j++] = text[i];
    }
    reversed_text[j] = '\0';
    printf("\nReversed text:\n%s\n", reversed_text);

    // Finding the number of words in the text
    int num_words = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            num_words++;
        }
    }
    num_words++; // Last word doesn't have a space after it
    printf("\nNumber of words in the text: %d\n", num_words);

    // Converting the text to all uppercase
    for (int i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }
    printf("\nText in uppercase:\n%s\n", text);

    return 0;
}