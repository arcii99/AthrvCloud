//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Max length of the input string

/*
 * Function to translate the input string from Cat Language to English
 */
char* translateToEnglish(char* input) {
    char output[MAX_LENGTH] = "";
    int i, j = 0;
    for(i = 0; i < strlen(input); i++) {
        if(input[i] == 'M' && input[i+1] == 'e') {
            output[j] = 'I'; // Replace 'Me' with 'I'
            i++;
        } else if(input[i] == '(' && input[i+1] == 'a' && input[i+2] == ')') {
            output[j] = 'a'; // Replace '(a)' with 'a'
            i += 2;
        } else if(input[i] == '(' && input[i+1] == 'i' && input[i+2] == ')') {
            output[j] = 'i'; // Replace '(i)' with 'in'
            output[j+1] = 'n';
            i += 2;
            j++;
        } else if(input[i] == '(' && input[i+1] == 'o' && input[i+2] == ')') {
            output[j] = 'o'; // Replace '(o)' with 'out'
            output[j+1] = 'u';
            output[j+2] = 't';
            i += 2;
            j += 2;
        } else if(input[i] == ' ') {
            output[j] = ' '; // Keep spaces as is
        }
        j++;
    }
    return strdup(output); // Return the translated string
}

/*
 * Main function
 */
int main() {
    char input[MAX_LENGTH];
    printf("Enter a string in Cat Language:\n");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0'; // Replacing newline character at the end with null character
    char* output = translateToEnglish(input);
    printf("Translated string: %s\n", output);
    return 0;
}