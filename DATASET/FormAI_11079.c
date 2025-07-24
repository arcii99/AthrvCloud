//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 10000
#define MAX_NAME_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
    float salary;
}employee;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int index;
}index_data;

int index_count = 0;
index_data name_index[MAX_RECORDS];

employee employees[MAX_RECORDS];

void add_employee(employee e){
    employees[e.id] = e;

    index_data index;
    strcpy(index.name, e.name);
    index.index = e.id;
    name_index[index_count] = index;
    index_count++;
}

void print_employee(int id){
    printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", employees[id].id, employees[id].name, employees[id].department, employees[id].salary);
}

int search_employee(char *name){
    for(int i=0; i<index_count; i++){
        if(strcmp(name_index[i].name, name) == 0){
            return name_index[i].index;
        }
    }
    return -1;
}

int main(){
    employee e1 = {0, "John Doe", "Sales", 60000};
    employee e2 = {1, "Jane Smith", "HR", 70000};
    employee e3 = {2, "Bob Johnson", "IT", 80000};

    add_employee(e1);
    add_employee(e2);
    add_employee(e3);

    int search_result = search_employee("Jane Smith");

    if(search_result == -1){
        printf("Employee not found.\n");
    }else{
        printf("Employee found.\n\n");
        print_employee(search_result);
    }

    return 0;
}