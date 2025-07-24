//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void compress(char *input, char *output) {
    int i = 0, j = 0;
    int count = 1;
    int len = strlen(input);
 
    while (i < len) {
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[j++] = input[i];
        if (count > 1) {
            char buffer[255];
            sprintf(buffer, "%d", count);
            strcat(output, buffer);
            j += strlen(buffer);
            count = 1;
        }
        i++;
    }
    output[j] = '\0';
}

int main() {
    char input[255];
    char output[255];
 
    printf("Enter the string to compress:\n");
    scanf("%[^\n]", input);
    getchar();
 
    compress(input, output);
 
    printf("Compressed string: %s\n", output);
 
    return 0;
}