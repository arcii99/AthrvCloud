//FormAI DATASET v1.0 Category: Encryption ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(char *arr, int len) {
    srand(time(NULL));
    for(int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void encrypt(char *input) {
    int len = strlen(input);
    shuffle(input, len);
    for(int i = 0; i < len; i++) {
        input[i] = ((int)input[i]) * 2 - i;
    }
}

void decrypt(char *input) {
    int len = strlen(input);
    for(int i = 0; i < len; i++) {
        input[i] = (input[i] + i) / 2;
    }
}

int main() {
    char message[1000];

    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    encrypt(message);
    printf("Encrypted message: %s\n", message);

    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}