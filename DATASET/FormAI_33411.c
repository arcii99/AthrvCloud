//FormAI DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define a struct to hold information about employees */
struct Employee {
    int id;
    char name[50];
    float salary;
};

/* declare the function to compare employees by their salaries */
int compareEmployeesBySalary(const void *a, const void *b) {
    struct Employee *e1 = (struct Employee *)a;
    struct Employee *e2 = (struct Employee *)b;
    if (e1->salary < e2->salary) {
        return -1;
    } else if (e1->salary > e2->salary) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    /* create an array of employees */
    struct Employee employees[] = {
        {1, "Alice", 50000.0},
        {2, "Bob", 75000.0},
        {3, "Carl", 60000.0},
        {4, "Dave", 90000.0},
        {5, "Eve", 45000.0},
        {6, "Frank", 80000.0},
        {7, "Grace", 55000.0},
        {8, "Heidi", 70000.0},
        {9, "Ivan", 65000.0},
        {10, "Judy", 85000.0}
    };
    int num_employees = sizeof(employees) / sizeof(struct Employee);
    
    /* print out the unsorted array of employees */
    printf("Unsorted employees:\n");
    for (int i = 0; i < num_employees; i++) {
        printf("%d: %s, %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    
    /* sort the array of employees by their salaries */
    qsort(employees, num_employees, sizeof(struct Employee), compareEmployeesBySalary);
    
    /* print out the sorted array of employees */
    printf("Sorted employees by salary:\n");
    for (int i = 0; i < num_employees; i++) {
        printf("%d: %s, %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    
    return 0;
}