//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of Students 
#define MAX_STUDENTS 100

// Define the maximum length of Student's Name 
#define MAX_NAME_LENGTH 50

// Define the maximum length of Student's ID 
#define MAX_ID_LENGTH 10

// Define the maximum length of Student's Address 
#define MAX_ADDRESS_LENGTH 100

// Define the maximum number of subjects 
#define MAX_SUBJECTS 5

// Define the Student struct 
typedef struct Student {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int marks[MAX_SUBJECTS];
} Student;

// Define the Database struct 
typedef struct Database {
    Student students[MAX_STUDENTS];
    int count;
} Database;

// Function to add Student to Database 
void addStudent(Database *database, Student student) {
    database->students[database->count++] = student;
}

// Function to delete Student from Database 
void deleteStudent(Database *database, int index) {
    for(int i = index; i < database->count - 1; i++) {
        database->students[i] = database->students[i+1];
    }
    database->count--;
}

// Function to modify Student in Database 
void modifyStudent(Database *database, int index, Student student) {
    database->students[index] = student;
}

// Function to search Student in Database 
int searchStudent(Database *database, char id[]) {
    for(int i = 0; i < database->count; i++) {
        if(strcmp(database->students[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print all Students in Database 
void printAllStudents(Database *database) {
    printf("All Students:\n");
    for(int i = 0; i < database->count; i++) {
        printf("Name: %s\n", database->students[i].name);
        printf("ID: %s\n", database->students[i].id);
        printf("Address: %s\n", database->students[i].address);
        printf("Marks: ");
        for(int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%d ", database->students[i].marks[j]);
        }
        printf("\n\n");
    }
}

// Main Function 
int main() {
    // Create the Database 
    Database database;
    database.count = 0;

    // Add Some Students 
    Student student1 = {"John", "123", "123 Main Street", {90, 80, 70, 85, 90}};
    addStudent(&database, student1);
    Student student2 = {"Jane", "456", "456 High Street", {80, 90, 60, 75, 80}};
    addStudent(&database, student2);

    // Print all Students 
    printAllStudents(&database);

    // Delete a Student 
    int index = searchStudent(&database, "123");
    if(index != -1) {
        deleteStudent(&database, index);
    }

    // Print all Students again 
    printAllStudents(&database);

    // Modify a Student 
    index = searchStudent(&database, "456");
    if(index != -1) {
        Student modifiedStudent = {"Janet", "456", "456 Low Street", {70, 85, 65, 80, 90}};
        modifyStudent(&database, index, modifiedStudent);
    }

    // Print all Students again 
    printAllStudents(&database);

    return 0;
}