//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char english[MAX_INPUT_LENGTH];
    char c_cat[MAX_INPUT_LENGTH];
    int i, j = 0;

    printf("Enter English text to translate to C Cat Language:\n");
    fgets(english, MAX_INPUT_LENGTH, stdin);

    for (i = 0; i < strlen(english) - 1; i++) {
        if(english[i] == ' ') {
            c_cat[j++] = 'm';
            c_cat[j++] = 'e';
        } else if(english[i] >= 'a' && english[i] <= 'z') {
            c_cat[j++] = english[i] - 32;
            c_cat[j++] = 'e';
        } else if(english[i] >= 'A' && english[i] <= 'Z') {
            c_cat[j++] = english[i];
            c_cat[j++] = 'e';
        } else if(english[i] == ',' || english[i] == '.') {
            c_cat[j++] = english[i];
            c_cat[j++] = ' ';
        } else {
            // character not currently supported
            printf("Unable to translate character: %c\n", english[i]);
        }
    }

    c_cat[j] = '\0';

    printf("\nEnglish Translation: %sC Cat Translation: %s\n", english, c_cat);

    return 0;
}