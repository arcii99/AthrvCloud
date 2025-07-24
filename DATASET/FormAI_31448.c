//FormAI DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000
#define SHIFT_AMOUNT 5

void printArray(int arr[], int size);

int main() {
    char message[MAX_LENGTH];
    printf("Enter your message: ");
    fgets(message, MAX_LENGTH, stdin);

    srand(time(NULL));
    int key[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; i++) {
        key[i] = rand() % 10;
    }

    int encrypted[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; i++) {
        encrypted[i] = ((int) message[i]) + (key[i] * SHIFT_AMOUNT);
    }

    printf("Encrypted message:\n");
    printArray(encrypted, MAX_LENGTH);

    int decrypted[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; i++) {
        decrypted[i] = (encrypted[i] - (key[i] * SHIFT_AMOUNT));
    }
    
    printf("Decrypted message:\n");
    printArray(decrypted, MAX_LENGTH);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}