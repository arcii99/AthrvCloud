//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the structure for storing data
typedef struct {
  int id;
  char name[50];
  int age;
  double salary;
} Employee;

int main() {
  FILE *fp;
  Employee emp;
  int count = 0;
  double sum = 0.0;

  // Open the file for reading
  fp = fopen("employee_data.txt", "r");
  
  // Check if the file was opened successfully
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  // Read the data from the file and perform data mining
  while (fscanf(fp, "%d %s %d %lf", &emp.id, emp.name, &emp.age, &emp.salary) != EOF) {
    count++;
    sum += emp.salary;

    // Print the details of the employee
    printf("ID: %d\nName: %s\nAge: %d\nSalary: %.2lf\n\n", emp.id, emp.name, emp.age, emp.salary);
  }

  // Calculate the average salary of the employees
  double average_salary = (double)sum / count;
  printf("Average Salary: %.2lf\n", average_salary);

  // Close the file
  fclose(fp);

  return 0;
}