//FormAI DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void task1()
{
    printf("Task 1 has been executed.\n");
}

void task2()
{
    printf("Task 2 has been executed.\n");
}

void task3()
{
    printf("Task 3 has been executed.\n");
}
 
int main()
{
    int i;
    int tasks[3] = {1, 2, 3};
 
    printf("Welcome to the Task Scheduler!\n");
 
    while (1) {
        for (i = 0; i < 3; i++) {
            switch(tasks[i]) {
                case 1:
                    task1();
                    break;
                case 2:
                    task2();
                    break;
                case 3:
                    task3();
                    break;
            }
        }
    }
 
    printf("Thanks for using the Task Scheduler!\n");
 
    return 0;
}