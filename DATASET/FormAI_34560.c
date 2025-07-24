//FormAI DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_VAL_LEN 32
#define MAX_REC_LEN (MAX_KEY_LEN+MAX_VAL_LEN)

/* Node structure */
typedef struct node *NodePtr;
typedef struct node {
    char *key;
    char *val;
    NodePtr next;
} Node;

/* Index structure */
typedef struct index *IndexPtr;
typedef struct index {
    NodePtr head;
    IndexPtr next;
} Index;

/* Hash function */
unsigned int hash(char *key) {
    unsigned int h = 0;
    while (*key)
        h = h * 31 + (*key++);
    return h;
}

/* Lookup function */
char *lookup(IndexPtr index, char *key) {
    unsigned int h = hash(key);
    for (; index != NULL; index = index->next) {
        if (index->head != NULL && hash(index->head->key) == h) {
            NodePtr node;
            for (node = index->head; node != NULL; node = node->next) {
                if (strcmp(node->key, key) == 0)
                    return node->val;
            }
        }
    }
    return NULL;
}

/* Insert function */
void insert(IndexPtr *index, char *key, char *val) {
    unsigned int h = hash(key);
    for (; *index != NULL; index = &((*index)->next)) {
        if ((*index)->head != NULL && hash((*index)->head->key) == h) {
            NodePtr node, *prev;
            for (prev = &((*index)->head), node = *prev; node != NULL; prev = &(node->next), node = *prev) {
                if (strcmp(node->key, key) == 0) {
                    free(node->val);
                    node->val = strdup(val);
                    return;
                }
            }
            *prev = (NodePtr) malloc(sizeof(Node));
            (*prev)->key = strdup(key);
            (*prev)->val = strdup(val);
            (*prev)->next = NULL;
            return;
        }
    }
    *index = (IndexPtr) malloc(sizeof(Index));
    (*index)->head = (NodePtr) malloc(sizeof(Node));
    (*index)->head->key = strdup(key);
    (*index)->head->val = strdup(val);
    (*index)->head->next = NULL;
    (*index)->next = NULL;
}

int main() {
    char keys[][MAX_KEY_LEN] = {"apple", "banana", "cherry", "durian", "elderberry", "fig", "grape"};
    char vals[][MAX_VAL_LEN] = {"a", "b", "c", "d", "e", "f", "g"};
    IndexPtr index = NULL;
    int i;
    for (i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
        insert(&index, keys[i], vals[i]);
    printf("lookup(apple): %s\n", lookup(index, "apple"));
    printf("lookup(elderberry): %s\n", lookup(index, "elderberry"));
    printf("lookup(watermelon): %s\n", lookup(index, "watermelon"));
    return 0;
}