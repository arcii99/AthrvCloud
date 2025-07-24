//FormAI DATASET v1.0 Category: Sorting ; Style: real-life
// Program to sort a list of employees based on their salary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[20];
    int age;
    int salary;
};

void printEmployees(struct employee *employees, int n) {
    printf("Name\tAge\tSalary\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%d\t%d\n", employees[i].name, employees[i].age, employees[i].salary);
    }
}

int compareSalary(const void *a, const void *b) {
    return ((struct employee*)b)->salary - ((struct employee*)a)->salary;
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    struct employee employees[n];
    
    for(int i=0; i<n; i++) {
        printf("Enter the name of employee #%d: ", i+1);
        scanf("%s", employees[i].name);
        printf("Enter the age of employee #%d: ", i+1);
        scanf("%d", &employees[i].age);
        printf("Enter the salary of employee #%d: ", i+1);
        scanf("%d", &employees[i].salary);
    }
    
    printf("\nBefore sorting:\n");
    printEmployees(employees, n);
    
    qsort(employees, n, sizeof(struct employee), compareSalary);
    
    printf("\nAfter sorting based on salary:\n");
    printEmployees(employees, n);
    
    return 0;
}