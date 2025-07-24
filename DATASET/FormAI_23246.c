//FormAI DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 20
#define MAX_PASS_LEN 32

struct entry {
    char name[32];
    char password[MAX_PASS_LEN];
};

int num_entries = 0;
struct entry entries[MAX_ENTRIES];

void add_entry(char *name, char *password) {
    if (num_entries == MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
    } else {
        strncpy(entries[num_entries].name, name, 32);
        strncpy(entries[num_entries].password, password, MAX_PASS_LEN);
        num_entries++;
    }
}

int find_entry(char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strncmp(entries[i].name, name, 32) == 0) {
            return i;
        }
    }

    return -1;
}

void change_password(char *name, char *new_password) {
    int entry_index = find_entry(name);

    if (entry_index == -1) {
        printf("Error: Entry not found.\n");
    } else {
        strncpy(entries[entry_index].password, new_password, MAX_PASS_LEN);
    }
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].password);
    }
}

int main() {
    int done = 0;

    while (!done) {
        printf("Enter a command (add, change, print, quit):\n");

        char command[32];
        fgets(command, 32, stdin);

        if (strncmp(command, "add", 3) == 0) {
            char name[32];
            char password[MAX_PASS_LEN];

            printf("Enter the name:\n");
            fgets(name, 32, stdin);

            printf("Enter the password:\n");
            fgets(password, MAX_PASS_LEN, stdin);

            add_entry(name, password);
        } else if (strncmp(command, "change", 6) == 0) {
            char name[32];
            char password[MAX_PASS_LEN];

            printf("Enter the name:\n");
            fgets(name, 32, stdin);

            printf("Enter the new password:\n");
            fgets(password, MAX_PASS_LEN, stdin);

            change_password(name, password);
        } else if (strncmp(command, "print", 5) == 0) {
            print_entries();
        } else if (strncmp(command, "quit", 4) == 0) {
            done = 1;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}