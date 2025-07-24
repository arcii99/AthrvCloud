//FormAI DATASET v1.0 Category: Digital Diary ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY 1000

struct diary_entry {
  char date[20];
  char time[20];
  char entry[MAX_ENTRY];
};

void clear_screen();
void print_header();
void print_menu();
void print_entry(struct diary_entry entry);
void add_entry(struct diary_entry *entries, int num_entries);
void search_entry(struct diary_entry *entries, int num_entries);
void edit_entry(struct diary_entry *entries, int num_entries);
void delete_entry(struct diary_entry *entries, int num_entries);

int main()
{
  clear_screen();
  print_header();
  struct diary_entry entries[MAX_ENTRY];
  int num_entries = 0;
  
  while (1) {
    print_menu();
    int choice;
    scanf("%d", &choice);
    clear_screen();
    
    switch (choice) {
      case 1:
        add_entry(entries, num_entries);
        num_entries++;
        break;
      case 2:
        search_entry(entries, num_entries);
        break;
      case 3:
        edit_entry(entries, num_entries);
        break;
      case 4:
        delete_entry(entries, num_entries);
        num_entries--;
        break;
      case 5:
        printf("Exiting Digital Diary. Goodbye!\n\n");
        exit(0);
      default:
        printf("Invalid choice, please try again.\n\n");
        break;
    }
  }
  
  return 0;
}

void clear_screen()
{
  printf("\033[H\033[J");
}

void print_header()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("********************************\n");
  printf("            CYBER DIARY         \n");
  printf("               %d/%d/%d          \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
  printf("********************************\n\n");
}

void print_menu()
{
  printf("Please select one of the following options:\n");
  printf("1. Add a new entry\n");
  printf("2. Search for an entry\n");
  printf("3. Edit an entry\n");
  printf("4. Delete an entry\n");
  printf("5. Exit program\n\n");
}

void print_entry(struct diary_entry entry)
{
  printf("%s %s\n%s\n\n", entry.date, entry.time, entry.entry);
}

void add_entry(struct diary_entry *entries, int num_entries)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("Enter your diary entry:\n\n");
  fflush(stdin);
  fgets(entries[num_entries].entry, MAX_ENTRY, stdin);
  entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = 0;
  strcpy(entries[num_entries].date, asctime(localtime(&t)));
  entries[num_entries].date[strcspn(entries[num_entries].date, "\n")] = 0;
  sprintf(entries[num_entries].time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
  printf("\nDiary entry added successfully!\n\n");
}

void search_entry(struct diary_entry *entries, int num_entries)
{
  char keyword[MAX_ENTRY];
  printf("Enter a keyword to search for: ");
  fflush(stdin);
  fgets(keyword, MAX_ENTRY, stdin);
  keyword[strcspn(keyword, "\n")] = 0;
  int found = 0;
  for (int i = 0; i < num_entries; i++) {
    if (strstr(entries[i].entry, keyword)) {
      print_entry(entries[i]);
      found = 1;
    }
  }
  if (!found) {
    printf("\nNo entries found with the specified keyword.\n\n");
  }
}

void edit_entry(struct diary_entry *entries, int num_entries)
{
  int entry_no;
  printf("Enter the entry number you want to edit: ");
  scanf("%d", &entry_no);
  getchar();
  entry_no--;
  
  if (entry_no < 0 || entry_no >= num_entries) {
    printf("\nInvalid entry number. Please try again.\n\n");
    return;
  }
  
  print_entry(entries[entry_no]);
  printf("Enter your edited entry: ");
  fflush(stdin);
  fgets(entries[entry_no].entry, MAX_ENTRY, stdin);
  entries[entry_no].entry[strcspn(entries[entry_no].entry, "\n")] = 0;
  printf("\nEntry edited successfully!\n\n");
}

void delete_entry(struct diary_entry *entries, int num_entries)
{
  int entry_no;
  printf("Enter the entry number you want to delete: ");
  scanf("%d", &entry_no);
  getchar();
  entry_no--;
  
  if (entry_no < 0 || entry_no >= num_entries) {
    printf("\nInvalid entry number. Please try again.\n\n");
    return;
  }
  
  for (int i = entry_no; i < num_entries - 1; i++) {
    entries[i] = entries[i + 1];
  }
  printf("\nEntry deleted successfully!\n\n");
}