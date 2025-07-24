//FormAI DATASET v1.0 Category: QR code generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_PAYLOAD_LENGTH 160
#define QR_CODE_VERSION 1 // can be from 1 to 40
#define QR_CODE_SIZE 21 // size of QR code in blocks
#define MAX_QR_CODE_SIZE (QR_CODE_SIZE*QR_CODE_SIZE) // maximum size in pixels (441)

// define some arrays for QR code data
uint8_t qr_code[MAX_QR_CODE_SIZE];
uint8_t payload_data[MAX_PAYLOAD_LENGTH];
uint8_t qr_code_mask[MAX_QR_CODE_SIZE];

// function prototypes
void generate_qr_code();
void print_qr_code();

int main() {
    // input payload data
    printf("Enter the payload data (max 160 chars): ");
    fgets(payload_data, MAX_PAYLOAD_LENGTH, stdin);
    payload_data[strcspn(payload_data, "\n")] = 0; // remove trailing newline

    // generate the QR code
    generate_qr_code();

    // print the QR code
    print_qr_code();

    return 0;
}

void generate_qr_code() {
    // calculate the length of the payload data
    int data_length = strlen(payload_data);

    // encode the payload data using QR code encoding rules
    // (not implemented here - assuming payload data is already correctly encoded)
    // note that there are many libraries available for QR code encoding

    // set QR code to all white
    memset(qr_code, 0xff, sizeof(qr_code));

    // add finder patterns to QR code
    qr_code[0] = qr_code[QR_CODE_SIZE-1] = qr_code[MAX_QR_CODE_SIZE-QR_CODE_SIZE] = 0x7f;
    qr_code[QR_CODE_SIZE*(QR_CODE_SIZE-1)] = qr_code[MAX_QR_CODE_SIZE-1] = qr_code[MAX_QR_CODE_SIZE-QR_CODE_SIZE+1] = 0x7f;

    // add alignment patterns to QR code (currently not implemented)

    // add timing patterns to QR code
    for(int i=8; i<QR_CODE_SIZE-8; i+=2) {
        qr_code[i] = qr_code[(QR_CODE_SIZE-1)*QR_CODE_SIZE+i] = 0x7f;
        qr_code[i*QR_CODE_SIZE] = qr_code[i*QR_CODE_SIZE+(QR_CODE_SIZE-1)] = 0x7f;
    }

    // add dark module to QR code
    qr_code[QR_CODE_SIZE*8+8] = 0x7f;

    // reserve format information area in QR code
    for(int i=0; i<8; i++) {
        qr_code[8*QR_CODE_SIZE+i] = 0x7f; // top left
        qr_code[i*QR_CODE_SIZE+8] = 0x7f; // bottom right
    }
    for(int i=0; i<7; i++) {
        qr_code[(8*QR_CODE_SIZE)+7+i] = 0x7f; // top right
        qr_code[(7*QR_CODE_SIZE)+8+i] = 0x7f; // bottom left
    }

    // reserve version information area in QR code (currently not implemented)

    // place payload data in QR code (simplest method used here - byte mode only)
    int x = QR_CODE_SIZE-1;
    int y = QR_CODE_SIZE-1;
    int direction = -1; // start moving up
    int data_index = 0;
    while(data_index < data_length) {
        qr_code[y*QR_CODE_SIZE+x] = payload_data[data_index++];
        if(direction == -1) {
            if(x == 0) {
                y -= 2;
                direction = 1;
            }
            else if(y == 0) {
                x -= 2;
                direction = 1;
            }
            else if(qr_code[(y-1)*QR_CODE_SIZE+(x-1)] != 0xff) {
                y -= 2;
                x -= 1;
            }
            else {
                y -= 1;
                x -= 1;
            }
        }
        else {
            if(x == QR_CODE_SIZE-1) {
                y -= 2;
                direction = -1;
            }
            else if(y == QR_CODE_SIZE-1) {
                x -= 2;
                direction = -1;
            }
            else if(qr_code[(y-1)*QR_CODE_SIZE+(x+1)] != 0xff) {
                y -= 2;
                x += 1;
            }
            else {
                y -= 1;
                x += 1;
            }
        }
    }

    // apply mask to QR code (currently not implemented)
}

void print_qr_code() {
    printf("\nQR code (size %dx%d):\n\n", QR_CODE_SIZE, QR_CODE_SIZE);
    for(int i=0; i<QR_CODE_SIZE; i++) {
        for(int j=0; j<QR_CODE_SIZE; j++) {
            printf("%c ", qr_code[i*QR_CODE_SIZE+j] == 0xff ? '.' : '#');
        }
        printf("\n");
    }
}