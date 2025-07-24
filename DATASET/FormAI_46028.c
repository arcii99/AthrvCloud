//FormAI DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // maximum number of entries in the diary
#define MAX_ENTRY_LENGTH 100 // maximum length of an entry

int numEntries = 0; // number of entries in the diary

void addEntry(char *diary[]) {
    char entry[MAX_ENTRY_LENGTH];

    // prompt user for the new entry
    printf("Enter new entry:\n");
    fgets(entry, MAX_ENTRY_LENGTH, stdin);

    // remove newline from entry
    entry[strcspn(entry, "\n")] = 0;

    // add entry to diary
    diary[numEntries] = malloc(strlen(entry) + 1);
    strcpy(diary[numEntries], entry);

    // increment number of entries in diary
    numEntries++;

    // print confirmation message
    printf("New entry added to diary.\n");
}

void listEntries(char *diary[]) {
    // check if diary is empty
    if (numEntries == 0) {
        printf("The diary is empty.\n");
        return;
    }

    // list all entries in diary
    printf("Here are all the entries in your diary:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d. %s\n", i+1, diary[i]);
    }
}

void deleteEntry(char *diary[]) {
    int entryNum;

    // check if diary is empty
    if (numEntries == 0) {
        printf("The diary is empty.\n");
        return;
    }

    // prompt user for entry number to delete
    printf("Enter the number of the entry to delete:\n");
    scanf("%d", &entryNum);

    // check if entry number is valid
    if (entryNum < 1 || entryNum > numEntries) {
        printf("Invalid entry number.\n");
        return;
    }

    // delete entry from diary
    free(diary[entryNum-1]);
    for (int i = entryNum-1; i < numEntries-1; i++) {
        diary[i] = diary[i+1];
    }
    diary[numEntries-1] = NULL;

    // decrement number of entries in diary
    numEntries--;

    // print confirmation message
    printf("Entry deleted from diary.\n");
}

int main() {
    char *diary[MAX_ENTRIES];
    char command[MAX_ENTRY_LENGTH];

    // print greeting message
    printf("Welcome to your digital diary!\n");

    // loop to handle user commands
    while (1) {
        // prompt user for command
        printf("Enter a command (add, list, delete, exit):\n");
        fgets(command, MAX_ENTRY_LENGTH, stdin);

        // remove newline from command
        command[strcspn(command, "\n")] = 0;

        // check command and execute corresponding function
        if (strcmp(command, "add") == 0) {
            addEntry(diary);
        } else if (strcmp(command, "list") == 0) {
            listEntries(diary);
        } else if (strcmp(command, "delete") == 0) {
            deleteEntry(diary);
        } else if (strcmp(command, "exit") == 0) {
            // free memory used by diary
            for (int i = 0; i < numEntries; i++) {
                free(diary[i]);
            }
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    // print farewell message
    printf("Goodbye! Thanks for using your digital diary.\n");

    // return success
    return 0;
}