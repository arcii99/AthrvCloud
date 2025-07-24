//FormAI DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the recovered data
typedef struct {
    int id;
    char name[20];
    char address[50];
    float salary;
} Employee;

// Define a function to read the recovered data from file
int readRecoveredData(Employee* employees, int num_employees) {
    FILE* fp;
    fp = fopen("recovered_data.txt", "r");
    if (fp == NULL) {
        printf("Error: failed to read file.\n");
        return 0;
    }
    int i;
    for (i = 0; i < num_employees; i++) {
        fscanf(fp, "%d %s %s %f", &employees[i].id, employees[i].name, employees[i].address, &employees[i].salary);
    }
    fclose(fp);
    return 1;
}

// Define a function to display the recovered data
void displayRecoveredData(Employee* employees, int num_employees) {
    int i;
    printf("ID\tName\t\tAddress\t\tSalary\n");
    for (i = 0; i < num_employees; i++) {
        printf("%d\t%s\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].address, employees[i].salary);
    }
}

// Define the main function
int main() {
    int num_employees = 3;  // number of employees to recover
    Employee employees[num_employees];  // array to store the recovered data
    int success = readRecoveredData(employees, num_employees);  // read the recovered data from file
    if (success) {
        printf("Recovered data:\n");
        displayRecoveredData(employees, num_employees);  // display the recovered data
    }
    return 0;
}