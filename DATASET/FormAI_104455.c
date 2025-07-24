//FormAI DATASET v1.0 Category: Task Scheduler ; Style: distributed
#include<stdio.h>

/* Declaring task functions */
void task1();
void task2();
void task3();
void task4();


int main() {
   /* Scheduling tasks */
   printf("Task scheduler started!\n");
   task1();
   task2();
   task3();
   task4();
   printf("Task scheduler finished!\n");
   return 0;
}

/* Defining task functions */
void task1() {
   printf("Executing task1...\n");
}

void task2() {
   printf("Executing task2...\n");
}

void task3() {
   printf("Executing task3...\n");
}

void task4() {
   printf("Executing task4...\n");
}