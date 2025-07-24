//FormAI DATASET v1.0 Category: Text processing ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to remove all Newline, Tab, Space characters
void removeWhiteSpace(char *str) {
    char *temp = str;
    while (*str) {
        if (*str != ' ' && *str != '\n' && *str != '\t')
            *temp++ = *str;
        str++;
    }
    *temp = '\0';
}

// function to reverse a text string
void reverseText(char *str) {
    int i, j;
    int len = strlen(str);
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char text[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // remove all white space characters from the text
    removeWhiteSpace(text);
    printf("Text after removing white space: %s\n", text);

    // reverse the text string
    reverseText(text);
    printf("Text after reversing string: %s\n", text);

    return 0;
}