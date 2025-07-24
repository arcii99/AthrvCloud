//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>

// Function to print ASCII art of a given character
void print_ascii_art(char ch) {

    switch(ch) {
        
        case 'A':
        case 'a':
            printf("    ###\n");
            printf("   ## ##\n");
            printf("  ##   ##\n");
            printf(" ##     ##\n");
            printf("#########\n");
            printf("##       ##\n");
            printf("##       ##\n");
            break;
            
        case 'B':
        case 'b':
            printf("########\n");
            printf("##      ##\n");
            printf("##      ##\n");
            printf("########\n");
            printf("##      ##\n");
            printf("##      ##\n");
            printf("########\n");
            break;
            
        case 'C':
        case 'c':
            printf("   #####\n");
            printf(" ##     ##\n");
            printf("##\n");
            printf("##\n");
            printf("##\n");
            printf(" ##     ##\n");
            printf("   #####\n");
            break;
            
        // Add more cases for other characters
        
        default:
            printf("Invalid character entered!\n");
    }
}

int main() {

    char ch;
    
    printf("Enter a character: ");
    scanf("%c", &ch);
    
    print_ascii_art(ch);
    
    return 0;
}