//FormAI DATASET v1.0 Category: Database querying ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to hold employee data
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} employee;

int main() {
    // create an array of employees
    employee employees[5];
    // populate the array with some dummy data
    employees[0].id = 1;
    strcpy(employees[0].name, "John");
    employees[0].age = 25;
    employees[0].salary = 50000.0;
    employees[1].id = 2;
    strcpy(employees[1].name, "Jane");
    employees[1].age = 30;
    employees[1].salary = 75000.0;
    employees[2].id = 3;
    strcpy(employees[2].name, "Bob");
    employees[2].age = 35;
    employees[2].salary = 100000.0;
    employees[3].id = 4;
    strcpy(employees[3].name, "Sue");
    employees[3].age = 40;
    employees[3].salary = 125000.0;
    employees[4].id = 5;
    strcpy(employees[4].name, "Tom");
    employees[4].age = 45;
    employees[4].salary = 150000.0;

    // query the database for employees with a salary greater than 100000.0
    printf("Employees with salary greater than 100000.0:\n");
    for (int i = 0; i < 5; i++) {
        if (employees[i].salary > 100000.0) {
            printf("ID: %d | Name: %s | Age: %d | Salary: %.2f\n",
                   employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
        }
    }
    return 0;
}