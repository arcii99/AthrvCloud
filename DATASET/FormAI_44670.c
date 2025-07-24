//FormAI DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10

#define HASH_TABLE_SIZE 100

typedef struct element_t {
    char* value;
    int count;
} Element;

typedef struct node_t {
    Element* element;
    struct node_t* next;
} Node;

typedef struct hash_table_t {
    Node* buckets[HASH_TABLE_SIZE];
} HashTable;

int hash(char* key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = (hash + key[i]) % HASH_TABLE_SIZE;
    }
    return hash;
}

Element* create_element(char* value, int count) {
    Element* element = malloc(sizeof(Element));
    element->value = strdup(value);
    element->count = count;
    return element;
}

void destroy_element(Element* element) {
    free(element->value);
    free(element);
}

Node* create_node(Element* element, Node* next) {
    Node* node = malloc(sizeof(Node));
    node->element = element;
    node->next = next;
    return node;
}

void destroy_node(Node* node) {
    destroy_element(node->element);
    free(node);
}

void insert_element(HashTable* table, char* value) {
    int index = hash(value);
    Node* node = table->buckets[index];
    while (node != NULL) {
        if (strcmp(node->element->value, value) == 0) {
            node->element->count++;
            return;
        }
        node = node->next;
    }
    Element* element = create_element(value, 1);
    Node* new_node = create_node(element, table->buckets[index]);
    table->buckets[index] = new_node;
}

void destroy_bucket(Node* node) {
    if (node == NULL) {
        return;
    }
    destroy_bucket(node->next);
    destroy_node(node);
}

void destroy_hash_table(HashTable* table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        destroy_bucket(table->buckets[i]);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        return 1;
    }
    HashTable table = {0};
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        line_number++;
        char* token = strtok(line, ",");
        int column_number = 0;
        while (token != NULL && column_number < MAX_COLUMNS) {
            column_number++;
            insert_element(&table, token);
            token = strtok(NULL, ",");
        }
    }
    fclose(fp);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* node = table.buckets[i];
        while (node != NULL) {
            printf("%s, %d\n", node->element->value, node->element->count);
            node = node->next;
        }
    }
    destroy_hash_table(&table);
    return 0;
}