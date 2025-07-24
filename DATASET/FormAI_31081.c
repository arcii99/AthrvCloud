//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    char email[50];
} record;

typedef struct {
    int num_records;
    record records[MAX_RECORDS];
} indexed_database;

typedef struct {
    char key[50];
    int index;
} index_entry;

typedef struct {
    int num_entries;
    index_entry index[MAX_RECORDS];
} index_table;

void add_record(indexed_database* database, int id, char* name, char* email);
void create_index(indexed_database* database, index_table* index);
int binary_search(index_table* index, char* key, int min, int max);

int main() {
    indexed_database database;
    index_table index;
    int choice = 0;

    // Initialize the database
    database.num_records = 0;

    // Main menu loop
    while (choice != 4) {
        printf("\n1. Add record");
        printf("\n2. Search by name");
        printf("\n3. Search by email");
        printf("\n4. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add record
                printf("\nEnter ID: ");
                int id;
                scanf("%d", &id);
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter email: ");
                char email[50];
                scanf("%s", email);
                add_record(&database, id, name, email);
                create_index(&database, &index);
                break;
            case 2:
                // Search by name
                printf("\nEnter name to search for: ");
                char search_name[50];
                scanf("%s", search_name);
                int name_index = binary_search(&index, search_name, 0, index.num_entries - 1);
                if (name_index == -1) {
                    printf("\nNo records found.\n");
                } else {
                    record r = database.records[index.index[name_index].index];
                    printf("\nID: %d\nName: %s\nEmail: %s\n", r.id, r.name, r.email);
                }
                break;
            case 3:
                // Search by email
                printf("\nEnter email to search for: ");
                char search_email[50];
                scanf("%s", search_email);
                int email_index = binary_search(&index, search_email, 0, index.num_entries - 1);
                if (email_index == -1) {
                    printf("\nNo records found.\n");
                } else {
                    record r = database.records[index.index[email_index].index];
                    printf("\nID: %d\nName: %s\nEmail: %s\n", r.id, r.name, r.email);
                }
                break;
            case 4:
                // Quit
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}

void add_record(indexed_database* database, int id, char* name, char* email) {
    if (database->num_records >= MAX_RECORDS) {
        printf("\nDatabase is full. Cannot add record.\n");
        return;
    }

    record r = {id, "", ""};
    strcpy(r.name, name);
    strcpy(r.email, email);
    database->records[database->num_records++] = r;
    printf("\nRecord added.\n");
}

void create_index(indexed_database* database, index_table* index) {
    // Reset the index
    index->num_entries = 0;

    // Loop through the records and add the keys to the index
    for (int i = 0; i < database->num_records; i++) {
        index_entry e;
        strcpy(e.key, database->records[i].name);
        e.index = i;
        index->index[index->num_entries++] = e;
    }

    // Sort the index by key
    for (int i = 0; i < index->num_entries - 1; i++) {
        for (int j = i + 1; j < index->num_entries; j++) {
            if (strcmp(index->index[i].key, index->index[j].key) > 0) {
                index_entry temp = index->index[i];
                index->index[i] = index->index[j];
                index->index[j] = temp;
            }
        }
    }
}

int binary_search(index_table* index, char* key, int min, int max) {
    while (min <= max) {
        int mid = (min + max) / 2;
        if (strcmp(index->index[mid].key, key) == 0) {
            return mid;
        } else if (strcmp(index->index[mid].key, key) < 0) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    return -1;
}