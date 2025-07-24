//FormAI DATASET v1.0 Category: QR code reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct qr_code {
    int length;
    char *data;
} qr_code_t;

void print_qr_code(qr_code_t *qr) {
    printf("QR Code Data (%d bytes): %s\n", qr->length, qr->data);
}

int main() {
    char input[1024];
    printf("Please enter a QR code as a string of 1s and 0s:\n");
    fgets(input, 1024, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("Scanning QR code: %s\n", input);
    
    qr_code_t *qr = (qr_code_t*)malloc(sizeof(qr_code_t));
    qr->length = strlen(input);
    qr->data = (char*)malloc(qr->length + 1);
    strcpy(qr->data, input);
    
    print_qr_code(qr);
    
    free(qr->data);
    free(qr);
    
    return 0;
}