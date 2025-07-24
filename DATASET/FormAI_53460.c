//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate(char* input, char* output) {
    int i;
    for(i = 0; i < strlen(input); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = input[i] + 32;
        } else if(input[i] >= 'a' && input[i] <= 'z') {
            output[i] = input[i] - 32;
        } else {
            output[i] = input[i];
        }
    }
}

int main() {
    char input[1000], output[1000];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character at end of input
    
    printf("\n----------\nTranslation\n----------\n");
    translate(input, output);
    printf("%s\n", output);
    
    return 0;
}