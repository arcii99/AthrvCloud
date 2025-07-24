//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define ROWS 64
#define COLS 64

int main()
{
  int matrix[ROWS][COLS];
  int watermark[ROWS][COLS];
  int i, j;

  // initialize the matrices
  srand(time(0));
  for (i=0; i<ROWS; i++) {
      for (j=0; j<COLS; j++) {
          matrix[i][j] = rand() % 256;
          watermark[i][j] = rand() % 2;
      }
  }

  // embed the watermark
  for (i=0; i<ROWS; i++) {
      for (j=0; j<COLS; j++) {
          if (watermark[i][j] == 1) {
              matrix[i][j] |= 1;
          }
          else {
              matrix[i][j] &= ~1;
          }
      }
  }

  // extract the watermark
  int extracted_watermark[ROWS][COLS];
  for (i=0; i<ROWS; i++) {
      for (j=0; j<COLS; j++) {
          extracted_watermark[i][j] = matrix[i][j] & 1;
      }
  }

  // verify the extraction
  int errors = 0;
  for (i=0; i<ROWS; i++) {
      for (j=0; j<COLS; j++) {
          errors += (extracted_watermark[i][j] != watermark[i][j]);
      }
  }
  if (errors > 0) {
      printf("Extraction failed with %d errors\n", errors);
  }
  else {
      printf("Extraction succeeded\n");
  }

  return 0;
}