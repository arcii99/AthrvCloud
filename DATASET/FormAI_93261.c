//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

typedef struct {
    char* name;
    int age;
    char* phone_number;
    float salary;
} Employee;

int main() {
    FILE* csv_file = fopen("employees.csv", "r");
    if (csv_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[MAX_LINE_LEN];
    fgets(line, MAX_LINE_LEN, csv_file); // skip header line

    int num_employees = 0;
    while (fgets(line, MAX_LINE_LEN, csv_file)) {
        num_employees++;
    }

    rewind(csv_file);
    fgets(line, MAX_LINE_LEN, csv_file); // skip header line

    Employee* employees = (Employee*) malloc(num_employees * sizeof(Employee));
    int current_employee = 0;

    while (fgets(line, MAX_LINE_LEN, csv_file)) {
        char* token = strtok(line, ",");
        char* name = token;
        int age = atoi(strtok(NULL, ","));
        char* phone_number = strtok(NULL, ",");
        float salary = atof(strtok(NULL, ","));

        employees[current_employee].name = (char*) malloc(strlen(name) * sizeof(char));
        strcpy(employees[current_employee].name, name);
        employees[current_employee].age = age;
        employees[current_employee].phone_number = (char*) malloc(strlen(phone_number) * sizeof(char));
        strcpy(employees[current_employee].phone_number, phone_number);
        employees[current_employee].salary = salary;

        current_employee++;
    }

    fclose(csv_file);

    // print out employee data
    for (int i = 0; i < num_employees; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Phone Number: %s\n", employees[i].phone_number);
        printf("Salary: $%.2f\n\n", employees[i].salary);
    }

    // free allocated memory
    for (int i = 0; i < num_employees; i++) {
        free(employees[i].name);
        free(employees[i].phone_number);
    }
    free(employees);

    return 0;
}