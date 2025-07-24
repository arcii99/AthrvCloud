//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

char* translate(char* input) {
    char* output = calloc(strlen(input) * 4, sizeof(char));
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == 'c' || input[i] == 'C') {
            strcat(output, "meow");
        }
        else if(input[i] == 'a' || input[i] == 'A') {
            strcat(output, "purrr");
        }
        else if(input[i] == 't' || input[i] == 'T') {
            strcat(output, "hiss");
        }
        else if(input[i] == 's' || input[i] == 'S') {
            strcat(output, "purr");
        }
        else {
            char temp[2];
            temp[0] = input[i];
            temp[1] = '\0';
            strcat(output, temp);
        }
    }
    return output;
}

int main() {
    char input[100];
    printf("Enter a string to translate into Cat Language:\n");
    scanf("%[^\n]", input);
    getchar();
    printf("%s\n", translate(input));
    return 0;
}