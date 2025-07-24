//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STUDENTS 1000

// Define the student structure
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Define the database structure
typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} Database;

// Initialize a database
void init_database(Database* db) {
    db->count = 0;
}

// Add a student to the database
void add_student(Database* db, int id, const char* name, float gpa) {
    // Create a new student
    Student new_student = { .id = id, .gpa = gpa };
    strncpy(new_student.name, name, sizeof(new_student.name) - 1);

    // Add the new student to the database
    db->students[db->count] = new_student;
    db->count++;
}

// Find a student in the database by ID
Student* find_student_by_id(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].id == id) {
            return &db->students[i];
        }
    }

    return NULL;
}

// Find all students in the database with a GPA greater than or equal to the given value
void find_students_by_gpa(Database* db, float gpa) {
    printf("Students with a GPA >= %.2f:\n", gpa);
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].gpa >= gpa) {
            printf("%d, %s, %.2f\n", db->students[i].id, db->students[i].name, db->students[i].gpa);
        }
    }
}

// Remove a student from the database by ID
bool remove_student(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].id == id) {
            // Shift all the students after the one to be removed to fill the gap
            for (int j = i; j < db->count - 1; j++) {
                db->students[j] = db->students[j + 1];
            }
            db->count--;
            return true;
        }
    }

    return false;
}

int main() {
    // Initialize the database
    Database db;
    init_database(&db);

    // Add some students to the database
    add_student(&db, 1001, "John", 3.5);
    add_student(&db, 1002, "Jane", 3.8);
    add_student(&db, 1003, "Bob", 2.9);
    add_student(&db, 1004, "Alice", 3.2);

    // Find a student by ID
    Student* john = find_student_by_id(&db, 1001);
    if (john) {
        printf("Student found: %d, %s, %.2f\n", john->id, john->name, john->gpa);
    } else {
        printf("Student not found!\n");
    }

    // Find all students with a GPA >= 3.0
    find_students_by_gpa(&db, 3.0);

    // Remove a student by ID
    if (remove_student(&db, 1003)) {
        printf("Student removed successfully!\n");
    } else {
        printf("Student not found!\n");
    }

    return 0;
}