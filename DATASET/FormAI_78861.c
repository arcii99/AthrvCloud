//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>

void error_handle(int code) {
  if (code == 0) {
    printf("SUCCESS!\n");
  } else {
    printf("ERROR CODE: %d\n", code);
  }
}

int main() {
  int x = 10;
  int y = 0;
  int result;

  if (y == 0) {
    error_handle(1);
    return 1;
  }

  result = x / y;

  error_handle(0);
  return 0;
}