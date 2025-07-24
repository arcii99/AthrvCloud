//FormAI DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
  char title[100];
  char content[1000];
  char date[20];
};

typedef struct entry Entry;

int main() {
  Entry diary[365];
  int choice, day;
  
  for (int i =0; i<365; i++) {
    strcpy(diary[i].title, "Empty");
    strcpy(diary[i].content, "");
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    strftime(diary[i].date, 20, "%Y-%m-%d", local);
  }
  
  printf("Welcome to your digital diary!\n");

  while (1) {
    printf("What would you like to do?\n");
    printf("1. Add an entry\n");
    printf("2. View an entry\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1: {
        printf("Enter the day you want to add entry for (1-365): \n");
        scanf("%d", &day);
        getchar();

        if (day < 1 || day > 365) {
          printf("Invalid day number\n");
          break;
        }

        printf("Enter the title of the entry: ");
        fgets(diary[day-1].title, 100, stdin);
        diary[day-1].title[strcspn(diary[day-1].title, "\n")] = 0;

        printf("Enter the content: ");
        fgets(diary[day-1].content, 1000, stdin);
        diary[day-1].content[strcspn(diary[day-1].content, "\n")] = 0;

        printf("Entry added successfully!\n");
        break;
      }

      case 2: {
        printf("Enter the day you want to view entry for (1-365):\n");
        scanf("%d", &day);

        if (day < 1 || day > 365) {
          printf("Invalid day number\n");
          break;
        }

        printf("Title: %s\n", diary[day-1].title);
        printf("Content: %s\n", diary[day-1].content);
        printf("Date: %s\n", diary[day-1].date);
        break;
      }

      case 3: {
        printf("Thank you for using your digital diary!\n");
        exit(0);
        break;
      }

      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}