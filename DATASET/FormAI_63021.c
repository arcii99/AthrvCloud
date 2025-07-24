//FormAI DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int employee_id;
    float salary;
    char password[20];
};

void print_employee(struct Employee e) {
    printf("Name: %s\n", e.name);
    printf("Employee ID: %d\n", e.employee_id);
    printf("Salary: $%.2f\n", e.salary);
}

int main() {
    struct Employee e1;
    strcpy(e1.name, "John Doe");
    e1.employee_id = 1234;
    e1.salary = 75000.00;
    strcpy(e1.password, "password1");
    
    // print employee information
    print_employee(e1);
    
    // prompt user to enter password and verify
    char password_attempt[20];
    printf("Please enter your password: ");
    scanf("%s", password_attempt);
    
    if (strcmp(password_attempt, e1.password) == 0) {
        printf("Access granted.\n");
    }
    else {
        printf("Access denied.\n");
    }
    
    return 0;
}