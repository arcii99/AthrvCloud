//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  file = fopen("mathematics.txt", "w");
  int num = 2;
  float x = 15.5;
  char op = '+';

  if (file != NULL) {
    fprintf(file, "Mathematical Operations:\n\n");

    // Addition operation
    fprintf(file, "Addition: %d %c %.2f = %.2f\n", num, op, x, num + x);

    // Subtraction operation
    fprintf(file, "Subtraction: %d %c %.2f = %.2f\n", num, op, x, num - x);

    // Multiplication operation
    fprintf(file, "Multiplication: %d %c %.2f = %.2f\n", num, op, x, num * x);

    // Division operation
    fprintf(file, "Division: %.2f %c %d = %.2f\n", x, op, num, x / num);
  }
  else {
    printf("Unable to open file.");
    return 1;
  }

  fclose(file);
  printf("File write successful.\n");
  return 0;
}