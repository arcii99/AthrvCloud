//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin); // read input from user
    
    printf("Your sanitized input: ");
    for(int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if(c >= 'a' && c <= 'z') { // if lowercase character
            c = c - 32; // convert to uppercase
        }
        if(c >= 'A' && c <= 'Z' || c == ' ' || c == '\n') { // if uppercase character, space or newline
            printf("%c", c); // print character
        }
    }
    printf("\n"); // newline after input
    return 0;
}