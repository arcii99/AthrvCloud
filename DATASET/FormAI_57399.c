//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence in Cat Language: ");
    fgets(input, 100, stdin);

    char output[100];
    int i, j = 0;
    for(i=0; i < strlen(input); i++) {
        if(input[i] == 'm') {
            output[j] = 'c';
            j++;
        } else if(input[i] == 'e') {
            output[j] = 'a';
            j++;
        } else if(input[i] == 'o') {
            output[j] = 't';
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';

    printf("The translated sentence in C Language is: %s\n", output);
    return 0;
}