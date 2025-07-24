//FormAI DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void compress(char *input, int size) {
    int i = 0, j = 0, count = 1;
    while(i < size) {
        if(input[i] == input[i + 1]) {
            count++;
        }
        else {
            printf("%d%c", count, input[i]);
            count = 1;
        }
        i++;
    }
    printf("\n");
}

int main() {
    char input[50];
    printf("Enter the input string:\n");
    fgets(input, 50, stdin);
    int size = strlen(input);
    input[size - 1] = '\0'; //Remove the newline character
    compress(input, size - 1);
    return 0;
}