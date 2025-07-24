//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x, y;
  FILE *fp;

  fp = fopen("numbers.txt", "w"); // opening file for writing

  if (fp == NULL) { // if file pointer returns null
    printf("Oh no! Unable to open file.\n"); // print error message
    exit(1);
  }

  printf("Wow! Successfully opened file.\n"); // print success message

  printf("Enter the value of x: ");
  scanf("%d", &x);

  printf("Enter the value of y: ");
  scanf("%d", &y);

  fprintf(fp, "%d\n%d\n", x, y); // writing x and y values to file

  printf("Numbers successfully written to file.\n"); // print success message

  fclose(fp); // closing the file

  fp = fopen("numbers.txt", "r"); // opening file for reading

  if (fp == NULL) { // if file pointer returns null
    printf("Oh no! Unable to open file.\n"); // print error message
    exit(1);
  }

  printf("Wow! Successfully opened file again.\n"); // print success message

  fscanf(fp, "%d", &x); // reading x value from file
  fscanf(fp, "%d", &y); // reading y value from file

  printf("Value of x: %d\nValue of y: %d\n", x, y); // printing the values

  fclose(fp); // closing the file

  printf("File successfully closed. The end.\n"); // print end message

  return 0;
}