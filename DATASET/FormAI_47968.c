//FormAI DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50];
    int age;
    float salary;
    char department[50];
};

int main() {
    struct employee emp;
    char filename[50];
    printf("Enter file name:");
    scanf("%s", filename);
    FILE *fptr;
    fptr = fopen(filename, "wb+");
    if(fptr == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    printf("\nEnter employee name:");
    scanf("%s", emp.name);
    printf("\nEnter employee age:");
    scanf("%d", &emp.age);
    printf("\nEnter employee salary:");
    scanf("%f", &emp.salary);
    printf("\nEnter employee department:");
    scanf("%s", emp.department);
    // writing to file
    fwrite(&emp, sizeof(struct employee), 1, fptr);
    printf("\nWritten data to file successfully!");
    // reading from file
    fseek(fptr, 0, SEEK_SET);
    struct employee emp_read;
    fread(&emp_read, sizeof(struct employee), 1, fptr);
    printf("\nEmployee details:");
    printf("\nName: %s", emp_read.name);
    printf("\nAge: %d", emp_read.age);
    printf("\nSalary: %f", emp_read.salary);
    printf("\nDepartment: %s", emp_read.department);
    fclose(fptr);
    return 0;
}