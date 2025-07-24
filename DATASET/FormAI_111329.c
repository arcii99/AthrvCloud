//FormAI DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char profession[20];
    float salary;
} Employee;

const int NUM_EMPLOYEES = 4;

int main() {
    Employee employees[NUM_EMPLOYEES];

    // Populate employee data
    strcpy(employees[0].name, "John");
    employees[0].age = 30;
    strcpy(employees[0].profession, "Software Engineer");
    employees[0].salary = 75000.0;

    strcpy(employees[1].name, "Samantha");
    employees[1].age = 25;
    strcpy(employees[1].profession, "Data Analyst");
    employees[1].salary = 60000.0;

    strcpy(employees[2].name, "Mike");
    employees[2].age = 40;
    strcpy(employees[2].profession, "Project Manager");
    employees[2].salary = 90000.0;

    strcpy(employees[3].name, "Sarah");
    employees[3].age = 35;
    strcpy(employees[3].profession, "Financial Analyst");
    employees[3].salary = 80000.0;

    // Find employee with highest salary
    float maxSalary = 0.0;
    int maxSalaryIndex = 0;

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        if (employees[i].salary > maxSalary) {
            maxSalary = employees[i].salary;
            maxSalaryIndex = i;
        }
    }

    printf("Employee with highest salary:\n");
    printf("Name: %s\n", employees[maxSalaryIndex].name);
    printf("Age: %d\n", employees[maxSalaryIndex].age);
    printf("Profession: %s\n", employees[maxSalaryIndex].profession);
    printf("Salary: %.2f\n", employees[maxSalaryIndex].salary);

    return 0;
}