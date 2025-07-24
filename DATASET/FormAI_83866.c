//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Congratulations! You have just stumbled upon the most amazing C File System Simulation program!\n");
  printf("Get ready to be blown away by our incredible code!\n");

  int num_files;
  printf("How many files would you like to simulate? ");
  scanf("%d", &num_files);

  char** files = (char**)malloc(num_files * sizeof(char*));
  for (int i = 0; i < num_files; i++) {
    files[i] = (char*)malloc(20 * sizeof(char));
    printf("Enter the name of file #%d: ", i+1);
    scanf("%s", files[i]);
  }

  printf("\n\n");

  printf("Here are the files you entered:\n");
  for (int i = 0; i < num_files; i++) {
    printf("%s\n", files[i]);
  }

  printf("\n\n");

  printf("Now, let's randomly generate some file sizes for these files!\n");

  srand(time(NULL));
  for (int i = 0; i < num_files; i++) {
    int file_size = rand() % 1001;
    printf("The size of %s is %d bytes.\n", files[i], file_size);
  }

  printf("\n\n");

  printf("That's it for our C File System Simulation program!\n");
  printf("We hope you enjoyed this amazing experience!\n");

  return 0;
}