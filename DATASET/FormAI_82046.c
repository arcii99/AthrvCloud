//FormAI DATASET v1.0 Category: Database querying ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    float salary;
} Employee;

int main() {
    Employee employees[5] = { {101, "John", 25, "Male", 2500.0},
                              {102, "Mary", 30, "Female", 3500.0},
                              {103, "David", 35, "Male", 4500.0},
                              {104, "Susan", 40, "Female", 5500.0},
                              {105, "Bill", 45, "Male", 6500.0} };

    // Print all employees
    printf("All employees:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s, Salary: $%.2f\n", 
               employees[i].id, employees[i].name, employees[i].age, employees[i].gender, employees[i].salary);
    }
    
    // Print female employees
    printf("\nFemale employees:\n");
    for (int i = 0; i < 5; i++) {
        if (strcmp(employees[i].gender, "Female") == 0) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %s, Salary: $%.2f\n", 
                   employees[i].id, employees[i].name, employees[i].age, employees[i].gender, employees[i].salary);
        }
    }
    
    // Print employees with salary greater than $5000
    printf("\nEmployees with salary greater than $5000:\n");
    for (int i = 0; i < 5; i++) {
        if (employees[i].salary > 5000.0) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %s, Salary: $%.2f\n", 
                   employees[i].id, employees[i].name, employees[i].age, employees[i].gender, employees[i].salary);
        }
    }
    
    // Print employee with ID 103
    printf("\nEmployee with ID 103:\n");
    for (int i = 0; i < 5; i++) {
        if (employees[i].id == 103) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %s, Salary: $%.2f\n", 
                   employees[i].id, employees[i].name, employees[i].age, employees[i].gender, employees[i].salary);
            break;
        }
    }
    
    // Update employee with ID 102's salary to $4000
    for (int i = 0; i < 5; i++) {
        if (employees[i].id == 102) {
            employees[i].salary = 4000.0;
            break;
        }
    }
    
    // Print all employees after salary update
    printf("\nAll employees after salary update for ID 102:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s, Salary: $%.2f\n", 
               employees[i].id, employees[i].name, employees[i].age, employees[i].gender, employees[i].salary);
    }
    
    return 0;
}