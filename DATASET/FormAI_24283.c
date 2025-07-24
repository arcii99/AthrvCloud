//FormAI DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <ctype.h>

int wordCount(char *str) {
    int count = 0, i = 0;
    char prevChar = ' ';
    
    while (str[i] != '\0') {
        if (isspace(str[i]) && !isspace(prevChar)) {
            count++;
        }
        prevChar = str[i];
        i++;
    }
    
    if (!isspace(prevChar)) {
        count++;
    }
    
    return count;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    int count = wordCount(str);
    printf("The number of words in the given string is: %d", count);
    
    return 0;
}