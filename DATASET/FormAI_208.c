//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include<stdio.h>

struct Employee {
  int empId;
  char empName[20];
  float empSalary;
};

int main() {
  struct Employee empList[3] = {
    {101, "John", 2500.50},
    {102, "Jane", 3000.75},
    {103, "Alex", 4000.00}
  };

  // Displaying the Employee data using Single pointer
  printf("Single Pointer Visualisation\n");
  printf("------------------------------\n");
  struct Employee *empPtr;
  empPtr = empList;
  int i;
  for(i=0; i<3; i++) {
    printf("Employee ID: %d\n", (empPtr+i)->empId);
    printf("Employee Name: %s\n", (empPtr+i)->empName);
    printf("Employee Salary: $%.2f\n\n", (empPtr+i)->empSalary);
  }

  // Displaying the Employee data using Double pointer
  printf("Double Pointer Visualisation\n");
  printf("------------------------------\n");
  struct Employee **empDblPtr;
  empDblPtr = &empPtr;
  for(i=0; i<3; i++) {
    printf("Employee ID: %d\n", (*empDblPtr+i)->empId);
    printf("Employee Name: %s\n", (*empDblPtr+i)->empName);
    printf("Employee Salary: $%.2f\n\n", (*empDblPtr+i)->empSalary);
  }

  return 0;
}