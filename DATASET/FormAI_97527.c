//FormAI DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>

int main() {
    printf("Welcome to the C programming language!\n");
    printf("This program will calculate your grade point average (GPA)\n");
    
    // initialize variables
    int num_courses;
    float grade, total_grades = 0.0, gpa;
    
    // get user input for number of courses
    printf("How many courses did you take?: ");
    scanf("%d", &num_courses);
    
    // iterate through all courses to get grades
    for (int i = 1; i <= num_courses; i++) {
        printf("Enter grade for course #%d (out of 4.0): ", i);
        scanf("%f", &grade);
        
        // make sure grade is valid
        while (grade < 0.0 || grade > 4.0) {
            printf("Invalid grade, please enter a grade between 0 and 4.0: ");
            scanf("%f", &grade);
        }
        
        // add grade to total
        total_grades += grade;
    }
    
    // calculate GPA
    gpa = total_grades / num_courses;
    
    printf("Your GPA is: %.2f\n", gpa);
    printf("Thank you for using our GPA calculator!");
    
    return 0;
}