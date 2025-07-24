//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
// Peaceful C Compression Algorithm Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the given string
void compress(char* str, int len) {
    char* temp = (char*)calloc(len + 1, sizeof(char));
    int count = 1, index = 0;
    char ch = str[0];
    for(int i = 1; i < len; i++) {
        if(ch == str[i]) {
            count++;
        } else {
            temp[index++] = ch;
            temp[index++] = count + '0';
            ch = str[i];
            count = 1;
        }
    }
    temp[index++] = ch;
    temp[index++] = count + '0';

    // Update the original string with the compressed string
    if(index < len) {
        for(int i = 0; i < index; i++) {
            str[i] = temp[i];
        }
        str[index] = '\0';
    }
    free(temp);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    // Remove the newline character from the input string
    int len = strlen(str);
    if(str[len - 1] == '\n'){
        str[len - 1] = '\0';
    }
    // Compress the string
    compress(str, len);
    printf("Compressed string: %s\n", str);
    return 0;
}