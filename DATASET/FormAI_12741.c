//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to store employee information
struct Employee {
    char name[50];
    int age;
    char department[50];
};

// function to print the employee data
void print_employee(struct Employee e) {
    printf("Name: %s\n", e.name);
    printf("Age: %d\n", e.age);
    printf("Department: %s\n", e.department);
}

// main function
int main() {
    // create an array of employees
    struct Employee employees[3];

    // fill in the employee data
    strcpy(employees[0].name, "John");
    employees[0].age = 25;
    strcpy(employees[0].department, "Engineering");

    strcpy(employees[1].name, "Mary");
    employees[1].age = 30;
    strcpy(employees[1].department, "Marketing");

    strcpy(employees[2].name, "Bob");
    employees[2].age = 35;
    strcpy(employees[2].department, "Sales");

    // search for employees with a particular department
    char query[50];
    printf("Enter the department to search for: ");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = 0; // remove the newline character

    int found = 0; // flag to indicate if any employees were found

    for (int i = 0; i < 3; i++) {
        if (strcmp(employees[i].department, query) == 0) {
            print_employee(employees[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No employees found in %s department\n", query);
    }

    return 0;
}