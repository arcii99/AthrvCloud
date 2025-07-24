//FormAI DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char* name;
    float salary;
} Employee;

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    Employee* employees = (Employee*) malloc(n * sizeof(Employee));
    
    if (employees == NULL) {
        printf("Memory allocation failed. Exiting program.");
        exit(1);
    }
    
    for (int i = 0; i < n; i++) {
        printf("Enter details of employee %d:\n", i+1);
        employees[i].id = i+1;
        
        printf("Name: ");
        employees[i].name = (char*) malloc(50 * sizeof(char));
        scanf("%s", employees[i].name);
        
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
    
    printf("\n\nEmployee details:\n");
    printf("-------------------\n");
    printf("| ID | NAME | SALARY |\n");
    
    for (int i = 0; i < n; i++) {
        printf("| %d | %s | %0.2f |\n", employees[i].id, employees[i].name, employees[i].salary);
        free(employees[i].name);
    }
    
    free(employees);
    
    return 0;
}