//FormAI DATASET v1.0 Category: QR code reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODE_SIZE 21
#define MAX_ATTEMPTS 3

int attempts = 0;

void error(char* message) {
    printf("[ERROR]: %s\n", message);
    exit(1);
}

void read_code(char* code) {
    printf("Scan the QR code: ");
    scanf("%20s", code);
}

int validate_code(char* code) {
    if (strlen(code) != CODE_SIZE) {
        error("Invalid code. Must be 21 characters long");
    }

    for (int i = 0; i < CODE_SIZE; i++) {
        if (code[i] < '0' || code[i] > '9') {
            error("Invalid code. Must be numeric");
        }
    }

    // Code validation logic could be extended here

    return 1;
}

void access_granted(char* code) {
    printf("\nAccess granted:\n");
    printf("Code: %s\n", code);
    printf("Welcome, survivor.\n");

    // Post-apocalyptic style welcome message
    printf("The world is a dangerous place. Keep your guard up and stay alive.\n");
    printf("There's shelter and supplies nearby. Follow the radio signal.\n");
}

void access_denied() {
    printf("\nAccess denied. ");

    if (++attempts >= MAX_ATTEMPTS) {
        printf("The security system has been activated. Run!\n");

        // Post-apocalyptic style warning message
        printf("The air raid sirens are blaring. The bomb will drop within seconds.\n");
        printf("Get to cover. Quick!\n");

        exit(1);
    }
    else {
        printf("You have %d attempts left\n", MAX_ATTEMPTS - attempts);
    }
}

int main() {
    char code[CODE_SIZE + 1];

    while (1) {
        read_code(code);

        if (!validate_code(code)) {
            continue;
        }

        if (strcmp(code, "12345678901234567890") == 0) {
            access_granted(code);
            break;
        }
        else {
            access_denied();
        }
    }

    return 0;
}