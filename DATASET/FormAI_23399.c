//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct employee {
    int emp_id;
    char name[50];
    int age;
    char department[50];
};

int main() {
    FILE *fptr;
    struct employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.emp_id);

    printf("Enter employee name: ");
    scanf("%s", emp.name);

    printf("Enter employee age: ");
    scanf("%d", &emp.age);

    printf("Enter employee department: ");
    scanf("%s", emp.department);

    fptr = fopen("employees.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fptr, "%d %s %d %s\n", emp.emp_id, emp.name, emp.age, emp.department);

    printf("Employee details saved in employees.txt!\n");

    fclose(fptr);

    return 0;
}