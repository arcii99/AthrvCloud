//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>

int main() {
    // declare variables
    int num_students;
    float marks, total_marks = 0, average_marks;
    
    // get number of students from user
    printf("Enter number of students: ");
    scanf("%d", &num_students);
    
    // get marks for each student and add to total marks
    for (int i = 1; i <= num_students; i++) {
        printf("Enter marks for student %d: ", i);
        scanf("%f", &marks);
        
        total_marks += marks;
    }
    
    // calculate average marks
    average_marks = total_marks / num_students;
    
    // determine grade based on average marks
    char grade;
    if (average_marks >= 90) {
        grade = 'A';
    } else if (average_marks >= 80) {
        grade = 'B';
    } else if (average_marks >= 70) {
        grade = 'C';
    } else if (average_marks >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    
    // display results
    printf("Number of students: %d\n", num_students);
    printf("Total marks: %0.2f\n", total_marks);
    printf("Average marks: %0.2f\n", average_marks);
    printf("Grade: %c\n", grade);
    
    return 0;
}