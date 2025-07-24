//FormAI DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char answer;
  
  printf("Warning: This program will delete all files in your home directory. Do you want to proceed? [y/n]\n");
  scanf("%c", &answer);

  if (answer == 'y') {
    printf("Deleting all files in home directory...\n");
    system("rm -rf ~/*");
    printf("All files in home directory have been deleted.\n");
  } else if (answer == 'n') {
    printf("Program terminated.\n");
  } else {
    printf("Invalid input.\n");
  }
  
  return 0;
}