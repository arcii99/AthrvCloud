//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char compressed[MAX_SIZE];
    int count = 1;
    int i, j, k;

    printf("Enter a string to compress: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;

    int len = strlen(input);

    if (len == 0) {
        printf("Invalid input. Program will now exit.\n");
        return 1;
    }

    for (i = 0, j = 0; i < len; i++) {
        compressed[j++] = input[i];
        count = 1;
        while (i < len - 1 && input[i] == input[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            char* count_str = (char*) malloc(10 * sizeof(char));
            sprintf(count_str, "%d", count);
            for (k = 0; k < strlen(count_str); k++) {
                compressed[j++] = count_str[k];
            }
        }
    }

    compressed[j] = '\0';
    printf("Compressed string: %s\n", compressed);

    return 0;
}