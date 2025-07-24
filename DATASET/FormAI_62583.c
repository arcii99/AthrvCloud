//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {

// ASCII art characters have a height and width of 8 pixels.

char asciiArt[8][8];

/* Define the characters to generate ASCII art for */

char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
                     'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                     'W', 'X', 'Y', 'Z'};

int numChars = sizeof(characters)/sizeof(char);

/* Loop through each character and generate ASCII art */

for (int i=0; i<numChars; i++) {
    
    /* Convert the character to its ASCII code */
    
    int asciiCode = (int)characters[i];
    
    /* Generate the ASCII art */
    
    for (int j=0; j<8; j++) {
        for (int k=0; k<8; k++) {
            
            int bit = asciiCode & (1 << (7 - (j * 8 + k)));
            
            if (bit) {
                asciiArt[j][k] = '#';
            } else {
                asciiArt[j][k] = '.';
            }
        }
    }
    
    /* Print the ASCII art */
    
    printf("ASCII art for character '%c':\n", characters[i]);
    
    for (int j=0; j<8; j++) {
        for (int k=0; k<8; k++) {
            printf("%c ", asciiArt[j][k]);
        }
        printf("\n");
    }
    
    printf("\n");
}

return 0;
}