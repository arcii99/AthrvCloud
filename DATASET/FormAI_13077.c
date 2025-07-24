//FormAI DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to your personal digital diary!\n");
  printf("Please enter today's date (dd/mm/yy): ");
  char date[9];
  scanf("%s", date);

  char *filename = malloc(sizeof(char) * 15); // choose a filename based on date
  sprintf(filename, "%c%c-%c%c-%c%c.txt", date[0], date[1], date[3], date[4], date[6], date[7]);

  FILE *file = fopen(filename, "a"); // open file for appending
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  printf("What's on your mind today?\n");
  char entry[1000];
  fgets(entry, 1000, stdin); // take input from user
  fprintf(file, "%s: %s\n", date, entry); // write to file
  printf("Entry saved successfully!\n");

  fclose(file);

  return 0;
}