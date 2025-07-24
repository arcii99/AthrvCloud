//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to hold the data from each row of the CSV file
typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

// function to parse a single line of the CSV file and fill the Employee struct
void parseLine(char *line, Employee *employee) {
    char *token;
    int i = 0;
    // split the line into tokens using comma as the separator
    token = strtok(line, ",");
    while(token != NULL) {
        // fill the Employee struct fields based on the token position
        switch(i) {
            case 0:
                strcpy(employee->name, token);
                break;
            case 1:
                employee->age = atoi(token);
                break;
            case 2:
                employee->salary = atof(token);
                break;
        }
        // move to the next token
        token = strtok(NULL, ",");
        i++;
    }
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    Employee employees[100];
    int i = 0;
    // open the CSV file for reading
    fp = fopen("employees.csv", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    // read the file line by line and fill the Employee structs
    while((read = getline(&line, &len, fp)) != -1) {
        parseLine(line, &employees[i]);
        i++;
    }
    // close the file
    fclose(fp);
    // free the memory allocated for the getline function
    if(line) {
        free(line);
    }
    // print the employee data to the console
    for(int j = 0; j < i; j++) {
        printf("Name: %s\n", employees[j].name);
        printf("Age: %d\n", employees[j].age);
        printf("Salary: %.2f\n", employees[j].salary);
    }
    return 0;
}