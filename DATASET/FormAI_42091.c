//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
#include<stdio.h>
#include<string.h> //for strlen() function

char* encrypt(char* input, char* key){
    char* output = (char*) malloc(strlen(input)+1);
    int inputLen = strlen(input), keyLen = strlen(key), i, j;
    for(i = 0, j = 0; i < inputLen; ++i, ++j){
        if(j == keyLen) j = 0;
        output[i] = (input[i] + key[j]) % 128;
    }
    output[i] = '\0';
    return output;
}

int main() {
    char* input = "Hello, World!";
    char* key = "secret";
    char* output = encrypt(input, key);
    printf("%s", output);
    return 0;
}