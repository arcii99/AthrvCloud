//FormAI DATASET v1.0 Category: Educational ; Style: invasive
#include <stdio.h>

int main() {
  // We will create a program to calculate the final grades of students
  // The grades will be stored in an array
  // Any grade below 60 is considered as failed
  // We will count the number of failures and print it at the end
  
  int grades[10]; // array to store grades
  int count = 0; // variable to count the number of failures
  
  printf("Enter the grades of 10 students:\n");
  
  // Loop to get input from the user and store in the array
  for (int i = 0; i < 10; i++) {
    printf("Enter the grade of student %d: ", i+1);
    scanf("%d", &grades[i]);
    
    // Check if the grade is a failure
    if (grades[i] < 60) {
      count++; // increase the count of failures
    }
  }
  
  printf("\n\n***********************************\n");
  printf("FINAL GRADES OF THE STUDENTS\n");
  printf("***********************************\n\n");
  
  // Loop to print the final grade of each student
  for (int i = 0; i < 10; i++) {
    if (grades[i] < 60) {
      printf("Student %d: Failed\n", i+1);
    } else {
      printf("Student %d: Passed\n", i+1);
    }
  }
  
  printf("\n\nThere are %d students who failed the course\n", count);
  
  return 0;
}