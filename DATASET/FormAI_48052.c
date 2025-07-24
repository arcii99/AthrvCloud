//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>

struct employee {
   char name[50];
   int age;
   float salary;
};

int main() {
   struct employee emp = {"John Doe", 25, 2500.00};
   printf("Employee Name: %s\n", emp.name);
   printf("Employee Age: %d\n", emp.age);
   printf("Employee Salary: %f\n", emp.salary);
   
   return 0;
}