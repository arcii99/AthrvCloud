//FormAI DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int employee_id;
    char name[50];
    char department[50];
    float salary;
};

void print_title(char *title) {
    printf("\n%s\n", title);
    int len = strlen(title);
    for(int i=0; i<len; i++) {
        printf("=");
    }
    printf("\n");
}

void print_employee_details(struct employee emp) {
    printf("Employee ID: %d\n", emp.employee_id);
    printf("Name: %s\n", emp.name);
    printf("Department: %s\n", emp.department);
    printf("Salary: $%.2f\n", emp.salary);
}

void print_employees(struct employee *employees, int num_employees) {
    printf("\nEmployee Details\n");
    printf("=============================\n");
    for(int i=0; i<num_employees; i++) {
        print_employee_details(employees[i]);
    }
}

void query_by_employee_id(struct employee *employees, int num_employees) {
    int id;
    printf("\nEnter employee ID to search for: ");
    scanf("%d", &id);

    for(int i=0; i<num_employees; i++) {
        if(employees[i].employee_id == id) {
            printf("\nFound Employee Details\n");
            printf("================================\n");
            print_employee_details(employees[i]);
            return;
        }
    }

    printf("\nNo employee with ID %d was found.\n", id);
}

void query_by_department(struct employee *employees, int num_employees) {
    char dept_name[50];
    printf("\nEnter department name to search for: ");
    scanf("%s", dept_name);

    printf("\nEmployee Details in %s Department\n", dept_name);
    printf("=================================\n");
    for(int i=0; i<num_employees; i++) {
        if(strcmp(employees[i].department, dept_name) == 0) {
            print_employee_details(employees[i]);
        }
    }
}

void query_by_salary(struct employee *employees, int num_employees) {
    float min_salary;
    printf("\nEnter minimum salary to search for: ");
    scanf("%f", &min_salary);

    printf("\nEmployee Details with salary >= $%.2f\n", min_salary);
    printf("====================================\n");
    for(int i=0; i<num_employees; i++) {
        if(employees[i].salary >= min_salary) {
            print_employee_details(employees[i]);
        }
    }
}

int main() {
    struct employee employees[] = {
        {1001, "John Smith", "Sales", 60000},
        {1002, "Jane Doe", "HR", 70000},
        {1003, "Bob Johnson", "IT", 80000},
        {1004, "Mary Brown", "Marketing", 90000},
        {1005, "Jack Lee", "Finance", 100000},
    };
    int num_employees = sizeof(employees) / sizeof(employees[0]);

    print_title("Employee Database Querying Program");
    char menu_choice;
    do {
        printf("\nMenu\n");
        printf("=====\n");
        printf("1- Search for employee by ID\n");
        printf("2- Search for employees in department\n");
        printf("3- Search for employees by minimum salary\n");
        printf("Q- Quit\n");
        printf("\nEnter menu choice: ");
        scanf("%s", &menu_choice);

        switch(menu_choice) {
            case '1': query_by_employee_id(employees, num_employees);
                      break;
            case '2': query_by_department(employees, num_employees);
                      break;
            case '3': query_by_salary(employees, num_employees);
                      break;
            case 'Q': printf("\nGoodbye!\n");
                      break;
            default: printf("\nInvalid choice. Please try again.\n");
                     break;
        }
    } while(menu_choice != 'Q');

    return 0;
}