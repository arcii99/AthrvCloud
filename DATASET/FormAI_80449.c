//FormAI DATASET v1.0 Category: QR code reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_SIZE 500

int main(void) {

    char qr_code[MAX_QR_SIZE];
    bool match = false;

    printf("Welcome to HappyQR Reader! Let's get started.\n");

    do {
        printf("Please scan your QR code: \n");
        scanf("%s", qr_code);

        // Check if QR code starts with "HappyQR"
        if (strncmp(qr_code, "HappyQR", 7) == 0) {
            printf("Yay! You have a HappyQR code.\n");

            // Check if QR code contains "HappyWorld"
            if (strstr(qr_code, "HappyWorld") != NULL) {
                printf("Your HappyQR code says: Hello Happy World!\nLet's spread happiness together :)\n");
            } else {
                printf("Your HappyQR code doesn't contain 'HappyWorld'.\nIt's still a HappyQR code though!\n");
            }

            match = true;
        } else {
            printf("Oops! That doesn't seem to be a HappyQR code. Try again?\n");
        }

    } while (!match);

    printf("Thank you for using HappyQR Reader. Have a Happy Day!\n");

    return 0;
}