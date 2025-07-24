//FormAI DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

int numEmployees = 0;
Employee employeeList[MAX_SIZE];

int main() {

    int choice;
    do {
        printf("\n********** employee database *********\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addEmployee() {
    Employee employee;

    printf("\nEnter employee id:");
    scanf("%d", &employee.id);

    printf("\nEnter employee name:");
    scanf("%s", employee.name);

    printf("\nEnter employee age:");
    scanf("%d", &employee.age);

    printf("\nEnter employee salary:");
    scanf("%f", &employee.salary);

    employeeList[numEmployees] = employee;
    numEmployees++;

    printf("\nEmployee added successfully!\n");
}

void displayAll() {
    if (numEmployees == 0) {
        printf("\nNo employees to display!\n");
        return;
    }

    printf("\nEmployee List:\n");
    for (int i = 0; i < numEmployees; i++) {
        Employee employee = employeeList[i];
        printf("\n%d\t%s\t%d\t%.2f", employee.id, employee.name, employee.age, employee.salary);
    }
    printf("\n");
}

void searchEmployee() {
    int id;
    printf("\nEnter employee id:");
    scanf("%d", &id);

    for (int i = 0; i < numEmployees; i++) {
        Employee employee = employeeList[i];
        if (employee.id == id) {
            printf("\nEmployee details:");
            printf("\n%d\t%s\t%d\t%.2f\n", employee.id, employee.name, employee.age, employee.salary);
            return;
        }
    }

    printf("\nEmployee not found!\n");
}

void updateEmployee() {
    int id, choice;
    printf("\nEnter employee id:");
    scanf("%d", &id);

    for (int i = 0; i < numEmployees; i++) {
        Employee *employee = &employeeList[i];
        if (employee->id == id) {
            printf("\nEmployee details:");
            printf("\n%d\t%s\t%d\t%.2f\n", employee->id, employee->name, employee->age, employee->salary);
            printf("\n1. Update name");
            printf("\n2. Update age");
            printf("\n3. Update salary");
            printf("\nEnter your choice:");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\nEnter new name:");
                    scanf("%s", employee->name);
                    break;
                case 2:
                    printf("\nEnter new age:");
                    scanf("%d", &employee->age);
                    break;
                case 3:
                    printf("\nEnter new salary:");
                    scanf("%f", &employee->salary);
                    break;
                default:
                    printf("\nInvalid choice!");
            }

            printf("\nEmployee details updated successfully!\n");
            return;
        }
    }

    printf("\nEmployee not found!\n");
}

void deleteEmployee() {
    int id;
    printf("\nEnter employee id:");
    scanf("%d", &id);

    for (int i = 0; i < numEmployees; i++) {
        Employee employee = employeeList[i];
        if (employee.id == id) {
            for (int j = i; j < numEmployees - 1; j++) {
                employeeList[j] = employeeList[j + 1];
            }
            numEmployees--;
            printf("\nEmployee deleted successfully!\n");
            return;
        }
    }

    printf("\nEmployee not found!\n");
}