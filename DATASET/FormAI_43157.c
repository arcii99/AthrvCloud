//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;

   fp = fopen("example.txt", "w+");
   if(fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   char name[20];
   int age;
   float salary;

   printf("Please enter details for a new employee:\n");
   printf("Name: ");
   scanf("%s", name);
   printf("Age: ");
   scanf("%d", &age);
   printf("Salary: ");
   scanf("%f", &salary);

   fprintf(fp, "Name: %s\nAge: %d\nSalary: %.2f", name, age, salary);

   rewind(fp);

   char buffer[255];

   while(fgets(buffer, 255, fp) != NULL){
      printf("%s", buffer);
   }

   fclose(fp);

   return 0;
}