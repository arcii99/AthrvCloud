//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50];
    int age;
    float salary;
};

int main() {
    struct employee emp;
    FILE *fp;

    fp = fopen("employee.bin", "wb+");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Enter employee name: ");
    gets(emp.name);

    printf("Enter employee age: ");
    scanf("%d", &emp.age);

    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(emp), 1, fp);

    fseek(fp, 0, SEEK_SET);

    fread(&emp, sizeof(emp), 1, fp);

    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);

    fclose(fp);
    return 0;
}