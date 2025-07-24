//FormAI DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000 // Maximum number of entries allowed
#define MAX_ENTRY_SIZE 200 // Maximum size of a single entry

typedef struct Entry {
    char date[11]; // Date of the entry
    char text[MAX_ENTRY_SIZE]; // Text of the entry
} Entry;

Entry* entries[MAX_ENTRIES]; // Array of pointers to Entry structs
int num_entries = 0; // Number of entries in the array

// Helper function to print the latest entry
void print_latest_entry() {
    if (num_entries == 0) {
        printf("No entries found.\n");
    } else {
        Entry latest_entry = *entries[num_entries-1]; // Dereference the pointer to get the Entry struct
        printf("%s\n", latest_entry.text);
    }
}

int main() {
    printf("Welcome to your Digital Diary!\n");

    char command[MAX_ENTRY_SIZE]; // Buffer for user input
    while (1) {
        printf("\nEnter a command ('help' for options): ");
        scanf("%[^\n]%*c", command); // Read in a line of input

        if (strcmp(command, "help") == 0) {
            printf("\nCommands:\n");
            printf("  help            - Show this menu\n");
            printf("  latest          - Show latest entry\n");
            printf("  add <text>      - Add a new entry\n");
            printf("  list [<date>]   - List entries (optionally by date)\n");
            printf("  delete <index>  - Delete an entry\n");
            printf("  quit            - Quit the program\n");

        } else if (strcmp(command, "latest") == 0) {
            printf("\nLatest entry:\n");
            print_latest_entry();

        } else if (strncmp(command, "add", 3) == 0) {
            char* text = command + 4; // Extract the text portion of the command
            if (strlen(text) > MAX_ENTRY_SIZE) {
                printf("\nEntry too long (max %d characters).\n", MAX_ENTRY_SIZE);
            } else {
                time_t t = time(NULL);
                struct tm* tm = localtime(&t);
                char date[11];
                strftime(date, sizeof(date), "%Y-%m-%d", tm);

                Entry* new_entry = malloc(sizeof(Entry)); // Allocate memory for a new Entry struct
                strcpy(new_entry->date, date);
                strcpy(new_entry->text, text);
                entries[num_entries] = new_entry;
                num_entries++;
                printf("\nEntry added.\n");
            }

        } else if (strncmp(command, "list", 4) == 0) {
            char* date;
            if (strlen(command) > 5) {
                date = command + 5; // Extract the date portion of the command
                printf("\nEntries for %s:\n", date);
            } else {
                printf("\nAll entries:\n");
            }

            int found_entries = 0;
            for (int i = 0; i < num_entries; i++) {
                Entry entry = *entries[i]; // Dereference the pointer to get the Entry struct
                if (strlen(command) <= 5 || strcmp(entry.date, date) == 0) {
                    printf("%d. %s\n", i+1, entry.text);
                    found_entries++;
                }
            }

            if (found_entries == 0) {
                printf("No entries found.\n");
            }

        } else if (strncmp(command, "delete", 6) == 0) {
            int index = atoi(command + 7); // Extract the index portion of the command
            if (index <= 0 || index > num_entries) {
                printf("\nInvalid index.\n");
            } else {
                free(entries[index-1]); // Free the memory allocated for the Entry struct
                for (int i = index-1; i < num_entries-1; i++) {
                    entries[i] = entries[i+1]; // Shift the pointers to fill in the gap
                }
                num_entries--;
                printf("\nEntry deleted.\n");
            }

        } else if (strcmp(command, "quit") == 0) {
            printf("\nGoodbye!\n");
            break;

        } else {
            printf("\nCommand not recognized. Type 'help' for options.\n");
        }
    }

    return 0;
}