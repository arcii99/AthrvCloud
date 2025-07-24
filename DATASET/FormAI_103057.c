//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000

typedef struct Employee {
    int id;
    char name[100];
    char department[100];
    int salary;
    int next;
} Employee;

typedef struct Index {
    int key;
    int pos;
} Index;

Employee records[MAX_RECORDS];
int free_list = 0;
Index index[MAX_RECORDS];
int index_size = 0;

void init_db() {
    int i;
    for(i = 0; i < MAX_RECORDS; i++) {
        records[i].id = -1;
        records[i].next = i + 1;
    }
    records[MAX_RECORDS - 1].next = -1;
}

void add_record(int id, char* name, char* department, int salary) {
    if(free_list == -1) {
        printf("Error: Database is full\n");
        return;
    }
    int new_pos = free_list;
    free_list = records[free_list].next;
    records[new_pos].id = id;
    strcpy(records[new_pos].name, name);
    strcpy(records[new_pos].department, department);
    records[new_pos].salary = salary;
    records[new_pos].next = -1;

    int i;
    for(i = 0; i < index_size; i++) {
        if(index[i].key > id) {
            break;
        }
    }
    if(i == index_size) {
        index[index_size].key = id;
        index[index_size].pos = new_pos;
        index_size++;
    } else {
        int j;
        for(j = index_size; j > i; j--) {
            index[j] = index[j-1];
        }
        index[i].key = id;
        index[i].pos = new_pos;
        index_size++;
    }
}

void delete_record(int id) {
    int i;
    int delete_pos = -1;
    for(i = 0; i < index_size; i++) {
        if(index[i].key == id) {
            delete_pos = index[i].pos;
            break;
        }
    }
    if(delete_pos == -1) {
        printf("Error: Record not found\n");
        return;
    }
    int prev_pos = -1;
    int curr_pos = delete_pos;
    int next_pos = records[curr_pos].next;
    while(curr_pos != -1) {
        records[curr_pos].id = -1;
        records[curr_pos].next = free_list;
        free_list = curr_pos;
        for(i = 0; i < index_size; i++) {
            if(index[i].pos == curr_pos) {
                int j;
                for(j = i; j < index_size; j++) {
                    index[j] = index[j+1];
                }
                index_size--;
                break;
            }
        }
        prev_pos = curr_pos;
        curr_pos = next_pos;
        if(next_pos != -1) {
            next_pos = records[next_pos].next;
        }
    }
    if(prev_pos != delete_pos) {
        records[prev_pos].next = next_pos;
    }
}

void print_record(int id) {
    int i;
    int print_pos = -1;
    for(i = 0; i < index_size; i++) {
        if(index[i].key == id) {
            print_pos = index[i].pos;
            break;
        }
    }
    if(print_pos == -1) {
        printf("Error: Record not found\n");
        return;
    }
    printf("ID: %d\n", records[print_pos].id);
    printf("Name: %s\n", records[print_pos].name);
    printf("Department: %s\n", records[print_pos].department);
    printf("Salary: %d\n", records[print_pos].salary);
}

int main() {
    init_db();
    add_record(123, "John", "HR", 50000);
    add_record(456, "Mike", "Marketing", 60000);
    add_record(789, "Sarah", "Sales", 70000);
    delete_record(456);
    print_record(123);
    return 0;
}