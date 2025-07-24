//FormAI DATASET v1.0 Category: QR code generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QR_CODE_LENGTH 21
#define NUM_CHARACTERS 36

char* generate_qr_code() {
    srand(time(NULL));
    char* qr_code = (char*) malloc((QR_CODE_LENGTH + 1) * sizeof(char));
    for (int i = 0; i < QR_CODE_LENGTH; i++) {
        int random_num = rand() % NUM_CHARACTERS;
        qr_code[i] = (random_num < 10) ? (char) ('0' + random_num) : (char) ('a' + (random_num - 10));
    }
    qr_code[QR_CODE_LENGTH] = '\0';
    return qr_code;
}

int main() {
    char* qr_code = generate_qr_code();
    printf("QR Code: %s\n", qr_code);
    free(qr_code);
    return 0;
}