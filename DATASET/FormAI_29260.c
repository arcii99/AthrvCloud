//FormAI DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>

int main() {
  char filename[50];
  FILE *fptr;
  int i, n;

  printf("Enter the filename to open: ");
  scanf("%s", filename);

  // Assuming the file contains only integer
  fptr = fopen(filename, "w");
  if (fptr == NULL) {
      printf("Unable to open file %s\n", filename);
      return -1;
  }

  printf("How many integers do you want to enter?\n");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d integers: \n", n);

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    fprintf(fptr, "%d ", arr[i]);
  }

  fclose(fptr);

  printf("\nFile saved successfully.\n");

  return 0;
}