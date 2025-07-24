//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to convert a given character to ASCII art
void convertToASCII(char c) {
    switch (c) {
        case 'A':
        case 'a':
            printf("  # #  \n");
            printf(" #   # \n");
            printf("#     #\n");
            printf("#######\n");
            printf("#     #\n");
            break;
        case 'B':
        case 'b':
            printf("###### \n");
            printf("#     #\n");
            printf("###### \n");
            printf("#     #\n");
            printf("###### \n");
            break;
        case 'C':
        case 'c':
            printf(" ##### \n");
            printf("#      \n");
            printf("#      \n");
            printf("#      \n");
            printf(" ##### \n");
            break;
        // Add more cases as required
        
        default:
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            break;
            
    }
}

int main() {
    char input[1000];
    int len, i;
    
    printf("Enter a string to convert to ASCII art: ");
    fgets(input, sizeof(input), stdin);
    
    len = strlen(input)-1;
    
    for (i = 0; i < len; i++) {
        convertToASCII(input[i]);
    }
    
    return 0;
}