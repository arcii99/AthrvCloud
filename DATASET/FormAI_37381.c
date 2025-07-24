//FormAI DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_CODE_SIZE 21

int scan_qr_code(char qr_code[QR_CODE_SIZE][QR_CODE_SIZE], int x, int y, int visited[QR_CODE_SIZE][QR_CODE_SIZE], char qr_string[QR_CODE_SIZE * QR_CODE_SIZE]);

int main() {
    char qr_code[QR_CODE_SIZE][QR_CODE_SIZE] = {  // Example QR code
        "###############",
        "#             #",
        "# ##### ##### #",
        "# #   # #   # #",
        "# # # # # # # #",
        "# # # # # # # #",
        "# # # # # # # #",
        "# # # # # # # #",
        "# # # # # # # #",
        "# # # # # # # #",
        "# # # # # # # #",
        "# # # # # # # #",
        "# #   # #   # #",
        "# ##### ##### #",
        "#             #",
        "###############"
    };

    int visited[QR_CODE_SIZE][QR_CODE_SIZE];  // Keep track of visited cells
    memset(visited, 0, sizeof visited);

    char qr_string[QR_CODE_SIZE * QR_CODE_SIZE];  // The resulting QR code string
    memset(qr_string, 0, sizeof qr_string);

    int start_x = 1, start_y = 1;

    scan_qr_code(qr_code, start_x, start_y, visited, qr_string);

    printf("QR code string: %s\n", qr_string);

    return 0;
}

int scan_qr_code(char qr_code[QR_CODE_SIZE][QR_CODE_SIZE], int x, int y, int visited[QR_CODE_SIZE][QR_CODE_SIZE], char qr_string[QR_CODE_SIZE * QR_CODE_SIZE]) {
    int dx[] = { 1, -1, 0, 0 };  // Movement in x direction
    int dy[] = { 0, 0, 1, -1 };  // Movement in y direction

    visited[x][y] = true;
    qr_string[strlen(qr_string)] = qr_code[x][y];

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x >= 0 && new_x < QR_CODE_SIZE && new_y >= 0 && new_y < QR_CODE_SIZE) {
            if (!visited[new_x][new_y]) {
                scan_qr_code(qr_code, new_x, new_y, visited, qr_string);
            }
        }
    }

    return 0;
}