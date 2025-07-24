//FormAI DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>

// Define the size of the diary
#define MAX_SIZE 365

// Define the structure of the diary entry
struct DiaryEntry {
  int day;
  int month;
  int year;
  char entry[200];
};

// Declare the functions for the program
void DisplayMenu();
void AddEntry(struct DiaryEntry*);
void ViewEntry(struct DiaryEntry*);
void DeleteEntry(struct DiaryEntry*);

// Main function of the program
int main() {

  // Initialize the diary
  struct DiaryEntry diary[MAX_SIZE];

  // Set all entry days to 0 to indicate empty entries
  for (int i = 0; i < MAX_SIZE; i++) {
    diary[i].day = 0;
  }

  // Display the main menu
  DisplayMenu();

  // Define the user's menu choice variable
  int choice;

  // Loop through the menu until the user exits
  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    // Perform the requested action
    switch (choice)
    {
    case 1:
      AddEntry(diary);
      break;

    case 2:
      ViewEntry(diary);
      break;

    case 3:
      DeleteEntry(diary);
      break;

    case 4:
      // Exit the program
      printf("Exiting program...\n");
      break;

    default:
      printf("Invalid choice, please try again.\n");
      break;
    }

  } while (choice != 4);

  return 0;
}

// Display the menu to the user
void DisplayMenu() {
  printf("Digital Diary Program\n");
  printf("----------------------\n");
  printf("1. Add entry\n");
  printf("2. View entry\n");
  printf("3. Delete entry\n");
  printf("4. Exit program\n");
}

// Allow the user to add an entry to the diary
void AddEntry(struct DiaryEntry* diary) {
  printf("Add Diary Entry:\n");
  printf("-----------------\n");

  // Find the next available empty entry
  int index = 0;
  while (diary[index].day != 0) {
    index++;
  }

  // Read in the date and entry from the user
  printf("Enter day (1-31): ");
  scanf("%d", &diary[index].day);
  printf("Enter month (1-12): ");
  scanf("%d", &diary[index].month);
  printf("Enter year: ");
  scanf("%d", &diary[index].year);
  printf("Enter entry (max 200 characters):\n");
  scanf("%s", diary[index].entry);

  // Confirm entry has been added
  printf("Entry added for %d/%d/%d.\n", diary[index].day, diary[index].month, diary[index].year);
}

// Allow the user to view an existing entry in the diary
void ViewEntry(struct DiaryEntry* diary) {
  printf("View Diary Entry:\n");
  printf("------------------\n");

  // Read in the date to view
  int day, month, year;
  printf("Enter day (1-31): ");
  scanf("%d", &day);
  printf("Enter month (1-12): ");
  scanf("%d", &month);
  printf("Enter year: ");
  scanf("%d", &year);

  // Find the entry in the diary
  int index = 0;
  while (index < MAX_SIZE && diary[index].day != day && diary[index].month != month && diary[index].year != year) {
    index++;
  }

  // Display the entry or an error message
  if (index < MAX_SIZE && diary[index].day == day && diary[index].month == month && diary[index].year == year) {
    printf("\nEntry for %d/%d/%d:\n", diary[index].day, diary[index].month, diary[index].year);
    printf("%s\n", diary[index].entry);
  }
  else {
    printf("\nEntry not found.\n");
  }
}

// Allow the user to delete an existing entry in the diary
void DeleteEntry(struct DiaryEntry* diary) {
  printf("Delete Diary Entry:\n");
  printf("--------------------\n");

  // Read in the date to delete
  int day, month, year;
  printf("Enter day (1-31): ");
  scanf("%d", &day);
  printf("Enter month (1-12): ");
  scanf("%d", &month);
  printf("Enter year: ");
  scanf("%d", &year);

  // Find the entry in the diary
  int index = 0;
  while (index < MAX_SIZE && diary[index].day != day && diary[index].month != month && diary[index].year != year) {
    index++;
  }

  // Delete the entry or display an error message
  if (index < MAX_SIZE && diary[index].day == day && diary[index].month == month && diary[index].year == year) {
    diary[index].day = 0;
    diary[index].month = 0;
    diary[index].year = 0;
    diary[index].entry[0] = '\0';
    printf("\nEntry deleted for %d/%d/%d.\n", day, month, year);
  }
  else {
    printf("\nEntry not found.\n");
  }
}