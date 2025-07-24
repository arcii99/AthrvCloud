//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <ctype.h>

// Define the dimensions of the ASCII art
#define ROWS 10
#define COLUMNS 50

// Define the maximum input length to prevent buffer overflow
#define MAX_INPUT_LENGTH 100

// Function to print ASCII art of a given character
void print_ascii_art(char c) {
    // Initialize the ASCII art
    char ascii_art[ROWS][COLUMNS] = {
        "  # # # # # # # # # # # # # # # # # # # # # # # # # #",
        "  #                                                 #",
        "  #                                                 #",
        "  #                                                 #",
        "  #                                                 #",
        "  #                                                 #",
        "  #                                                 #",
        "  #                                                 #",
        "  #                                                 #",
        "  # # # # # # # # # # # # # # # # # # # # # # # # # #",
    };
    
    // Replace the whitespace with the character
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (isspace(ascii_art[i][j])) {
                ascii_art[i][j] = c;
            }
        }
    }
    
    // Print the ASCII art
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", ascii_art[i]);
    }
}

int main() {
    // Initialize the user input variable
    char user_input[MAX_INPUT_LENGTH];
    
    // Prompt the user for input
    printf("Enter a character: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    
    // Print the ASCII art of the given character
    if (isascii(user_input[0]) && !isspace(user_input[0])) {
        print_ascii_art(user_input[0]);
    } else {
        printf("Invalid input! Please enter a valid character.\n");
    }
    
    return 0;
}