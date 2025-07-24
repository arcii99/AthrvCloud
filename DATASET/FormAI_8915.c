//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

// Define the ASCII art for each letter
const char *letters[] = {
    "  ######  \n #     # \n #     # \n #     # \n #     # \n #     # \n  ######  \n",
    "  #####  \n #     # \n #       \n #       \n #       \n #       \n ####### \n",
    " ######  \n #     # \n       # \n  #####  \n       # \n #     # \n ######  \n",
    // Define the ASCII art for the remaining letters here...
};

// Define the function that generates the ASCII art
void generate_ascii_art(char *text) {
    int len = strlen(text);

    for (int i = 0; i < 7; i++) { // For each line of the ASCII art
        for (int j = 0; j < len; j++) { // For each letter in the input text
            char c = text[j];
            int index = c - 'A'; // Convert the letter to an index into the letters array
            if (index >= 0 && index <= 25) {
                printf("%s", letters[index] + (i * (MAX_LINE_LENGTH + 1))); // Print the appropriate line of the ASCII art
            } else {
                printf("                                                 "); // Print a blank space for non-alphabetic characters
            }
        }
        printf("\n"); // Move to the next line of the ASCII art
    }
}

int main() {
    char text[MAX_LINE_LENGTH];
    printf("Enter some text to generate ASCII art: ");
    fgets(text, MAX_LINE_LENGTH, stdin);
    generate_ascii_art(text);
    return 0;
}