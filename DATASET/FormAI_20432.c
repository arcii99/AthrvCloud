//FormAI DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void swap(Employee *a, Employee *b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(Employee employees[], int n, int sort_by) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sort_by == 1) {
                if (employees[j].id > employees[j + 1].id)
                    swap(&employees[j], &employees[j + 1]);
            } else if (sort_by == 2) {
                if (strcmp(employees[j].name, employees[j + 1].name) > 0)
                    swap(&employees[j], &employees[j + 1]);
            } else if (sort_by == 3) {
                if (employees[j].salary > employees[j + 1].salary)
                    swap(&employees[j], &employees[j + 1]);
            }
        }
    }
}

int main() {
    Employee employees[] = {
            {101, "John", 2500.0},
            {102, "Alice", 3000.0},
            {103, "Samuel", 2000.0},
            {104, "Emily", 4000.0},
            {105, "George", 3500.0}
    };

    int n = sizeof(employees) / sizeof(Employee);

    printf("Before Sorting:\n");
    printf("ID\tName\tSalary\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    printf("\nSorting by ID....\n");
    bubble_sort(employees, n, 1);
    printf("After Sorting:\n");
    printf("ID\tName\tSalary\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    printf("\nSorting by Name....\n");
    bubble_sort(employees, n, 2);
    printf("After Sorting:\n");
    printf("ID\tName\tSalary\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    printf("\nSorting by Salary....\n");
    bubble_sort(employees, n, 3);
    printf("After Sorting:\n");
    printf("ID\tName\tSalary\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    return 0;
}