//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of the database

// Struct for storing data in the database
struct Data {
    int id;
    char name[20];
    float score;
};

// Struct for storing the database and its indexing data
struct Database {
    int size;
    struct Data data[MAX_SIZE];
    int index_id[MAX_SIZE];
    char index_name[MAX_SIZE][20];
};

// Function to add data to the database and update its indexes
void addData(struct Database *db, struct Data data) {
    db->data[db->size] = data;
    db->index_id[db->size] = data.id;
    strcpy(db->index_name[db->size], data.name);
    db->size++;
}

// Function to search for data in the database by ID
void searchById(struct Database *db, int id) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (db->index_id[i] == id) {
            printf("ID: %d\nName: %s\nScore: %.2f\n", db->data[i].id, db->data[i].name, db->data[i].score);
            return;
        }
    }
    printf("No data found for ID %d\n", id);
}

// Function to search for data in the database by name
void searchByName(struct Database *db, char name[]) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->index_name[i], name) == 0) {
            printf("ID: %d\nName: %s\nScore: %.2f\n", db->data[i].id, db->data[i].name, db->data[i].score);
        }
    }
}

// Main function
int main() {
    struct Database db = {0};
    struct Data data1 = {1, "Alice", 85.6};
    struct Data data2 = {2, "Bob", 73.9};
    struct Data data3 = {3, "Charlie", 91.7};
    struct Data data4 = {4, "Alice", 79.3};
    struct Data data5 = {5, "Eve", 88.1};
    
    // Add data to the database
    addData(&db, data1);
    addData(&db, data2);
    addData(&db, data3);
    addData(&db, data4);
    addData(&db, data5);
    
    // Search for data by ID and name
    printf("Searching for data with ID 3:\n");
    searchById(&db, 3);
    printf("\nSearching for data with name \"Alice\":\n");
    searchByName(&db, "Alice");
    
    return 0;
}