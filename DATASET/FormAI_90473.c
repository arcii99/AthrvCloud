//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void convertToASCII(char* text) {
    int length = strlen(text);
    
    // Print top border
    for(int i=0; i<(length*8)+3; i++) {
        printf("*");
    }
    printf("\n");
    
    // Print top row of characters
    printf("* ");
    for(int i=0; i<length; i++) {
        printf("%c     * ", text[i]);
    }
    printf("\n");
    
    // Print middle rows of characters
    printf("* ");
    for(int i=0; i<length; i++) {
        printf("*     * ");
    }
    printf("\n");
    printf("* ");
    for(int i=0; i<length; i++) {
        printf("*  %c  * ", text[i]);
    }
    printf("\n");
    printf("* ");
    for(int i=0; i<length; i++) {
        printf("*     * ");
    }
    printf("\n");
    
    // Print bottom row of characters
    printf("* ");
    for(int i=0; i<length; i++) {
        printf("%c     * ", text[i]);
    }
    printf("\n");
    
    // Print bottom border
    for(int i=0; i<(length*8)+3; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    char userInput[50];
    printf("Enter text to convert to ASCII art: ");
    scanf("%s", userInput);
    
    convertToASCII(userInput);
    
    return 0;
}