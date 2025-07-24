//FormAI DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

struct DiaryEntry {
  time_t timestamp;
  char* message;
};

typedef struct DiaryEntry DiaryEntry;

void print_entry(DiaryEntry* entry) {
  struct tm* t_info = localtime(&entry->timestamp);
  char buffer[20];
  strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", t_info);
  printf("[%s]: %s\n", buffer, entry->message);
}

int main() {
  DiaryEntry* entries[MAX_ENTRIES];
  int num_entries = 0;

  while (1) {
    printf("\n1. Add entry\n2. View all entries\n3. Exit\n\n");    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1: {
        if (num_entries >= MAX_ENTRIES) {
          printf("Diary is full, cannot add more entries.\n");
          break;
        }
        DiaryEntry* entry = (DiaryEntry*)malloc(sizeof(DiaryEntry));
        entry->timestamp = time(NULL);

        char message[1000];
        getchar();
        printf("Enter message:\n");
        fgets(message, 1000, stdin);

        int len = strlen(message);
        message[len - 1] = '\0';
        entry->message = (char*)malloc(len);
        strcpy(entry->message, message);

        entries[num_entries++] = entry;
        printf("Entry added successfully.\n");

        break;
      }
      case 2: {
        if (num_entries == 0) {
          printf("No entries yet.\n");
          break;
        }
        printf("All entries:\n");
        for (int i = 0; i < num_entries; i++) {
          print_entry(entries[i]);
        }
        break;
      }
      case 3: {
        printf("Goodbye!\n");
        return 0;
      }
      default:
        printf("Invalid choice.\n");
    }
  }
}