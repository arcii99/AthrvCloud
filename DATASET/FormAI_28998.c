//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to our CSV Reader Program! 🎉🎊\n");
  
  char file_name[50];
  printf("Enter the name of the CSV file: ");
  fgets(file_name, sizeof(file_name), stdin);
  strtok(file_name, "\n"); // remove newline character
  
  FILE* fp;
  fp = fopen(file_name, "r");
  
  if (fp == NULL) {
    printf("Oops! Looks like we could not open the file. 😕\n");
    printf("Please check if the file exists and try again. 💻\n");
    return 1; // exit program with error code
  }
  
  printf("Great! The CSV file was successfully opened! 🎉\n");
  printf("Reading data from the file...📖\n");
  
  char line[100]; // assuming each line in the CSV is less than 100 characters
  int num_rows = 0;
  int num_cols = 0;
  
  while (fgets(line, sizeof(line), fp)) {
    num_rows++;
    int curr_num_cols = 1;
    
    // count the number of columns in the current row
    for (int i = 0; i < strlen(line); i++) {
      if (line[i] == ',') {
        curr_num_cols++;
      }
    }
    
    // update the total number of columns
    if (curr_num_cols > num_cols) {
      num_cols = curr_num_cols;
    }
    
    printf("%s", line); // print the current line
  }
  
  printf("Data successfully read! 🎉\n");
  printf("Total number of rows: %d\n", num_rows);
  printf("Total number of columns: %d\n", num_cols);
  
  fclose(fp); // close the file
  
  printf("Thank you for using our program! Have a great day! 👋\n");
  
  return 0; // exit program with success code
}