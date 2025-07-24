//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 10000

int main() {
    printf("Running C Cyberpunk Compression Algorithm\n");

    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE] = "";
    int n;
    printf("Enter input string (max length = %d) : ", MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);

    n = strlen(input);
    int i;
    for(i = 0; i < n; i++) {
        if(input[i] == ' ') {
            strcat(output, "01010101");
        } else if(input[i] == '\n') {
            strcat(output, "0101010101");
        } else {
            int j;
            for (j = 0; j < (int)input[i]; j++) {
                strcat(output, "01");
            }
            strcat(output, "000001");
        }
    }

    printf("\nOriginal string: %s\n", input);
    printf("Compressed string: %s\n", output);

    return 0;
}