//FormAI DATASET v1.0 Category: File handling ; Style: Alan Touring
// Alan Turing style file handling program 
#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename[50];
  FILE *infile, *outfile;
  int num1, num2, sum;
  
  printf("Please enter the name of the input file: ");
  scanf("%s", filename);
  
  // Open the input file for reading
  infile = fopen(filename, "r");
  if (infile == NULL) {
    printf("Error! Could not open file %s for reading.", filename);
    exit(1);
  }
  
  // Open the output file for writing
  outfile = fopen("output.txt", "w");
  if (outfile == NULL) {
    printf("Error! Could not open file output.txt for writing.");
    exit(1);
  }
  
  // Read in the numbers from the input file, sum them, and write the sum to the output file
  while (fscanf(infile, "%d %d", &num1, &num2) == 2) {
    sum = num1 + num2;
    fprintf(outfile, "The sum of %d and %d is %d\n", num1, num2, sum);
  }
  
  // Close the files
  fclose(infile);
  fclose(outfile);
  
  // Print out a success message
  printf("File handling program complete. Check output.txt for results.\n");
  
  return 0;
}