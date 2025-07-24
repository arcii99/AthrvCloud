//FormAI DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 200
#define MAX_ENTRIES 100

//Struct to hold diary entry information
typedef struct {
  char date[20];
  char time[20];
  char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main(void) {
  DiaryEntry entries[MAX_ENTRIES]; //Array of DiaryEntry structs
  int num_entries = 0; //Number of entries currently in the diary
  char input[10]; //Holds user input for menu options

  //Loop until user chooses to exit
  while(1) {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    fgets(input, 10, stdin);

    //Add Entry
    if(strcmp(input, "1\n") == 0) {
      if(num_entries == MAX_ENTRIES) { //Diary is full
        printf("\nDiary is full. Cannot add any more entries.\n");
      } else {
        DiaryEntry new_entry; //Create new entry struct
        printf("\nEnter date (dd/mm/yyyy): ");
        fgets(new_entry.date, 20, stdin);
        printf("Enter time (hh:mm): ");
        fgets(new_entry.time, 20, stdin);
        printf("Enter diary entry (max 200 characters): ");
        fgets(new_entry.entry, MAX_ENTRY_LENGTH, stdin);

        //Add new entry to array and increment entry count
        entries[num_entries++] = new_entry;
        printf("\nEntry added successfuly!\n");
      }
    }

    //View Entries
    else if(strcmp(input, "2\n") == 0) {
      if(num_entries == 0) { //Diary is empty
        printf("\nDiary is empty. No entries to display.\n");
      } else {
        printf("\n--- Diary Entries ---\n");
        for(int i = 0; i < num_entries; i++) {
          printf("\nDate: %s", entries[i].date);
          printf("Time: %s", entries[i].time);
          printf("Entry: %s", entries[i].entry);
        }
      }
    }

    //Search Entries
    else if(strcmp(input, "3\n") == 0) {
      if(num_entries == 0) { //Diary is empty
        printf("\nDiary is empty. No entries to search.\n");
      } else {
        char search_string[MAX_ENTRY_LENGTH]; //String to search for
        printf("\nEnter search string: ");
        fgets(search_string, MAX_ENTRY_LENGTH, stdin);

        int found_count = 0; //Number of entries containing the search string
        printf("\n--- Search Results ---\n");
        for(int i = 0; i < num_entries; i++) {
          if(strstr(entries[i].entry, search_string) != NULL) {
            printf("\nDate: %s", entries[i].date);
            printf("Time: %s", entries[i].time);
            printf("Entry: %s", entries[i].entry);
            found_count++;
          }
        }
        if(found_count == 0) { //Search string not found in any entries
          printf("No results found for \"%s\".\n", search_string);
        } else {
          printf("\n%d result(s) found for \"%s\".\n", found_count, search_string);
        }
      }
    }

    //Exit
    else if(strcmp(input, "4\n") == 0) {
      printf("\nExiting Digital Diary. Goodbye!\n");
      exit(0);
    }

    //Invalid input
    else {
      printf("\nInvalid input. Please enter a valid menu option.\n");
    }
  }

  return 0;
}