//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

typedef struct {
    char name[20];
    int start_index;
    int end_index;
} Index;

Index index_arr[MAX_ENTRIES];
Employee employees[MAX_ENTRIES];
int num_employees = 0;
int num_indexes = 0;

void insert_employee(Employee e) {
    employees[num_employees++] = e;
}

void sort_employees() {
    for (int i = 0; i < num_employees - 1; i++) {
        for (int j = 0; j < num_employees - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j+1].name) > 0) {
                Employee temp = employees[j];
                employees[j] = employees[j+1];
                employees[j+1] = temp;
            }
        }
    }
}

void create_index() {
    int start_index = 0;
    int end_index = 0;
    strcpy(index_arr[num_indexes].name, employees[0].name);

    for (int i = 1; i < num_employees; i++) {
        if (strcmp(employees[i].name, index_arr[num_indexes].name) != 0) {
            end_index = i - 1;
            index_arr[num_indexes].start_index = start_index;
            index_arr[num_indexes].end_index = end_index;
            num_indexes++;
            start_index = i;
            strcpy(index_arr[num_indexes].name, employees[i].name);
        }
    }

    //set last index
    end_index = num_employees - 1;
    index_arr[num_indexes].start_index = start_index;
    index_arr[num_indexes].end_index = end_index;
    num_indexes++;
}

void search_by_name(char *name) {
    int index = -1;

    for (int i = 0; i < num_indexes; i++) {
        if (strcmp(name, index_arr[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("%s not found\n", name);
        return;
    }

    for (int i = index_arr[index].start_index; i <= index_arr[index].end_index; i++) {
        printf("%d. %s %d %.1f\n", i+1, employees[i].name, employees[i].age, employees[i].salary);
    }
}

int main() {
    
    //insert some employees
    insert_employee((Employee){"John", 25, 2500});
    insert_employee((Employee){"Mary", 30, 3000});
    insert_employee((Employee){"David", 35, 3500});
    insert_employee((Employee){"Alice", 22, 2000});
    insert_employee((Employee){"Bob", 25, 2500});
    insert_employee((Employee){"Kate", 30, 2800});
    insert_employee((Employee){"Eric", 36, 4000});
    insert_employee((Employee){"Lucy", 28, 2700});
    insert_employee((Employee){"Mike", 33, 3200});
    insert_employee((Employee){"Ann", 29, 2900});

    //sort the employees by name
    sort_employees();

    //create an index
    create_index();

    //search for employees by name
    search_by_name("Bob");
    search_by_name("Kate");
    search_by_name("Adam");
    
 
    return 0;
}