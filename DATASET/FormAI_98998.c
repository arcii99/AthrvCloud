//FormAI DATASET v1.0 Category: Online Examination System ; Style: scalable
#include <stdio.h>

struct student {
    char name[50];
    int roll_no;
    int marks;
};

void main() {
    int num_of_students, i;
    printf("Enter the number of students: ");
    scanf("%d", &num_of_students);
    struct student arr[num_of_students];
    
    // Get student details
    for(i=0; i<num_of_students; i++) {
        printf("\nEnter student %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", &arr[i].name);
        printf("Roll number: ");
        scanf("%d", &arr[i].roll_no);
        printf("Marks: ");
        scanf("%d", &arr[i].marks);
    }
    
    // Display student details
    printf("\nStudent Details:\n");
    printf("Name\tRoll No.\tMarks\n");
    for(i=0; i<num_of_students; i++) {
        printf("%s \t%d\t%d\n", arr[i].name, arr[i].roll_no, arr[i].marks);
    }
    
    // Calculate average marks
    int total_marks=0;
    for(i=0; i<num_of_students; i++) {
        total_marks += arr[i].marks;
    }
    float avg_marks = (float) total_marks/num_of_students;
    printf("\nAverage marks: %.2f\n", avg_marks);
}