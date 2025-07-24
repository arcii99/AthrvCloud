//FormAI DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

void printEmployee(Employee emp){
    printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", emp.name, emp.age, emp.salary);
}

int main(){
    int numEmployees;
    printf("How many employees do you want to enter?\n");
    scanf("%d", &numEmployees);

    Employee *employees = malloc(numEmployees * sizeof(Employee));

    for(int i = 0; i < numEmployees; i++){
        printf("Enter employee %d's name:\n", i+1);
        scanf("%s", employees[i].name);
        printf("Enter employee %d's age:\n", i+1);
        scanf("%d", &employees[i].age);
        printf("Enter employee %d's salary:\n", i+1);
        scanf("%f", &employees[i].salary);
        printf("\n");
    }

    printf("Employees:\n");
    for(int i = 0; i < numEmployees; i++){
        printEmployee(employees[i]);
    }

    float totalSalary = 0;
    for(int i = 0; i < numEmployees; i++){
        totalSalary += employees[i].salary;
    }
    printf("Total salary of all employees: %.2f\n", totalSalary);

    free(employees);
    return 0;
}