//FormAI DATASET v1.0 Category: Data validation ; Style: innovative
#include <stdio.h>

void validate(int age, float salary, char gender, char job[]) {
  // Validation rule #1: Age must be between 18 and 60
  if (age < 18 || age > 60) {
    printf("Invalid age! Age must be between 18 and 60.\n");
    return; // End function execution
  }
  // Validation rule #2: Salary must be greater than 0
  if (salary <= 0) {
    printf("Invalid salary! Salary must be greater than 0.\n");
    return;
  }
  // Validation rule #3: Gender must be either 'M' or 'F'
  if (gender != 'M' && gender != 'F') {
    printf("Invalid gender! Gender must be either 'M' or 'F'.\n");
    return;
  }
  // Validation rule #4: Job must either be 'Student' or 'Employee'
  if (strcmp(job, "Student") != 0 && strcmp(job, "Employee") != 0) {
    printf("Invalid job! Job must either be 'Student' or 'Employee'.\n");
    return;
  }
  // If all validation rules pass, print success message
  printf("Data validation successful! Age: %d, Salary: %.2f, Gender: %c, Job: %s\n", age, salary, gender, job);
}

int main() {
  int age; 
  float salary; 
  char gender, job[10];

  printf("Enter your age: ");
  scanf("%d", &age);
  printf("Enter your salary: ");
  scanf("%f", &salary);
  printf("Enter your gender (M/F): ");
  scanf(" %c", &gender); // Note the space before %c to consume white space
  printf("Enter your job (Student/Employee): ");
  scanf("%s", job);

  // Call validation function with user input as arguments
  validate(age, salary, gender, job);

  return 0;
}