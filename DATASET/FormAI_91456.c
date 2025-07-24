//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_language[1000];
    printf("Welcome to C Cat Language Translator!\n");
    printf("Please enter your phrase in C Cat Language: ");
    fgets(c_cat_language, 1000, stdin);
    int length = strlen(c_cat_language);
    // Replacing all occurrences of "meow" with "happy"
    for(int i = 0; i < length; i++) {
        if(c_cat_language[i] == 'm' && c_cat_language[i+1] == 'e' && c_cat_language[i+2] == 'o' && c_cat_language[i+3] == 'w') {
            c_cat_language[i] = 'h';
            c_cat_language[i+1] = 'a';
            c_cat_language[i+2] = 'p';
            c_cat_language[i+3] = 'p';
            c_cat_language[i+4] = 'y';
        }
    }
    printf("Your phrase in human language: %s", c_cat_language);
    printf("\nThank you for using our C Cat Language Translator. Have a happy day!");
    return 0;
}