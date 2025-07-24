//FormAI DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[25];
    float salary;
} Employee;

typedef struct {
    int key;
    int index;
} EmployeeIndex;

int compare(const void *a, const void *b) {
    EmployeeIndex *ea = (EmployeeIndex *)a;
    EmployeeIndex *eb = (EmployeeIndex *)b;
    return ea->key - eb->key;
}

void display(Employee employee) {
    printf("%d\t%25s\t%.2f\n", employee.id, employee.name, employee.salary);
}

int main() {
    Employee employees[MAX_RECORDS] = {
        {1, "John Doe", 56000.75},
        {2, "Sarah Smith", 36000.50},
        {3, "Michael Johnson", 47000.25},
        {4, "Julia Parker", 64500.00},
        {5, "Robert Wilson", 53000.75},
        {6, "Jessica Lee", 42000.50},
        {7, "David Brown", 59000.25},
        {8, "Maria Ramirez", 67500.00},
        {9, "Kevin Jones", 51000.75},
        {10, "Catherine Kim", 49000.50},
    };
    EmployeeIndex employeeIndexes[MAX_RECORDS];
    int i, n = 10;
    printf("Original Employee Records: \n");
    for (i = 0; i < n; i++) {
        display(employees[i]);
        employeeIndexes[i].key = employees[i].id;
        employeeIndexes[i].index = i;
    }
    printf("\n");
    qsort(employeeIndexes, n, sizeof(EmployeeIndex), compare);
    int id;
    printf("Enter Employee ID to Search: ");
    scanf("%d", &id);
    int lo = 0, hi = n-1, mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (employeeIndexes[mid].key == id) {
            display(employees[employeeIndexes[mid].index]);
            break;
        }
        else if (employeeIndexes[mid].key < id) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    if (lo > hi) {
        printf("Employee not found.\n");
    }
    return 0;
}