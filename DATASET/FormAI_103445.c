//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>

struct student {
   char name[50];
   int age;
   float marks;
};

int main() {
   int i;
   struct student arr[5]; // initialize array of students

   // get input for all students
   printf("Enter details of 5 students:\n");
   for(i=0; i<5; i++) {
       printf("Enter name of student %d: ", i+1);
       scanf("%s", &arr[i].name);
       printf("Enter age of student %d: ", i+1);
       scanf("%d", &arr[i].age);
       printf("Enter marks of student %d: ", i+1);
       scanf("%f", &arr[i].marks);
   }
   
   // find student with highest marks
   float highest_marks;
   int highest_marks_index;
   for(i=0; i<5; i++) {
       if(arr[i].marks > highest_marks) {
           highest_marks = arr[i].marks;
           highest_marks_index = i;
       }
   }
   
   // print student with highest marks
   printf("\nStudent with highest marks:\n");
   printf("Name: %s\n", arr[highest_marks_index].name);
   printf("Age: %d\n", arr[highest_marks_index].age);
   printf("Marks: %f\n", arr[highest_marks_index].marks);

   return 0;
}