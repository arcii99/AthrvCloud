//FormAI DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

Employee employees[MAX_SIZE]; // an array of employees
int numEmployees = 0; // the number of employees currently in the array

// function prototypes
void addEmployee(int id, char* name, int age, float salary);
void printEmployees();
void queryByAge(int age);

int main() {
    // example usage
    addEmployee(1, "John Doe", 30, 50000.0);
    addEmployee(2, "Jane Smith", 25, 45000.0);
    addEmployee(3, "Bob Jones", 35, 60000.0);
    addEmployee(4, "Alice Williams", 28, 52000.0);
    
    printEmployees();
    queryByAge(30);
    
    return 0;
}

void addEmployee(int id, char* name, int age, float salary) {
    if (numEmployees >= MAX_SIZE) {
        fprintf(stderr, "Error: maximum number of employees exceeded\n");
        exit(1);
    }
    
    Employee newEmployee;
    newEmployee.id = id;
    strcpy(newEmployee.name, name);
    newEmployee.age = age;
    newEmployee.salary = salary;
    
    employees[numEmployees] = newEmployee;
    numEmployees++;
}

void printEmployees() {
    printf("ID\tName\t\tAge\t Salary\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%d\t%-20s%d\t$%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
    printf("\n");
}

void queryByAge(int age) {
    printf("Employees who are %d years old:\n", age);
    printf("ID\tName\t\tAge\t Salary\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].age == age) {
            printf("%d\t%-20s%d\t$%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
        }
    }
}