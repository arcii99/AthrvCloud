//FormAI DATASET v1.0 Category: Database querying ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold employee data
struct Employee {
    char name[50];
    int age;
    char department[50];
    double salary;
};

int main() {
    // Connect to database
    printf("Connecting to database...\n\n");

    // Simulate retrieval of employee data from database
    struct Employee employees[] = {
        {"John Smith", 32, "Marketing", 50000.0},
        {"Sarah Lee", 28, "Engineering", 75000.0},
        {"Michael Johnson", 45, "Human Resources", 65000.0},
        {"Emily Chen", 39, "Finance", 80000.0},
        {"David Kim", 26, "Sales", 45000.0},
        {"Jessica Lee", 31, "Engineering", 70000.0},
        {"James Kim", 38, "Marketing", 55000.0},
        {"Cindy Lee", 29, "Human Resources", 60000.0},
        {"Steven Chen", 42, "Finance", 90000.0},
        {"Grace Lee", 27, "Sales", 50000.0},
    };

    // Calculate total number of employees
    int num_employees = sizeof(employees) / sizeof(struct Employee);

    // Print out all employees in Engineering department
    printf("Employees in Engineering department:\n");
    for(int i = 0; i < num_employees; i++) {
        if(strcmp(employees[i].department, "Engineering") == 0) {
            printf("%s\n", employees[i].name);
        }
    }
    printf("\n");

    // Print out all employees making over $60,000
    printf("Employees making over $60,000:\n");
    for(int i = 0; i < num_employees; i++) {
        if(employees[i].salary > 60000.0) {
            printf("%s\n", employees[i].name);
        }
    }
    printf("\n");

    // Calculate average age of employees
    int total_age = 0;
    for(int i = 0; i < num_employees; i++) {
        total_age += employees[i].age;
    }
    double avg_age = (double) total_age / num_employees;
    printf("Average age of employees: %.2f\n\n", avg_age);

    // Disconnect from database
    printf("Disconnecting from database...\n");

    return 0;
}