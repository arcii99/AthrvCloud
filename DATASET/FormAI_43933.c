//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char* crypto_hash(char* input);

int main() {
    char string[100];
    printf("Please enter a string to hash: ");
    fgets(string, 100, stdin);
    char* hashed_string = crypto_hash(string);
    printf("The hashed value of '%s' is: %s", string, hashed_string);
    return 0;
}

char* crypto_hash(char* input) {
    int n = strlen(input);
    int i, j, k;
    char* output = calloc(1, (n+1)*sizeof(char));
    for(i=0, j=0; i<n; i++, j+=2) {
        char c = input[i];
        if(isalpha(c)) {
            c = tolower(c);
        }
        char b[8] = {0,0,0,0,0,0,0,0};
        for(k=0; c>0 && k<8; k++) {
            b[k] = c & 1;
            c >>= 1;
        }
        for(k=0; k<8; k++, j++) {
            output[j] = (b[k] > 0) ? '1' : '0';
        }
    }
    return output;
}