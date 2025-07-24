//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence in C Cat Language: ");
    fgets(input, 100, stdin);
    
    char output[1000] = "";
    char temp[1000];
    
    int i, j;
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        switch(input[i]) {
            case 'c':
                strcat(output, "meow");
                break;
            case 'C':
                strcat(output, "MEOW");
                break;
            case ' ':
                strcat(output, " ");
                break;
            case '\n':
                strcat(output, "\n");
                break;
            default:
                sprintf(temp, "%c", input[i]);
                strcat(output, temp);
        }
    }
    
    printf("Translated sentence: %s\n", output);
    return 0;
}