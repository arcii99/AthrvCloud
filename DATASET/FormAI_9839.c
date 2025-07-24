//FormAI DATASET v1.0 Category: QR code generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Statistical QR Code Generator */

#define QR_SIZE 25
#define WHITE ' '
#define BLACK 'X'

/* Function to calculate the binomial coefficient */
long binomial(int n, int k) {
    if(k == 0 || n == k) {
        return 1;
    } else {
        return binomial(n-1, k-1) + binomial(n-1, k);
    }
}

/* Function to calculate the Number of Black Cells */
int get_num_black_cells(int version) {
    int n = QR_SIZE + 4;
    int k = version * 4 + 17;
    int white_cells = binomial(n, 2) - binomial(n-k, 2) - binomial(k, 2);
    return QR_SIZE * QR_SIZE - white_cells;
}

/* Function to generate code with given version */
char** generate_code(int version) {
    char **qr_code = malloc(QR_SIZE * sizeof(char*));
    int num_black_cells = get_num_black_cells(version);
    int i, j, x, y;
    /* Initialize QR code with all white cells */
    for(i = 0; i < QR_SIZE; i++) {
        qr_code[i] = malloc((QR_SIZE+1) * sizeof(char));
        for(j = 0; j < QR_SIZE; j++) {
            qr_code[i][j] = WHITE;
        }
        qr_code[i][j] = '\0';
    }
    /* Calculate coordinates of black cells using pi sequence */
    double pi = acos(-1);
    for(i = 0; i < num_black_cells; i++) {
        double theta = 2 * pi * i / num_black_cells;
        double r = sqrt(i+0.5) / sqrt(num_black_cells);
        x = r * cos(theta) * QR_SIZE / 2 + QR_SIZE / 2;
        y = r * sin(theta) * QR_SIZE / 2 + QR_SIZE / 2;
        qr_code[y][x] = BLACK;
    }
    return qr_code;
}

/* Function to print QR code */
void print_code(char **qr_code) {
    int i, j;
    printf("\n");
    for(i = 0; i < QR_SIZE; i++) {
        for(j = 0; j < QR_SIZE; j++) {
            printf("%c ", qr_code[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int version = 5; /* Change version number here */
    char **qr_code = generate_code(version);
    print_code(qr_code);
    int i;
    for(i = 0; i < QR_SIZE; i++) {
        free(qr_code[i]);
    }
    free(qr_code);
    return 0;
}