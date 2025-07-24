//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    // Create a sample database of employees
    struct employee employees[] = {
        {101, "John", 50000.0},
        {102, "Jane", 60000.0},
        {103, "Bob", 45000.0},
        {104, "Alice", 55000.0},
        {105, "Tom", 70000.0},
        {106, "Sara", 65000.0},
        {107, "Jack", 48000.0},
        {108, "Mary", 72000.0},
        {109, "Mark", 58000.0},
        {110, "Janet", 62000.0}
    };
    
    // Get the total number of employees
    int num_employees = sizeof(employees) / sizeof(struct employee);
    
    // Print the list of employees
    printf("List of Employees:\n");
    printf("ID\tName\t\tSalary\n");
    for(int i=0; i<num_employees; i++) {
        printf("%d\t%-10s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("\n");
    
    // Query 1: Get the total number of employees who earn more than $60,000
    int count = 0;
    for(int i=0; i<num_employees; i++) {
        if(employees[i].salary > 60000.0) {
            count++;
        }
    }
    printf("Number of employees who earn more than $60,000: %d\n\n", count);
    
    // Query 2: Get the names of employees whose name starts with "J"
    printf("Names of employees whose name starts with 'J':\n");
    printf("Name\n");
    for(int i=0; i<num_employees; i++) {
        if(employees[i].name[0] == 'J') {
            printf("%s\n", employees[i].name);
        }
    }
    printf("\n");
    
    // Query 3: Get the average salary of all employees
    float total_salary = 0.0;
    for(int i=0; i<num_employees; i++) {
        total_salary += employees[i].salary;
    }
    float avg_salary = total_salary / num_employees;
    printf("Average salary of employees: %.2f\n\n", avg_salary);
    
    // Query 4: Get the employee with the highest salary
    struct employee max_salary_employee = employees[0];
    for(int i=1; i<num_employees; i++) {
        if(employees[i].salary > max_salary_employee.salary) {
            max_salary_employee = employees[i];
        }
    }
    printf("Employee with highest salary:\n");
    printf("ID\tName\t\tSalary\n");
    printf("%d\t%-10s\t%.2f\n\n", max_salary_employee.id, max_salary_employee.name, max_salary_employee.salary);
    
    // Query 5: Get the employee with the lowest salary
    struct employee min_salary_employee = employees[0];
    for(int i=1; i<num_employees; i++) {
        if(employees[i].salary < min_salary_employee.salary) {
            min_salary_employee = employees[i];
        }
    }
    printf("Employee with lowest salary:\n");
    printf("ID\tName\t\tSalary\n");
    printf("%d\t%-10s\t%.2f\n\n", min_salary_employee.id, min_salary_employee.name, min_salary_employee.salary);
    
    return 0;
}