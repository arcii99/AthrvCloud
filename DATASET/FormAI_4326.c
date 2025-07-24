//FormAI DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int count_repeats(char *str, char c, int start) {
    int count = 0;
    for (int i = start; i < strlen(str); i++) {
        if (str[i] == c) {
            count++;
        } else {
            break;
        }
    }
    return count;
}

void compress(char *str) {
    int length = strlen(str);
    char compressed[length];
    int count = 1;
    int j = 0;
    for (int i = 0; i < length; i++) {
        int repeats = count_repeats(str, str[i], i);
        if (repeats > 1) {
            compressed[j] = repeats + '0';
            j++;
        }
        compressed[j] = str[i];
        j++;
        i += repeats - 1;
    }
    compressed[j] = '\0';
    strcpy(str, compressed);
}

int main(void) {
    char input[MAX_LENGTH];
    printf("Enter a string to compress (maximum length %d): ", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';  // remove trailing newline
    compress(input);
    printf("Compressed string: %s\n", input);
    return 0;
}