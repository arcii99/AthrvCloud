//FormAI DATASET v1.0 Category: Compression algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program implements a simple text compression algorithm which replaces
   repeated characters with an integer representing their count. */

/* Function to compress the input string */
char *compress(char *str) {
    int len = strlen(str);
    char *res = (char *) malloc((len + 1) * sizeof(char));  // Allocate memory for the compressed string

    int count = 1, i, j = 0;
    for (i = 1; i <= len; i++) {
        if (str[i] == str[i - 1]) {  // Increment count if character is repeated
            count++;
        } else {  // Replace repeated characters with count and move to next character
            res[j++] = str[i - 1];
            if (count > 1) {
                char *cnt_str = (char *) malloc(10 * sizeof(char));  // Allocate memory for integer string
                sprintf(cnt_str, "%d", count);
                strcat(res, cnt_str);
                j += strlen(cnt_str);
                count = 1;
                free(cnt_str);
            }
        }
    }

    res[j] = '\0';  // Append null character at the end
    return res;
}

int main() {
    char str[] = "aabbbbccccddee";
    char *res = compress(str);
    printf("Compressed string: %s\n", res);
    free(res);
    return 0;
}