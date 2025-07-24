//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for holding student's information
struct Student {
    int id;
    char name[50];
    char department[50];
};

// Struct for holding course's information
struct Course {
    int id;
    char name[50];
    struct Student students[50];
    int num_students;
};

// Struct for holding database's information and courses
struct Database {
    struct Course courses[50];
    int num_courses;
};

// Function for adding a new course to the database
void add_course(struct Database* db, int id, char name[]) {
    // Create new course and add it to the database
    struct Course new_course;
    new_course.id = id;
    strcpy(new_course.name, name);
    new_course.num_students = 0;
    db->courses[db->num_courses++] = new_course;
    printf("Added course with ID %d and name %s\n", id, name);
}

// Function for adding a new student to a course
void add_student(struct Database* db, int course_id, int student_id, char name[], char department[]) {
    // Find the course in the database
    int course_index = -1;
    for (int i = 0; i < db->num_courses; i++) {
        if (db->courses[i].id == course_id) {
            course_index = i;
            break;
        }
    }

    if (course_index != -1) {
        // Create new student and add him to the course
        struct Student new_student;
        new_student.id = student_id;
        strcpy(new_student.name, name);
        strcpy(new_student.department, department);
        db->courses[course_index].students[db->courses[course_index].num_students++] = new_student;
        printf("Added student with ID %d and name %s to course with ID %d\n", student_id, name, course_id);
    } else {
        printf("Error: Could not find course with ID %d\n", course_id);
    }
}

// Function for printing all courses and their students
void print_database(struct Database* db) {
    for (int i = 0; i < db->num_courses; i++) {
        printf("Course ID: %d, Name: %s, Number of Students: %d\n", db->courses[i].id, db->courses[i].name, db->courses[i].num_students);

        for (int j = 0; j < db->courses[i].num_students; j++) {
            printf("  Student ID: %d, Name: %s, Department: %s\n", db->courses[i].students[j].id, db->courses[i].students[j].name, db->courses[i].students[j].department);
        }
    }
}

int main() {
    // Create new database
    struct Database db;
    db.num_courses = 0;

    // Add some courses and students to the database
    add_course(&db, 101, "English");
    add_course(&db, 102, "Mathematics");
    add_student(&db, 101, 1, "John Smith", "Literature");
    add_student(&db, 101, 2, "Jane Doe", "English");
    add_student(&db, 102, 3, "Bob Johnson", "Mathematics");
    add_student(&db, 102, 4, "Mary Johnson", "Mathematics");

    // Print the database
    printf("Database after adding courses and students:\n");
    print_database(&db);

    // Add a new course and student to the database
    add_course(&db, 103, "Science");
    add_student(&db, 103, 5, "Samantha Lee", "Physics");

    // Print the database again
    printf("\nDatabase after adding a new course and student:\n");
    print_database(&db);

    return 0;
}