//FormAI DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void task1(int signum){
    printf("Task 1 executed successfully!\n");
}

void task2(int signum){
    printf("Task 2 executed successfully!\n");
}

void task3(int signum){
    printf("Task 3 executed successfully!\n");
}

void schedule_task(int task_id, int delay){
    signal(SIGALRM, (task_id==1?task1:(task_id==2?task2:task3)));
    alarm(delay);
}

int main(){
    int choice, delay;
    while(1){
        printf("1. Schedule Task 1\n2. Schedule Task 2\n3. Schedule Task 3\n4. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        if(choice==4){
            break;
        }
        printf("Enter delay (in seconds): ");
        scanf("%d", &delay);
        schedule_task(choice, delay);
        pause();
    }
    return 0;
}