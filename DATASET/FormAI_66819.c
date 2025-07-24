//FormAI DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

int main() {
  float hourlyRate, hoursWorked, regularPay, overtimePay, totalPay;
  char name[30], job[30];
  
  printf("Welcome to Payroll System!\n");
  printf("Please enter your name: ");
  scanf("%s", &name);
  printf("Please enter your job title: ");
  scanf("%s", &job);
  printf("Please enter the hourly rate: ");
  scanf("%f", &hourlyRate);
  printf("Please enter the hours worked: ");
  scanf("%f", &hoursWorked);
  
  if (hoursWorked <= 40) {
    regularPay = hourlyRate * hoursWorked;
    overtimePay = 0;
  }
  else {
    regularPay = hourlyRate * 40;
    overtimePay = (hoursWorked - 40) * (hourlyRate * 1.5);
  }
  
  totalPay = regularPay + overtimePay;
  
  printf("\nPayroll Summary for %s\n", name);
  printf("Job Title: %s\n", job);
  printf("Hourly Rate: $%.2f\n", hourlyRate);
  printf("Hours Worked: %.2f\n", hoursWorked);
  printf("Regular Pay: $%.2f\n", regularPay);
  printf("Overtime Pay: $%.2f\n", overtimePay);
  printf("Total Pay: $%.2f\n", totalPay);
  
  return 0;
}