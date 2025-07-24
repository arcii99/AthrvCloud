//FormAI DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_CONTACTS 1000

struct contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

void add_contact(struct contact* contacts, int* count) {
    if (*count == MAX_CONTACTS) {
        printf("Error: maximum number of contacts reached\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*count].name, MAX_NAME_LENGTH, stdin);

    printf("Enter email: ");
    fgets(contacts[*count].email, MAX_EMAIL_LENGTH, stdin);

    (*count)++;
}

void list_contacts(struct contact* contacts, int count) {
    printf("Contacts:\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s (%s)", i+1, contacts[i].name, contacts[i].email);
    }
}

void save_contacts(struct contact* contacts, int count, char* filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error: could not open file for writing\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(f, "%s,%s\n", contacts[i].name, contacts[i].email);
    }

    fclose(f);

    printf("Saved %d contacts to file %s\n", count, filename);
}

void load_contacts(struct contact* contacts, int* count, char* filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Error: could not open file for reading\n");
        return;
    }

    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];
    while (fgets(line, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2, f)) {
        char* split = strchr(line, ',');
        if (split) {
            *split = '\0';
            split++;

            struct contact c;
            strncpy(c.name, line, MAX_NAME_LENGTH);
            strncpy(c.email, split, MAX_EMAIL_LENGTH);

            contacts[*count] = c;
            (*count)++;
        }
    }

    fclose(f);

    printf("Loaded %d contacts from file %s\n", *count, filename);
}

int main() {
    struct contact contacts[MAX_CONTACTS] = {0};
    int count = 0;

    char input[10];
    do {
        printf("Enter command (add, list, save, load, exit): ");
        fgets(input, 10, stdin);
        strtok(input, "\n");

        if (strcmp(input, "add") == 0) {
            add_contact(contacts, &count);
        } else if (strcmp(input, "list") == 0) {
            list_contacts(contacts, count);
        } else if (strcmp(input, "save") == 0) {
            char filename[MAX_NAME_LENGTH];
            printf("Enter file name to save to: ");
            fgets(filename, MAX_NAME_LENGTH, stdin);
            strtok(filename, "\n");
            save_contacts(contacts, count, filename);
        } else if (strcmp(input, "load") == 0) {
            char filename[MAX_NAME_LENGTH];
            printf("Enter file name to load from: ");
            fgets(filename, MAX_NAME_LENGTH, stdin);
            strtok(filename, "\n");
            load_contacts(contacts, &count, filename);
        } else if (strcmp(input, "exit") != 0) {
            printf("Unknown command '%s'\n", input);
        }
    } while (strcmp(input, "exit") != 0);

    return 0;
}