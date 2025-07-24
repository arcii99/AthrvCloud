//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void readCSV(const char *fileName, Employee employee[]) {
    FILE *file = fopen(fileName, "r");
    char line[1000];
    char *token;
    int row = 0;
    while (fgets(line, 1000, file) != NULL) {
        token = strtok(line, ",");
        strcpy(employee[row].name, token);
        token = strtok(NULL, ",");
        employee[row].age = atoi(token);
        token = strtok(NULL, ",");
        employee[row].salary = atof(token);
        row++;
    }
}

int main() {
    const char *fileName = "employee.csv";
    Employee employee[10];
    readCSV(fileName, employee);
    for (int i = 0; i < 5; i++) {
        printf("Name: %s\nAge: %d\nSalary: %f\n", employee[i].name, employee[i].age, employee[i].salary);
    }
    return 0;
}