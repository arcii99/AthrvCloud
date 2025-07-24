//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000 // The maximum length of input string

void printAsciiArt(char *str);

int main() {
    char inputStr[MAX_LEN];
    printf("Please enter the text you want to convert to ASCII art: ");
    fgets(inputStr, MAX_LEN, stdin); // Getting input from user

    printf("\n");

    printAsciiArt(inputStr); // Calling function to print ASCII art

    return 0;
}

void printAsciiArt(char *str) {
    int len = strlen(str); // Getting the length of input string
    int asciiArt[128][8] = {0};

    for (int i = 0; i < len; i++) { 
        int asciiVal = str[i];
        if (asciiVal == 10) { // Checking for newline character
            printf("\n");
            continue;
        }
        for (int j = 0; j < 8; j++) { 
            asciiArt[asciiVal][j] = (asciiVal >> j) & 1; // Converting ASCII value to binary
        }
    }

    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < len; j++) { 
            for (int k = 0; k < 8; k++) { 
                if (asciiArt[str[j]][i] == 1) { // If the bit is set, print *
                    printf("*");
                } else { // Else print a space
                    printf(" ");
                }
            }
            printf(" "); // Space between characters
        }
        printf("\n");
    }
}