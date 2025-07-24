//FormAI DATASET v1.0 Category: Data recovery tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char *output;
    int i, j, k, len;

    printf("Enter the corrupted data in hexadecimal format: ");
    scanf("%s", input);
    len = strlen(input);

    output = (char*) malloc(len/2 + 1);

    // Read the corrupted data in 2 byte chunks
    for(i = 0, j = 0; i < len; i += 2, j++) {
        if(input[i] >= '0' && input[i] <= '9') {
            k = input[i] - '0';
        } else {
            k = input[i] - 'a' + 10;
        }

        if(input[i+1] >= '0' && input[i+1] <= '9') {
            k = k * 16 + input[i+1] - '0';
        } else {
            k = k * 16 + input[i+1] - 'a' + 10;
        }

        output[j] = k;
    }
    output[j] = '\0';

    printf("Recovered data: %s\n", output);
    free(output);

    return 0;
}