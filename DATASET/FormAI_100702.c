//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define MAX_NAME_LENGTH 20

struct record {
    int id;
    char name[MAX_NAME_LENGTH];
};

struct index_node {
    char name[MAX_NAME_LENGTH];
    int record_id;
    struct index_node *next;
};

struct index {
    struct index_node *head;
};

void init_index(struct index *index) {
    index->head = NULL;
}

void insert_index(struct index *index, char *name, int record_id) {
    if (index->head == NULL) {
        struct index_node *new_node = (struct index_node *)malloc(sizeof(struct index_node));
        strncpy(new_node->name, name, MAX_NAME_LENGTH);
        new_node->record_id = record_id;
        new_node->next = NULL;
    
        index->head = new_node;
        return;
    }
  
    struct index_node *node = index->head;
    while (node != NULL) {
        if (strncmp(node->name, name, MAX_NAME_LENGTH) == 0) {
            // append node to the list of record ids for this name
            while (node->next != NULL) {
                node = node->next;
            }
            struct index_node *new_node = (struct index_node *)malloc(sizeof(struct index_node));
            new_node->record_id = record_id;
            new_node->next = NULL;
            node->next = new_node;
            return;
        }
        node = node->next;
    }

    // name not found, add new index node at end of list
    struct index_node *new_node = (struct index_node *)malloc(sizeof(struct index_node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    new_node->record_id = record_id;
    new_node->next = index->head;
    index->head = new_node;
}

void print_index(struct index *index) {
    struct index_node *node = index->head;
    while (node != NULL) {
        printf("%s -> ", node->name);
        struct index_node *id_node = node;
        while (id_node != NULL) {
            printf("%d ", id_node->record_id);
            id_node = id_node->next;
        }
        printf("\n");
        node = node->next;
    }
}

int main() {
    // create some dummy records
    struct record database[MAX_RECORDS];
    for (int i = 0; i < MAX_RECORDS; i++) {
        database[i].id = i + 1;
        snprintf(database[i].name, MAX_NAME_LENGTH, "Record %d", i + 1);
    }

    // create index for records
    struct index name_index;
    init_index(&name_index);
    for (int i = 0; i < MAX_RECORDS; i++) {
        insert_index(&name_index, database[i].name, i);
    }

    // print index
    print_index(&name_index);

    return 0;
}