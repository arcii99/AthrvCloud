//FormAI DATASET v1.0 Category: QR code generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define QR_SIZE 21

void generate_qr_code(int matrix[QR_SIZE][QR_SIZE]) {
  srand(time(NULL));
  int i, j, rand_num;

  for(i = 0; i < QR_SIZE; i++) {
    for(j = 0; j < QR_SIZE; j++) {
      rand_num = rand() % 2;
      matrix[i][j] = rand_num;
    }
  }
}

void print_qr_code(int matrix[QR_SIZE][QR_SIZE]) {
  printf("QR Code:\n");

  int i, j;
  for(i = 0; i < QR_SIZE; i++) {
    for(j = 0; j < QR_SIZE; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int qr_matrix[QR_SIZE][QR_SIZE];
  memset(qr_matrix, 0, sizeof(qr_matrix[0][0]) * QR_SIZE * QR_SIZE);

  generate_qr_code(qr_matrix);
  print_qr_code(qr_matrix);

  return 0;
}