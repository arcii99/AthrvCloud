//FormAI DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char entry[1000], username[50], password[50], check_username[50], check_password[50];
  int choice, found = 0, i;
  FILE *fp, *temp;

  printf("Welcome to Cryptic Diary\n");
  printf("Enter an existing username to log in or create a new one: ");
  scanf("%s", username);

  sprintf(entry, "%s.txt", username);
  while (1) {
    printf("\nSelect an option:\n");
    printf("1. Write a new entry\n");
    printf("2. View previous entries\n");
    printf("3. Logout\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      fp = fopen(entry, "a");
      printf("Enter your entry:\n");
      scanf("%s", entry);
      fprintf(fp, "%s\n", entry);
      fclose(fp);
    } else if (choice == 2) {
      fp = fopen(entry, "r");
      if (fp) {
        printf("Previous Entries:\n");
        while (fgets(entry, 1000, fp)) {
          printf("%s", entry);
        }
        fclose(fp);
      } else {
        printf("You have no previous entries.\n");
      }
    } else {
      break;
    }
  }

  printf("\nThank you for using Cryptic Diary!\n");
  return 0;
}