//FormAI DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

typedef struct {
    Employee records[MAX_RECORDS];
    int count;
} Database;

void addRecord(Database *db, Employee emp) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count++] = emp;
        printf("Record added successfully!\n");
    } else {
        printf("Database is full!\n");
    }
}

void deleteRecord(Database *db, int id) {
    int index = -1;
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Record not found!\n");
        return;
    }
    for (int i = index; i < db->count - 1; i++) {
        db->records[i] = db->records[i+1];
    }
    db->count--;
    printf("Record deleted successfully!\n");
}

void printRecord(Employee emp) {
    printf("ID: %d, Name: %s, Age: %d, Salary: $%.2f\n", emp.id, emp.name, emp.age, emp.salary);
}

void printDatabase(Database *db) {
    printf("Database:\n");
    printf("--------------------------------------------------\n");
    printf("ID\t|Name\t|Age\t|Salary\n");
    for (int i = 0; i < db->count; i++) {
        printRecord(db->records[i]);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    Database db = { .records = {}, .count = 0 };
    Employee emp1 = { .id = 100, .name = "John Smith", .age = 35, .salary = 50000.00 };
    Employee emp2 = { .id = 101, .name = "Jane Doe", .age = 28, .salary = 45000.00 };
    Employee emp3 = { .id = 102, .name = "Peter Parker", .age = 25, .salary = 60000.00 };
    addRecord(&db, emp1);
    addRecord(&db, emp2);
    addRecord(&db, emp3);
    printDatabase(&db);
    deleteRecord(&db, 101);
    printDatabase(&db);

    return 0;
}