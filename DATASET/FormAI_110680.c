//FormAI DATASET v1.0 Category: Database querying ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Struct to store data of employees*/
struct Employee {
    int emp_id;
    char emp_name[50];
    float emp_salary;
    char emp_department[25];
};

/*Function to initialize array of employees*/
void initEmployees(struct Employee employees[], int len) {
    for(int i = 0; i < len; i++) {
        employees[i].emp_id = i + 1;
        snprintf(employees[i].emp_name, 50, "Employee %d", i+1);
        employees[i].emp_salary = (rand() % 5000) + 50000;
        snprintf(employees[i].emp_department, 25, "Department %d", i%5 + 1);
    }
}

/*Function to print array of employees*/
void printEmployees(struct Employee employees[], int len) {
    for(int i = 0; i < len; i++) {
        printf("ID: %d | Name: %s | Salary: %0.2f | Department: %s\n",
               employees[i].emp_id, employees[i].emp_name, employees[i].emp_salary, employees[i].emp_department);
    }
}

/*Function to query employees by department*/
void queryByDepartment(struct Employee employees[], int len, char department[]) {
    bool found = false;
    printf("Employees in %s department:\n", department);
    for(int i = 0; i < len; i++) {
        if(strcmp(employees[i].emp_department, department) == 0) {
            printf("ID: %d | Name: %s | Salary: %0.2f\n", employees[i].emp_id, employees[i].emp_name, employees[i].emp_salary);
            found = true;
        }
    }
    if(!found) {
        printf("No employees found in %s department.\n", department);
    }
}

/*Function to query employees by salary range*/
void queryBySalaryRange(struct Employee employees[], int len, float min_salary, float max_salary) {
    bool found = false;
    printf("Employees with salary between %0.2f and %0.2f:\n", min_salary, max_salary);
    for(int i = 0; i < len; i++) {
        if(employees[i].emp_salary >= min_salary && employees[i].emp_salary <= max_salary) {
            printf("ID: %d | Name: %s | Salary: %0.2f | Department: %s\n",
                   employees[i].emp_id, employees[i].emp_name, employees[i].emp_salary, employees[i].emp_department);
            found = true;
        }
    }
    if(!found) {
        printf("No employees found with salary between %0.2f and %0.2f\n", min_salary, max_salary);
    }
}

/*Main function*/
int main() {
    srand(1234); //Initialize random seed
    int num_employees = 100;
    struct Employee employees[num_employees];
    initEmployees(employees, num_employees);
    printf("All Employees:\n");
    printEmployees(employees, num_employees);
    queryByDepartment(employees, num_employees, "Department 3");
    queryBySalaryRange(employees, num_employees, 55000.0, 60000.0);
    return 0;
}