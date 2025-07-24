//FormAI DATASET v1.0 Category: Data validation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    
    char input[50];
    int valid = 1;
    
    printf("Enter a string containing only letters and digits (up to 50 characters):\n");
    fgets(input, 50, stdin);
    
    for (int i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i])) {  // isalnum checks if the character is an alphabet or digit
            valid = 0;
            break;
        }
    }
    
    if (valid) {
        printf("Input is valid!\n");
    }
    else {
        printf("Input is invalid.\n");
    }
    
    return 0;
}