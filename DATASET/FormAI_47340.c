//FormAI DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

void printEmployees(struct Employee employees[], int numEmployees) {
    printf("Employees:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s, Age: %d, Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
}

int compareByAge(const void* a, const void* b) {
    struct Employee* empA = (struct Employee*)a;
    struct Employee* empB = (struct Employee*)b;
    return (empA->age - empB->age);
}

int compareBySalary(const void* a, const void* b) {
    struct Employee* empA = (struct Employee*)a;
    struct Employee* empB = (struct Employee*)b;
    return (empA->salary - empB->salary) * 100;
}

int main()
{
    struct Employee employees[] = {
        {"John Smith", 27, 50000.0},
        {"Mary Johnson", 31, 70000.0},
        {"Bob Williams", 25, 40000.0},
        {"Alice Davis", 29, 60000.0},
        {"Mike Miller", 22, 35000.0},
        {"Sarah Brown", 33, 80000.0}
    };
    int numEmployees = sizeof(employees) / sizeof(struct Employee);

    // print unsorted array
    printf("Before sorting:\n");
    printEmployees(employees, numEmployees);

    // sort by age
    qsort(employees, numEmployees, sizeof(struct Employee), compareByAge);
    printf("\nAfter sorting by age:\n");
    printEmployees(employees, numEmployees);

    // sort by salary
    qsort(employees, numEmployees, sizeof(struct Employee), compareBySalary);
    printf("\nAfter sorting by salary:\n");
    printEmployees(employees, numEmployees);

    return 0;
}