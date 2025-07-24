//FormAI DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void readQR(char* message, int index) {
    if (index == strlen(message)) {
        return;
    }
    printf("%c", message[index]);
    readQR(message, index + 1);
}

int main() {
    char QR[MAX_SIZE];
    printf("Enter the QR code: ");
    fgets(QR, MAX_SIZE, stdin);
    QR[strcspn(QR, "\n")] = 0;
    printf("\nQR code scanned: ");
    readQR(QR, 0);
    printf("\n");
    return 0;
}