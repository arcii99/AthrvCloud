//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void compress(char* original, int length) {
    int count = 1;
    char current = original[0];
    printf("%c", current);
    for(int i=1; i<length; i++) {
        if(original[i] == current) {
            count++;
        }
        else {
            printf("%d", count);
            current = original[i];
            printf("%c", current);
            count = 1;
        }
    }
    printf("%d", count);
}

int main() {
    char input_string[100];
    printf("Enter a string to compress: ");
    fgets(input_string, 100, stdin);
    printf("Compressed string: ");
    compress(input_string, strlen(input_string)-1);
    return 0;
}