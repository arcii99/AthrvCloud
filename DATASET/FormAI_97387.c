//FormAI DATASET v1.0 Category: Data validation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[30];
    int age;
    double salary;

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    printf("Enter age: ");
    if (scanf("%d", &age) != 1 || age <= 0) {
        printf("Invalid input. Age must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    printf("Enter salary: ");
    if (scanf("%lf", &salary) != 1 || salary <= 0) {
        printf("Invalid input. Salary must be a positive number.\n");
        return EXIT_FAILURE;
    }

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Salary: $%.2f\n", salary);

    return EXIT_SUCCESS;
}