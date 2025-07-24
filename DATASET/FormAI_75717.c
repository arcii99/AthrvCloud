//FormAI DATASET v1.0 Category: Data validation ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>

int main() {
    char name[50];
    int age;
    float salary;
    
    // Accepting user input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your salary: ");
    scanf("%f", &salary);
    
    // Validating user input
    if (isdigit(name[0])) {
        printf("Invalid name\n");
    }
    else if (age < 18 || age > 60) {
        printf("Invalid age\n");
    }
    else if (salary < 5000 || salary > 1000000) {
        printf("Invalid salary\n");
    }
    else {
        printf("Valid input\n");
    }
    
    return 0;
}