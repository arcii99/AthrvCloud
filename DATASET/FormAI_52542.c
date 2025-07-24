//FormAI DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    char* randString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char qrCode[25];

    printf("Welcome to the Surreal QR Code Generator!\n");
    printf("Enter the text you want to encode: ");

    fgets(qrCode, 25, stdin);
    qrCode[strcspn(qrCode, "\n")] = 0;

    printf("Generating QR code...\n\n");

    for (int i = 0; i < 25; i++) {
        if (i % 5 == 0 && i != 0) {
            printf("\n");
        }
        int randIndex = rand() % strlen(randString);
        if (qrCode[i] != '\0') {
            printf("%c", qrCode[i]);
        } else {
            printf("%c", randString[randIndex]);
        }
    }

    printf("\n\nYour surreal QR code has been generated. Thank you for using our service!\n");

    return 0;
}