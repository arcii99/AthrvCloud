//FormAI DATASET v1.0 Category: QR code reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_medieval_art() {
    printf("      ,\n");
    printf("  I  /|\n");
    printf("  | |||\n");
    printf("  | |||\n");
    printf("  | |||\n");
    printf("  | |||\n");
    printf(" _| |||_ \n");
    printf("[_-'''-_-]\\ \n\n");
}

void scan_qr_code(char* code) {
    printf("Scanning QR code...\n");
    printf("The code is %s\n", code);
}

int main() {
    printf("Welcome explorer!\n");
    printf("This is the Medieval QR Code Reader Program.\n");
    printf("Please proceed by placing the QR code in front of the screen.\n");

    char* qr_code = (char*)malloc(sizeof(char)*100);
    fgets(qr_code, 100, stdin);

    print_medieval_art();
    scan_qr_code(qr_code);

    return 0;
}