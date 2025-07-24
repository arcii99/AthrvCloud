//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_DB_SIZE 10

// Struct to represent a row in the database
typedef struct Row {
    int id;
    char name[20];
    double value;
} Row;

// Struct to represent the database
typedef struct Database {
    int size;
    Row rows[MAX_DB_SIZE];
} Database;

// Function to initialize the database
void init_database(Database* db) {
    db->size = 0;
}

// Function to print the contents of the database
void print_database(Database* db) {
    printf("ID\tName\tValue\n");
    for(int i=0; i<db->size; i++) {
        printf("%d\t%s\t%.2lf\n", db->rows[i].id, db->rows[i].name, db->rows[i].value);
    }
}

// Function to add a row to the database
void add_row(Database* db, int id, char* name, double value) {
    if(db->size == MAX_DB_SIZE) {
        printf("Database is full\n");
        return;
    }
    db->rows[db->size].id = id;
    for(int i=0; i<20; i++) {
        if(name[i] == '\0') {
            db->rows[db->size].name[i] = '\0';
            break;
        }
        db->rows[db->size].name[i] = name[i];
    }
    db->rows[db->size].value = value;
    db->size++;
}

// Function to remove a row from the database
void remove_row(Database* db, int id) {
    for(int i=0; i<db->size; i++) {
        if(db->rows[i].id == id) {
            for(int j=i; j<db->size-1; j++) {
                db->rows[j] = db->rows[j+1];
            }
            db->size--;
            break;
        }
    }
}

int main() {
    Database db;
    init_database(&db);
    
    add_row(&db, 1, "Row 1", 10.25);
    add_row(&db, 2, "Row 2", 20.50);
    add_row(&db, 3, "Row 3", 30.75);
    print_database(&db);
    
    remove_row(&db, 2);
    print_database(&db);
    
    add_row(&db, 4, "Row 4", 40.00);
    add_row(&db, 5, "Row 5", 50.25);
    add_row(&db, 6, "Row 6", 60.50);
    add_row(&db, 7, "Row 7", 70.75);
    add_row(&db, 8, "Row 8", 80.00);
    add_row(&db, 9, "Row 9", 90.25);
    add_row(&db, 10, "Row 10", 100.50);
    print_database(&db);
    
    return 0;
}