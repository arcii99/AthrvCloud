//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h> 

int main() {
   int numOfAppointments;
   printf("Enter the number of appointments you want to schedule: \n");
   scanf("%d", &numOfAppointments);

   char patientName[numOfAppointments][50];
   char patientAddress[numOfAppointments][100];
   int patientAge[numOfAppointments];
   char appointmentDate[numOfAppointments][20];
   char doctorName[numOfAppointments][50];

   int i;

   for (i = 0; i < numOfAppointments; i++) {
        printf("Enter the details for appointment number %d:\n", i+1);

        printf("Patient Name: ");
        scanf("%s", patientName[i]);

        printf("Patient Address: ");
        scanf("%s", patientAddress[i]);

        printf("Patient Age: ");
        scanf("%d", &patientAge[i]);

        printf("Appointment Date: ");
        scanf("%s", appointmentDate[i]);

        printf("Doctor Name: ");
        scanf("%s", doctorName[i]);
   }

   printf("\nAppointment Scheduled Successfully:\n");

   for (i = 0; i < numOfAppointments; i++) {

        printf("Patient Name: %s\n", patientName[i]);
        printf("Patient Address: %s\n", patientAddress[i]);
        printf("Patient Age: %d\n", patientAge[i]);
        printf("Appointment Date: %s\n", appointmentDate[i]);
        printf("Doctor Name: %s\n", doctorName[i]);
        printf("\n");
   }

   return 0;
}