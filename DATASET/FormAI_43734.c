//FormAI DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 10

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

typedef struct {
    Employee data[MAX_INDEX];
    int count;
} EmployeeIndex;

void init(EmployeeIndex *index) {
    index->count = 0;
}

void add(EmployeeIndex *index, Employee employee) {
    index->data[index->count++] = employee;
}

void display(EmployeeIndex *index) {
    printf("Name\tAge\tSalary\n");
    printf("-----------------------\n");
    for (int i = 0; i < index->count; i++) {
        printf("%s\t%d\t%.2f\n", index->data[i].name, index->data[i].age, index->data[i].salary);
    }
}

void indexByName(EmployeeIndex *index) {
    int i, j;
    Employee temp;
    for (i = 0; i < index->count - 1; i++) {
        for (j = i + 1; j < index->count; j++) {
            if (strcmp(index->data[i].name, index->data[j].name) > 0) {
                temp = index->data[i];
                index->data[i] = index->data[j];
                index->data[j] = temp;
            }
        }
    }
}

void indexByAge(EmployeeIndex *index) {
    int i, j;
    Employee temp;
    for (i = 0; i < index->count - 1; i++) {
        for (j = i + 1; j < index->count; j++) {
            if (index->data[i].age > index->data[j].age) {
                temp = index->data[i];
                index->data[i] = index->data[j];
                index->data[j] = temp;
            }
        }
    }
}

void indexBySalary(EmployeeIndex *index) {
    int i, j;
    Employee temp;
    for (i = 0; i < index->count - 1; i++) {
        for (j = i + 1; j < index->count; j++) {
            if (index->data[i].salary > index->data[j].salary) {
                temp = index->data[i];
                index->data[i] = index->data[j];
                index->data[j] = temp;
            }
        }
    }
}

int main() {
    EmployeeIndex index;
    Employee employee;
    
    init(&index);
    
    employee = (Employee) { "John", 25, 5000 };
    add(&index, employee);
    employee = (Employee) { "Sarah", 32, 8000 };
    add(&index, employee);
    employee = (Employee) { "Mike", 28, 6500 };
    add(&index, employee);
    employee = (Employee) { "Alice", 24, 4500 };
    add(&index, employee);
    employee = (Employee) { "Jake", 27, 7000 };
    add(&index, employee);
    
    printf("Unsorted List:\n");
    display(&index);
    
    indexByName(&index);
    printf("List Sorted by Name:\n");
    display(&index);
    
    indexByAge(&index);
    printf("List Sorted by Age:\n");
    display(&index);
    
    indexBySalary(&index);
    printf("List Sorted by Salary:\n");
    display(&index);
    
    return 0;
}