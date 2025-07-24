//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20], department[10];
    float salary;
} Employee;

void insert_employee(Employee e) {
    FILE *fp;
    fp = fopen("employees", "ab");
    fwrite(&e, sizeof(Employee), 1, fp);
    fclose(fp);
}

void display_employees() {
    FILE *fp;
    Employee e;
    fp = fopen("employees", "rb");
    printf("%-4s %-20s %-10s %-10s\n", "ID", "Name", "Department", "Salary");
    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        printf("%-4d %-20s %-10s %-10.2f\n", e.id, e.name, e.department, e.salary);
    }
    fclose(fp);
}

void search_employee_by_id(int id) {
    FILE *fp;
    Employee e;
    fp = fopen("employees", "rb");
    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        if (e.id == id) {
            printf("%-4s %-20s %-10s %-10s\n", "ID", "Name", "Department", "Salary");
            printf("%-4d %-20s %-10s %-10.2f\n", e.id, e.name, e.department, e.salary);
            fclose(fp);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
    fclose(fp);
}

int main() {

    Employee e1, e2, e3;
    e1.id = 1; strcpy(e1.name, "John"); strcpy(e1.department, "Sales"); e1.salary = 5000.00;
    e2.id = 2; strcpy(e2.name, "Jane"); strcpy(e2.department, "Marketing"); e2.salary = 6000.50;
    e3.id = 3; strcpy(e3.name, "Bob"); strcpy(e3.department, "IT"); e3.salary = 7000.75;

    insert_employee(e1);
    insert_employee(e2);
    insert_employee(e3);

    display_employees();

    search_employee_by_id(2);

    return 0;
}