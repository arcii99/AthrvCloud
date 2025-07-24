//FormAI DATASET v1.0 Category: QR code reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_SIZE 1000

bool is_valid_qr(char qr[MAX_QR_SIZE]) {
    int len = strlen(qr);
    if(qr[0] != 'C' || qr[1] != ':' || len <= 3) return false;
    for(int i=2; i<len-1; i++) {
        if(qr[i] < '0' || qr[i] > '9') return false;
    }
    return true;
}

int read_qr(char qr[MAX_QR_SIZE]) {
    printf("Please scan the C QR code: ");
    fgets(qr, MAX_QR_SIZE, stdin);
    int len = strlen(qr);
    qr[len-1] = '\0';
    if(!is_valid_qr(qr)) {
        printf("Invalid QR code. Try again.\n");
        return -1;
    }
    printf("QR code successfully read!\n");
    return 0;
}

int main() {
    char qr[MAX_QR_SIZE];
    while(read_qr(qr) != 0);
    return 0;
}