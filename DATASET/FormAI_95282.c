//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processString(char* str, int pos)
{
    if(str[pos] == '\0') {
        return;
    }
    if(isalpha(str[pos])) {
        putchar(str[pos] + 1);
    } else if(isdigit(str[pos])) {
        putchar(str[pos]);
        processString(str, pos + 1);
    } else {
        processString(str, pos + 1);
        putchar(str[pos]);
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Processed string: ");
    processString(str, 0);
    return 0;
}