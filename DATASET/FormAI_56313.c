//FormAI DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* input){
    int length = strlen(input);
    char* compressed = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0, compressedIndex = 0, count = 1;
    char currentChar = input[0];
    for(index = 1; index < length; index++){
        if(input[index] == currentChar){
            count++;
        }else{
            compressed[compressedIndex++] = currentChar;
            compressed[compressedIndex++] = (char) (count + '0');
            currentChar = input[index];
            count = 1;
        }
    }
    //Adding last character
    compressed[compressedIndex++] = currentChar;
    compressed[compressedIndex] = (char) (count + '0');
    return compressed;
}

int main(){
    char* input = "aaaaabbbccccddd";
    printf("Input String: %s\n", input);
    char* compressed = compress(input);
    printf("Compressed String: %s\n", compressed);
    free(compressed);
    return 0;
}