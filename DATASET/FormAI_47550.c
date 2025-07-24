//FormAI DATASET v1.0 Category: Text processing ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// function to remove whitespace from given string
char* removeWhitespace(char* str) {
    int i, j;
    for(i = 0; str[i]; i++) {
        if(!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}

int main() {
    char str[100];
    printf("Enter a string to remove whitespace : ");
    fgets(str, sizeof(str), stdin);
    char* strWithoutSpace = removeWhitespace(str);
    printf("String without Whitespace is : ");
    printf("%s", strWithoutSpace);
    return 0;
}