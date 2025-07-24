//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char input[500];
    char output[500];
    int i,j;
    
    printf("Welcome to the C Cat Language Translator\n");
    printf("Please enter a sentence in C Cat Language:\n");
    scanf("%[^\n]s", input);
    
    for (i=0, j=0; i<strlen(input); i++) {
        if (input[i] == 'c') {
            output[j++] = 'm';
            output[j++] = 'e';
            output[j++] = 'o';
            output[j++] = 'w';
        } else {
            output[j++] = input[i];
        }
    }
    
    output[j] = '\0';
    
    printf("\nTranslating...\n\n");
    printf("Your sentence in English is:\n%s\n", output);
    
    return 0;
}