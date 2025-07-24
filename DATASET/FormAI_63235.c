//FormAI DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int EmployeeID;
    char EmployeeName[50];
    int Age;
    char Department[50];
    float Salary;
};

struct Index {
    int key;
    int recordNumber;
};

int main() {
    int totalRecords = 10;
    struct Employee employees[totalRecords];
    struct Index indexForEmployeeID[totalRecords];
    struct Index indexForAge[totalRecords];
    struct Index indexForSalary[totalRecords];
    int i;
    int employeeIDKey = 0;
    int ageKey = 0;
    float salaryKey = 0.0;
    for(i=0; i<totalRecords; i++) {
        employees[i].EmployeeID = i;
        strcpy(employees[i].EmployeeName, "John Doe");
        employees[i].Age = i % 5;
        strcpy(employees[i].Department, "IT");
        employees[i].Salary = i * 1000.0;
        indexForEmployeeID[i].key = employees[i].EmployeeID;
        indexForEmployeeID[i].recordNumber = i;
        indexForAge[i].key = employees[i].Age;
        indexForAge[i].recordNumber = i;
        indexForSalary[i].key = employees[i].Salary;
        indexForSalary[i].recordNumber = i;
    }
    employeeIDKey = 5;
    ageKey = 2;
    salaryKey = 4000.0;
    printf("-------- Indexing based on Employee ID -----------\n");
    for(i=0; i<totalRecords; i++) {
        if(indexForEmployeeID[i].key == employeeIDKey) {
            int recordNumber = indexForEmployeeID[i].recordNumber;
            printf("Employee ID: %d, Employee Name: %s, Age: %d, Department: %s, Salary: %f\n", employees[recordNumber].EmployeeID, employees[recordNumber].EmployeeName, employees[recordNumber].Age, employees[recordNumber].Department, employees[recordNumber].Salary);
        }
    }
    printf("\n");
    printf("-------- Indexing based on Age ---------\n");
    for(i=0; i<totalRecords; i++) {
        if(indexForAge[i].key == ageKey) {
            int recordNumber = indexForAge[i].recordNumber;
            printf("Employee ID: %d, Employee Name: %s, Age: %d, Department: %s, Salary: %f\n", employees[recordNumber].EmployeeID, employees[recordNumber].EmployeeName, employees[recordNumber].Age, employees[recordNumber].Department, employees[recordNumber].Salary);
        }
    }
    printf("\n");
    printf("-------- Indexing based on Salary ---------\n");
    for(i=0; i<totalRecords; i++) {
        if(indexForSalary[i].key == salaryKey) {
            int recordNumber = indexForSalary[i].recordNumber;
            printf("Employee ID: %d, Employee Name: %s, Age: %d, Department: %s, Salary: %f\n", employees[recordNumber].EmployeeID, employees[recordNumber].EmployeeName, employees[recordNumber].Age, employees[recordNumber].Department, employees[recordNumber].Salary);
        }
    }
    return 0;
}