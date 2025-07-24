//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to print ASCII art of the entered text */
void printAsciiArt(char* text) {
    char* asciiArt[7][10] = {
        {"###### ", "#     #", "#     #", "#######", "#     #", "#     #", "#######", "\n"},
        {"#######", "#      ", "#      ", "###### ", "#      ", "#      ", "#######", "\n"},
        {" ######", "#     #", "      #", "      #", "      #", "#     #", " ######", "\n"},
        {"#######", "      #", "      #", " ######", "      #", "      #", "#######", "\n"},
        {"#     #", "#     #", "#     #", "#######", "      #", "      #", "      #", "\n"},
        {"#######", "#      ", "#      ", "###### ", "#      ", "#      ", "#      ", "\n"},
        {" ######", "#     #", "      #", "  #####", "#     #", "#     #", " ######", "\n"}
    };
    
    // Print ASCII art line by line
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < strlen(text); j++) {
            if(text[j] >= 'a' && text[j] <= 'z') {
                printf("%s", asciiArt[i][text[j] - 'a']);
            } else if(text[j] >= 'A' && text[j] <= 'Z') {
                printf("%s", asciiArt[i][text[j] - 'A']);
            } else {
                printf("          "); // Space for non-alphabets
            }
        }
        printf("\n");
    }
}

int main() {
    char text[50];

    printf("Enter the text you want to convert to ASCII art: ");
    scanf("%[^\n]s", text); // Read the input text with spaces

    printAsciiArt(text); // Call the function to print ASCII art of the entered text

    return 0;
}