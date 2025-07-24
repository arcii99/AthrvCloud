//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct student {
   int id;
   char name[50];
   int age;
   float marks;
};

int main() {
   int i, n;
   struct student *s;

   printf("Enter the number of students: ");
   scanf("%d", &n);

   s = (struct student*)malloc(n * sizeof(struct student));

   if (s == NULL) {
      printf("Memory allocation failed.");
      exit(EXIT_FAILURE);
   }

   for (i = 0;i < n;i++) {
      printf("Enter id, name, age, and marks respectively: ");

      scanf("%d", &((s + i)->id));
      scanf("%s", &((s + i)->name));
      scanf("%d", &((s + i)->age));
      scanf("%f", &((s + i)->marks));
   }

   printf("Displaying Information: \n\n");
   for (i = 0;i < n;++i){
      printf("id: %d\n", (s + i)->id);
      printf("Name: %s\n", (s + i)->name);
      printf("Age: %d\n", (s + i)->age);
      printf("Marks: %.2f\n\n", (s + i)->marks);
   }

   free(s);

   return 0;
}