//FormAI DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char* compress(char* str) {
    int len = strlen(str);
    char* compressed = malloc(MAX_LEN * sizeof(char));
    int count = 1;
    int index = 0;
    char current = str[0];

    for (int i = 1; i < len; i++) {
        if (str[i] == current) {
            count++;
        } else {
            compressed[index] = current;
            index++;
            char temp[MAX_LEN];
            sprintf(temp, "%d", count);
            strcat(compressed, temp);
            index += strlen(temp);
            count = 1;
            current = str[i];
        }
    }

    compressed[index] = current;
    index++;
    char temp[MAX_LEN];
    sprintf(temp, "%d", count);
    strcat(compressed, temp);
    index += strlen(temp);
    compressed[index] = '\0';
    return compressed;
}

int main() {
    char* str = "You are the sun that brightens my day, the moon that lights up my night. I cannot imagine my life without you, my love.";
    char* compressed = compress(str);
    printf("Original: %s\n", str);
    printf("Compressed: %s\n", compressed);
    free(compressed);
    return 0;
}