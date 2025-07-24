//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>

int main() {
  printf("Hello everyone! I'm so excited to show you my C File handling program! \n\n");

  FILE *myFile;
  myFile = fopen("numbers.txt", "w"); //open file for writing

  if (myFile == NULL){
    printf("Error! Unable to open file for writing.\n");
    return 1;
  }

  printf("Enter 5 numbers separated by spaces: ");
  int num1, num2, num3, num4, num5;
  scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

  fprintf(myFile, "%d %d %d %d %d", num1, num2, num3, num4, num5); //write to the file
  printf("Successfully wrote to the file.\n");
  fclose(myFile);

  myFile = fopen("numbers.txt", "r"); //open file for reading

  if (myFile == NULL){
    printf("Error! Unable to open file for reading.\n");
    return 1;
  }

  int numbers[5];
  fscanf(myFile, "%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]); //read from the file

  printf("Numbers read from file: %d %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
  fclose(myFile);

  printf("\nWow! Writing and reading from a file in C was so much fun! \n");

  return 0;
}