//FormAI DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char entry[1000];
  char fname[50];
  char date[20];
  FILE *fp;

  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  strftime(date, sizeof(date), "%m/%d/%Y", tm);

  printf("Welcome to your Digital Diary!\n");
  printf("Please enter your first name: ");
  scanf("%s", fname);
  
  printf("Enter your daily entry:\n");
  scanf("\n%[^\n]%*c", entry);

  fp = fopen("diary.txt", "a");
  if (fp == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }

  fprintf(fp, "%s\n%s\n\n", date, entry);

  fclose(fp);

  printf("\nThank you for your entry! View your diary by typing 'cat diary.txt' in your terminal.\n");

  return 0;
}