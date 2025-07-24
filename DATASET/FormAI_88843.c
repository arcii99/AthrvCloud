//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

int main() {
    struct Employee employeeData;
    FILE *filePointer;
    filePointer = fopen("employee.txt", "w");
    
    if(filePointer == NULL) {
        printf("Error in opening file\n");
        return 1;
    }
    
    printf("Enter employee name: ");
    fgets(employeeData.name, 50, stdin);

    printf("Enter employee age: ");
    scanf("%d", &employeeData.age);

    printf("Enter employee salary: ");
    scanf("%f", &employeeData.salary);

    fprintf(filePointer, "%s %d %.2f", employeeData.name, employeeData.age, employeeData.salary);
    
    fclose(filePointer);
    
    filePointer = fopen("employee.txt", "r");
    
    if(filePointer == NULL) {
        printf("Error in opening file\n");
        return 1;
    }

    fscanf(filePointer, "%s %d %f", &employeeData.name, &employeeData.age, &employeeData.salary);
    
    printf("\n\nEmployee Name: %s", employeeData.name);
    printf("\nEmployee Age: %d", employeeData.age);
    printf("\nEmployee Salary: $%.2f", employeeData.salary);
    
    fclose(filePointer);

    return 0;
}