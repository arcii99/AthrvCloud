//FormAI DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include<stdio.h> //Including the stdio header file
#include<unistd.h> //Including the header file for sleep function
 
int main(){
    int i, j, k; //Declaring the variables
 
    printf("\nStarting the task scheduler...\n\n");
 
    for(i=1; i<=10; i++){ //Outer loop for 10 tasks
        printf("Task %d started...\n",i);
 
        for(j=1; j<=5; j++){ //Inner loop for 5 sub-tasks in each task
            printf("Sub-Task %d of Task %d started...\n",j,i);
            sleep(1); //Delay of 1 second
            printf("Sub-Task %d of Task %d completed...\n",j,i);
        }
 
        printf("Task %d completed.\n\n",i);
 
        for(k=1; k<=3; k++){ //Delay of 3 seconds before starting the next task
            printf("%d ",k);
            sleep(1); //Delay of 1 second
        }
 
        printf("\n\n");
    }
 
    printf("\nAll tasks completed.\n\n");
 
    return 0; //Returning 0 to indicate successful execution
}