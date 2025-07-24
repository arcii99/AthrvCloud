//FormAI DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define a struct for our custom data type
typedef struct {
    int id;
    char* name;
} Employee;

int main() {
    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    // Allocate a block of memory for our employees array
    Employee* employees = (Employee*)malloc(numEmployees * sizeof(Employee));

    // Loop through each employee and ask for their id and name
    for(int i = 0; i < numEmployees; i++) {
        printf("Enter the id for employee %d: ", i+1);
        scanf("%d", &(employees[i].id));

        // Allocate memory for the employee's name
        employees[i].name = (char*)malloc(50 * sizeof(char));

        printf("Enter the name for employee %d: ", i+1);
        scanf("%s", employees[i].name);
    }

    // Print out all of the employee information
    for(int i = 0; i < numEmployees; i++) {
        printf("Employee %d:\n", i+1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);

        // Free the memory used for the employee's name
        free(employees[i].name);
    }

    // Free the memory used for the employees array
    free(employees);

    return 0;
}