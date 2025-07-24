//FormAI DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// struct for a record in the database
typedef struct {
    int id;
    char name[20];
    int age;
} Record;

// struct for a node in the index tree
typedef struct IndexNode {
    int key;
    int num_records;
    Record* records[10];
    struct IndexNode* left_child;
    struct IndexNode* right_child;
} IndexNode;

// function to search for a key in the index tree
Record* search(IndexNode* node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (node->key == key) {
        return node->records[0];
    }
    else if (key < node->key) {
        return search(node->left_child, key);
    }
    else {
        return search(node->right_child, key);
    }
}

// function to insert a record into the index tree
void insert(IndexNode** node_ptr, Record* record) {
    if (*node_ptr == NULL) {
        // create a new leaf node and insert the record
        IndexNode* new_node = (IndexNode*) malloc(sizeof(IndexNode));
        new_node->key = record->id;
        new_node->num_records = 1;
        new_node->records[0] = record;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        *node_ptr = new_node;
    }
    else if ((*node_ptr)->num_records < 10) {
        // add the record to the node
        int i = (*node_ptr)->num_records;
        while (i > 0 && record->id < (*node_ptr)->records[i-1]->id) {
            (*node_ptr)->records[i] = (*node_ptr)->records[i-1];
            i--;
        }
        (*node_ptr)->records[i] = record;
        (*node_ptr)->num_records++;
    }
    else {
        // split the node and insert the record into the appropriate child node
        int mid = (*node_ptr)->num_records / 2;
        IndexNode* left_node = (IndexNode*) malloc(sizeof(IndexNode));
        IndexNode* right_node = (IndexNode*) malloc(sizeof(IndexNode));
        left_node->key = (*node_ptr)->records[0]->id;
        left_node->num_records = mid;
        for (int i = 0; i < mid; i++) {
            left_node->records[i] = (*node_ptr)->records[i];
        }
        left_node->left_child = (*node_ptr)->left_child;
        left_node->right_child = right_node;
        right_node->key = (*node_ptr)->records[mid]->id;
        right_node->num_records = (*node_ptr)->num_records - mid;
        for (int i = mid; i < (*node_ptr)->num_records; i++) {
            right_node->records[i-mid] = (*node_ptr)->records[i];
        }
        right_node->left_child = left_node;
        right_node->right_child = (*node_ptr)->right_child;
        (*node_ptr) = NULL;
        insert(node_ptr, record->id < right_node->key ? left_node : right_node);
    }
}

// function to print the index tree in-order
void print_tree(IndexNode* node) {
    if (node != NULL) {
        print_tree(node->left_child);
        printf("%d:\t", node->key);
        for (int i = 0; i < node->num_records; i++) {
            printf("%s (%d)\t", node->records[i]->name, node->records[i]->age);
        }
        printf("\n");
        print_tree(node->right_child);
    }
}

// main function to demonstrate the indexing system
int main() {
    // create some sample records
    Record* record1 = (Record*) malloc(sizeof(Record));
    record1->id = 3;
    sprintf(record1->name, "John");
    record1->age = 25;
    Record* record2 = (Record*) malloc(sizeof(Record));
    record2->id = 5;
    sprintf(record2->name, "Sarah");
    record2->age = 32;
    Record* record3 = (Record*) malloc(sizeof(Record));
    record3->id = 2;
    sprintf(record3->name, "Mike");
    record3->age = 18;
    Record* record4 = (Record*) malloc(sizeof(Record));
    record4->id = 7;
    sprintf(record4->name, "Emily");
    record4->age = 41;
    Record* record5 = (Record*) malloc(sizeof(Record));
    record5->id = 1;
    sprintf(record5->name, "Bob");
    record5->age = 47;
    Record* record6 = (Record*) malloc(sizeof(Record));
    record6->id = 8;
    sprintf(record6->name, "Alice");
    record6->age = 29;
    Record* record7 = (Record*) malloc(sizeof(Record));
    record7->id = 4;
    sprintf(record7->name, "Tom");
    record7->age = 36;
    Record* record8 = (Record*) malloc(sizeof(Record));
    record8->id = 6;
    sprintf(record8->name, "Lisa");
    record8->age = 23;

    // insert the records into the index tree
    IndexNode* root = NULL;
    insert(&root, record1);
    insert(&root, record2);
    insert(&root, record3);
    insert(&root, record4);
    insert(&root, record5);
    insert(&root, record6);
    insert(&root, record7);
    insert(&root, record8);

    // print the index tree
    printf("Index Tree:\n");
    print_tree(root);

    // search for a record
    int id = 4;
    Record* result = search(root, id);
    if (result != NULL) {
        printf("\nRecord with id %d found: %s (%d)\n", id, result->name, result->age);
    }
    else {
        printf("\nRecord with id %d not found.\n", id);
    }

    // free memory allocated for records
    free(record1);
    free(record2);
    free(record3);
    free(record4);
    free(record5);
    free(record6);
    free(record7);
    free(record8);

    return 0;
}