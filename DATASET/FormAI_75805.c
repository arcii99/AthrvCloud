//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h> 

struct Process{
    char name;
    int arrivalTime, burstTime, waitingTime, turnAroundTime, completionTime;
    int executed; // if process is executed or not
} processes[] = {{'P', 0, 3}, {'Q', 1, 4}, {'R', 2, 2}, {'S', 3, 1}};

int size = sizeof processes / sizeof(struct Process);

void sortProcessesByArrivalTime(){
    struct Process temp;
    
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(processes[i].arrivalTime > processes[j].arrivalTime){
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void executeRR(int quantum){
    int remainingTime[size];
    int currentTime = 0;
    int completionTime = 0;
    int timeSlotStart[size];
    int timeSlotEnd[size];
    int counter = 0;
    
    for(int i=0; i<size; i++){ // remaining time for each process
        remainingTime[i] = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].executed = 0;
        timeSlotStart[i] = -1;
    }
    
    while(counter < size){
        int minRemainingTime = 9999;
        int minRemainingTimeIndex = 0;
        int currentBurst = 0;
        int flag = 0;
        
        for(int i=0; i<size; i++){
            if(processes[i].arrivalTime <= currentTime && processes[i].executed == 0 && remainingTime[i] < minRemainingTime){
                minRemainingTimeIndex = i;
                minRemainingTime = remainingTime[i];
                currentBurst = minRemainingTime;
                flag = 1;
            }
        }

        if(flag == 0){
            timeSlotEnd[counter] = currentTime;
            currentTime++;
            continue;
        }
        
        if(currentBurst > quantum){
            currentBurst = quantum;
        }
        
        timeSlotStart[minRemainingTimeIndex] = currentTime;
        currentTime += currentBurst;
        remainingTime[minRemainingTimeIndex] -= currentBurst;
        
        if(remainingTime[minRemainingTimeIndex] <= 0){
            processes[minRemainingTimeIndex].completionTime = currentTime;
            processes[minRemainingTimeIndex].turnAroundTime = processes[minRemainingTimeIndex].completionTime - processes[minRemainingTimeIndex].arrivalTime;
            processes[minRemainingTimeIndex].waitingTime = processes[minRemainingTimeIndex].turnAroundTime - processes[minRemainingTimeIndex].burstTime;
            processes[minRemainingTimeIndex].executed = 1;
            counter++;
            timeSlotEnd[minRemainingTimeIndex] = currentTime;
        }
    }
    
    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\tTurn Around Time\tTime slots\n");
    for(int i=0; i<size; i++){
        printf("%c\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t", processes[i].name, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].completionTime, processes[i].turnAroundTime);
        for(int j=timeSlotStart[i]; j<timeSlotEnd[i]; j++){
            printf("%d ", j);
        }
        printf("%d", timeSlotEnd[i]);
        printf("\n");
    }
}

int main(){
    printf("Round Robin CPU Scheduling Algorithm:\n");
    printf("======================================\n\n");
    printf("Process Details:\n");
    printf("================\n");
    sortProcessesByArrivalTime();
    executeRR(1);
    
    return 0;
}