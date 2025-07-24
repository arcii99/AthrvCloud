//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_LEN 255 // max length of input string

// function to convert character to ASCII art
void charToArt(char c) {
    switch(c) {
        case 'a':
        case 'A':
            printf("  /\\  \n /  \\ \n/____\\\n/\\   /\\ \n/  \\ /  \\ \n");
            break;
        case 'b':
        case 'B':
            printf("||||| \n||||| \n||||| \n||||| \n||||| \n");
            break;
        case 'c':
        case 'C':
            printf("   _____ \n /      \\\n/        \\\n\\        /\n \\_____/\n");
            break;
        // add more cases for each character
        // ...
        default:
            printf("Cannot convert '%c' to ASCII art.\n", c);
            break;
    }
}

int main() {
    char input[MAX_LEN];
    printf("Enter a string to convert to ASCII art:\n");
    fgets(input, MAX_LEN, stdin);   // read input string from user
    input[strcspn(input, "\n")] = '\0';   // remove newline character
    
    int len = strlen(input);
    for(int i=0; i<len; i++) {
        charToArt(input[i]);    // convert each character to ASCII art
    }
    
    return 0;
}