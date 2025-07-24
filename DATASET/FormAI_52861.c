//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Function to convert ASCII character to binary
void charToBinary(char c, char *binary) {
    for(int i = 7; i >= 0; i--) {
        if(c & (1 << i)) {
            strcat(binary, "1");
        } else {
            strcat(binary, "0");
        }
    }
}

// Function to print the ASCII art
void printAsciiArt(char *str) {
    // Loop through each character in the string
    for(int i = 0; i < strlen(str); i++) {
        // Print the character in binary
        char binary[9] = "";
        charToBinary(str[i], binary);
        
        // Loop through each bit in the binary representation
        for(int j = 0; j < strlen(binary); j++) {
            int num = binary[j] - '0';
            if(num) {
                printf("%c%c%c", 219, 219, 219);
            } else {
                printf("   ");
            }
        }
        
        // Print a new line for each row of the character
        printf("\n");
    }
}

int main() {
    // Get input from the user
    char input[256];
    printf("Enter a string: ");
    fgets(input, 256, stdin);
    
    // Print the ASCII art of the input
    printAsciiArt(input);
    
    return 0;
}