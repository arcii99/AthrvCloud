//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

char* translate(char* input) {
    int input_len = strlen(input);
    char output[input_len+1];
    for(int i=0; i<input_len; i++) {
        switch(input[i]) {
            case 'm':
                output[i] = 'p';
                break;
            case 'o':
                output[i] = 'e';
                break;
            case 'w':
                output[i] = 'r';
                break;
            case 't':
                output[i] = 'c';
                break;
            case 'h':
                output[i] = 'd';
                break;
            case 's':
                output[i] = 'a';
                break;
            default:
                output[i] = input[i];
        }
    }
    output[input_len] = '\0';
    char *result = output;
    return result;
}

int main() {
    char* input = "meow";
    char* output = translate(input);
    printf("C Cat Language output: %s", output);
    return 0;
}