//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include<stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define CHARSET_SIZE 94

int main() {
    // Declare variables
    int i, j, k, ascii, count;
    char text[MAX_ROWS][MAX_COLS+1];
    char charset[CHARSET_SIZE] = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', 
                                  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', 
                                  '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 
                                  'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', 
                                  '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 
                                  'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~'};

    // Get user input
    printf("Enter text to be converted to ASCII art:\n");
    for(i=0; i<MAX_ROWS; i++) {
        fgets(text[i], MAX_COLS+1, stdin); // Use fgets to allow spaces in input
    }

    // Convert text to ASCII art
    for(i=0; i<MAX_ROWS; i++) {
        for(j=0; j<MAX_COLS && text[i][j] != '\0' && text[i][j] != '\n'; j++) {
            ascii = (int) text[i][j];
            if(ascii < 32 || ascii > 126) { // Check for invalid characters
                printf("Error: \"%c\" is not a valid character.\n", text[i][j]);
                return 1;
            }
            count = 0;
            for(k=0; k<CHARSET_SIZE; k++) { // Search for matching character in charset
                if(charset[k] == text[i][j]) {
                    count = k;
                    break;
                }
            }
            for(k=0; k<8; k++) { // Print ASCII artwork for each row of character
                if((count >> k) % 2 == 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n"); // Separate rows of ASCII art
    }

    return 0;
}