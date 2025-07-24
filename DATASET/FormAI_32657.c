//FormAI DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple QR-code generator in C 
   in the style of Ken Thompson */

#define MAX_CODE_LENGTH 50

int main() {

    // Define the QR code string and its maximum length
    char code[MAX_CODE_LENGTH] = "";
    int code_length = 0;
    
    // Get the input data from the user
    printf("Enter data to convert into QR code: ");
    fgets(code, MAX_CODE_LENGTH, stdin);
    code_length = strlen(code);
    
    // Remove the newline character from the end of the input
    if (code[code_length-1] == '\n') {
        code[code_length-1] = '\0';
        code_length--;
    }
    
    // Generate the QR code
    printf("\nQR code for \"%s\":\n", code);
    printf("+");
    for (int i = 0; i < code_length + 2; i++) {
        printf("-");
    }
    printf("+\n");
    for (int i = 0; i < code_length; i++) {
        printf("| %c", code[i]);
    }
    printf(" |\n");
    printf("+");
    for (int i = 0; i < code_length + 2; i++) {
        printf("-");
    }
    printf("+\n\n");

    return 0;
}