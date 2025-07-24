//FormAI DATASET v1.0 Category: QR code reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[256];
    int size;
} qr_code;

// function to generate a random qr code
void generate_qr_code(qr_code *code) {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, random;

    code->size = rand() % 256;
    for (i = 0; i < code->size; i++) {
        random = rand() % strlen(charset);
        code->data[i] = charset[random];
    }
}

// function to read a qr code
void read_qr_code(qr_code *code) {
    int i;

    printf("Please scan the QR code:\n");

    // read the input from the user
    fgets(code->data, 256, stdin);

    // remove the newline character
    code->data[strcspn(code->data, "\n")] = '\0';

    // calculate the size of the input
    code->size = strlen(code->data);

    printf("Scanning...\n");

    // simulate the scanning process
    for (i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout); // ensure that the dots are printed immediately
        usleep(500000); // wait for half a second
    }

    printf("\n");
}

int main() {
    qr_code code;
    int tries = 0;

    printf("Welcome to the QR code reader program!\n");

    do {
        generate_qr_code(&code);
        printf("QR code generated: %s\n", code.data);
        printf("Please scan the QR code within 10 seconds:\n");

        read_qr_code(&code);

        if (strcmp(code.data, "C0D3B34NS") == 0) {
            printf("Access granted!\n");
            break;
        } else {
            printf("Access denied!\n");
            tries++;
        }
    } while (tries < 3);

    if (tries == 3) {
        printf("Too many attempts. Program terminated.\n");
    }

    return 0;
}