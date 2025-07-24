//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[100], translation[10][10] = {
        {"a"}, {"b"}, {"c"}, {"d"}, {"e"}, {"f"}, {"g"}, {"h"}, {"i"}, {"j"}
    };
    
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter a word in the alien language: ");
    scanf("%s", &input);
    
    int length = strlen(input);
    int i;
    
    for (i = 0; i < length; i++) {
        int index = input[i] - 48;
        strcat(output, translation[index]);
    }
    printf("Translation in English: %s", output);
    
    return 0;
}