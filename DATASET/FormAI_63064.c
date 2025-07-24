//FormAI DATASET v1.0 Category: QR code generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate a random hex code
void generate_hex(char* hex_code, int length) {
    srand(time(NULL));
    char hex_chars[] = "0123456789ABCDEF";
    for (int i = 0; i < length; i++) {
        hex_code[i] = hex_chars[rand() % 16];
    }
}

//function to generate QR code in C language
int generate_qr_code() {
    char hex_code[7];
    generate_hex(hex_code, 6);
    printf("Your C QR code is: C-%s\n", hex_code);
    return 0;
}

//main function that generates 10 unique QR codes
int main() {
    printf("Welcome to the Happy C QR Code Generator!\n");
    for (int i = 0; i < 10; i++) {
        generate_qr_code();
    }
    printf("Thank you for using the Happy C QR Code Generator!");
    return 0;
}