//FormAI DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* Input string to be compressed */
    char str[100];
    printf("Enter your string: ");
    fgets(str, 100, stdin);

    int count = 1;
    char currChar = str[0];
    int len = strlen(str);

    /* Compressing the string and writing it to a new compressed string */
    char compStr[100];
    int compIdx = 0;
    for (int i = 1; i < len; i++) {
        if (str[i] == currChar) {
            count++;
        } else {
            compStr[compIdx] = currChar;
            compStr[compIdx + 1] = count + '0';
            compIdx += 2;
            count = 1;
            currChar = str[i];
        }
    }

    /* Writing the last compressed character and count to the compressed string */
    compStr[compIdx] = currChar;
    compStr[compIdx + 1] = count + '0';
    compIdx += 2;

    /* Printing the compressed string */
    printf("\nCompressed String: %s", compStr);

    return 0;
}