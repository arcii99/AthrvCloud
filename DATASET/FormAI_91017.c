//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>

int main() {
    char text[100], c;
    int i, j, k;
    printf("Enter a text: ");
    fgets(text, 100, stdin);

    // loop through each letter in the text
    for (i = 0; text[i] != '\0'; i++) {
        
        // get the ASCII value of the letter
        int ascii_val = (int)text[i];
        
        // loop through each row of the ASCII art
        for (j = 0; j < 8; j++) {
            
            // loop through each column of the ASCII art
            for (k = 0; k < 8; k++) {
                
                // check if the current bit in the ASCII value is 1 or 0 
                if (ascii_val & (1 << (7 - (k + 8*j)))) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}