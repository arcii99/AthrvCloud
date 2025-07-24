//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int i;
    struct{
      char name[20];
      char appointment_date[10];
      int age;
      char gender[10];
    }patient[3];
    printf("Welcome to the Appointment Scheduler!\n");
    for(i=0;i<3;i++)
    {
      printf("\nEnter Patient Info for Slot %d\n",i+1);
      printf("Patient Name: ");
      scanf("%s",patient[i].name);
      printf("Appointment Date: ");
      scanf("%s",patient[i].appointment_date);
      printf("Age: ");
      scanf("%d",&patient[i].age);
      printf("Gender[M/F/O]: ");
      scanf("%s",patient[i].gender);
    }
    printf("\nList of Patients booked for Appointments\n");
    for(i=0;i<3;i++)
    {
      printf("\n%d. Name: %s\nDate: %s\nAge: %d\nGender: %s\n",i+1,patient[i].name,patient[i].appointment_date,patient[i].age,patient[i].gender);
    }
    return 0;
}