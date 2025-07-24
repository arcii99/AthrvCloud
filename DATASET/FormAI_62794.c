//FormAI DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000

// The main function that compresses a string and returns the compressed string
char* compress(char* str) {
    int n = strlen(str);
    char* res = (char*)malloc(sizeof(char) * (MAXSIZE + 1));
    int count = 1, j = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == str[i + 1]) {
            count++;
        }
        else {
            if(count > 1) {
                char c[10], k = 0;
                while (count != 0) {
                    c[k++] = count % 10 + '0';
                    count /= 10;
                }
                while (k > 0) {
                    res[j++] = c[--k];
                }
                count = 1;
            }
            res[j++] = str[i];
        }
    }
    res[j] = '\0';
    return res;
}

int main() {
    char str[MAXSIZE], *compressedStr;
    printf("Enter a string to compress: ");
    scanf("%[^\n]s", str);
    compressedStr = compress(str);
    printf("Original String: %s\n", str);
    printf("Compressed String: %s\n", compressedStr);
    free(compressedStr); // Freeing the memory used by compressed string
    return 0;
}