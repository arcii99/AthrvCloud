//FormAI DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>

int main() {
  char username[20];
  char entry[200];
  char filename[30];
  FILE *fp;

  printf("Welcome to your Digital Diary!\n\n");
  printf("Please enter your username: ");
  scanf("%s", username);
  sprintf(filename, "%s_diary.txt", username);

  fp = fopen(filename, "a+");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  printf("\nEnter your thoughts for the day: ");
  fflush(stdin);
  fgets(entry, 200, stdin);

  fprintf(fp, "\n%s", entry);
  printf("\nEntry saved successfully!\n");

  fclose(fp);

  return 0;
}