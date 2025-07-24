//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
    char skills[100];
} Employee;

void printEmployee(Employee emp) {
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);
    printf("Skills: %s\n", emp.skills);
}

int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.");
        return 1;
    }
    
    Employee emp;
    char line[100];
    fgets(line, 100, file); // read name
    strcpy(emp.name, line);
    
    fgets(line, 100, file); // read age
    emp.age = atoi(line);
    
    fgets(line, 100, file); // read salary
    emp.salary = atof(line);
    
    fgets(line, 100, file); // read skills
    strcpy(emp.skills, line);
    
    fclose(file);
    
    printEmployee(emp);
    
    return 0;
}