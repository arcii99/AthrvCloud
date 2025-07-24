//FormAI DATASET v1.0 Category: Database simulation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold the data of an employee record
struct Employee {
    int id;
    char name[20];
    float salary;
};

// Global variables
int numEmployees = 0;
struct Employee *employeeList;

int main() {
    int choice;
    while(1) {
        // Display menu
        printf("\n\n-----------------------------\n");
        printf("Please select an option:\n");
        printf("1. Add an employee\n");
        printf("2. Display all employees\n");
        printf("3. Search for an employee\n");
        printf("4. Exit\n");
        printf("-----------------------------\n\n");

        // Get user choice
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to add a new employee
void addEmployee() {
    numEmployees++;
    employeeList = (struct Employee*)realloc(employeeList, numEmployees*sizeof(struct Employee)); // Increase size of employeeList

    // Get employee details
    printf("Enter employee ID: ");
    scanf("%d", &employeeList[numEmployees-1].id);

    printf("Enter employee name: ");
    scanf("%s", employeeList[numEmployees-1].name);

    printf("Enter employee salary: ");
    scanf("%f", &employeeList[numEmployees-1].salary);

    printf("Employee added!\n");
}

// Function to display all employees
void displayEmployees() {
    if(numEmployees == 0) {
        printf("No employees found!\n");
    }
    else {
        for(int i=0; i<numEmployees; i++) {
            printf("ID: %d | Name: %s | Salary: $%.2f\n", employeeList[i].id, employeeList[i].name, employeeList[i].salary);
        }
    }
}

// Function to search for an employee
void searchEmployee() {
    if(numEmployees == 0) {
        printf("No employees found!\n");
    }
    else {
        int searchId;
        printf("Enter the ID of the employee you want to search for: ");
        scanf("%d", &searchId);

        int found = 0;
        for(int i=0; i<numEmployees; i++) {
            if(employeeList[i].id == searchId) {
                found = 1;
                printf("Employee found!\n");
                printf("ID: %d | Name: %s | Salary: $%.2f\n", employeeList[i].id, employeeList[i].name, employeeList[i].salary);
                break;
            }
        }

        if(found == 0) {
            printf("Employee not found!\n");
        }
    }
}