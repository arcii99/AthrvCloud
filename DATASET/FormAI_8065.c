//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  char inputFile[] = "input.txt"; // Define input file name
  char outputFile[] = "output.txt"; // Define output file name
  
  // Open input file in read mode
  FILE *inFile = fopen(inputFile, "r");
  
  if (inFile == NULL) { // Check if file was successfully opened
    printf("Error: could not open input file!\n");
    return 1;
  }
  
  // Open output file in write mode
  FILE *outFile = fopen(outputFile, "w");
  
  if (outFile == NULL) { // Check if file was successfully opened
    printf("Error: could not open output file!\n");
    return 1;
  }
  
  int num; // Declare a variable to hold a number read from the input file
  
  while (fscanf(inFile, "%d", &num) != EOF) { // While there are still numbers to read from the input file
    fprintf(outFile, "%d\n", num * 2); // Write twice the number read to the output file
  }
  
  // Close the input and output files
  fclose(inFile);
  fclose(outFile);
  
  printf("Input numbers were doubled and saved in output.txt.\n");
  
  return 0;
}