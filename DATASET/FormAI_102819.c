//FormAI DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXRECORDS 50
#define MAXNAME 30

typedef struct {
    char name[MAXNAME];
    int id;
    double salary;
} Employee;

typedef struct {
    Employee records[MAXRECORDS];
    int num_records;
} Database;

typedef struct {
    int id;
    int index;
} Index;

typedef struct {
    Index indexes[MAXRECORDS];
    int num_indexes;
} IndexList;

void init_database(Database *db) {
    db->num_records = 0;
}

void add_record(Database *db, char *name, int id, double salary) {
    if (db->num_records >= MAXRECORDS) {
        printf("Error: Database is full\n");
        return;
    }
    Employee new_employee;
    strcpy(new_employee.name, name);
    new_employee.id = id;
    new_employee.salary = salary;
    db->records[db->num_records++] = new_employee;
}

void print_record(Employee *employee) {
    printf("Name: %s\nID: %d\nSalary: %g\n", employee->name, employee->id, employee->salary);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
    }
}

void add_index(IndexList *index_list, Database *db, int id) {
    for (int i = 0; i < index_list->num_indexes; i++) {
        if (index_list->indexes[i].id == id) {
            printf("Error: Index already exists\n");
            return;
        }
    }
    Index new_index;
    new_index.id = id;
    new_index.index = db->num_records - 1;
    index_list->indexes[index_list->num_indexes++] = new_index;
}

void print_index_list(IndexList *index_list) {
    for (int i = 0; i < index_list->num_indexes; i++) {
        printf("ID: %d Index: %d\n", index_list->indexes[i].id, index_list->indexes[i].index);
    }
}

void search_records(Database *db, IndexList *index_list, int id) {
    for (int i = 0; i < index_list->num_indexes; i++) {
        if (index_list->indexes[i].id == id) {
            print_record(&db->records[index_list->indexes[i].index]);
            return;
        }
    }
    printf("Error: Record not found\n");
}

int main() {
    Database db;
    init_database(&db);
    IndexList index_list;
    index_list.num_indexes = 0;

    add_record(&db, "John Doe", 1234, 10000);
    add_record(&db, "Jane Doe", 5678, 20000);
    add_record(&db, "Bob Smith", 9012, 30000);

    add_index(&index_list, &db, 1234);
    add_index(&index_list, &db, 5678);
    add_index(&index_list, &db, 9012);

    printf("Database:\n");
    print_database(&db);

    printf("Index List:\n");
    print_index_list(&index_list);

    printf("Search Result:\n");
    search_records(&db, &index_list, 5678);

    return 0;
}