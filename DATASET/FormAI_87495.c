//FormAI DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_FIELD_LENGTH 50

// Define the data structure for an entry in the database
struct Entry {
    char name[MAX_FIELD_LENGTH];
    int age;
    char occupation[MAX_FIELD_LENGTH];
};

// Define the data structure for the index
struct Index {
    char field[MAX_FIELD_LENGTH];  // field to be indexed (e.g. "name")
    void* index[MAX_ENTRIES];      // array of pointers to entries
    int num_entries;               // number of entries in the index
};

// Function to add an entry to the database
void add_entry(struct Entry database[], int* num_entries) {
    printf("Enter name: ");
    scanf("%s", database[*num_entries].name);
    printf("Enter age: ");
    scanf("%d", &database[*num_entries].age);
    printf("Enter occupation: ");
    scanf("%s", database[*num_entries].occupation);
    (*num_entries)++;
}

// Function to print all entries in the database
void print_database(struct Entry database[], int num_entries) {
    printf("Name\tAge\tOccupation\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%s\n", database[i].name, database[i].age, database[i].occupation);
    }
}

// Function to initialize an index on a specified field
void init_index(struct Entry database[], int num_entries, struct Index* index, char* field) {
    strcpy(index->field, field);
    index->num_entries = 0;
    for (int i = 0; i < num_entries; i++) {
        void* ptr = &database[i];
        if (strcmp(field, "name") == 0) {
            index->index[index->num_entries] = &database[i].name;
        } else if (strcmp(field, "age") == 0) {
            index->index[index->num_entries] = &database[i].age;
        } else if (strcmp(field, "occupation") == 0) {
            index->index[index->num_entries] = &database[i].occupation;
        }
        index->num_entries++;
    }
}

// Function to print all entries in an index
void print_index(struct Index index) {
    printf("Field: %s\n", index.field);
    for (int i = 0; i < index.num_entries; i++) {
        if (strcmp(index.field, "name") == 0) {
            printf("%s\n", *(char**)index.index[i]);
        } else if (strcmp(index.field, "age") == 0) {
            printf("%d\n", *(int*)index.index[i]);
        } else if (strcmp(index.field, "occupation") == 0) {
            printf("%s\n", *(char**)index.index[i]);
        }
    }
}

int main() {
    struct Entry database[MAX_ENTRIES] = {};
    int num_entries = 0;
    struct Index name_index;
    struct Index age_index;
    struct Index occupation_index;
    init_index(database, num_entries, &name_index, "name");
    init_index(database, num_entries, &age_index, "age");
    init_index(database, num_entries, &occupation_index, "occupation");
    while (1) {
        printf("1. Add entry\n");
        printf("2. Print database\n");
        printf("3. Print name index\n");
        printf("4. Print age index\n");
        printf("5. Print occupation index\n");
        printf("6. Quit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry(database, &num_entries);
                break;
            case 2:
                print_database(database, num_entries);
                break;
            case 3:
                print_index(name_index);
                break;
            case 4:
                print_index(age_index);
                break;
            case 5:
                print_index(occupation_index);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}