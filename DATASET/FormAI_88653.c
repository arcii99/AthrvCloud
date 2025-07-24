//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 10000

/**
 * @brief This function takes a string as input and returns the string with all vowels removed. 
 * 
 * @param str A string that contains all the vowels
 * @return char* The resultant string with all vowels removed
 */
char* removeVowels(char* str) {
    char *newStr = malloc(MAX_STR_LEN * sizeof(char));
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            newStr[j] = str[i];
            j++;
        }
    }
    newStr[j] = '\0'; // Adding null character at the end of the string
    return newStr;
}

int main() {
    char text[MAX_STR_LEN];
    printf("Please enter some text:\n");
    fgets(text, MAX_STR_LEN, stdin);
    char *newText = removeVowels(text);
    printf("Text without vowels: %s\n", newText);
    free(newText);
    return 0;
}