//FormAI DATASET v1.0 Category: QR code reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_SIZE 1024

void print_qr(char qr_data[MAX_QR_SIZE][MAX_QR_SIZE], int qr_size) {
    for(int i=0; i<qr_size; i++) {
        for(int j=0; j<qr_size; j++) {
            printf("%c",qr_data[i][j]);
        }
        printf("\n");
    }
}

bool verify_qr(char qr_data[MAX_QR_SIZE][MAX_QR_SIZE], int qr_size) {
    bool flag1 = qr_size >= 21;
    bool flag2 = qr_data[6][6] == '1' && qr_data[6][7] == '0' && qr_data[6][8] == '1';
    bool flag3 = qr_data[6][11] == '1' && qr_data[6][12] == '0' && qr_data[6][13] == '1';
    bool flag4 = qr_data[6][16] == '1' && qr_data[6][17] == '0' && qr_data[6][18] == '1';
    return flag1 && flag2 && flag3 && flag4;
}

int main() {
    char qr_data[MAX_QR_SIZE][MAX_QR_SIZE]; // the qr code will be stored here
    int qr_size;
    memset(qr_data, '0', sizeof(qr_data)); // initialize with zeros
    
    printf("Welcome to the QR code reader program!\n");
    printf("Please enter the size of the QR code (maximum size is %d): ", MAX_QR_SIZE);
    scanf("%d",&qr_size);
    
    if(qr_size < 1 || qr_size > MAX_QR_SIZE) {
        printf("Invalid size input. Program exiting.\n");
        return 0;
    }
    
    printf("Please enter the QR code data (use '1' and '0'): \n");
    for(int i=0; i<qr_size; i++) {
        scanf("%s", qr_data[i]);
        if(strlen(qr_data[i]) != qr_size) {
            printf("Invalid data input. Program exiting.\n");
            return 0;
        }
    }

    printf("\nThe QR code data is: \n");
    print_qr(qr_data, qr_size);

    bool is_valid_qr = verify_qr(qr_data, qr_size);
    if(is_valid_qr) {
        printf("\nThis is a valid QR code! Congratulations!\n");
    } else {
        printf("\nThis is not a valid QR code! Sorry!\n");
    }

    return 0;
}