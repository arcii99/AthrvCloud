//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>

int main(void) {
  int day, month, year;
  double hours_spent, pages_read;

  printf("Welcome to your Digital Diary!\n");

  // Get user input
  printf("Please enter today's date:\n");
  printf("Day: ");
  scanf("%d", &day);
  printf("Month: ");
  scanf("%d", &month);
  printf("Year: ");
  scanf("%d", &year);

  printf("How many hours did you spend studying today? ");
  scanf("%lf", &hours_spent);
  printf("How many pages did you read today? ");
  scanf("%lf", &pages_read);

  // Write to file
  FILE *file_ptr;

  file_ptr = fopen("digital_diary.txt", "a");

  if (file_ptr == NULL) {
    printf("Error: Could not open digital_diary.txt\n");
    return 1;
  }

  fprintf(file_ptr, "Date: %d-%d-%d\n", day, month, year);
  fprintf(file_ptr, "Hours spent studying: %.1f\n", hours_spent);
  fprintf(file_ptr, "Pages read: %.1f\n", pages_read);

  fclose(file_ptr);

  return 0;
}