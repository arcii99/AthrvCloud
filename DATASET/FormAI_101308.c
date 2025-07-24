//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <string.h>

// Function to convert character to ASCII art
void toAscii(char c){

    // Array of ASCII art characters
    char asciiArt[7][6] = {
        "  ##  ",
        " #  # ",
        "#    #",
        "######",
        "#    #",
        "#    #"
    };

    // Convert character to ASCII index
    int asciiIndex = (int) c - 97;

    // Print ASCII art character
    printf("%s", asciiArt[asciiIndex]);
}


// Main function
int main(){

    // Prompt user for input
    printf("Enter a word or phrase: ");

    // Get user input
    char input[100];
    fgets(input, 100, stdin);

    // Strip newline character from input
    input[strcspn(input, "\n")] = 0;

    // Loop through each character of input and print ASCII art
    for(int i = 0; i < strlen(input); i++){
        toAscii(input[i]);
    }

    return 0;
}