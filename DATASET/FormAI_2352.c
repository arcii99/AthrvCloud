//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print ASCII Art
void printArt(char *text)
{
    // Define the ASCII Art
    char art[256][256] = {
        {"   _____                    _____ _ _   \n"},
        {"  / ____|                  / ____(_) |  \n"},
        {" | |     _ __ ___  ___ ___| (___  _| |_ \n"},
        {" | |    | '__/ _ \\/ __/ _ \\\\___ \\| | __|\n"},
        {" | |____| | |  __/ (_|  __/____) | | |_ \n"},
        {"  \\_____|_|  \\___|\\___\\___|_____/|_|\\__|\n\n"}
    };

    // Determine the length of the text and allocate memory for it
    int len = strlen(text);
    char *upperText = malloc(len * sizeof(char));
    
    // Copy text to upperText in uppercase
    for(int i = 0; i < len; i++){
        upperText[i] = toupper(text[i]);
    }

    // Print the ASCII Art
    for(int i=0; i<6; i++){
        printf("%s", art[i]);
    }
    printf("\n%s\n", upperText);
    
    // Free memory used by upperText
    free(upperText);
}

int main()
{
    // Prompt user to enter text
    printf("Enter Text: ");
    char text[256];
    fgets(text, 256, stdin);

    // Call printArt function to print ASCII Art
    printArt(text);

    return 0;
}