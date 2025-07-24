//FormAI DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct student { 
    int id; 
    char name[50]; 
    float score; 
} students[MAX_RECORDS];

int num_records = 0;

void add_student(int id, char name[], float score) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached!\n");
        return;
    }
    students[num_records].id = id;
    strcpy(students[num_records].name, name);
    students[num_records].score = score;
    num_records++;
}

void display_records() {
    printf("ID\tName\t\tScore\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%-16s%.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

void search_by_id(int id) {
    for (int i = 0; i < num_records; i++) {
        if (students[i].id == id) {
            printf("Record found:\n");
            printf("ID\tName\t\tScore\n");
            printf("%d\t%-16s%.2f\n", students[i].id, students[i].name, students[i].score);
            return;
        }
    }
    printf("Record not found for ID %d\n", id);
}

void delete_by_id(int id) {
    for (int i = 0; i < num_records; i++) {
        if (students[i].id == id) {
            for (int j = i; j < num_records-1; j++) {
                students[j] = students[j+1];
            }
            num_records--;
            printf("Record with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Record not found for ID %d\n", id);
}

int main() {
    add_student(1001, "John Doe", 87.0);
    add_student(1002, "Jane Smith", 91.5);
    add_student(1003, "Bob Johnson", 78.3);
    add_student(1004, "Sally Lee", 95.7);
    display_records();
    search_by_id(1002);
    delete_by_id(1003);
    printf("\nAfter deleting record:\n");
    display_records();
    return 0;
}