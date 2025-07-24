//FormAI DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LEN 256
#define NUM_RECORDS 10000
#define HASH_SIZE 1000

typedef struct record {
    int id;
    char name[MAX_STRING_LEN];
    int age;
} Record;

typedef struct node {
    Record *data;
    struct node *next;
} Node;

Node *hash_table[HASH_SIZE];

int hash(int key) {
    return key % HASH_SIZE;
}

void insert_hash(Record *data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    int key = hash(data->id);
    new_node->next = hash_table[key];
    hash_table[key] = new_node;
}

Record *search_hash(int id) {
    int key = hash(id);
    Node *current_node = hash_table[key];
    while(current_node != NULL) {
        if(current_node->data->id == id) {
            return current_node->data;
        }
        current_node = current_node->next;
    }
    return NULL;
}

int main() {
    Record database[NUM_RECORDS];

    //initialize records
    for(int i=0; i<NUM_RECORDS; i++) {
        database[i].id = i;
        sprintf(database[i].name, "Person %d", i);
        database[i].age = rand()%100;
    }

    //insert records into hash table
    for(int i=0; i<NUM_RECORDS; i++) {
        insert_hash(&database[i]);
    }

    //search for record and print results
    int search_id = rand()%NUM_RECORDS;
    Record *result = search_hash(search_id);
    if(result != NULL) {
        printf("Record %d found: %d %s %d\n", search_id, result->id, result->name, result->age);
    } else {
        printf("Record %d not found\n", search_id);
    }

    return 0;
}