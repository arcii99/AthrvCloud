//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    int height;
    double salary;
} Employee;

int main() {
    FILE *file = fopen("employees.dat", "rb");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    Employee employee;

    printf("Enter name to search: ");
    char searchName[50];
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; //remove trailing newline

    int found = 0;
    while (fread(&employee, sizeof(Employee), 1, file)) {
        if (strcmp(employee.name, searchName) == 0) {
            printf("Name: %s\n", employee.name);
            printf("Age: %d\n", employee.age);
            printf("Height: %d\n", employee.height);
            printf("Salary: %.2f\n", employee.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found\n");
    }

    fclose(file);
    return 0;
}