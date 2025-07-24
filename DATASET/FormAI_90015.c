//FormAI DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fptr;
  int num;

  fptr = fopen("numbers.txt", "r");
  if (fptr == NULL) {
    fprintf(stderr, "Error: File cannot be opened");
    exit(1);
  }

  while (fscanf(fptr, "%d", &num) == 1) {
    printf("%d\n", num);
  }

  if (ferror(fptr)) {
    fprintf(stderr, "Error: Reading file failed");
    clearerr(fptr);
  }

  fclose(fptr);

  return 0;
}