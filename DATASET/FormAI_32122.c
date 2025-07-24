//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include <stdio.h>

int main() {
    char input[200]; // to store user input
    char ascii[8][80] = {
    "                        __  ",
    "                     ~~/  | ",
    "                     |//\\| ",
    "      ==_________    \\_\\/",
    "       /         /~~\\   \\",
    "      /_________/\\__\\   \\",
    "     |   TRAVEL   |   |",
    "     |____________|   |"
    }; // a sample ASCII art
    
    printf("Enter your text: ");
    scanf("%[^\n]", input); // to get user input including spaces
    
    // to print the ASCII art with user input
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < strlen(input) + 2; j++) {
            if (i == 3 && j == strlen(input)/2 + 1) {
                printf("%c ", ascii[i][j]); // to put user input in the middle of the ASCII art
            }
            else if (j == 0 || j == strlen(input) + 1){
                printf("%c ", ascii[i][j]); // to print the vertical bars
            }
            else if (i == 0 && j >= strlen(input)/2 && j < strlen(input)/2 + 2){
                printf("%c ", input[j - 1]); // to print the first line of the user input in ascii art style
            }
            else if (i == 1 && j >= strlen(input)/2 - 1 && j < strlen(input)/2 + 3){
                printf("%c ", input[j - 2]); // to print the second line of the user input in ascii art style
            }
            else if (i == 2 && j >= strlen(input)/2 - 2 && j < strlen(input)/2 + 4){
                printf("%c ", input[j - 3]); // to print the third line of the user input in ascii art style
            }
            else {
                printf("  "); // to print spaces for everything else
            }
        }
        printf("\n"); // to go to the next line
    }
    
    return 0;
}