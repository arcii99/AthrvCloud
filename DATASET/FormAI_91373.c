//FormAI DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store data
typedef struct {
    char name[20];
    int age;
    double salary;
} Employee;

// Define the function to load data
Employee* loadData(char* filename, int* size) {
    FILE *fp;
    Employee *data;
    char buffer[100];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        exit(1);
    }

    while (fgets(buffer, 100, fp) != NULL) {
        i++;
    }

    // Allocate memory for the data
    data = (Employee*) malloc(i * sizeof(Employee));
    if (data == NULL) {
        printf("Error: could not allocate memory");
        exit(1);
    }

    *size = i;
    rewind(fp);
    i = 0;

    // Load the data into the struct array
    while (fgets(buffer, 100, fp) != NULL) {
        sscanf(buffer, "%s %d %lf", data[i].name, &data[i].age, &data[i].salary);
        i++;
    }

    fclose(fp);
    return data;
}

// Define the function to display the data
void displayData(Employee* data, int size) {
    int i;

    printf("Name\tAge\tSalary\n");
    for (i = 0; i < size; i++) {
        printf("%s\t%d\t%.2lf\n", data[i].name, data[i].age, data[i].salary);
    }
}

// Define the function to sort the data by age
void sortData(Employee* data, int size) {
    int i, j;
    Employee temp;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (data[i].age > data[j].age) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main() {
    int size;
    Employee *data;

    data = loadData("employees.txt", &size);
    printf("Data loaded successfully with size: %d\n", size);
    displayData(data, size);

    sortData(data, size);
    printf("Data sorted by age:\n");
    displayData(data, size);

    free(data);
    return 0;
}