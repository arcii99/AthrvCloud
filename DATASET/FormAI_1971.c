//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constant for maximum length of a line in CSV file
#define MAX_LINE_LENGTH 100

// define a struct for CSV data
typedef struct {
    char name[20];
    int age;
    float salary;
} Person;

int main() {
    // open CSV file for reading
    FILE *csvFile = fopen("data.csv", "r");

    // check if file exists
    if (csvFile == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }

    // initialize variables for reading CSV data
    char line[MAX_LINE_LENGTH];
    char *token;
    int numPersons = 0;

    // count number of lines in CSV file
    while (fgets(line, MAX_LINE_LENGTH, csvFile) != NULL) {
        numPersons++;
    }

    // allocate memory for array of Person structs
    Person *persons = malloc(numPersons * sizeof(Person));

    // reset file pointer to beginning of CSV file
    rewind(csvFile);

    // read CSV data into array of Person structs
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, csvFile) != NULL) {
        // tokenize line at commas
        token = strtok(line, ",");
        
        // read name from first token
        strcpy(persons[i].name, token);
        
        // read age from second token
        token = strtok(NULL, ",");
        persons[i].age = atoi(token);
        
        // read salary from third token
        token = strtok(NULL, ",");
        persons[i].salary = atof(token);

        i++;
    }

    // close CSV file
    fclose(csvFile);

    // print out CSV data in table format
    printf("%-20s%-10s%-10s\n", "Name", "Age", "Salary");
    for (i = 0; i < numPersons; i++) {
        printf("%-20s%-10d%-10.2f\n", persons[i].name, persons[i].age, persons[i].salary);
    }

    // free dynamically allocated memory
    free(persons);

    return 0;
}