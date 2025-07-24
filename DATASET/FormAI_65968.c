//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[] = "ZxyyzxZYYZXyyZZZxYzX";
    char output[100];
    int i, j;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'Z') {
            output[i] = 'A';
        } else if (input[i] == 'Y') {
            output[i] = 'B';
        } else if (input[i] == 'X') {
            output[i] = 'C';
        } else if (input[i] == 'y') {
            output[i] = 'a';
        } else if (input[i] == 'z') {
            output[i] = 'b';
        }
    }
    output[i] = '\0';

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    return 0;
}