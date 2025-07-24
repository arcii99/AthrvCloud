//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for storing data
struct Employee {
    int id;
    char name[50];
    int age;
    char department[50];
};

int main() {
    FILE *fp;
    struct Employee emp;
    int id;

    // Open database file for reading binary
    fp = fopen("employees.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Prompt user for employee ID
    printf("Enter employee ID: ");
    scanf("%d", &id);

    // Loop through file and find matching ID
    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == id) {
            // Show employee details
            printf("Employee ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Age: %d\n", emp.age);
            printf("Department: %s\n", emp.department);
            break;
        }
    }

    // Close file
    fclose(fp);

    return 0;
}