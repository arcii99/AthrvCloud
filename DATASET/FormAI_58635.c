//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Donald Knuth inspired Compression Algorithm */

char *compress(char *input) {
    int len = strlen(input);
    int i, j, count, k = 0;
    char *output = (char *)malloc((len * 2) * sizeof(char));

    for (i = 0; i < len; i++) {
        count = 1;
        while (input[i] == input[i+1]) {
            count++;
            i++;
        }

        if (count > 1) {
            output[k++] = input[i];
            sprintf(&output[k], "%d", count);
            k += strlen(&output[k]);
        } else {
            output[k++] = input[i];
        }
    }

    output[k] = '\0';

    return output;
}

int main() {
    char *input = "aabcccccaaa";
    char *output = compress(input);

    printf("%s\n", output);

    free(output);

    return 0;
}