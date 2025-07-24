//FormAI DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

//define a structure for holding student's data
struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {

    //declare an array of student structures
    struct Student students[5];

    //get student data from user
    for(int i=0;i<5;i++) {
        printf("Enter Student %d's ID: ", i+1);
        scanf("%d", &students[i].id);
        printf("Enter Student %d's Name: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter Student %d's GPA: ", i+1);
        scanf("%f", &students[i].gpa);
    }

    //declare variables for calculating average and highest GPA
    float total_gpa = 0, highest_gpa = 0;
    int highest_gpa_student_index = -1;

    //calculate average and highest GPA
    for(int i=0;i<5;i++) {
        total_gpa += students[i].gpa;
        if(students[i].gpa > highest_gpa) {
            highest_gpa = students[i].gpa;
            highest_gpa_student_index = i;
        }
    }

    //calculate average GPA
    float average_gpa = total_gpa / 5;

    //print out the results
    printf("The Average GPA is: %.2f\n", average_gpa);
    printf("The Student with the Highest GPA is: %s with a GPA of: %.2f\n", 
            students[highest_gpa_student_index].name, highest_gpa);

    return 0;

}