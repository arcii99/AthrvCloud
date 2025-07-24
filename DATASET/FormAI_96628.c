//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10000

typedef struct student {
    int id;
    char name[50];
    char major[50];
    float gpa;
} Student;

Student db[MAX_RECORDS];

// Database functionality
void add_student(int id, char* name, char* major, float gpa)
{
    int i = 0;
    while (db[i].id != 0) { // Find first empty record
        i++;
    }

    db[i].id = id;
    strcpy(db[i].name, name);
    strcpy(db[i].major, major);
    db[i].gpa = gpa;
}

void remove_student(int id)
{
    int i = 0;
    while (db[i].id != id && i < MAX_RECORDS) {
        i++;
    }

    if (i < MAX_RECORDS && db[i].id == id) { // Found matching record
        db[i].id = 0;
        strcpy(db[i].name, "");
        strcpy(db[i].major, "");
        db[i].gpa = 0.0;
    }
}

void print_student(Student s)
{
    printf("ID: %d, Name: %s, Major: %s, GPA: %.2f\n", s.id, s.name, s.major, s.gpa);
}

void print_all_students()
{
    int i = 0;
    while (db[i].id != 0 && i < MAX_RECORDS) { // Print all non-empty records
        print_student(db[i]);
        i++;
    }
}

int main()
{
    // Add sample students
    add_student(1, "Alice", "Computer Science", 3.8);
    add_student(2, "Bob", "Mathematics", 3.4);
    add_student(3, "Charlie", "Physics", 3.9);
    add_student(4, "David", "Biology", 3.2);
    add_student(5, "Eve", "Psychology", 3.6);

    // Print all students
    printf("All students:\n");
    print_all_students();

    // Remove a student
    printf("Removing student with ID 3\n");
    remove_student(3);

    // Print all students again
    printf("All students after removal:\n");
    print_all_students();

    return 0;
}