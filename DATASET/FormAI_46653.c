//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char buffer[100];
  FILE *file = fopen("surprise.txt", "w");

  if(file == NULL) {
    printf("Error opening file!");
    exit(1);
  }

  printf("Surprise System Administration Example Program!\n\n");
  printf("Enter your name: ");
  fgets(buffer, 100, stdin);
  
  // Remove newline character at the end of the input string
  strtok(buffer, "\n"); 

  fprintf(file, "Hello, %s!\n", buffer);
  printf("\nCongrats! You're writing to the file \"surprise.txt\"\n");

  fclose(file);
  return 0;
}