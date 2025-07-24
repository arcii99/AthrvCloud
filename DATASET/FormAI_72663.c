//FormAI DATASET v1.0 Category: Database querying ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the structure for student data
typedef struct Student {
    int id;
    char name[25];
    float gpa;
} Student;

//Function prototypes
void addStudent(Student* s);
void displayStudent(Student s);
void displayAllStudents(Student* s, int num);
void searchStudent(Student* s, int num, int id);
void updateStudent(Student* s, int num, int id);
void deleteStudent(Student* s, int* num, int id);

int main() {
    int num, choice, id;
    Student* students;

    printf("Enter number of students: ");
    scanf("%d", &num);

    //Dynamically allocating memory for storing student data
    students = (Student*)malloc(num * sizeof(Student));

    //Loop for displaying menu and taking choices from user
    do {
        printf("\n----- MENU -----\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by ID\n");
        printf("4. Update student data\n");
        printf("5. Delete student data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students[num]);
                num++;
                break;

            case 2:
                displayAllStudents(students, num);
                break;

            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                searchStudent(students, num, id);
                break;

            case 4:
                printf("Enter student ID to update data: ");
                scanf("%d", &id);
                updateStudent(students, num, id);
                break;

            case 5:
                printf("Enter student ID to delete data: ");
                scanf("%d", &id);
                deleteStudent(students, &num, id);
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while(choice != 6);

    //Freeing dynamically allocated memory
    free(students);

    return 0;
}

//Function to add student data to the database
void addStudent(Student* s) {
    printf("Enter student ID: ");
    scanf("%d", &s->id);
    printf("Enter student name: ");
    scanf("%s", s->name);
    printf("Enter student GPA: ");
    scanf("%f", &s->gpa);
    printf("Student data added successfully!\n");
}

//Function to display a single student's data
void displayStudent(Student s) {
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("GPA: %.2f\n", s.gpa);
}

//Function to display all students' data
void displayAllStudents(Student* s, int num) {
    if(num == 0) {
        printf("No student data found!\n");
    } else {
        printf("Students in database:\n");
        for(int i = 0; i < num; i++) {
            displayStudent(s[i]);
            printf("\n");
        }
    }
}

//Function to search for a student by their ID
void searchStudent(Student* s, int num, int id) {
    int found = 0;
    for(int i = 0; i < num; i++) {
        if(s[i].id == id) {
            printf("Student found!\n");
            displayStudent(s[i]);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Student not found in database!\n");
    }
}

//Function to update a student's data
void updateStudent(Student* s, int num, int id) {
    int found = 0;
    for(int i = 0; i < num; i++) {
        if(s[i].id == id) {
            printf("Student found!\n");
            printf("Enter updated name: ");
            scanf("%s", s[i].name);
            printf("Enter updated GPA: ");
            scanf("%f", &s[i].gpa);
            printf("Student data updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Student not found in database!\n");
    }
}

//Function to delete a student's data
void deleteStudent(Student* s, int* num, int id) {
    int found = 0;
    for(int i = 0; i < *num; i++) {
        if(s[i].id == id) {
            printf("Student found!\n");
            for(int j = i; j < *num-1; j++) {
                s[j] = s[j+1];
            }
            (*num)--;
            found = 1;
            printf("Student data deleted successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("Student not found in database!\n");
    }
}