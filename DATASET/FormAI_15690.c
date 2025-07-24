//FormAI DATASET v1.0 Category: QR code reader ; Style: mind-bending
#include <stdio.h>
#include <string.h> // for strlen function
#include <stdlib.h> // for malloc function

#define ARRAY_SIZE 21 // a QR code can contain maximum 21 alphanumeric characters

int main()
{
    char *qr_code = (char*) malloc(sizeof(char) * ARRAY_SIZE);
    // allocate memory for the QR code string

    printf("Please scan your QR code:\n");
    scanf("%s", qr_code); // read the QR code string from the user

    char error_message[] = "The QR code you scanned is invalid!";

    if (strlen(qr_code) != 21) {
        // if the length of the QR code string is not 21, it's invalid
        printf("%s\n", error_message);
    } else {
        int i;
        for (i = 0; i < 21; i++) {
            char current_char = qr_code[i];
            if (current_char >= '0' && current_char <= '9') {
                // if the current character is a digit between 0 and 9, it's valid
                continue;
            } else if (
                current_char >= 'A' && current_char <= 'Z' ||
                current_char >= 'a' && current_char <= 'z'
            ) {
                // if the current character is an uppercase or lowercase letter, it's valid
                continue;
            } else {
                // if the current character is neither a digit nor a letter, it's invalid
                printf("%s\n", error_message);
                return -1;
            }
        }

        // if we reach here, the QR code is valid
        printf("The QR code you scanned is:\n");
        printf("%s\n", qr_code);
    }

    free(qr_code); // free the allocated memory
    qr_code = NULL; // set the pointer to NULL to avoid dangling pointer issues

    return 0;
}