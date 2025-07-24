//FormAI DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>

// Define a struct to represent a student
typedef struct Student {
    char name[50];
    int age;
    char gender;
    int grade;
} Student;

// Print out the information of a given student
void printStudent(Student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Gender: %c\n", s.gender);
    printf("Grade: %d\n", s.grade);
}

// Generate a report for a given class, printing the information of each student
void generateReport(Student class[], int numStudents) {
    printf("Class Report:\n\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i+1);
        printStudent(class[i]);
        printf("\n");
    }
}

int main() {

    // Create an array of students
    Student class[] = {
        {"Alice Smith", 16, 'F', 11},
        {"Bob Johnson", 15, 'M', 10},
        {"Charlie Brown", 16, 'M', 11},
        {"Daisy Williams", 15, 'F', 10}
    };

    // Calculate the average grade of the class
    int totalGrade = 0;
    for (int i = 0; i < 4; i++) {
        totalGrade += class[i].grade;
    }
    double averageGrade = (double) totalGrade / 4;

    // Print out the class average
    printf("Class Average: %.2f\n\n", averageGrade);

    // Generate the class report
    generateReport(class, 4);

    // Find the top student in the class
    Student topStudent = class[0];
    for (int i = 1; i < 4; i++) {
        if (class[i].grade > topStudent.grade) {
            topStudent = class[i];
        }
    }

    // Print out the top student's information
    printf("Top Student:\n");
    printStudent(topStudent);
    printf("\n");

    // Find the average age of the male students in the class
    int totalMaleAge = 0;
    int numMaleStudents = 0;
    for (int i = 0; i < 4; i++) {
        if (class[i].gender == 'M') {
            totalMaleAge += class[i].age;
            numMaleStudents++;
        }
    }
    double averageMaleAge = (double) totalMaleAge / numMaleStudents;

    // Print out the average male age
    printf("Average Age of Male Students: %.2f\n", averageMaleAge);

    return 0;
}