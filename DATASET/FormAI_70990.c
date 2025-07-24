//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>

int main() {
  // This program helps students to calculate their total GPA score for a semester
  int num_courses; // number of courses taken in the semester
  printf("Enter number of courses: ");
  scanf("%d", &num_courses); // read the number of courses from user

  float grades[num_courses]; // array to store all the grades received
  int credits[num_courses]; // array to store the credit hours for each course

  // loop to read inputs for each course
  for (int i = 0; i < num_courses; i++) {
    printf("Enter the grade for course %d [A=4, B=3, C=2, D=1, F=0]: ", i+1);
    scanf("%f", &grades[i]);

    printf("Enter the credit hours for course %d: ", i+1);
    scanf("%d", &credits[i]);
  }

  float total_credits = 0.0, total_grade_points = 0.0;

  // loop to calculate the total credit hours and grade points
  for (int i = 0; i < num_courses; i++) {
    total_credits += credits[i]; // add the credit hours for this course
    total_grade_points += grades[i] * credits[i]; // add the grade points for this course
  }

  float gpa = total_grade_points / total_credits; // calculate the GPA
  printf("Your GPA is: %.2f", gpa); // print the results

  return 0; // indicate successful program execution
}