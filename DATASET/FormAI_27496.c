//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

const char ascii_chart[95][8] = {
    "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", 
    "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", 
    "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", 
    "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", 
    "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", 
    "  ", "  ", "  ", "  ", "__", "|__)", "|   ", "|__)", "  ", 
    " _ ", "/ \\","| |","|_||","| |"," /\\ ","(( ))","/\\","_\\/_", 
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", 
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", 
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", 
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", 
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ",
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ",
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ",
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ",
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ",
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ",
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ",
    "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "
};

void convertToASCII(char* text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        char c = toupper(text[i]);
        if (isalpha(c)) {
            printf("%s", ascii_chart[c - 32]);
        }
        else {
            printf("   ");
        }
    }
    printf("\n");
}

int main()
{
    char input[100];
    printf("Enter Text: ");
    fgets(input, sizeof(input), stdin); 
    printf("\n");
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        convertToASCII(&input[i]);
    }
    return 0;
}