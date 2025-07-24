//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char const *input) {
    int len = strlen(input);
    char *output = (char *) malloc(len * sizeof(char));
    int pos = 0;
    char curr = input[0];
    int count = 1;
    for(int i = 1; i < len; i++) {
        if(input[i] == curr) {
            count++;
        } else {
            if(count > 1) {
                output[pos++] = '(';
                output[pos++] = count + '0';
                output[pos++] = curr;
                output[pos++] = ')';
            } else {
                output[pos++] = curr;
            }
            curr = input[i];
            count = 1;
        }
    }
    if(count > 1) {
        output[pos++] = '(';
        output[pos++] = count + '0';
        output[pos++] = curr;
        output[pos++] = ')';
    } else {
        output[pos++] = curr;
    }
    output[pos++] = '\0';
    return output;
}

int main() {
    char input[100], *output;
    printf("Enter the input string: ");
    scanf("%s", input);
    output = compress(input);
    printf("Compressed string: %s\n", output);
    free(output);
    return 0;
}