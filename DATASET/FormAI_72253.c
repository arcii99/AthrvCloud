//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_CONTACTS 1000000
 
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;
 
typedef struct {
    Contact *contacts;
    int num_contacts;
} Database;
 
typedef struct {
    char index_key[MAX_NAME_LEN];
    int database_index;
} Index;
 
typedef struct {
    Index *index;
    int num_entries;
} IndexTable;
 
void add_contact(Database *database, char *name, char *phone);
int search_index(IndexTable *index_table, char *search_key);
void create_index(Database *database, IndexTable *index_table);
void print_database(Database *database);
 
int main() {
    Database my_database;
    my_database.num_contacts = 0;
    my_database.contacts = calloc(MAX_CONTACTS, sizeof(Contact));
 
    IndexTable my_index_table;
    my_index_table.index = calloc(MAX_CONTACTS, sizeof(Index));
    my_index_table.num_entries = 0;
 
    char input[MAX_NAME_LEN + MAX_PHONE_LEN + 3];
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
 
    while (1) {
        printf("Enter contact name and phone number separated by a space or 'q' to quit: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s %s", name, phone);
 
        if (strcmp(name, "q") == 0) {
            break;
        }
 
        add_contact(&my_database, name, phone);
    }
 
    create_index(&my_database, &my_index_table);
 
    print_database(&my_database);
 
    printf("\nEnter a name to search for or 'q' to quit: ");
 
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
 
        if (strcmp(input, "q") == 0) {
            break;
        }
 
        int index = search_index(&my_index_table, input);
 
        if (index == -1) {
            printf("No contact found with name %s\n", input);
        } else {
            printf("Contact found with name %s and phone number %s\n", my_database.contacts[index].name, my_database.contacts[index].phone);
        }
 
        printf("\nEnter a name to search for or 'q' to quit: ");
    }
 
    free(my_database.contacts);
    free(my_index_table.index);
 
    return 0;
}
 
void add_contact(Database *database, char *name, char *phone) {
    strcpy(database->contacts[database->num_contacts].name, name);
    strcpy(database->contacts[database->num_contacts].phone, phone);
    database->num_contacts++;
}
 
int compare_indices(const void *a, const void *b) {
    Index *index_a = (Index *)a;
    Index *index_b = (Index *)b;
 
    return strcmp(index_a->index_key, index_b->index_key);
}
 
void create_index(Database *database, IndexTable *index_table) {
    int i;
 
    for (i = 0; i < database->num_contacts; i++) {
        Index new_index;
 
        strcpy(new_index.index_key, database->contacts[i].name);
        new_index.database_index = i;
 
        index_table->index[index_table->num_entries++] = new_index;
    }
 
    qsort(index_table->index, index_table->num_entries, sizeof(Index), compare_indices);
}
 
int search_index(IndexTable *index_table, char *search_key) {
    int i;
 
    for (i = 0; i < index_table->num_entries; i++) {
        if (strcmp(index_table->index[i].index_key, search_key) == 0) {
            return index_table->index[i].database_index;
        }
 
        if (strcmp(index_table->index[i].index_key, search_key) > 0) {
            return -1;
        }
    }
 
    return -1;
}
 
void print_database(Database *database) {
    int i;
 
    printf("\nDatabase contacts:\n\n");
 
    for (i = 0; i < database->num_contacts; i++) {
        printf("%s %s\n", database->contacts[i].name, database->contacts[i].phone);
    }
 
    printf("\n");
}