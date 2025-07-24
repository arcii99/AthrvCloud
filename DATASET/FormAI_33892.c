//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 1024 // Number of bytes in a page
#define DATA_SIZE 100 // Maximum size of data item

struct Record {
    int id;
    char data[DATA_SIZE];
};

struct Page {
    int count; // Number of records in the page
    struct Record records[PAGE_SIZE/sizeof(struct Record)];
};

struct Node {
    int key;
    int pageNum;
    struct Node* next;
};

struct Index {
    struct Node* head;
};

struct Database {
    struct Page* pages;
    struct Index* index;
};

// Initialize database with a given number of pages
struct Database* initDB(int numPages) {
    struct Database* db = (struct Database*) malloc(sizeof(struct Database));
    db->pages = (struct Page*) calloc(numPages, sizeof(struct Page));
    db->index = (struct Index*) malloc(sizeof(struct Index));
    db->index->head = NULL;
    return db;
}

// Insert record into database
void insert(struct Database* db, int id, const char* data) {
    // Find page number for record
    int pageNum = 0;
    while (pageNum < PAGE_SIZE && db->pages[pageNum].count > 0) {
        pageNum += db->pages[pageNum].count;
    }

    // Add record to page
    struct Record record = {id};
    strncpy(record.data, data, DATA_SIZE-1);
    db->pages[pageNum].records[db->pages[pageNum].count++] = record;

    // Add to index
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = id;
    node->pageNum = pageNum;
    node->next = db->index->head;
    db->index->head = node;
}

// Find record in database given an id
struct Record* find(struct Database* db, int id) {
    // Find page number using index
    struct Node* node = db->index->head;
    while (node != NULL && node->key != id) {
        node = node->next;
    }
    if (node == NULL) {
        return NULL;
    }
    int pageNum = node->pageNum;

    // Search for record in page
    struct Page* page = &db->pages[pageNum];
    for (int i = 0; i < page->count; i++) {
        if (page->records[i].id == id) {
            return &page->records[i];
        }
    }
    return NULL;
}

// Free memory allocated for database
void freeDB(struct Database* db) {
    free(db->pages);
    struct Node* node = db->index->head;
    while (node != NULL) {
        struct Node* next = node->next;
        free(node);
        node = next;
    }
    free(db->index);
    free(db);
}

int main() {
    // Initialize database
    struct Database* db = initDB(10);

    // Insert records
    insert(db, 1, "data1");
    insert(db, 2, "data2");

    // Find records
    struct Record* record = find(db, 1);
    if (record != NULL) {
        printf("Record found: id=%d, data=%s\n", record->id, record->data);
    } else {
        printf("Record not found\n");
    }

    // Free database memory
    freeDB(db);

    return 0;
}