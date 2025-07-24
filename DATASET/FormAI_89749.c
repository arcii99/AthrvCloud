//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void task1(){
    printf("Task 1 is running\n");
}

void task2(){
    printf("Task 2 is running\n");
}

void task3(){
    printf("Task 3 is running\n");
}

int main(){
    
    // seed the random number generator
    srand(time(NULL));
    
    // set the maximum time for each task
    int maxTime = 10;
    
    // randomly generate the execution time for each task between 1 and maxTime
    int task1Time = rand() % maxTime + 1;
    int task2Time = rand() % maxTime + 1;
    int task3Time = rand() % maxTime + 1;
    
    printf("Task 1 execution time: %d seconds\n", task1Time);
    printf("Task 2 execution time: %d seconds\n", task2Time);
    printf("Task 3 execution time: %d seconds\n", task3Time);
    
    // calculate the total execution time
    int totalExecutionTime = task1Time + task2Time + task3Time;
    
    printf("Total execution time: %d seconds\n", totalExecutionTime);
    printf("Task Scheduler starting...\n");
    
    // run the tasks in the order specified by the scheduler
    if(totalExecutionTime >= 30){
        printf("Error: Total execution time exceeds maximum allowed time\n");
    }
    else{
        printf("Running task 1...\n");
        task1();
        sleep(task1Time);
        
        printf("Running task 2...\n");
        task2();
        sleep(task2Time);
        
        printf("Running task 3...\n");
        task3();
        sleep(task3Time);
        
        printf("All tasks completed successfully\n");
    }
    
    return 0;
}