//FormAI DATASET v1.0 Category: QR code generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QR_CODE_SIZE 21

// function to generate a random alphanumeric string
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));
    int i;
    for (i = 0; i < length; i++) {
        int random_index = rand() % strlen(charset);
        str[i] = charset[random_index];
    }
    str[length] = '\0';
    return str;
}

// function to generate QR code
void generate_qr_code(char *string) {
    char qr_code[QR_CODE_SIZE];
    sprintf(qr_code, "QR-%s", string);
    printf("Generated QR code: %s\n", qr_code);
}

int main() {
    int num_qr_codes;
    printf("Enter the number of QR codes to generate: ");
    scanf("%d", &num_qr_codes);

    int i;
    for (i = 0; i < num_qr_codes; i++) {
        char *random_string = generate_random_string(10);
        generate_qr_code(random_string);
        free(random_string);
    }
    return 0;
}