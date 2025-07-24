//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: recursive
#include<stdio.h>
#include<string.h>

char* cat_language_translator(char* input_string, int n) {
    // Base case
    if(n == 0) {
        char* output_string = (char*)malloc(sizeof(char));
        output_string[0] = '\0';
        return output_string;
    }
    // Recursive case
    else {
        char* output_string_prev = cat_language_translator(input_string, n-1);
        int output_length_prev = strlen(output_string_prev);
        char* output_string = (char*)malloc(sizeof(char) * (output_length_prev + 2));
        strcpy(output_string, output_string_prev);
        output_string[output_length_prev] = input_string[n-1];
        output_string[output_length_prev+1] = input_string[n-1];
        output_string[output_length_prev+2] = '\0';
        free(output_string_prev);
        return output_string;
    }
}

int main() {
    char input_string[20];
    printf("Enter the string to translate in C Cat Language: ");
    scanf("%s", input_string);
    int input_length = strlen(input_string);
    char* output_string = cat_language_translator(input_string, input_length);
    printf("Translated string: %s", output_string);
    free(output_string);
    return 0;
}