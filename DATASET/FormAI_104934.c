//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>

// Define ASCII art characters as constants
const char H = 72;
const char E = 69;
const char L = 76;
const char O = 79;
const char W = 87;
const char R = 82;
const char D = 68;

int main() {
    // Print out the letters as ASCII art
    printf("  %c%c%c%c%c\n", H, H, H, H, H);
    printf("  %c   %c\n", H, H);
    printf("  %c%c%c%c%c\n\n", H, H, H, H, H);
    
    printf("  %c%c%c%c\n", E, E, E, E);
    printf("  %c   \n", E);
    printf("  %c%c%c%c\n\n", E, E, E, E);
    
    printf("  %c   \n", L);
    printf("  %c   \n", L);
    printf("  %c%c%c%c%c\n\n", L, L, L, L, L);
    
    printf("  %c%c%c%c%c\n", O, O, O, O, O);
    printf("     %c\n", O);
    printf("  %c%c%c%c%c\n\n", O, O, O, O, O);
    
    printf("  %c   %c   %c   %c\n", W, R, L, D);
    printf("  %c %c %c %c %c %c\n", W, R, L, L, R, D);
    printf("    %c%c %c%c\n", W, W, D, D);
    
    return 0;
}