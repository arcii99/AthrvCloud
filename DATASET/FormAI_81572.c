//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>

int main() {
    // Declare variables to hold user input and ASCII art
    char input_str[100];
    char ascii_art[5][51];
    int char_index, i, j;
    
    // Prompt user for input string
    printf("Enter a string to convert to ASCII art (max 100 characters): ");
    fgets(input_str, 100, stdin);
    
    // Loop through each character in input string
    for (char_index = 0; char_index < strlen(input_str); char_index++) {
        // Convert character to ASCII code
        int ascii_code = (int)input_str[char_index];
        
        // Create ASCII art corresponding to ASCII code
        switch (ascii_code) {
            case 65:
                strcpy(ascii_art[0], "    #     ");
                strcpy(ascii_art[1], "   # #    ");
                strcpy(ascii_art[2], "  #####   ");
                strcpy(ascii_art[3], " #     #  ");
                strcpy(ascii_art[4], "#       # ");
                break;
            case 66:
                strcpy(ascii_art[0], " ######  ");
                strcpy(ascii_art[1], " #     # ");
                strcpy(ascii_art[2], " ######  ");
                strcpy(ascii_art[3], " #     # ");
                strcpy(ascii_art[4], " ######  ");
                break;
            // Add more cases for other ASCII codes...
            
            default:
                strcpy(ascii_art[0], "         ");
                strcpy(ascii_art[1], "         ");
                strcpy(ascii_art[2], "         ");
                strcpy(ascii_art[3], "         ");
                strcpy(ascii_art[4], "         ");
                break;
        }
        
        // Print ASCII art to console
        for (i = 0; i < 5; i++) {
            for (j = 0; j < strlen(ascii_art[i]); j++) {
                printf("%c", ascii_art[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}