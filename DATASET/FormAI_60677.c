//FormAI DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

// Structure to hold the employee information
typedef struct {
    char name[MAX_LENGTH];
    int age;
    float salary;
} Employee;

// Function to compare employee ages
int compareAge(const void *a, const void *b) {
    Employee *empA = (Employee *)a;
    Employee *empB = (Employee *)b;
    
    if (empA->age < empB->age) {
        return -1;
    } else if (empA->age > empB->age) {
        return 1;
    } else {
        return 0;
    }
}

// Function to compare employee salaries
int compareSalary(const void *a, const void *b) {
    Employee *empA = (Employee *)a;
    Employee *empB = (Employee *)b;
    
    if (empA->salary < empB->salary) {
        return -1;
    } else if (empA->salary > empB->salary) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Create an array of employees
    Employee employees[5];
    
    // Populate the array with employee information
    strcpy(employees[0].name, "John");
    employees[0].age = 30;
    employees[0].salary = 50000.0;
    
    strcpy(employees[1].name, "Mary");
    employees[1].age = 25;
    employees[1].salary = 60000.0;
    
    strcpy(employees[2].name, "Bob");
    employees[2].age = 35;
    employees[2].salary = 45000.0;
    
    strcpy(employees[3].name, "Emma");
    employees[3].age = 28;
    employees[3].salary = 55000.0;
    
    strcpy(employees[4].name, "Dave");
    employees[4].age = 32;
    employees[4].salary = 52000.0;
    
    // Sort the employees by age
    qsort(employees, 5, sizeof(Employee), compareAge);
    
    // Print out the sorted employees by age
    printf("Employees sorted by age:\n");
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t%d\t%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
    printf("\n");
    
    // Sort the employees by salary
    qsort(employees, 5, sizeof(Employee), compareSalary);
    
    // Print out the sorted employees by salary
    printf("Employees sorted by salary:\n");
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t%d\t%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
    
    return 0;
}