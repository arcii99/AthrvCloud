//FormAI DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Student struct with name, age, and GPA.
typedef struct {
    char name[50];
    int age;
    float GPA;
} Student;

// Swap function to swap two Students.
void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort function to sort an array of Students based on their GPA.
void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].GPA < students[j+1].GPA) {
                swap(&students[j], &students[j+1]);
            }
        }
    }
}

int main() {
    // Declare an array of Students.
    Student students[5];
    
    // Populate the array of Students.
    strcpy(students[0].name, "John");
    students[0].age = 20;
    students[0].GPA = 2.5;
    
    strcpy(students[1].name, "Mary");
    students[1].age = 19;
    students[1].GPA = 3.2;
    
    strcpy(students[2].name, "Bob");
    students[2].age = 21;
    students[2].GPA = 3.8;
    
    strcpy(students[3].name, "Sara");
    students[3].age = 18;
    students[3].GPA = 2.0;
    
    strcpy(students[4].name, "Tom");
    students[4].age = 22;
    students[4].GPA = 3.5;
    
    // Print the unsorted array of Students.
    printf("Unsorted Array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d, GPA: %.1f\n", students[i].name, students[i].age, students[i].GPA);
    }
    
    // Sort the array of Students based on their GPA using Bubble Sort.
    bubbleSort(students, 5);
    
    // Print the sorted array of Students.
    printf("\nSorted Array based on GPA:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d, GPA: %.1f\n", students[i].name, students[i].age, students[i].GPA);
    }
    
    return 0;
}