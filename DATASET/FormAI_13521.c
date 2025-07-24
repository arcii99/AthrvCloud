//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[100];
    int i, j, k, l, distance, length;

    printf("Enter the input string: ");
    scanf("%s", input);

    i = 0;
    while (input[i] != '\0') {
        distance = 0;
        length = 0;
        for (j = 0; j < i; j++) {
            k = 0;
            l = i;
            while (input[j+k] == input[l] && l < strlen(input)) {
                k++;
                l++;
            }
            if (k > length) {
                length = k;
                distance = i - j;
            }
        }
        if (length > 0) {
            sprintf(output, "(%d,%d)", distance, length);
            printf("%s", output);
            i += length;
        }
        else {
            output[0] = input[i];
            output[1] = '\0';
            printf("%s", output);
            i++;
        }
    }

    return 0;
}