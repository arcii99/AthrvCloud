//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <stdio.h>
#include <string.h>

void printLine(char ch, int len)
{
    for(int i=0; i<len; i++)
        putchar(ch);
    printf("\n");
}

void printCentralized(char* str, int len)
{
    int totalSpaces = len - strlen(str);
    int leftSpaces = totalSpaces/2;
    int rightSpaces = totalSpaces - leftSpaces;
    printf("|");
    printLine(' ', leftSpaces - 1);
    printf("%s", str);
    printLine(' ', rightSpaces);
    printf("|\n");
}

void printAsciiMedieval(char* str)
{
    int len = strlen(str) + 4;
    printLine('_', len);
    printCentralized(" ", len);
    printCentralized(str, len);
    printCentralized(" ", len);
    printLine('-', len);
    printf("\n");
}

int main()
{
    char inputStr[100];
    printf("Enter text to create Medieval Style ASCII Art: ");
    gets(inputStr); // Input string from user

    printAsciiMedieval(inputStr);

    return 0;
}