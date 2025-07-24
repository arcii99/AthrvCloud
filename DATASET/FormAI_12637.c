//FormAI DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* name;
  int age;
  float salary;
} Employee;

int compare_employee(const void* emp1, const void* emp2) {
  Employee* e1 = (Employee*) emp1;
  Employee* e2 = (Employee*) emp2;

  if (e1->age < e2->age) {
    return -1;
  } else if (e1->age == e2->age) {
    return strcmp(e1->name, e2->name);
  } else {
    return 1;
  }
}

void print_employee(Employee* emp, int count) {
  printf("\nName: %s\n", emp->name);
  printf("Age: %d\n", emp->age);
  printf("Salary: %.2f\n", emp->salary);

  if (count > 1) {
    printf("--------------------------\n");
  }
}

int main() {
  Employee employees[] = {
    { "Kevin", 22, 10000.50 },
    { "Alice", 24, 5000.00 },
    { "Bob", 25, 7500.00 },
    { "Zoe", 24, 5500.75 },
    { "Adam", 22, 8000.25 }
  };

  int num_employees = sizeof(employees) / sizeof(Employee);

  printf("Before sorting:\n");
  for (int i=0; i<num_employees; i++) {
    print_employee(&employees[i], num_employees);
  }

  qsort(employees, num_employees, sizeof(Employee), compare_employee);

  printf("\nAfter sorting:\n");
  for (int i=0; i<num_employees; i++) {
    print_employee(&employees[i], num_employees);
  }

  return 0;
}