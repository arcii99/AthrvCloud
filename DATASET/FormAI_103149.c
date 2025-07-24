//FormAI DATASET v1.0 Category: QR code reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CODE_LEN  100

int readQRCode(int[]);

int main() {
    printf("Welcome to the C QR Code Reader!\n");
    printf("Please input the QR code that you'd like to read as a series of integers, separated by spaces:\n");

    int code[MAX_CODE_LEN];
    int codeLen = readQRCode(code);

    // QR code processing logic goes here

    printf("The QR code has been successfully read!\n");

    return 0;
}

int readQRCode(int arr[]) {
    char input[MAX_CODE_LEN * 2];
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[--len] = '\0';
    }

    char *token = strtok(input, " ");
    int i = 0;

    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    return i;
}