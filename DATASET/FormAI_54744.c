//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Employee struct */
typedef struct {
    int emp_id;
    char name[100];
    char position[50];
    float salary;
} Employee;

/* Database struct */
typedef struct {
    Employee employees[100];
    int size;
} Database;

/* Add employee to database */
void add_employee(Database *db, Employee emp) {
    db->employees[db->size] = emp;
    db->size++;
}

/* Find employee by name */
Employee *find_employee(Database *db, char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->employees[i].name, name) == 0) {
            return &db->employees[i];
        }
    }
    return NULL;
}

int main() {
    /* Initialize database */
    Database db;
    db.size = 0;

    /* Add employees */
    Employee emp1 = {1, "John Smith", "Manager", 50000.0};
    Employee emp2 = {2, "Jane Doe", "Assistant", 25000.0};
    Employee emp3 = {3, "Bob Johnson", "Intern", 15000.0};
    add_employee(&db, emp1);
    add_employee(&db, emp2);
    add_employee(&db, emp3);

    /* Find and update employee salary */
    Employee *found = find_employee(&db, "Jane Doe");
    if (found != NULL) {
        found->salary = 30000.0;
    }

    /* Print all employees */
    printf("Employees:\n");
    for (int i = 0; i < db.size; i++) {
        printf("ID: %d, Name: %s, Position: %s, Salary: %.2f\n",
               db.employees[i].emp_id,
               db.employees[i].name,
               db.employees[i].position,
               db.employees[i].salary);
    }

    return 0;
}