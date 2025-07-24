//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <time.h>

#define TASKS_NUMBER 10

typedef struct{
    char name[30];
    int priority;
    int time;
} Task;

Task taskList[TASKS_NUMBER];

void initializeTasksList(){
    //insert some sample tasks
    Task task1 = {"Hack Mainframe Server", 10, 60};
    taskList[0] = task1;
    
    Task task2 = {"Steal Classified Data", 8, 45};
    taskList[1] = task2;
    
    Task task3 = {"Plant Malware in Corp Mainframe", 9, 120};
    taskList[2] = task3;
    
    Task task4 = {"Scrape Cyber Cafe's Wifi Traffic", 6, 30};
    taskList[3] = task4;
    
    Task task5 = {"Infiltrate Corporation Employee's PC", 7, 90};
    taskList[4] = task5;
    
    Task task6 = {"Disrupt Corp Communication Network", 5, 60};
    taskList[5] = task6;
    
    Task task7 = {"Deface Corp Website", 4, 20};
    taskList[6] = task7;
    
    Task task8 = {"Find New Security Flaw", 6, 30};
    taskList[7] = task8;
    
    Task task9 = {"Create Backdoor in Server", 9, 120};
    taskList[8] = task9;
    
    Task task10 = {"Sell Stolen Data to Highest Bidder", 10, 15};
    taskList[9] = task10;
}



int findHighestPriorityTask(){
    int highestPriorityIndex = 0;
    for(int i=0; i<TASKS_NUMBER; i++){
        if(taskList[i].priority > taskList[highestPriorityIndex].priority){
            highestPriorityIndex = i;
        }
    }
    
    return highestPriorityIndex;
}


int main(){
    int elapsedTime = 0;
    initializeTasksList();
    
    printf("Task Scheduler Starting...\n");
    
    while(1){
        int highestPriorityIndex = findHighestPriorityTask();
        Task taskToProcess = taskList[highestPriorityIndex];
        
        if(taskToProcess.time > 0){
            printf("%s Started. Time Required: %d Seconds.\n", taskToProcess.name, taskToProcess.time);
            
            while(taskToProcess.time > 0){
                sleep(1);
                elapsedTime++;
                taskToProcess.time--;
            }
            
            printf("%s Completed Successfully. Elapsed Time: %d Seconds.\n", taskToProcess.name, elapsedTime);
            elapsedTime = 0;
            
        }else{
            printf("%s has already been Done. Skipping...\n", taskToProcess.name);
        }
        
        taskList[highestPriorityIndex].priority = 0;
        
        int remainingTasks = 0;
        for(int i=0; i<TASKS_NUMBER; i++){
            if(taskList[i].priority > 0){
                remainingTasks++;
            }
        }
        
        if(remainingTasks == 0){
            printf("All Tasks Completed!\n");
            break;
        }
    }
    
    printf("Task Scheduler Terminated.\n");
    
    return 0;
}