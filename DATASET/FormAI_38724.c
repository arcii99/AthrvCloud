//FormAI DATASET v1.0 Category: QR code generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_SIZE 21

//QR code generator function
void gen_qr_code(char* data, int size) {
    int ascii_sum = 0;  //initialize sum
    char qr_code[MAX_QR_SIZE];

    //check if data size is less than maximum QR code size
    if(size > MAX_QR_SIZE) {
        printf("QR code size exceeds maximum limit!\n");
        return;
    }

    //loop through data and calculate sum of ascii values
    for(int i=0; i<size; i++) {
        ascii_sum += (int)data[i];
    }

    //generate QR code based on ascii sum
    sprintf(qr_code, "%cQR%d!", (char)(ascii_sum%26+65), ascii_sum);

    //print generated QR code
    printf("Generated QR code: %s\n", qr_code);
}

int main() {
    char data[100];
    int size;

    printf("Welcome to my cheerful QR code generator!\n");

    //get data input from user
    printf("Enter data to generate QR code: ");
    fgets(data, sizeof(data), stdin);

    //remove newline character from data input
    data[strcspn(data, "\n")] = 0;

    //get data size
    size = strlen(data);

    //generate QR code
    gen_qr_code(data, size);

    printf("Thank you for using my cheerful program!\n");

    return 0;
}