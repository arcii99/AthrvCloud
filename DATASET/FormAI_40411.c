//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void cheers() {
  printf("Hooray! We just recovered your lost data!\n");
}

void recover() {
  printf("Please wait while we recover your data...\n");
  // Some code here to recover the data
  cheers();
}

int main() {
  printf("Welcome to the Data Recovery Tool!\n");

  // Ask user if they want to recover data
  char choice;
  printf("Do you want to recover lost data? (Y/N) ");
  scanf("%c", &choice);

  if (choice == 'Y' || choice == 'y') {
    recover();
  } else if (choice == 'N' || choice == 'n') {
    printf("No problem! Thank you for using our tool.\n");
  } else {
    printf("Invalid choice. Please try again.\n");
    main();
  }

  return 0;
}