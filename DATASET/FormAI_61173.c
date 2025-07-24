//FormAI DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    double salary;
} Employee;

#define INDEX_SIZE 100

int main() {
    Employee employees[5] = {
        {1, "John", 25, 30000},
        {2, "Jane", 30, 40000},
        {3, "Bob", 33, 45000},
        {4, "Alice", 28, 35000},
        {5, "Tom", 40, 50000}
    };

    int idIndex[INDEX_SIZE];
    int ageIndex[INDEX_SIZE];
    double salaryIndex[INDEX_SIZE];

    memset(idIndex, -1, sizeof(idIndex));
    memset(ageIndex, -1, sizeof(ageIndex));
    memset(salaryIndex, -1, sizeof(salaryIndex));

    for (int i = 0; i < 5; i++) {
        Employee emp = employees[i];
        idIndex[emp.id % INDEX_SIZE] = i;
        ageIndex[emp.age % INDEX_SIZE] = i;
        salaryIndex[((int) emp.salary) % INDEX_SIZE] = i;
    }

    int queryId = 3;

    int resultId = idIndex[queryId % INDEX_SIZE];
    if (resultId != -1 && employees[resultId].id == queryId) {
        printf("Found Employee: %s\n", employees[resultId].name);
    } else {
        printf("Employee not found\n");
    }

    printf("\n");

    int queryAge = 33;

    int resultAge = ageIndex[queryAge % INDEX_SIZE];
    if (resultAge != -1 && employees[resultAge].age == queryAge) {
        printf("Found Employee: %s\n", employees[resultAge].name);
    } else {
        printf("Employee not found\n");
    }

    printf("\n");

    double querySalary = 40000;

    int resultSalary = salaryIndex[((int) querySalary) % INDEX_SIZE];
    if (resultSalary != -1 && employees[resultSalary].salary == querySalary) {
        printf("Found Employee: %s\n", employees[resultSalary].name);
    } else {
        printf("Employee not found\n");
    }

    return 0;
}