//FormAI DATASET v1.0 Category: Modern Encryption ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 100

void encode(char *input, int key) {
    int i;
    printf("\nEncoded message: ");
    for(i=0; i<MAX_LEN && input[i] != '\0'; i++) {
        printf("%c", (input[i]+key)%128);
    }
}

void decode(char *input, int key) {
    int i;
    printf("\nDecoded message: ");
    for(i=0; i<MAX_LEN && input[i] != '\0'; i++) {
        printf("%c", (input[i]-key)%128);
    }
}

int main() {
    char input[MAX_LEN];
    int key;
    printf("Enter the text to encrypt (must be less than %d characters): ", MAX_LEN);
    fgets(input, MAX_LEN, stdin);
    printf("Enter the key (must be less than 128): ");
    scanf("%d", &key);
    encode(input, key);
    decode(input, key);
    return 0;
}