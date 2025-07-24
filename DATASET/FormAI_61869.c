//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

int main() {
    struct Employee employees[] = {
        {1, "John Doe", "Sales", 5000.0},
        {2, "Jane Smith", "Marketing", 6000.0},
        {3, "Mike Johnson", "IT", 7000.0},
        {4, "Hannah Baker", "Human Resources", 8000.0},
        {5, "Tommy Lee", "Operations", 9000.0}
    };
    int numEmployees = sizeof(employees)/sizeof(employees[0]);
    
    // Query employees in IT department with salary greater than 6500.0
    printf("Employees in IT department with salary greater than 6500.0:\n");
    for (int i=0; i<numEmployees; i++) {
        if (strcmp(employees[i].department, "IT") == 0 && employees[i].salary > 6500.0) {
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Salary: %.2f\n\n", employees[i].salary);
        }
    }
    
    // Query employees with names containing the letter "e"
    printf("Employees with names containing the letter \"e\":\n");
    for (int i=0; i<numEmployees; i++) {
        char* name = employees[i].name;
        bool containsE = false;
        int len = strlen(name);
        for (int j=0; j<len; j++) {
            if (name[j] == 'e' || name[j] == 'E') {
                containsE = true;
                break;
            }
        }
        if (containsE) {
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Salary: %.2f\n\n", employees[i].salary);
        }
    }
    
    // Query employee with ID 4 using linear search
    int idToFind = 4;
    int foundIndex = -1;
    for (int i=0; i<numEmployees; i++) {
        if (employees[i].id == idToFind) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        printf("Employee with ID %d found:\n", idToFind);
        printf("ID: %d\n", employees[foundIndex].id);
        printf("Name: %s\n", employees[foundIndex].name);
        printf("Department: %s\n", employees[foundIndex].department);
        printf("Salary: %.2f\n\n", employees[foundIndex].salary);
    } else {
        printf("Employee with ID %d not found.\n\n", idToFind);
    }
    
    return 0;
}