//FormAI DATASET v1.0 Category: QR code generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUIET_ZONE 4
#define MODULE_SIZE 4

typedef struct {
  unsigned char* data;
  int version;
  int size;
} qr_code;

void generate_pattern(qr_code* code, int x, int y, int w, int h) {
  int i, j;
  for (i = x; i < x + w; i++) {
    for (j = y; j < y + h; j++) {
      code->data[i + j * code->size] = 1;
    }
  }
}

void generate_code(qr_code* code, char* data, int len) {
  int i, j, padding;
  int capacity = (code->size - 2 * QUIET_ZONE) / MODULE_SIZE;

  // start with pattern version 1, and increase until we fit
  for (code->version = 1; code->version <= 40; code->version ++) {
    padding = 8;
    if (code->version >= 2 && code->version <= 6) padding = 9;
    if (code->version >= 7 && code->version <= 13) padding = 10;
    if (code->version >= 14 && code->version <= 20) padding = 11;
    if (code->version >= 21 && code->version <= 27) padding = 12;
    if (code->version >= 28 && code->version <= 34) padding = 13;
    if (code->version >= 35 && code->version <= 40) padding = 14;

    if (capacity >= len * 8 + padding) {
      break;
    }
    code->size = 17 + code->version * 4;
  }

  // generate the data portion
  code->data = malloc(code->size * code->size);
  memset(code->data, 0, code->size * code->size);

  int k = 0;
  for (i = 0; i < code->version * 4 + 17; i++) {
    for (j = 0; j < code->version * 4 + 17; j++) {
      if (i < QUIET_ZONE || j < QUIET_ZONE ||
          i >= code->version * 4 + 17 - QUIET_ZONE ||
          j >= code->version * 4 + 17 - QUIET_ZONE) {
        generate_pattern(code, i, j, MODULE_SIZE, MODULE_SIZE);
        continue;
      }

      if (k < len * 8) {
        if (data[k / 8] & (1 << (7 - k % 8))) {
          generate_pattern(code, i, j, MODULE_SIZE, MODULE_SIZE);
        }
        k++;
      }
    }
  }
}

void print_code(qr_code* code) {
  int i, j;
  for (i = 0; i < code->size; i++) {
    for (j = 0; j < code->size; j++) {
      printf("%s", code->data[i + j * code->size] ? "##" : "  ");
    }
    printf("\n");
  }
}

void free_code(qr_code* code) {
  free(code->data);
}

int main() {
  char* data = "http://www.example.com";
  qr_code code;
  generate_code(&code, data, strlen(data));

  print_code(&code);
  free_code(&code);
  return 0;
}