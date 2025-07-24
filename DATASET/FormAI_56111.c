//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Function to convert a character to ASCII art
void char_to_ascii_art(char c) {
    switch(c) {
        case 'A': printf("  /\\"); break;
        case 'B': printf(" ___"); break;
        case 'C': printf("(_ _)"); break;
        case 'D': printf(" |)"); break;
        case 'E': printf("|||"); break;
        case 'F': printf("``/"); break;
        case 'G': printf("/(,)\\"); break;
        case 'H': printf("<>|"); break;
        case 'I': printf("/==\\"); break;
        case 'J': printf("_/)"); break;
        case 'K': printf("|<"); break;
        case 'L': printf("######"); break;
        case 'M': printf("//\\\\"); break;
        case 'N': printf("\\\\//"); break;
        case 'O': printf("(oo)"); break;
        case 'P': printf("---/"); break;
        case 'Q': printf("(_|_)"); break;
        case 'R': printf("|>"); break;
        case 'S': printf("``/"); break;
        case 'T': printf("/^\\"); break;
        case 'U': printf("| |"); break;
        case 'V': printf("\\_/"); break;
        case 'W': printf("\\\\//"); break;
        case 'X': printf("\\_//"); break;
        case 'Y': printf("\\^/"); break;
        case 'Z': printf("/--\\"); break;
        case ' ': printf("   "); break;
        default: break;
    }
}

int main() {
    char input[100];
    printf("Enter a String: ");
    fgets(input, 100, stdin);

    printf("\nASCII Art Output:\n\n");
    for(int i = 0; i < strlen(input); i++) {
        char c = toupper(input[i]);
        char_to_ascii_art(c);
        printf("  ");
    }
    
    printf("\n");
    return 0;
}