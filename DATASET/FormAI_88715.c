//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_COLS 40

void generateArt(char asciiArt[MAX_ROWS][MAX_COLS], char text[]) {
    int len = strlen(text);
    int symCount = 0;
    int symIndex = 0;
    
    char symbols[] = {'$', '#', '@', '&', '%', '!', '+', '*', '-', '/', '|', '^', '~', '.', ' '};
    
    for (int i = 0; i < len; i++) {
        // Map symIndex to length of symbols array
        if (symIndex == (sizeof(symbols)/sizeof(char))) {
            symIndex = 0; 
        }
        
        // Loop until we have filled a row with characters
        while (symCount < MAX_COLS) {
            if (i >= len) {
                // End of input text, fill with spaces
                asciiArt[symIndex][symCount] = ' ';
            } else {
                // Map character to symbol and fill to MAX_COLS
                int asciiCode = (int) text[i];
                int symbolIndex = asciiCode % (sizeof(symbols)/sizeof(char));
                asciiArt[symIndex][symCount] = symbols[symbolIndex];
            }
            
            symCount++;
        }
        
        // Reset symCount and move to next row
        symCount = 0;
        symIndex++;
        
        // If we have filled all rows, print ascii art and reset
        if (symIndex == MAX_ROWS) {
            for (int row = 0; row < MAX_ROWS; row++) {
                for (int col = 0; col < MAX_COLS; col++) {
                    printf("%c", asciiArt[row][col]);
                }
                
                printf("\n");
            }
            
            printf("\n");
            
            // Reset asciiArt array
            for (int row = 0; row < MAX_ROWS; row++) {
                for (int col = 0; col < MAX_COLS; col++) {
                    asciiArt[row][col] = ' ';
                }
            }
            
            // Move to next row
            symIndex = 0;
        }
    }
}

int main(void) {
    char asciiArt[MAX_ROWS][MAX_COLS];
    char text[] = "Hello World!";
    
    generateArt(asciiArt, text);
    
    return 0;
}