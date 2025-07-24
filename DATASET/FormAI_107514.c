//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Creating arrays of data
  int ages[] = {18, 22, 30, 45, 50, 60, 70, 80, 90, 100};
  double salaries[] = {1000.50, 2500.00, 4000.00, 6000.00, 8000.00, 10000.00, 12000.00, 15000.00, 18000.00, 20000.00};
  char *names[] = {"Alice", "Bob", "Charlie", "David", "Ellie", "Frank", "George", "Hannah", "Isaac", "Jack"};

  int count = sizeof(ages) / sizeof(int);

  // Finding average age
  int age_sum = 0;
  double salary_sum = 0.0;

  for (int i = 0; i < count; i++) {
    age_sum += ages[i];
    salary_sum += salaries[i];
  }

  double avg_age = (double)age_sum / count;
  double avg_salary = salary_sum / count;

  printf("The average age of the group is: %.2f\n", avg_age);
  printf("The average salary of the group is: %.2f\n", avg_salary);

  // Finding the person with the highest salary
  double highest_salary = salaries[0];
  int highest_salary_index = 0;

  for (int i = 1; i < count; i++) {
    if (salaries[i] > highest_salary) {
      highest_salary = salaries[i];
      highest_salary_index = i;
    }
  }

  printf("%s has the highest salary of %.2f\n", names[highest_salary_index], highest_salary);

  // Finding the oldest person
  int oldest_age = ages[0];
  int oldest_age_index = 0;

  for (int i = 1; i < count; i++) {
    if (ages[i] > oldest_age) {
      oldest_age = ages[i];
      oldest_age_index = i;
    }
  }

  printf("%s is the oldest person at %d years old\n", names[oldest_age_index], oldest_age);

  return 0;
}