//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   int id;
   char name[20];
   int age;
   float marks;
};

int main() {
   int n, i;
   printf("Enter number of students: ");
   scanf("%d", &n);

   struct student *database = (struct student*) malloc(n * sizeof(struct student));

   for (i = 0; i < n; i++) {
      printf("\nEnter details of student %d:\n", i+1);
      printf("Enter ID: ");
      scanf("%d", &database[i].id);
      printf("Enter name: ");
      scanf("%s", database[i].name);
      printf("Enter age: ");
      scanf("%d", &database[i].age);
      printf("Enter marks: ");
      scanf("%f", &database[i].marks);
   }

   printf("\nDatabase:\n");

   for (i = 0; i < n; i++) {
      printf("\nStudent %d:\n", i+1);
      printf("ID: %d\n", database[i].id);
      printf("Name: %s\n", database[i].name);
      printf("Age: %d\n", database[i].age);
      printf("Marks: %.2f\n", database[i].marks);
   }

   free(database);
   return 0;
}