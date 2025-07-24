//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>

int main()
{
  // Let's create a puzzle to be solved by a clever programmer!
  
  FILE *filePointer;
  char fileName[20];
  char content[50];
  
  printf("Welcome, programmer!\n");
  printf("To proceed, you will need to solve this puzzle...\n");
  
  printf("\nI am thinking of a word that starts with 'F', has six letters, and rhymes with 'Dapple'\n");
  
  printf("\nEnter your guess: ");
  scanf("%s", content);
  
  if (strcasecmp(content, "fizzle") == 0) {
    printf("\nYou are correct!\n");
    printf("As a reward, you can now create your own file!\n");
    
    printf("\nEnter a file name with less than 20 characters: ");
    scanf("%s", fileName);
    
    filePointer = fopen(fileName, "w");
    
    if (filePointer != NULL) {
      printf("\nPlease enter your file content: ");
      scanf(" %[^\n]", content);
      fprintf(filePointer, "%s", content);
      printf("\nFile created successfully!\n");
      fclose(filePointer);
    } else {
      printf("\nFailed to create file!");
    }
    
  } else {
    printf("\nWrong guess. Try again later!");
  }
  
  return 0;
}