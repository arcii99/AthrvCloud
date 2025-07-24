//FormAI DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>

int main(void) {
  int day, month, year;
  char task[1000];

  FILE *fptr;

  fptr = fopen("diary.txt", "a");

  if (fptr == NULL) {
    printf("Error opening file!");
    return 1;
  }

  printf("Enter the date (dd mm yyyy): ");
  scanf("%d %d %d", &day, &month, &year);

  fprintf(fptr, "\n%d/%d/%d\n", day, month, year);

  printf("Enter the task for the day: ");
  scanf(" %[^\n]s", task);

  fprintf(fptr, "Task: %s\n", task);

  printf("\nTask added to diary successfully.\n");

  fclose(fptr);
  return 0;
}