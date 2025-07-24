//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_STR_LEN 30

int main(int argc, char *argv[]) {
  char *dataFile = "example_data.csv";
  char *outputFile = "output.txt";

  FILE *fpIn, *fpOut;
  char line[MAX_COLS * MAX_STR_LEN];
  char *token;
  int i = 0, j = 0, numRows = 0;

  // Read number of rows to determine size of data array
  if ((fpIn = fopen(dataFile, "r")) == NULL) {
    printf("Error: cannot open file %s\n", dataFile);
    exit(1);
  }
  while (fgets(line, sizeof(line), fpIn)) {
    numRows++;
  }
  fclose(fpIn);

  // Allocate memory for data array
  float **data = (float **)malloc(numRows * sizeof(float *));
  for (i = 0; i < numRows; i++) {
    data[i] = (float *)malloc(MAX_COLS * sizeof(float));
  }

  // Read data into array
  if ((fpIn = fopen(dataFile, "r")) == NULL) {
    printf("Error: cannot open file %s\n", dataFile);
    exit(1);
  }
  i = 0;
  while (fgets(line, sizeof(line), fpIn)) {
    j = 0;
    token = strtok(line, ",");
    while (token != NULL) {
      data[i][j++] = atof(token);
      token = strtok(NULL, ",");
    }
    i++;
  }
  fclose(fpIn);

  // Calculate means and standard deviations
  float means[MAX_COLS], stdDevs[MAX_COLS];
  for (j = 0; j < MAX_COLS; j++) {
    float sum = 0.0;
    for (i = 0; i < numRows; i++) {
      sum += data[i][j];
    }
    means[j] = sum / numRows;

    float sumSquares = 0.0;
    for (i = 0; i < numRows; i++) {
      sumSquares += (data[i][j] - means[j]) * (data[i][j] - means[j]);
    }
    stdDevs[j] = sqrt(sumSquares / numRows);
  }

  // Write means and standard deviations to output file
  if ((fpOut = fopen(outputFile, "w")) == NULL) {
    printf("Error: cannot open file %s\n", outputFile);
    exit(1);
  }
  for (j = 0; j < MAX_COLS; j++) {
    fprintf(fpOut, "Column %d: mean = %f, std dev = %f\n", j+1, means[j], stdDevs[j]);
  }
  fclose(fpOut);

  // Free memory
  for (i = 0; i < numRows; i++) {
    free(data[i]);
  }
  free(data);

  return 0;
}