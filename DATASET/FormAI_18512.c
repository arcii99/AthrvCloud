//FormAI DATASET v1.0 Category: QR code generator ; Style: Alan Touring
#include <stdio.h>

/* Define the maximum matrix size */
#define MAX_MATRIX_SIZE 21

/* Define the size of QR Code */
#define QR_CODE_SIZE 21

/* Define the white and black blocks */
#define WHITE_BLOCK 0
#define BLACK_BLOCK 1

/* Define the structure for QR Code matrix */
struct QRCodeMatrix {
    int size;
    int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
};

typedef struct QRCodeMatrix QRCode;

/* Function to initialize QR Code matrix with white blocks */
QRCode initQRMatrix() {
    QRCode qr;
    qr.size = QR_CODE_SIZE;
    for(int i=0; i<qr.size; i++) {
        for(int j=0; j<qr.size; j++) {
            qr.matrix[i][j] = WHITE_BLOCK;
        }
    }
    return qr;
}

/* Function to add data to QR Code matrix */
void addDataToMatrix(QRCode *qr, char *data, int dataSize) {
    int row = 0;
    int col = qr->size-1;
    int direction = -1;
    int dataIndex = 0;

    while(col >= 0 && dataIndex < dataSize) {
        if(qr->matrix[row][col] == WHITE_BLOCK) {
            qr->matrix[row][col] = data[dataIndex] - '0';
            dataIndex++;
        }
        row += direction;
        if(row < 0 || row >= qr->size) {
            direction *= -1;
            row += direction;
            col -= 2;
        }
    }
}

/* Function to display QR Code */
void displayQRCode(QRCode qr) {
    for(int i=0; i<qr.size; i++) {
        for(int j=0; j<qr.size; j++) {
            printf("%d", qr.matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char data[] = "C QR Code Generator Example";
    int dataSize = sizeof(data)/sizeof(data[0]);

    QRCode qr = initQRMatrix();

    addDataToMatrix(&qr, data, dataSize);

    displayQRCode(qr);

    return 0;
}