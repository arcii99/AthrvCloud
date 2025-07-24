//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   float appointmentTime[5];
   char clientName[5][20], clientPhoneNumber[5][12];
   int numOfAppointments = 0;
   
   while(numOfAppointments < 5)
   {
      printf("Welcome to the Appointment Scheduler! Please enter the client's name, phone number, and appointment time, separated by spaces:\n");
      scanf("%s %s %f", &clientName[numOfAppointments], &clientPhoneNumber[numOfAppointments], &appointmentTime[numOfAppointments]);
      
      printf("\nThanks! The appointment for %s at %0.2f has been scheduled.\n\n", clientName[numOfAppointments], appointmentTime[numOfAppointments]);
      
      numOfAppointments++;
   }
   
   printf("\n\nYou have reached the maximum number of appointments for today. Here is a list of all scheduled appointments:\n");
   
   for(int i = 0; i < numOfAppointments; i++)
   {
      printf("%d. %s - %s - %0.2f\n", i+1, clientName[i], clientPhoneNumber[i], appointmentTime[i]);
   }
   
   return 0;
}