//FormAI DATASET v1.0 Category: Data validation ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

int main() {
    int age;
    char name[50];
    float salary;
    bool valid = true;
    
    printf("Welcome to the Employee Data Validation System\n");
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your salary: ");
    scanf("%f", &salary);
    
    // validate age
    if (age < 18 || age > 65) {
        printf("Invalid age entered. Please enter an age between 18 and 65.\n");
        valid = false;
    }
    
    // validate salary
    if (salary < 0) {
        printf("Invalid salary entered. Salary cannot be negative.\n");
        valid = false;
    }
    
    // validate name
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && !isspace(name[i])) {
            printf("Invalid name entered. Name can only contain letters and spaces.\n");
            valid = false;
            break;
        }
    }
    
    if (valid) {
        printf("Data validation successful!\n");
        printf("Name: %sAge: %dSalary: %.2f\n", name, age, salary);
    } else {
        printf("Data validation failed.\n");
    }
    
    return 0;
}